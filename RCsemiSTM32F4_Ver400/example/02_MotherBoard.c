/***************************************************************************
 *	@�t�@�C����		:	02_MotherBoard.c
 *	@�T�v		:	�}�U�[�{�[�h��̊e�@�\�CLED�C�v�b�V���X�C�b�`�C
					4�r�b�g���[�^���[�X�C�b�`�𓮍삳����D
 *					���ʂ�DigitalIO�̏o�͂Ŋm�F����
 *
 *					�K�v�ȏ����̓R�����g�̐擪��**�����Ă��܂��̂ŁC
 *					�K���L������悤�ɂ��Ă��������D
 *	@�o�[�W����		:	2.0.0
 *	@�J����		:	�L�l�N�g
 *	@��������		�F	�ނ�
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver5, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __02_MB__

/******************************/
/* �����@�ȉ����T���v���@���� */
/******************************/
#include <stm32f4xx.h>	// **�ŏ��ɃC���N���[�h����
#include "motherboard.h"	// **�C���N���[�h����

#include "timer.h"	// delay���g�����߂ɕK�v�ɂȂ�

#include "digitalIO.h"	// ��Ԋm�F�p

int main(void)
{
	/* -------------	�ϐ��錾	----------------- */
	int pushsw_status;
	u8 rotarysw_value;

	/* ---------------------------------------------- */

	/* -----------------	������	----------------- */
	SystemCoreClockUpdate();	// **�ŏ��ɌĂяo��
	TIM7_CMT_Init();	// delay�֐��𗘗p���邽�߂̏�����

	MB_LED_Init();		// **�}�U�[�{�[�h���LED*2������������
	MB_PushSW_Init();	// **�}�U�[�{�[�h��̃v�b�V���X�C�b�`*2������������
	MB_RotarySW_Init();	// **�}�U�[�{�[�h��̃��[�^���[�X�C�b�`������������

	DIO0_Init(0x3F, DIO_MODE_OUT);	// �g������"01_DigitalIO.c"���Q��

	/* ---------------------------------------------- */

	MB_LED_TurnOn(0);	// LED0��_��������
	MB_LED_TurnOff(1);	// LED1������������

	/* -------------	���C�����[�v	------------- */
	while(1)
	{
		pushsw_status = MB_PushSW_IsPushed();	// �v�b�V���X�C�b�`��������Ă���:1 else :0

		rotarysw_value = MB_RotarySW_Check();	// ���[�^���[�X�C�b�`�������l(0-15)

		MB_LED_Toggle();	// LED�̏�Ԃ𔽓]������

		/* �v�b�V���X�C�b�`�̏�Ԃ��o�͂��� */
		DIO_OutputPin(0, 0, pushsw_status);
		
		/* ���[�^���[�X�C�b�`�̒l��4bit�l�Ƃ��ďo�͂��� */
		if(rotarysw_value & 0x01)	DIO_OutputPin(0, 2, 1);
		else						DIO_OutputPin(0, 2, 0);
		if(rotarysw_value & 0x02)	DIO_OutputPin(0, 3, 1);
		else						DIO_OutputPin(0, 3, 0);
		if(rotarysw_value & 0x04)	DIO_OutputPin(0, 4, 1);
		else						DIO_OutputPin(0, 4, 0);
		if(rotarysw_value & 0x08)	DIO_OutputPin(0, 5, 1);
		else						DIO_OutputPin(0, 5, 0);

		delay_ms(50);
	}
	/* ---------------------------------------------- */

	return 0;
}
/******************************/
/* �����@�ȏオ�T���v���@���� */
/******************************/

#endif /* __02_MB__ */
