/*/***************************************************************************
 *	@ファイル名		:	can.c
 *	@概要		:	CAN0,CAN1ポートを用いてCAN通信を行います.
 *	@バージョン		:	0.0.1
 *	@開発者			:	むぎ
 *	@使用環境		:	STM32F407VG, MB_Ver4
 **************************************************************************/

#include <stm32f4xx.h>
#include "stm32f4xx_can.h"
#include "stm32f4xx_gpio.h"
#include "can.h"

void can_init(void)
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

void send_frame()
{
	CanTxMsg CanTxMsgStructure;
	CanTxMsgStructure.StdId = 0xA5;
	CanTxMsgStructure.ExtId = 0x00;
	CanTxMsgStructure.IDE = CAN_ID_STD;
	CanTxMsgStructure.RTR = CAN_RTR_DATA;
	CanTxMsgStructure.DLC = 6;
	CanTxMsgStructure.Data[0] = 0xAA;
	CanTxMsgStructure.Data[1] = 0x55;
	CanTxMsgStructure.Data[2] = 0x00;
	CanTxMsgStructure.Data[3] = 0xFF;
	CanTxMsgStructure.Data[4] = 0x01;
	CanTxMsgStructure.Data[5] = 0x80;

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

void emergency_stop(void)
{

}
