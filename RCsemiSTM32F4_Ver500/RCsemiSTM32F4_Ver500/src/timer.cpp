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

void TIM7_IRQHandler(void)
{
//	static short pwmcounter;	// PWMのためのプリスケーラ
//
//	// 軽量化
////	TIM7->SR = (u16)~TIM_IT_Update;
//
//	/****************************	貫通電流対策	***********************************/
//	int i;
//	uint8_t port, ch;
//
//	for(i = 0; i < 8; i++)
//	{
//		port = i>>2;//TODO
//		ch = i&3;	//TODO
//		if((gMotor_status[port].deadtime[ch]) && (--gMotor_status[port].deadtime[ch] == 0))
//		{
//			gMotor_status[port].dir	   [ch]	= gMotor_status[port].dir_save[ch];
//			gMotor_status[port].dir_old[ch]	= gMotor_status[port].dir_save[ch];
//		}
//	}
//	/******************************************************************************/
//
//	/****************************	PWMのIO制御部分	*******************************/
//	if(!pwmcounter)
//	{
//		if(gMotor_status[0].isEnable[0])
//		{
//			DIO_OutputPin(0, 0, gMotor_status[0].dir[0]   );
//			DIO_OutputPin(0, 1, gMotor_status[0].dir[0]>>1);
//		}
//		if(gMotor_status[0].isEnable[1])
//		{
//			DIO_OutputPin(0, 2, gMotor_status[0].dir[1]   );
//			DIO_OutputPin(0, 3, gMotor_status[0].dir[1]>>1);
//		}
//		if(gMotor_status[0].isEnable[2])
//		{
//			DIO_OutputPin(0, 4, gMotor_status[0].dir[2]   );
//			DIO_OutputPin(0, 5, gMotor_status[0].dir[2]>>1);
//		}
//		if(gMotor_status[0].isEnable[3])
//		{
//			DIO_OutputPin(0, 6, gMotor_status[0].dir[3]   );
//			DIO_OutputPin(0, 7, gMotor_status[0].dir[3]>>1);
//		}
//		if(gMotor_status[1].isEnable[0])
//		{
//			DIO_OutputPin(1, 0, gMotor_status[1].dir[0]   );
//			DIO_OutputPin(1, 1, gMotor_status[1].dir[0]>>1);
//		}
//		if(gMotor_status[1].isEnable[1])
//		{
//			DIO_OutputPin(1, 2, gMotor_status[1].dir[1]   );
//			DIO_OutputPin(1, 3, gMotor_status[1].dir[1]>>1);
//		}
//		if(gMotor_status[1].isEnable[2])
//		{
//			DIO_OutputPin(1, 4, gMotor_status[1].dir[2]   );
//			DIO_OutputPin(1, 5, gMotor_status[1].dir[2]>>1);
//		}
//		if(gMotor_status[1].isEnable[3])
//		{
//			DIO_OutputPin(1, 6, gMotor_status[1].dir[3]   );
//			DIO_OutputPin(1, 7, gMotor_status[1].dir[3]>>1);
//		}
//	}
//	else
//	{
//		if(gMotor_status[0].duty[0] == pwmcounter)
//		{
//			DIO_OutputPin(0, 0, 0);
//			DIO_OutputPin(0, 1, 0);
//		}
//		if(gMotor_status[0].duty[1] == pwmcounter)
//		{
//			DIO_OutputPin(0, 2, 0);
//			DIO_OutputPin(0, 3, 0);
//		}
//		if(gMotor_status[0].duty[2] == pwmcounter)
//		{
//			DIO_OutputPin(0, 4, 0);
//			DIO_OutputPin(0, 5, 0);
//		}
//		if(gMotor_status[0].duty[3] == pwmcounter)
//		{
//			DIO_OutputPin(0, 6, 0);
//			DIO_OutputPin(0, 7, 0);
//		}
//		if(gMotor_status[1].duty[0] == pwmcounter)
//		{
//			DIO_OutputPin(1, 0, 0);
//			DIO_OutputPin(1, 1, 0);
//		}
//		if(gMotor_status[1].duty[1] == pwmcounter)
//		{
//			DIO_OutputPin(1, 2, 0);
//			DIO_OutputPin(1, 3, 0);
//		}
//		if(gMotor_status[1].duty[2] == pwmcounter)
//		{
//			DIO_OutputPin(1, 4, 0);
//			DIO_OutputPin(1, 5, 0);
//		}
//		if(gMotor_status[1].duty[3] == pwmcounter)
//		{
//			DIO_OutputPin(1, 6, 0);
//			DIO_OutputPin(1, 7, 0);
//		}
//	}
//	/******************************************************************************/
//
//	/**************	1kHzで割り込まれる部分，システムタイマ・タイミングディレイなどの処理	***************/
//	if(++pwmcounter == 100)
//	{
//		gSystemTimer_ms++;
//		if(timingDelay_ms)	timingDelay_ms--;
//		pwmcounter = 0;
//	}
//	/******************************************************************************/
//
}
//systemClockやPWMで共有しているTIM7の構成を考え直す

void timer::TIM6_CMT_Init(uint16_t prescaler, uint16_t period)
{
	__HAL_RCC_TIM6_CLK_ENABLE();

	TIM_Base_InitTypeDef TIM_Base_InitStructure;
	TIM_Base_InitStructure.Prescaler = prescaler-1;
	TIM_Base_InitStructure.Period = period-1;
}
}


