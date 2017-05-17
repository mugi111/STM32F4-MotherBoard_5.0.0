#include "adc.h"
#include <stm32f4xx.h>
#include <stm32f4xx_hal_adc.h>


namespace RCsemi{

//adc::adc(ADC_MODE_Def mode)
//{
//	m_mode = mode;
//
//	ADC_InitTypeDef ADC_InitStructure;
//	ADC_InitStructure.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
//
//}
//
//uint16_t adc::Single_Read(uint8_t ch)
//{
//	if	   (ch == 0)	HAL_ADC_GetValue(ADC_InitStructure);
//	else if(ch == 1)	HAL_ADC_ConfigChannel(ADC1, ADC_CHANNEL_3 , 1, ADC_SINGLECONV_CYCLE);
//	else if(ch == 2)	HAL_ADC_ConfigChannel(ADC1, ADC_CHANNEL_8 , 1, ADC_SINGLECONV_CYCLE);
//	else if(ch == 3)	HAL_ADC_ConfigChannel(ADC1, ADC_CHANNEL_9 , 1, ADC_SINGLECONV_CYCLE);
//	else if(ch == 4)	HAL_ADC_ConfigChannel(ADC1, ADC_CHANNEL_11, 1, ADC_SINGLECONV_CYCLE);
//	else if(ch == 5)	HAL_ADC_ConfigChannel(ADC1, ADC_CHANNEL_12, 1, ADC_SINGLECONV_CYCLE);
//	else if(ch == 6)	HAL_ADC_ConfigChannel(ADC1, ADC_CHANNEL_14, 1, ADC_SINGLECONV_CYCLE);
//	else if(ch == 7)	HAL_ADC_ConfigChannel(ADC1, ADC_CHANNEL_15, 1, ADC_SINGLECONV_CYCLE);
//	ADC_SoftwareStartConv(ADC1);
//
//	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
//	return 1;
//}

}
