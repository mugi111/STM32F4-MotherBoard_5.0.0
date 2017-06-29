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

typedef struct{
	u8 Type;
	u8 Mode;
	u8 Feq;
	u8 Board;
	u8 ZeroState;
}can_md_config_t;

uint8_t CanInit(void);
void FilterConfig();
void CanSendFrame(u8 Type, u8 Addr, u8* Buff, u8 DataLength, u8 FrameMode);
void CanDioOutputPin(u8 Board, u8 Pin, u8 Status);
void CanMotorDrive(can_md_config_t* Config, u8 Ch, u8 Pwm);
void EmergencyStop(int Stop);

#endif /* __CAN_H__ */
