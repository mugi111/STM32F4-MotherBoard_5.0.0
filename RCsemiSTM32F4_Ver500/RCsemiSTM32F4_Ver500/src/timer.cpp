/*
 * timer.cpp
 *
 *  Created on: 2017/04/20
 *      Author: mugi111
 */

#include "../inc/timer.h"
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_tim.h>


namespace RCsemi{

int gSystemTimer_ms = 0;

void timer::TIM7_CMT_Init()
{

}

void timer::delay_ms(int msec)
{
	m_timingDelay_ms = msec;
	while(m_timingDelay_ms);
}

//systemClockやPWMで共有しているTIM7の構成を考え直す
}


