
#ifndef __ADC__
#define __ADC__

#include <stm32f4xx_hal.h>

#define ADC_SINGLECONV_CYCLE	ADC_SAMPLETIME_56CYCLES
#define ADC_CONTSCAN_CYCLE		ADC_SAMPLETIME_56CYCLES

namespace RCsemi{

typedef enum{
	Single,
	ContScan
}ADC_MODE_Def;

class adc{
	uint8_t m_mode;
	volatile uint16_t adc_contscan_value[8];
public:
	adc(ADC_MODE_Def mode);

	uint16_t Single_Read(uint8_t ch);
	inline void ContScan_Read(int ch);
};

} //namespace RCsemi

#endif //__ADC__
