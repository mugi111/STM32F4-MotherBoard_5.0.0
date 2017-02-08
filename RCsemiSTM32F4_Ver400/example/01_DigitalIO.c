 /***************************************************************************
 *	@�t�@�C����		:	01_DigitalIO.c
 *	@�T�v		:	�{�T���v����DigitalIO�|�[�g�̓��o�͂����܂��D
 *
 *					�K�v�ȏ����̓R�����g�̐擪��**�����Ă��܂��̂ŁC
 *					�K���L������悤�ɂ��Ă��������D
 *	@�o�[�W����		:	3.0.0
 *	@�J����			:	�L�l�N�g
 *	@Ver3.0.0�ڍs	:	�ނ�
 *	@�g�p��		:	STM32F407VG, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __01_DIGITALIO__

/******************************/
/* �����@�ȉ����T���v���@���� */
/******************************/
#include <stm32f4xx.h>	// **�ŏ��ɃC���N���[�h����
#include "digitalIO.h"	// **�C���N���[�h����

#include "timer.h"	// delay���g�����߂ɕK�v�ɂȂ�

int main(void)
{
	/* -------------	�ϐ��錾	----------------- */
	int status[8];

	/* ---------------------------------------------- */

	/* -----------------	������	----------------- */
	SystemCoreClockUpdate();	// **�ŏ��ɌĂяo��

	TIM7_CMT_Init();	// delay�֐��𗘗p���邽�߂̏�����

	DIO0_Init(0xFF, DIO_MODE_IN);		// **DIO0�̂��ׂẴs������͂Ƃ��ď���������D
	
	DIO1_Init(0xFF, DIO_MODE_OUT);		// **DIO1�̂��ׂẴs�����o�͂Ƃ��ď���������D

	/* ---------------------------------------------- */

	/* -------------	���C�����[�v	------------- */
	while(1)
	{
		status[0] = DIO_CheckPin(0, 0);	// DIO0-0�̏�Ԃ�ǂݎ��
		status[1] = DIO_CheckPin(0, 1);	// DIO0-1�̏�Ԃ�ǂݎ��
		status[2] = DIO_CheckPin(0, 2);	// DIO0-2�̏�Ԃ�ǂݎ��
		status[3] = DIO_CheckPin(0, 3);	// DIO0-3�̏�Ԃ�ǂݎ��
		status[4] = DIO_CheckPin(0, 4);	// DIO0-4�̏�Ԃ�ǂݎ��
		status[5] = DIO_CheckPin(0, 5);	// DIO0-5�̏�Ԃ�ǂݎ��
		status[6] = DIO_CheckPin(0, 6);	// DIO0-6�̏�Ԃ�ǂݎ��
		status[7] = DIO_CheckPin(0, 7);	// DIO0-7�̏�Ԃ�ǂݎ��
		
		DIO_OutputPin(1, 0, status[0]);	// ���͐M��0��DIO1-0�̏o�͂ɔ��f������D
		DIO_OutputPin(1, 1, status[1]);	// ���͐M��1��DIO1-1�̏o�͂ɔ��f������D
		DIO_OutputPin(1, 2, status[2]);	// ���͐M��2��DIO1-2�̏o�͂ɔ��f������D
		DIO_OutputPin(1, 3, status[3]);	// ���͐M��3��DIO1-3�̏o�͂ɔ��f������D
		DIO_OutputPin(1, 4, status[4]);	// ���͐M��4��DIO1-4�̏o�͂ɔ��f������D
		DIO_OutputPin(1, 5, status[5]);	// ���͐M��5��DIO1-5�̏o�͂ɔ��f������D
		DIO_OutputPin(1, 6, status[6]);	// ���͐M��6��DIO1-6�̏o�͂ɔ��f������D
		DIO_OutputPin(1, 7, status[7]);	// ���͐M��7��DIO1-7�̏o�͂ɔ��f������D

		delay_ms(100);
	}
	/* ---------------------------------------------- */

	return 0;
}
/******************************/
/* �����@�ȏオ�T���v���@���� */
/******************************/

#endif /* __01_DIGITALIO__ */
