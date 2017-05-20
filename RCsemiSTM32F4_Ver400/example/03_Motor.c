/***************************************************************************
 *	@�t�@�C����		:	03_Motor.c
 *	@�T�v		:	DigitalIO�|�[�g���烂�[�^�h���C�o�𗘗p����D
 *
 *					�K�v�ȏ����̓R�����g�̐擪��**�����Ă��܂��̂ŁC
 *					�K���L������悤�ɂ��Ă��������D
 *	@�o�[�W����		:	2.0.0
 *	@�J����		:	�L�l�N�g
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver3, MB_Ver4, MB_Ver5, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __03_MOTOR__

/******************************/
/* �����@�ȉ����T���v���@���� */
/******************************/
#include <stm32f4xx.h>	// **�ŏ��ɃC���N���[�h����
#include "digitalIO.h"	// **�C���N���[�h����
#include "motor.h"	// **�C���N���[�h����
#include "timer.h"	// **�C���N���[�h����

#include "motherboard.h"	// �o�͕ω��p

int main(void)
{
	/* -------------	�ϐ��錾	----------------- */
	int rotarysw_value;

	/* ---------------------------------------------- */

	/* -----------------	������	----------------- */
	SystemCoreClockUpdate();	// **�ŏ��ɌĂяo��

	DIO0_Init(0xFF, DIO_MODE_OUT);	// **���[�^�|�[�g��DIO�Ȃ̂ŁC���������K�v�D�g������"01_DigitalIO.c"���Q��
	DIO1_Init(0xFF, DIO_MODE_OUT);	// **���[�^�|�[�g��DIO�Ȃ̂ŁC���������K�v�D�g������"01_DigitalIO.c"���Q��

	MotorDriver_Init(0xF0);	// **���[�^�|�[�g�ɑΉ�����r�b�g��1�ɂ��邱�Ƃŏ����������D
														// **���̏ꍇ�CMOTOR0-3, 8-11�����[�^�|�[�g�Ƃ��ď���������D
														// **�ݒ肳��Ă��Ȃ�MOTOR4-7��DigitalIO�Ƃ��ė��p�\�ł���D

	TIM7_CMT_Init();	// **PWM�����p�Cduty��100%�ł������Ƃ��Ă��K�v�ɂȂ�D

	MB_RotarySW_Init();	// �o�͕ω��p

	/* ---------------------------------------------- */

	/* -------------	���C�����[�v	------------- */
	while(1)
	{
		rotarysw_value = MB_RotarySW_Check();	// ���[�^���[�X�C�b�`�������l

		/* �w�肳�ꂽduty�䂪�o�͂���� */
		Motor_Drive(0, rotarysw_value);
		Motor_Drive(1, rotarysw_value * 2);
		Motor_Drive(2, rotarysw_value * 3);
		Motor_Drive(3, rotarysw_value * 6);

		Motor_Drive(8, -rotarysw_value * 3);
		Motor_Drive(9, -rotarysw_value * 6);
		Motor_Drive(10, BRAKEVALUE);	// �V���[�g�u���[�L
		Motor_Drive(11, BRAKEVALUE);	// �V���[�g�u���[�L
		
		/* �����@����̓��[�^�|�[�g�Ƃ��ď������������߂���Ă͂����Ȃ��@���� */
		/*
		DIO_OutputPin(0, 0, 1);
		DIO_OutputPin(0, 1);
		DIO_OutputPin(0, 2, 1);
		DIO_OutputPin(0, 3, 1);
		...etc
		*/
		
		/* �����@����̓��[�^�|�[�g�Ƃ��Đݒ肵�Ă��Ȃ��̂�OK�@���� */
		DIO_OutputPin(1, 0, 1);
		DIO_OutputPin(1, 1, 0);
		DIO_OutputPin(1, 2, 1);
		DIO_OutputPin(1, 3, 0);
		DIO_OutputPin(1, 4, 1);
		DIO_OutputPin(1, 5, 0);
		DIO_OutputPin(1, 6, 1);
		DIO_OutputPin(1, 7, 0);
	}
	/* ---------------------------------------------- */

	return 0;
}
/******************************/
/* �����@�ȏオ�T���v���@���� */
/******************************/

#endif /* __03_MOTOR__ */
