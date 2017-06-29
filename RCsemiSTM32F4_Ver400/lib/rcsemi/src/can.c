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

	return init;
}

void FilterConfig()
{
    CAN_FilterInitTypeDef  CAN_FilterInitStructure;
    CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
    CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
    CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
    CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = 0;

    CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
    CAN_FilterInit(&CAN_FilterInitStructure);
}

void CanSendFrame(u8 Type, u8 Addr, u8* Buff, u8 DataLength, u8 FrameMode)
{
	int i;
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

void Can_DIO_OutputPin(u8 board, u8 pin, u8 status)
{
	u8 buff[3] = {0	};

	buff[0] |= pin<<1;
	buff[0] |= status;

	CanSendFrame(C_DIO, board, buff, 1);
}

void Can_Motor_Drive(can_md_config_t* config, u8 ch, u8 pwm)
{
	u8 buff[3] = {0};

	buff[0] |= config->mode<<4;
	buff[0] |= config->feq;
	buff[1] |= ch<<4;
	buff[1] |= config->zerostate;
	if(pwm > 0){
		buff[2] = 1;
	}else {
		buff[2] = 0;
	}
	buff[2] |= ABS_VAL(pwm)<<1;

	CanSendFrame(config->type, config->board, buff, 3);
}

void EmergencyStop(int stop)
{
	CanTxMsg CanTxMsgStructure;
	CanTxMsgStructure.StdId = 0;
	CanTxMsgStructure.ExtId = 0;
	CanTxMsgStructure.IDE = CAN_ID_STD;
	CanTxMsgStructure.RTR = CAN_RTR_DATA;
	CanTxMsgStructure.DLC = 8;
	for(int i=0;i<8;i++){
		CanTxMsgStructure.Data[i] = stop;
	}

	CAN_Transmit(CAN1, &CanTxMsgStructure);
}
