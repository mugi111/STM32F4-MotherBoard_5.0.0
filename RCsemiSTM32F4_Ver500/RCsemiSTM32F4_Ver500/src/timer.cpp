/*
 * timer.cpp
 *
 *  Created on: 2017/04/20
 *      Author: mugi111
 */

#include "../inc/timer.h"
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_tim.h>
#include <stm32f4xx_hal_rcc.h>


namespace RCsemi{

int gSystemTimer_ms = 0;

void timer::TIM7_CMT_Init()
{
	__HAL_RCC_TIM7_CLK_ENABLE();

	TIM_Base_InitTypeDef TIM_Base_InitStructure;
	TIM_Base_InitStructure.Prescaler = 10-1;
	TIM_Base_InitStructure.Period = 84-1;

}

void timer::delay_ms(int msec)
{
	m_timingDelay_ms = msec;
	while(m_timingDelay_ms);
}


void timer::TIM6_CMT_Init(uint16_t prescaler, uint16_t period)
{
	__HAL_RCC_TIM6_CLK_ENABLE();

	TIM_Base_InitTypeDef TIM_Base_InitStructure;
	TIM_Base_InitStructure.Prescaler = prescaler-1;
	TIM_Base_InitStructure.Period = period-1;
}
}


