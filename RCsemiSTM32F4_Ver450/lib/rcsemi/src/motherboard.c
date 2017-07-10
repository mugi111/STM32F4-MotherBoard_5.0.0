/***************************************************************************
 *	@�t�@�C����		:	motherboard.h
 *	@�T�v		:	MB���LED�C�v�b�V���X�C�b�`�C���[�^���[�X�C�b�`�̋@�\��񋟂��܂��D
 *					�ȉ��ɁC�e�v�f�̃s���z�u�������܂��D
 *					LED			PA15
 *					PushSW		PB10
 *					RotarySW	0:PC10, 1:PC12, 2:PE0, 3:PE1
 *	@�o�[�W����		:	4.0.0
 *	@�J����			:	�L�l�N�g
 *	@Ver4.0.0�ڍs	:	�ނ�
 *	@�g�p��		:	STM32F407VG, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "motherboard.h"

/* -------------------------------------------------
 * @�֐���	:	MB_LED_Init
 * @�T�v		:	MB��LED�ɐڑ�����Ă���GPIO(PA8, PA15)��
 * 				���������܂��D
 * @����		:	�Ȃ�
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void MB_LED_Init(void)
{
	/* �N���b�N���� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	/* GPIO�ݒ� */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/* -------------------------------------------------
 * @�֐���	:	MB_LED_TurnOff
 * @�T�v		:	�w���LED���������܂��D
 * @����		:	�Ȃ�
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void MB_LED_TurnOff()
{
	GPIOA->BSRRH = GPIO_Pin_15;
}

/* -------------------------------------------------
 * @�֐���	:	MB_LED_TurnOn
 * @�T�v		:	�w���LED��_�����܂��D
 * @����		:	�Ȃ�
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void MB_LED_TurnOn()
{
	GPIOA->BSRRL = GPIO_Pin_15;
}

/* -------------------------------------------------
 * @�֐���	:	MB_LED_Toggle
 * @�T�v		:	�w���LED��O��ƈႤ��Ԃɂ��܂��D
 * @����		:	�Ȃ�
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void MB_LED_Toggle()
{
	GPIOA->ODR ^= GPIO_Pin_15;
}

/* -------------------------------------------------
 * @�֐���	:	MB_PushSW_Init
 * @�T�v		:	�v�b�V���X�C�b�`�ɐڑ�����Ă���GPIO(PB10)��
 * 				�����������܂��D
 * @����		:	�Ȃ�
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void MB_PushSW_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/* -------------------------------------------------
 * @�֐���	:	MB_PushSW_IsPushed
 * @�T�v		:	�v�b�V���X�C�b�`�������ꂽ���ǂ������肵�܂��D
 * @����		:	�Ȃ�
 * @�߂�l	:	�����ꂽ��1, �����łȂ����0
 * ---------------------------------------------- */
int MB_PushSW_IsPushed()
{
	return !(GPIOB->IDR & GPIO_Pin_10);
}

/* -------------------------------------------------
 * @�֐���	:	MB_RotarySW_Init
 * @�T�v		:	���[�^���[�X�C�b�`�ɐڑ�����Ă���
 * 				GPIO(PC10, PC12, PE0, PE1)�̏����������܂��D
 * @����		:	�Ȃ�
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void MB_RotarySW_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/* -------------------------------------------------
 * @�֐���	:	MB_RotarySW_Check
 * @�T�v		:	���[�^���[�X�C�b�`�������l(0-15)�𔻕ʂ��܂��D
 * @����		:	�Ȃ�
 * @�߂�l	:	���[�^���[�X�C�b�`�̒l(0-15)
 * ---------------------------------------------- */
unsigned int MB_RotarySW_Check(void)
{
	return (!(GPIOC->IDR & GPIO_Pin_10)    ) | (!(GPIOC->IDR & GPIO_Pin_12) << 1) |
		   (!(GPIOE->IDR & GPIO_Pin_0) << 2) | (!(GPIOE->IDR & GPIO_Pin_1) << 3);

}
