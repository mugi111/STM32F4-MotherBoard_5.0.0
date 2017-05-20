/*/***************************************************************************
 *	@ファイル名		:	can.h
 *	@概要		:	CAN0,CAN1ポートを用いてCAN通信を行います.
 *	@バージョン		:	0.1.0
 *	@開発者			:	むぎ
 *	@使用環境		:	STM32F407VG, MB_Ver5
 **************************************************************************/

#ifndef __CAN_H__
#define __CAN_H__

#include <stm32f4xx.h>

#define MASTER 0x01
//↓motorDriver
#define M_PWM  0x02
#define M_AIR  0x03
#define M_ENC  0x04
#define M_POT  0x05
#define M_CURRENT 0x06
//↑
#define DIO 0x07
#define ADC 0x08
#define ENC 0x09


void CanInit(void);
void SendFrame(u8 type, u8 add, u8* buff, int data_length);
void Can_Motor_Drive(u8 mode, u8 feq, u8 board, u8 zerostate, u8 ch, u8 pwm);
void EmergencyStop(int stop);

#endif /* __CAN_H__ */
