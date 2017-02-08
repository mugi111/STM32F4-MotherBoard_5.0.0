/***************************************************************************
 *	@�t�@�C����		:	RCsemi_tools.h
 *	@�T�v		:	����ƕ֗��ȃc�[�����܂Ƃ߂����̂ŁC
 *					�K�v���Ǝv�����c�[���𑫂��Č����č\��Ȃ��D
 *					���̏ꍇ�C�o�[�W�����̍X�V��ӂ�Ȃ����ƁD
 *					�܂��C������x���̃t�@�C�����c��ɂȂ��Ă�����C�t�@�C���𕪂����ق����悢�D
 *	@�o�[�W����		:	2.0.0
 *	@�J����		:	�L�l�N�g
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver3, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "tools.h"

/* --------------------------------------------------------
 * @�֐���		:	PID_control
 * @�T�v			:	PID������{���A�g��Ȃ��v�f������΃Q�C����0�ɂ��邱��
 * @����-pid		:	PID���{�����ϐ�
 * @�߂�l		:	�Ȃ�
 * ----------------------------------------------------- */
void PID_control(_PID_t *pid)
{
	float p, i, d, c;

	// �΍��̌v�Z
	pid->diff[0] = pid->target - pid->value;

	// �ݐό덷�����Z
	pid->integral += pid->diff[0];

	p = pid->KP * pid->diff[0];						// ���
	i = pid->KI * pid->integral;					// �ϕ�
	d = pid->KD * (pid->diff[1] - pid->diff[0]);	// ����
	c = pid->KC;									// �萔

	// �΍����X�V
	pid->diff[1] = pid->diff[0];

	pid->act = p + i + d + c;
}

/* -------------------------------------------------------
 * @�֐���			:	TIM6_CMT_Init
 * @�T�v				:	TIM6��CMT(�R���y�A�}�b�`�^�C�})������������
 * @����-prescaler	:	CMT�̃v���X�P�[��
 *�@  �@�@�@-period		:	CMT�̃J�E���^�����Z�b�g�����l
 * @�߂�l			:	�Ȃ�
 * ---------------------------------------------------- */
void TIM6_CMT_Init(u16 prescaler, u16 period)
{
	// �^�C�}�ɃN���b�N������
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

	/* �O���[�o�����荞�݂�L���� */
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel					 = TIM6_DAC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority		 = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd				 = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* TIM6��L���� */
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler		= prescaler	- 1;
	TIM_TimeBaseStructure.TIM_Period    	= period	- 1;
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);

	// �^�C�}���荞�݂�L����
	TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);

	TIM_Cmd(TIM6, ENABLE);
}

/* TIM6�̃^�C�}���荞�݂�L���ɂ����Ƃ��C
 * ���L�̂悤�ɋL�q�����֐��������I�ɌĂяo�����D
 * �ȉ����\�[�X�R�[�h�ɃR�s�[���ď�L��TIM6_CMT_Init���ďo���Ďg�p���邱�ƁD*/
/*
void TIM6_DAC_IRQHandler(void)
{
	// �^�C�}���荞�݃t���O�����Z�b�g
	TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
}
*/
