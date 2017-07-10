/***************************************************************************
 *	@�t�@�C����		:	04_PSpad.c
 *	@�T�v		:	PS�R���g���[�����g�����v���O�����̂ЂȌ^�D
 *						������R�s�y����ƊȒP�ȃ��{�b�g�̊�ՂɂȂ�܂�
 *
 *					�K�v�ȏ����̓R�����g�̐擪��**�����Ă��܂��̂ŁC
 *					�K���L������悤�ɂ��Ă��������D
 *	@�o�[�W����		:	3.0.0
 *	@�J����			:	�L�l�N�g
 *	@Ver3.0.0�ڍs	:	�ނ�
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver4, MB_Ver5, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __04_PSPAD__

/******************************/
/* �����@�ȉ����T���v���@���� */
/******************************/
#include <stm32f4xx.h>	// **�ŏ��ɃC���N���[�h����
#include "usart.h"	// **�C���N���[�h����
#include "pspad.h"	// **�C���N���[�h����


int main(void)
{
	/* -------------	�ϐ��錾	----------------- */
	psdata_format_t psdata;	// **PS�R���g���[�������M�����f�[�^���i�[�����

	/* ---------------------------------------------- */

	/* -----------------	������	----------------- */
	SystemCoreClockUpdate();	// **�ŏ��ɌĂяo��

	TIM7_CMT_Init();	// **�^�C���A�E�g�����ɕK�v
	
	Bluetooth_USART_Init(BT_BAUDRATE);	// **�ʐM�p�̃s����USART�Ƃ��ď���������
	Bluetooth_BDSlave_Init(0);	// **�R���g���[���ɑ΂��ă}�U�[�{�[�h�����X���[�u�Ƃ݂ď���������

	/* ---------------------------------------------- */

	/* -------------	���C�����[�v	------------- */
	while(1)
	{
#if defined(PSPAD_WIRE)	// �L��
		Modular_PSdata_Recv(&psdata);	// **�R���g���[���̏�Ԃ���M����

#elif defined(PSPAD_WIRELESS)	// **�R���g���[���̏�Ԃ���M����
		Bluetooth_PSdata_Recv(&psdata);
#endif

		if(PS_B_R1(psdata))				/* R1�������ɂ��ׂ����Ƃ����� */;
		if(PS_B_R2(psdata))				/* R2�������ɂ��ׂ����Ƃ����� */;
		if(PS_B_L1(psdata))				/* L1�������ɂ��ׂ����Ƃ����� */;
		if(PS_B_L2(psdata))				/* L2�������ɂ��ׂ����Ƃ����� */;
		if(PS_B_TRIANGLE(psdata))	/* ���������ɂ��ׂ����Ƃ����� */;
		if(PS_B_CIRCLE(psdata))		/* ���������ɂ��ׂ����Ƃ����� */;
		if(PS_B_CROSS(psdata))		/* �~�������ɂ��ׂ����Ƃ����� */;
		if(PS_B_SQUARE(psdata))		/* ���������ɂ��ׂ����Ƃ����� */;
		if(PS_B_START(psdata))		/* START�������ɂ��ׂ����Ƃ����� */;
		if(PS_B_SELECT(psdata))		/* SELECT�������ɂ��ׂ����Ƃ����� */;
		if(PS_B_ARROW_U(psdata))	/* ���������ɂ��ׂ����Ƃ����� */;
		if(PS_B_ARROW_R(psdata))	/* ���������ɂ��ׂ����Ƃ����� */;
		if(PS_B_ARROW_D(psdata))	/* ���������ɂ��ׂ����Ƃ����� */;
		if(PS_B_ARROW_L(psdata))	/* ���������ɂ��ׂ����Ƃ����� */;
		if(PS_B_STICK_R(psdata))	/* R3�������ɂ��ׂ����Ƃ����� */;
		if(PS_B_STICK_L(psdata))	/* L3�������ɂ��ׂ����Ƃ����� */;	

		// �E�X�e�B�b�N��X�������ɂ���ď����𕪂���
		// PS_STICK_RX(psdata)��0~15�̒l��\�����C
		// ���l�ω����X�e�B�b�N�̈ʒu�Ɣ�Ⴕ�Ȃ�����
		// gPSStick_convertTable�ɂ����-2~2�̈���I�Ȑ��l�ω�
		// �֕ϊ��ł���
		switch(gPSStick_convertTable[PS_STICK_RX(psdata)])
		{
			case -2:
				/* �X�e�B�b�N���������ς��ɓ|���ꂽ�Ƃ��ɂ��ׂ����Ƃ����� */
				break;
			case -1:
				/* ���ׂ����Ƃ����� */
				break;
			case  0:
				/* �X�e�B�b�N�����E�����Œ����̂Ƃ��ɂ��ׂ����Ƃ����� */
				break;
			case  1:
				/* ���ׂ����Ƃ����� */
				break;
			case  2:
				/* �X�e�B�b�N���E�����ς��ɓ|���ꂽ�Ƃ��ɂ��ׂ����Ƃ����� */
				break;
		}
		
		// �E�X�e�B�b�N��Y�������ɂ���ď����𕪂���
		// PS_STICK_RY(psdata)��0~15�̒l��\�����C
		// ���l�ω����X�e�B�b�N�̈ʒu�Ɣ�Ⴕ�Ȃ�����
		// gPSStick_convertTable�ɂ����-2~2�̈���I�Ȑ��l�ω�
		// �֕ϊ��ł���
		switch(gPSStick_convertTable[PS_STICK_RY(psdata)])
		{
			case -2:
				/* �X�e�B�b�N���������ς��ɓ|���ꂽ�Ƃ��ɂ��ׂ����Ƃ����� */
				break;
			case -1:
				/* ���ׂ����Ƃ����� */
				break;
			case  0:
				/* �X�e�B�b�N�����E�����Œ����̂Ƃ��ɂ��ׂ����Ƃ����� */
				break;
			case  1:
				/* ���ׂ����Ƃ����� */
				break;
			case  2:
				/* �X�e�B�b�N���E�����ς��ɓ|���ꂽ�Ƃ��ɂ��ׂ����Ƃ����� */
				break;
		}
		
		// ���X�e�B�b�N��X�������ɂ���ď����𕪂���
		// PS_STICK_LX(psdata)��0~15�̒l��\�����C
		// ���l�ω����X�e�B�b�N�̈ʒu�Ɣ�Ⴕ�Ȃ�����
		// gPSStick_convertTable�ɂ����-2~2�̈���I�Ȑ��l�ω�
		// �֕ϊ��ł���
		switch(gPSStick_convertTable[PS_STICK_LX(psdata)])
		{
			case -2:
				/* �X�e�B�b�N���������ς��ɓ|���ꂽ�Ƃ��ɂ��ׂ����Ƃ����� */
				break;
			case -1:
				/* ���ׂ����Ƃ����� */
				break;
			case  0:
				/* �X�e�B�b�N�����E�����Œ����̂Ƃ��ɂ��ׂ����Ƃ����� */
				break;
			case  1:
				/* ���ׂ����Ƃ����� */
				break;
			case  2:
				/* �X�e�B�b�N���E�����ς��ɓ|���ꂽ�Ƃ��ɂ��ׂ����Ƃ����� */
				break;
		}
		
		// ���X�e�B�b�N��Y�������ɂ���ď����𕪂���
		// PS_STICK_LY(psdata)��0~15�̒l��\�����C
		// ���l�ω����X�e�B�b�N�̈ʒu�Ɣ�Ⴕ�Ȃ�����
		// gPSStick_convertTable�ɂ����-2~2�̈���I�Ȑ��l�ω�
		// �֕ϊ��ł���
		switch(gPSStick_convertTable[PS_STICK_LY(psdata)])
		{
			case -2:
				/* �X�e�B�b�N���������ς��ɓ|���ꂽ�Ƃ��ɂ��ׂ����Ƃ����� */
				break;
			case -1:
				/* ���ׂ����Ƃ����� */
				break;
			case  0:
				/* �X�e�B�b�N�����E�����Œ����̂Ƃ��ɂ��ׂ����Ƃ����� */
				break;
			case  1:
				/* ���ׂ����Ƃ����� */
				break;
			case  2:
				/* �X�e�B�b�N���E�����ς��ɓ|���ꂽ�Ƃ��ɂ��ׂ����Ƃ����� */
				break;
		}
	}
	/* ---------------------------------------------- */

	return 0;
}
/******************************/
/* �����@�ȏオ�T���v���@���� */
/******************************/

#endif /* __04_PSPAD__ */
