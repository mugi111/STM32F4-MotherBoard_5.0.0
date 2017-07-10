/***************************************************************************
 *	@�t�@�C����		:	timer.c
 *	@�T�v		:	���[�^�h���C�u�Edelay�E���[�^���[�G���R�[�_�̐�����i��TIM7��
 *					�C���^�[�t�F�[�X��񋟂���D
 *					�܂��Cdelay�ESystemTimer���񋟂��Ă���D
 *	@�o�[�W����		:	1.2.0
 *	@�J����		:	�L�l�N�g
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver2, MB_Ver3, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "timer.h"
#include "motor.h"
#include "digitalIO.h"
#include "rotary_encoder.h"

// �V�X�e���^�C�}�C1ms���Ƃ�1����������D
int gSystemTimer_ms = 0;

// delay�֐��̂��߂̃J�E���g�l
static int timingDelay_ms;

// motor.h�Őݒ肵�����[�^�̏��
extern _motor_status_t gMotor_status[3];

/* --------------------------------------------------
 * @�֐���	:	TIM7_CMT_Init
 * @�T�v		:	���[�^�|�[�g�Edelay�E���[�^���[�G���R�[�_��
 * 				���p����TIM7�̏�����������D
 * @����		:	�Ȃ�
 * @�߂�l	:	�Ȃ�
   ---------------------------------------------- */
void TIM7_CMT_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);

	/* TIM7�̃O���[�o�����荞�ݐݒ� */
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel					 = TIM7_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority		 = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd				 = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* TIM7�̐ݒ� */
	TIM_DeInit(TIM7);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 10-1;
	TIM_TimeBaseStructure.TIM_Period    = 84-1;
	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);

	/* TIM7�̊��荞�݂�L���� */
	TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM7, ENABLE);
}


/* -------------------------------------------------
 * @�֐���		:	delay_ms
 * @�T�v			:	�w�莞�ԋ󃋁[�v������D
 * 					SystemCMT�������������ɌĂяo���ƁC
 * 					�������[�v���Ă��܂��D
 * @����-msec	:	���[�v���鎞��[ms]
 * @�߂�l		:	�Ȃ�
 * ---------------------------------------------- */
void delay_ms(int msec)
{
	timingDelay_ms = msec;
	while(timingDelay_ms);
}

/* -------------------------------------------------
 * @�֐���	:	TIM7_IRQHandler
 * @�T�v		:	100kHz�Ŋ��荞�܂�郋�[�`��
 * @����		:	�Ȃ�
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void TIM7_IRQHandler(void)
{
	static short pwmcounter;	// PWM�̂��߂̃v���X�P�[��

	// �y�ʉ�
	TIM7->SR = (u16)~TIM_IT_Update;
//	TIM_ClearITPendingBit(TIM7, TIM_IT_Update);

	/****************************	�ђʓd���΍�	***********************************/
	int i;
	u8 port, ch;

	for(i = 0; i < 8; i++)
	{
		port = i>>2;//TODO
		ch = i&3;	//TODO
		if((gMotor_status[port].deadtime[ch]) && (--gMotor_status[port].deadtime[ch] == 0))
		{
			gMotor_status[port].dir	   [ch]	= gMotor_status[port].dir_save[ch];
			gMotor_status[port].dir_old[ch]	= gMotor_status[port].dir_save[ch];
		}
	}
	/******************************************************************************/

	/****************************	PWM��IO���䕔��	*******************************/
	if(!pwmcounter)
	{
		if(gMotor_status[0].isEnable[0])
		{
			DIO_OutputPin(0, 0, gMotor_status[0].dir[0]   );
			DIO_OutputPin(0, 1, gMotor_status[0].dir[0]>>1);
		}
		if(gMotor_status[0].isEnable[1])
		{
			DIO_OutputPin(0, 2, gMotor_status[0].dir[1]   );
			DIO_OutputPin(0, 3, gMotor_status[0].dir[1]>>1);
		}
		if(gMotor_status[0].isEnable[2])
		{
			DIO_OutputPin(0, 4, gMotor_status[0].dir[2]   );
			DIO_OutputPin(0, 5, gMotor_status[0].dir[2]>>1);
		}
		if(gMotor_status[0].isEnable[3])
		{
			DIO_OutputPin(0, 6, gMotor_status[0].dir[3]   );
			DIO_OutputPin(0, 7, gMotor_status[0].dir[3]>>1);
		}
		if(gMotor_status[1].isEnable[0])
		{
			DIO_OutputPin(1, 0, gMotor_status[1].dir[0]   );
			DIO_OutputPin(1, 1, gMotor_status[1].dir[0]>>1);
		}
		if(gMotor_status[1].isEnable[1])
		{
			DIO_OutputPin(1, 2, gMotor_status[1].dir[1]   );
			DIO_OutputPin(1, 3, gMotor_status[1].dir[1]>>1);
		}
		if(gMotor_status[1].isEnable[2])
		{
			DIO_OutputPin(1, 4, gMotor_status[1].dir[2]   );
			DIO_OutputPin(1, 5, gMotor_status[1].dir[2]>>1);
		}
		if(gMotor_status[1].isEnable[3])
		{
			DIO_OutputPin(1, 6, gMotor_status[1].dir[3]   );
			DIO_OutputPin(1, 7, gMotor_status[1].dir[3]>>1);
		}
	}
	else
	{
		if(gMotor_status[0].duty[0] == pwmcounter)
		{
			DIO_OutputPin(0, 0, 0);
			DIO_OutputPin(0, 1, 0);
		}
		if(gMotor_status[0].duty[1] == pwmcounter)
		{
			DIO_OutputPin(0, 2, 0);
			DIO_OutputPin(0, 3, 0);
		}
		if(gMotor_status[0].duty[2] == pwmcounter)
		{
			DIO_OutputPin(0, 4, 0);
			DIO_OutputPin(0, 5, 0);
		}
		if(gMotor_status[0].duty[3] == pwmcounter)
		{
			DIO_OutputPin(0, 6, 0);
			DIO_OutputPin(0, 7, 0);
		}
		if(gMotor_status[1].duty[0] == pwmcounter)
		{
			DIO_OutputPin(1, 0, 0);
			DIO_OutputPin(1, 1, 0);
		}
		if(gMotor_status[1].duty[1] == pwmcounter)
		{
			DIO_OutputPin(1, 2, 0);
			DIO_OutputPin(1, 3, 0);
		}
		if(gMotor_status[1].duty[2] == pwmcounter)
		{
			DIO_OutputPin(1, 4, 0);
			DIO_OutputPin(1, 5, 0);
		}
		if(gMotor_status[1].duty[3] == pwmcounter)
		{
			DIO_OutputPin(1, 6, 0);
			DIO_OutputPin(1, 7, 0);
		}
	}
	/******************************************************************************/

	/**************	1kHz�Ŋ��荞�܂�镔���C�V�X�e���^�C�}�E�^�C�~���O�f�B���C�Ȃǂ̏���	***************/
	if(++pwmcounter == 100)
	{
		gSystemTimer_ms++;
		if(timingDelay_ms)	timingDelay_ms--;
		pwmcounter = 0;
	}
	/******************************************************************************/
}
