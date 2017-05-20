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
 **************************************************************************/

#include <stm32f4xx.h>
#include "can.h"

#define ABS_VAL(val) ((val) < 0 ? -(val) : (val))

void CanInit(void)
{

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

	CAN_InitTypeDef CAN_InitStracture;
	CAN_InitStracture.CAN_Mode = CAN_Mode_LoopBack;
//	CAN_InitStracture.CAN_SJW = CAN_SJW_1tq;
	CAN_InitStracture.CAN_BS1 = CAN_BS1_4tq;
	CAN_InitStracture.CAN_BS2 = CAN_BS2_3tq;
	CAN_InitStracture.CAN_TTCM = DISABLE;
	CAN_InitStracture.CAN_ABOM = DISABLE;
	CAN_InitStracture.CAN_AWUM = DISABLE;
	CAN_InitStracture.CAN_NART = DISABLE;
	CAN_InitStracture.CAN_RFLM = ENABLE;
	CAN_InitStracture.CAN_TXFP = DISABLE;
	CAN_InitStracture.CAN_Prescaler = 128;

	CAN_Init(CAN1, &CAN_InitStracture);

	GPIO_InitTypeDef CAN_GPIOInit_Stracture;
	CAN_GPIOInit_Stracture.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	CAN_GPIOInit_Stracture.GPIO_Mode = GPIO_Mode_AF;
	CAN_GPIOInit_Stracture.GPIO_OType = GPIO_OType_PP;
	CAN_GPIOInit_Stracture.GPIO_PuPd = GPIO_PuPd_UP;
	CAN_GPIOInit_Stracture.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOB, &CAN_GPIOInit_Stracture);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_CAN1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_CAN1);

}

void SendFrame(u8 type, u8 add, u8* buff, int data_length)
{
	int i;
	CanTxMsg CanTxMsgStructure;
	CanTxMsgStructure.StdId = type | add;
	CanTxMsgStructure.ExtId = 0x00;
	CanTxMsgStructure.IDE = CAN_ID_STD;
	CanTxMsgStructure.RTR = CAN_RTR_DATA;
	CanTxMsgStructure.DLC = date_length;
	for(i=0;i<data_length;i++){
		CanTxMsgStructure.Data[i] = buff[i];
	}
	CAN_Transmit(CAN1, &CanTxMsgStructure);
}

//void receive_flame()
//{
//	int receive_data[];
//
//	CanRxMsg CanRxMsgStructure;
//	for(i=0;i<CanRxMsgStructure.DLC;i++)	receive_date[i] =  CanRxMsgStructure.Data[i];
//
//	return receive_date;
//}

void Can_Motor_Drive(u8 mode, u8 feq, u8 board, u8 zerostate, u8 ch, u8 pwm)
{
	u8 buff[3];

	buff[0] |= mode<<4;
	buff[0] |= feq;
	buff[1] |= ch<<4;
	buff[1] |= zerostate;
	if(pwm > 0){
		buff[2] = 1;
	}else {
		buff[2] = 0;
	}
	buff[2] |= ABS_VAL(pwm)<<1;

	SendFrame(0x02, board, buff, 3);
}

void EmergencyStop(int stop)
{
	CanTxMsg CanTxMsgStructure;
	CanTxMsgStructure.StdId = 0x00;
	CanTxMsgStructure.ExtId = 0x00;
	CanTxMsgStructure.IDE = CAN_ID_STD;
	CanTxMsgStructure.RTR = CAN_RTR_DATA;
	CanTxMsgStructure.DLC = 8;
	for(i=0;i<8;i++){
		CanTxMsgStructure.Data[i] = stop;
	}

	CAN_Transmit(CAN1, &CanTxMsgStructure);
}
