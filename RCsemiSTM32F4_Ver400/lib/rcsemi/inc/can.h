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

#ifndef __CAN_H__
#define __CAN_H__

#include <stm32f4xx.h>

#define MASTER 0x01
//↓motorDriver
#define C_M_PWM  0x02
#define C_M_AIR  0x03
#define C_M_ENC  0x04
#define C_M_POT  0x05
#define C_M_CURRENT 0x06
//↑
#define C_DIO 0x07
#define C_ADC 0x08
#define C_ENC 0x09


void CanInit(void);
void SendFrame(u8 type, u8 add, u8* buff, u8 data_length);
void Can_DIO_OutputPin(u8 board, u8 pin, u8 status);
void Can_Motor_Drive(u8 type ,u8 mode, u8 feq, u8 board, u8 zerostate, u8 ch, u8 pwm);
void EmergencyStop(int stop);

#endif /* __CAN_H__ */
