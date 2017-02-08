/*/***************************************************************************
 *	@�t�@�C����		:	can.h
 *	@�T�v		:	CAN0,CAN1�|�[�g��p����CAN�ʐM���s���܂�.
 *	@�o�[�W����		:	0.0.1
 *	@�J����			:	�ނ�
 *	@�g�p��		:	STM32F407VG, MB_Ver4
 **************************************************************************/

#ifndef __CAN_H__
#define __CAN_H__

#include <stm32f4xx.h>

//#define MDD 0x2
//#define MD  0x3
//#define ENC 0x4
//#define DIO 0x5
//#define ADC 0x6

void can_init(void);
void send_frame();
void emergency_stop(void);

#endif /* __CAN_H__ */
