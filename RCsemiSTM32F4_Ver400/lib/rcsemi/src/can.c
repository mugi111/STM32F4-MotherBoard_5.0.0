/*/***************************************************************************
 *	@ファイル名		:	can.c
 *	@概要		:	CAN0,CAN1ポートを用いてCAN通信を行います.
 *	@バージョン		:	0.1.0
 *	@開発者			:	むぎ
 *	@使用環境		:	STM32F407VG, MB_Ver5
 *
 *	非常停止　全ビット　1
 *	解除		  全ビット　0
 *
 *MASTER		0x01
 *↓motorDriver
 *PWM MD  		0x02
 *AIRCYLINDER	0x03
 *PID MD		0x04
 *POT MD		0x05
 *CURRENT MD	0x06
 *↑
 *DIO			0x07
 *ADC			0x08
 *ENC			0x09
 **************************************************************************/

#include <stm32f4xx.h>
#include "can.h"

#define ABS_VAL(val) ((val) < 0 ? -(val) : (val))

uint8_t CanInit(void)
{
	uint8_t init;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB ,ENABLE);


	GPIO_InitTypeDef CAN_GPIOInit_Structure;
	CAN_GPIOInit_Structure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	CAN_GPIOInit_Structure.GPIO_Mode = GPIO_Mode_AF;
	CAN_GPIOInit_Structure.GPIO_OType = GPIO_OType_PP;
	CAN_GPIOInit_Structure.GPIO_PuPd = GPIO_PuPd_UP;
	CAN_GPIOInit_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &CAN_GPIOInit_Structure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_CAN1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_CAN1);

	CAN_DeInit(CAN1);

	CAN_InitTypeDef CAN_InitStructure;
	CAN_InitStructure.CAN_TTCM = DISABLE;
	CAN_InitStructure.CAN_ABOM = DISABLE;
	CAN_InitStructure.CAN_AWUM = DISABLE;
	CAN_InitStructure.CAN_NART = DISABLE;
	CAN_InitStructure.CAN_RFLM = DISABLE;
	CAN_InitStructure.CAN_TXFP = DISABLE;
	CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
	CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;

	CAN_InitStructure.CAN_BS1 = CAN_BS1_11tq;
	CAN_InitStructure.CAN_BS2 = CAN_BS2_2tq;
	CAN_InitStructure.CAN_Prescaler = 3;
	CAN_Init(CAN1, &CAN_InitStructure);

	init = CAN_Init(CAN1, &CAN_InitStructure);


	CAN_FilterInitTypeDef  CAN_FilterInitStructure;
	CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdList;
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
	CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
	CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
	CAN_FilterInitStructure.CAN_FilterIdLow = 0x1;
	CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO0;
	CAN_FilterInitStructure.CAN_FilterNumber = 0;

	CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
	CAN_FilterInit(&CAN_FilterInitStructure);

	return init;
}

//void FilterConfig(u8 FilterNum, u8 FilterId, u8 FilterMask, u8 FilterScale, u8 Fifo)
//{
//    CAN_FilterInitTypeDef  CAN_FilterInitStructure;
//    if(FilterMask>0){
//    	CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
//    	CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
//    	CAN_FilterInitStructure.CAN_FilterMaskIdLow = FilterMask;
//    }else{
//    	CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdList;
//    	CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
//    	CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
//    }
//    CAN_FilterInitStructure.CAN_FilterScale = FilterScale;
//    CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
//    CAN_FilterInitStructure.CAN_FilterIdLow = FilterId;
//
//    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = Fifo;
//    CAN_FilterInitStructure.CAN_FilterNumber = FilterNum;
//
//    CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
//    CAN_FilterInit(&CAN_FilterInitStructure);
//}

void CanSendFrame(u8 Type, u8 Addr, u8* Buff, u8 DataLength, u8 FrameMode)
{
	u8 TransmitMailbox;
	CanTxMsg TxMessage;
    TxMessage.StdId = 0x09;
    TxMessage.RTR = FrameMode;
    TxMessage.IDE = CAN_ID_STD;
    TxMessage.DLC = DataLength;

    for(int i=0;i<DataLength;i++)	TxMessage.Data[i] = Buff[i];

    TransmitMailbox = CAN_Transmit(CAN1, &TxMessage);

    u8 timeout = 0;
    while((CAN_TransmitStatus(CAN1, TransmitMailbox) != CANTXOK) && (timeout != 0xFFFF)) {
        timeout++;
    }
}

void CanDioOutputPin(u8 Board, u8 Pin, u8 Status)
{
	u8 Buff[1] = {0};

	Buff[0] |= 1;
	Buff[0] |= Pin<<2;
	Buff[0] |= Status;

	CanSendFrame(C_DIO, Board, Buff, 1, CAN_RTR_DATA);
}
//
//void CanDioPinStatus(u8 Board, u8 Pin)
//{
//	u8 Buff[1] = {0};
//
//	Buff[0] |= 0;
//	Buff[0] |= Pin<<2;
//	Buff[0] |= Status;
//
//	CanSendFrame(C_DIO, Board, Buff, 1, CAN_RTR_DATA);
//}

void CanMotorDrive(can_md_config_t* Config, u8 Ch, u8 Pwm)
{
	u8 Buff[3] = {0};

	Buff[0] |= Config->Mode<<4;
	Buff[0] |= Config->Feq;
	Buff[1] |= Ch<<4;
	Buff[1] |= Config->ZeroState;
	if(Pwm > 0){
		Buff[2] = 1;
	}else {
		Buff[2] = 0;
	}
	Buff[2] |= ABS_VAL(Pwm)<<1;

	CanSendFrame(Config->Type, Config->Board, Buff, 3, CAN_RTR_DATA);
}

void EmergencyStop(ES_Status Stop)
{
	CanTxMsg CanTxMsgStructure;
	CanTxMsgStructure.StdId = 0;
	CanTxMsgStructure.ExtId = 0;
	CanTxMsgStructure.IDE = CAN_ID_STD;
	CanTxMsgStructure.RTR = CAN_RTR_DATA;
	CanTxMsgStructure.DLC = 8;
	for(int i=0;i<8;i++){
		CanTxMsgStructure.Data[i] = Stop;
	}

	CAN_Transmit(CAN1, &CanTxMsgStructure);
}
