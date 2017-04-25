/*
 * rotary_encoder.cpp
 *
 *  Created on: 2017/03/07
 *      Author: mugi111
 */

#include "../inc/rotary_encoder.h"
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_rcc.h>
#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_tim.h>

namespace RCsemi{

	rotary_encoder::rotary_encoder(int ch)
	{
		m_ch = ch;

		if(ch == 0){
			__HAL_RCC_GPIOB_CLK_ENABLE();
			__HAL_RCC_TIM3_CLK_ENABLE();

			GPIO_InitTypeDef GPIO_InitStructure;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
			GPIO_InitStructure.Pin = GPIO_PIN_4 | GPIO_PIN_5;
			GPIO_InitStructure.Pull = GPIO_NOPULL;
			GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
			GPIO_InitStructure.Alternate = GPIO_AF2_TIM3;

			HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);

			TIM_Encoder_InitTypeDef Encoder_InitStructure;
			Encoder_InitStructure.EncoderMode = TIM_ENCODERMODE_TI12;
			Encoder_InitStructure.IC1Filter = 0;
			Encoder_InitStructure.IC1Polarity = TIM_ICPOLARITY_RISING;
			Encoder_InitStructure.IC1Selection = TIM_ICSELECTION_DIRECTTI;
			Encoder_InitStructure.IC1Prescaler = TIM_ICPSC_DIV1;
			Encoder_InitStructure.IC2Filter = 0;
			Encoder_InitStructure.IC2Polarity = TIM_ICPOLARITY_RISING;
			Encoder_InitStructure.IC2Selection = TIM_ICSELECTION_DIRECTTI;
			Encoder_InitStructure.IC2Prescaler = TIM_ICPSC_DIV1;

			TIM_HandleTypeDef htim3;
			htim3.Instance = TIM3;
			  htim3.Init.Prescaler = 0;
			  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
			  htim3.Init.Period = 0;
			  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

			HAL_TIM_Encoder_Init(&htim3, &Encoder_InitStructure);
			HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);

		}else if(ch == 1){
			__HAL_RCC_GPIOD_CLK_ENABLE();
			__HAL_RCC_TIM4_CLK_ENABLE();

			GPIO_InitTypeDef GPIO_InitStructure;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
			GPIO_InitStructure.Pin = GPIO_PIN_12 | GPIO_PIN_13;
			GPIO_InitStructure.Pull = GPIO_NOPULL;
			GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
			GPIO_InitStructure.Alternate = GPIO_AF2_TIM4;

			HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

			TIM_Encoder_InitTypeDef Encoder_InitStructure;
			Encoder_InitStructure.EncoderMode = TIM_ENCODERMODE_TI12;
			Encoder_InitStructure.IC1Filter = 0;
			Encoder_InitStructure.IC1Polarity = TIM_ICPOLARITY_RISING;
			Encoder_InitStructure.IC1Selection = TIM_ICSELECTION_DIRECTTI;
			Encoder_InitStructure.IC1Prescaler = TIM_ICPSC_DIV1;
			Encoder_InitStructure.IC2Filter = 0;
			Encoder_InitStructure.IC2Polarity = TIM_ICPOLARITY_RISING;
			Encoder_InitStructure.IC2Selection = TIM_ICSELECTION_DIRECTTI;
			Encoder_InitStructure.IC2Prescaler = TIM_ICPSC_DIV1;


			TIM_HandleTypeDef htim4;
			htim4.Instance = TIM4;
			htim4.Init.Prescaler = 0;
			htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
			htim4.Init.Period = 0;
			htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

			HAL_TIM_Encoder_Init(&htim4, &Encoder_InitStructure);
			HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);

		}else if(ch == 2){
			__HAL_RCC_GPIOE_CLK_ENABLE();
			__HAL_RCC_TIM9_CLK_ENABLE();

			GPIO_InitTypeDef GPIO_InitStructure;
			GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
			GPIO_InitStructure.Pin = GPIO_PIN_5 | GPIO_PIN_6;
			GPIO_InitStructure.Pull = GPIO_NOPULL;
			GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
			GPIO_InitStructure.Alternate = GPIO_AF3_TIM9;

			HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);

			TIM_Encoder_InitTypeDef Encoder_InitStructure;
			Encoder_InitStructure.EncoderMode = TIM_ENCODERMODE_TI12;
			Encoder_InitStructure.IC1Filter = 0;
			Encoder_InitStructure.IC1Polarity = TIM_ICPOLARITY_RISING;
			Encoder_InitStructure.IC1Selection = TIM_ICSELECTION_DIRECTTI;
			Encoder_InitStructure.IC1Prescaler = TIM_ICPSC_DIV1;
			Encoder_InitStructure.IC2Filter = 0;
			Encoder_InitStructure.IC2Polarity = TIM_ICPOLARITY_RISING;
			Encoder_InitStructure.IC2Selection = TIM_ICSELECTION_DIRECTTI;
			Encoder_InitStructure.IC2Prescaler = TIM_ICPSC_DIV1;


			TIM_HandleTypeDef htim9;
			htim9.Instance = TIM9;
			htim9.Init.Prescaler = 0;
			htim9.Init.CounterMode = TIM_COUNTERMODE_UP;
			htim9.Init.Period = 0;
			htim9.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

			HAL_TIM_Encoder_Init(&htim9, &Encoder_InitStructure);
			HAL_TIM_Encoder_Start(&htim9, TIM_CHANNEL_ALL);

		}else{
//#error "‚»‚ñ‚Èƒ|[ƒg‚Í‚È‚¢‚æ"
		}
	}

	inline int rotary_encoder::getCount()
	{
		if(m_ch == 0){
			return (signed short)TIM3->CNT;
		}else if(m_ch == 1){
			return (signed short)TIM4->CNT;
		}else if(m_ch == 2){
			return (signed short)TIM9->CNT;
		}else{
			return 0;
		}
	}

	inline void rotary_encoder::clearCount()
	{
		if(m_ch == 0){
			TIM3->CNT = 0;
		}else if(m_ch == 1){
			TIM4->CNT = 0;
		}else if(m_ch == 2){
			TIM9->CNT = 0;
		}else{

		}
	}
}


