/*/***************************************************************************
 *	@�t�@�C����		:	can.h
 *	@�T�v		:	CAN0,CAN1�|�[�g��p����CAN�ʐM���s���܂�.
 *	@�o�[�W����		:	0.1.0
 *	@�J����			:	�ނ�
 *	@�g�p��		:	STM32F407VG, MB_Ver5
 **************************************************************************/

#ifndef __CAN_H__
#define __CAN_H__

#include <stm32f4xx.h>

//#define MDD 0x2
//#define MD  0x3
//#define ENC 0x4
//#define DIO 0x5
//#define ADC 0x6

void CanInit(void);
void SendFrame(u8 type, u8 add, u8* buff, int data_length);
void Can_Motor_Drive(u8 mode, u8 feq, u8 board, u8 zerostate, u8 ch, u8 pwm);
void EmergencyStop(int stop);

#endif /* __CAN_H__ */
