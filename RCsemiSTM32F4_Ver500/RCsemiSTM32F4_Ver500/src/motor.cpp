/*
 * motor.cpp
 *
 *  Created on: 2017/04/25
 *      Author: mugi111
 */

#include "../inc/motor.h"


namespace RCsemi{

_motor_status_t gMotor_status[3] = {{{0}}};

motor::motor(unsigned short ch)
{
	m_currentDuty = 0;
	m_ch = ch;


}

int motor::drive(int duty)
{
//	u8 port = ch>>2;	// 0:0-3 / 1:4-7
//	ch &= 0x02; 		// 0-2Ç…êßå¿
//
//	u8 dir_now = DUTY_TO_DIR(duty);
//	u8 dir_old = gMotor_status[port].dir_old[ch];
//
//	if(gMotor_status[port].isEnable[ch])	gMotor_status[port].duty[ch] = ABS_VAL(duty);
//	else									gMotor_status[port].duty[ch] = 0;
//
//	/****************************	ä—í ìdó¨ëŒçÙ	***********************************/
//	if(gMotor_status[port].deadtime[ch])
//	{
//		if(IS_SHORTCURRENT_PATTERN(dir_now, dir_old))
//		{
//			gMotor_status[port].dir_save[ch] = dir_now;
//		}
//		else
//		{
//			gMotor_status[port].deadtime[ch] = 0;
//			gMotor_status[port].dir		[ch] = dir_now;
//			gMotor_status[port].dir_old [ch] = dir_now;
//		}
//	}
//	else
//	{
//		if(IS_SHORTCURRENT_PATTERN(dir_now, dir_old))
//		{
//			gMotor_status[port].deadtime[ch] = MOTOR_DEADTIME_10US;
//			gMotor_status[port].dir		[ch] = 0;
//			gMotor_status[port].dir_save[ch] = dir_now;
//		}
//		else
//		{
//			gMotor_status[port].dir	   [ch] = dir_now;
//			gMotor_status[port].dir_old[ch] = dir_now;
//		}
//	}
//	/******************************************************************************/
//

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
