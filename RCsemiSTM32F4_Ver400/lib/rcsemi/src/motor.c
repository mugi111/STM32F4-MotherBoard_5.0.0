/***************************************************************************
 *	@�t�@�C����		:	motor.c
 *	@�T�v		:	DIGITAL-IO�|�[�g�Ń��[�^�𐧌䂷�邽�߂�PWM�������Ɠ�����s���D
 *					�W���̃��[�^�h���C�o���g�����Ƃ�z�肵�Ă���D
 *	@�o�[�W����		:	2.0.0
 *	@�J����		:	�L�l�N�g
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver3, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "motor.h"
#include "digitalIO.h"

_motor_status_t gMotor_status[3] = {{{0}}};

/* �f���[�e�B�����]��\��2bit�ɕϊ����� */
#define DUTY_TO_DIR(duty) ((duty) == BRAKEVALUE	? 0x03 : \
						   (duty) < 0			? 0x02 : \
						   (duty) > 0	 		? 0x01 : 0x00)

/* ��Βl�����߂� */
#define ABS_VAL(val) ((val) < 0 ? -(val) : (val))

/* �ђʓd������������p�^�[�����𔻕ʂ��� */
#define IS_SHORTCURRENT_PATTERN(dir_now, dir_old)	((dir_now) != (dir_old) && (dir_now) && (dir_old))

/* -------------------------------------------------
 * @�֐���			:	MotorDriver_Init
 * @�T�v				:	���[�^�|�[�g�̏����������邪�C
 * 						�o�͐ݒ�Ȃǂ�DigitalIO_Init��
 * 						�g�p���邱�ƁD
 * @����-enable_bits	:	12bit�Ń��[�^�|�[�g���g�p���邩�ۂ���
 * 						���肵�܂��D1:�L��/0:����
 * @�߂�l			:	�Ȃ�
 * ---------------------------------------------- */
void MotorDriver_Init(u16 enable_bits)
{
	int i;
	for(i = 0; i < 12; i++)
	{
		if(enable_bits & (1<<i))	gMotor_status[i>>2].isEnable[i&3] = 1;
		else						gMotor_status[i>>2].isEnable[i&3] = 0;
	}
}

/* -------------------------------------------------
 * @�֐���		:	Motor_Drive
 * @�T�v			:	���[�^�|�[�g����PWM���o�͂���
 * 					Digital-IO���o�͐ݒ肵�Ă���Ăяo������
 * @����-ch		:	�o�͂���`�����l���ԍ��A0����̒ʂ��ԍ�
 *�@          -duty	:	duty�̒l�A������
 *�@          				���̒l�͐��]�A���̒l�͋t�]�A
 *�@          				BRAKEVALUE�̓V���[�g�u���[�L�������D
 * @�߂�l		:	�Ȃ�
 * ---------------------------------------------- */
void Motor_Drive(u8 ch, short duty)
{
	u8 port = ch>>2;	// 0:0-3 / 1:4-7
	ch &= 0x02; 		// 0-2�ɐ���

	u8 dir_now = DUTY_TO_DIR(duty);
	u8 dir_old = gMotor_status[port].dir_old[ch];

	if(gMotor_status[port].isEnable[ch])	gMotor_status[port].duty[ch] = ABS_VAL(duty);
	else									gMotor_status[port].duty[ch] = 0;

	/****************************	�ђʓd���΍�	***********************************/
	if(gMotor_status[port].deadtime[ch])
	{
		if(IS_SHORTCURRENT_PATTERN(dir_now, dir_old))
		{
			gMotor_status[port].dir_save[ch] = dir_now;
		}
		else
		{
			gMotor_status[port].deadtime[ch] = 0;
			gMotor_status[port].dir		[ch] = dir_now;
			gMotor_status[port].dir_old [ch] = dir_now;
		}
	}
	else
	{
		if(IS_SHORTCURRENT_PATTERN(dir_now, dir_old))
		{
			gMotor_status[port].deadtime[ch] = MOTOR_DEADTIME_10US;
			gMotor_status[port].dir		[ch] = 0;
			gMotor_status[port].dir_save[ch] = dir_now;
		}
		else
		{
			gMotor_status[port].dir	   [ch] = dir_now;
			gMotor_status[port].dir_old[ch] = dir_now;
		}
	}
	/******************************************************************************/
}
