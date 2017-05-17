/*
 * motor.cpp
 *
 *  Created on: 2017/04/25
 *      Author: mugi111
 */

#include "motor.h"

#define DUTY_TO_DIR(duty) ((duty) == BRAKEVALUE	? 0x03 : \
						   (duty) < 0			? 0x02 : \
						   (duty) > 0	 		? 0x01 : 0x00)

#define ABS_VAL(val) ((val) < 0 ? -(val) : (val))

#define IS_SHORTCURRENT_PATTERN(dir_now, dir_old)	((dir_now) != (dir_old) && (dir_now) && (dir_old))

namespace RCsemi{

_motor_status_t gMotor_status[3] = {{{0}}};

motor::motor(unsigned short ch)
{
	m_currentDuty = 0;
	m_ch = ch;


}

int motor::drive(int duty)
{
	uint8_t port = m_ch>>2;	// 0:0-3 / 1:4-7
	m_ch &= 0x02; 		// 0-2Ç…êßå¿

	uint8_t dir_now = DUTY_TO_DIR(duty);
	uint8_t dir_old = gMotor_status[port].dir_old[m_ch];

	if(gMotor_status[port].isEnable[m_ch])	gMotor_status[port].duty[m_ch] = ABS_VAL(duty);
	else									gMotor_status[port].duty[m_ch] = 0;

	/****************************	ä—í ìdó¨ëŒçÙ	***********************************/
	if(gMotor_status[port].deadtime[m_ch])
	{
		if(IS_SHORTCURRENT_PATTERN(dir_now, dir_old))
		{
			gMotor_status[port].dir_save[m_ch] = dir_now;
		}
		else
		{
			gMotor_status[port].deadtime[m_ch] = 0;
			gMotor_status[port].dir		[m_ch] = dir_now;
			gMotor_status[port].dir_old [m_ch] = dir_now;
		}
	}
	else
	{
		if(IS_SHORTCURRENT_PATTERN(dir_now, dir_old))
		{
			gMotor_status[port].deadtime[m_ch] = MOTOR_DEADTIME_10US;
			gMotor_status[port].dir		[m_ch] = 0;
			gMotor_status[port].dir_save[m_ch] = dir_now;
		}
		else
		{
			gMotor_status[port].dir	   [m_ch] = dir_now;
			gMotor_status[port].dir_old[m_ch] = dir_now;
		}
	}
	/******************************************************************************/


	m_currentDuty = duty;
	return duty;
}

bool motor::brake()
{
	drive(BRAKEVALUE);

	return true;
//	return false;
}

int motor::getCurrentDuty()
{
	return m_currentDuty;
}


}
