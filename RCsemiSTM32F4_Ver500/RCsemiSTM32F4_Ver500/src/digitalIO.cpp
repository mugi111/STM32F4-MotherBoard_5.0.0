#include "../inc/digitalIO.h"
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_rcc.h>
#include <stm32f4xx_hal_gpio.h>

namespace RCsemi{

/* bit banding */
/* bit_word_addr = bit_band_base + (byte_offset * 32) + (bit_number * 4) */
// GPIOB : 0x40020400 GPIOC : 0x40020800 GPIOD : 0x40020C00 GPIOE : 0x40021000
// GPIOx_ODR : 0x14
/* TODO: åvéZÇ∆ïœçX*/
const unsigned long DIO_ODR_ADDR_BB[2][8] =
{
		{	0x4240829C, 0x42410280, 0x424082AC, 0x424082B0, 0x424082B4, 0x424082B8, 0x424082BC, 0x42408298	},
		{	0x424102A0, 0x424102A4, 0x424102AC, 0x42420288, 0x4242028C, 0x42418288, 0x4241028C, 0x42418298	}
};
// GPIOx_IDR : 0x10
const unsigned long DIO_IDR_ADDR_BB[2][8] =
{
		{	0x4240821C, 0x42410200, 0x4240822C, 0x42408230, 0x42408234, 0x42408238, 0x4240823C, 0x42408218	},
		{	0x42410220, 0x42410224, 0x4241022C, 0x42420208, 0x4242020C, 0x42418208, 0x4241020C, 0x42420298	}
};


digitalIO::digitalIO(unsigned int port, unsigned int pin, unsigned long mode)
{

	m_port = port;
	m_pin = pin;
	m_mode = mode;

	if(port == 0){
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.Mode  = mode;
		GPIO_InitStructure.Pull  = GPIO_NOPULL;
		GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

		/* PORTB */
		if(pin & 0xFD){
			__HAL_RCC_GPIOB_CLK_ENABLE();
			GPIO_InitStructure.Pin = 0x0000;
			if(pin & 0x01)	GPIO_InitStructure.Pin |= GPIO_PIN_7;	// PB7
			if(pin & 0x04)	GPIO_InitStructure.Pin |= GPIO_PIN_11;	// PB11
			if(pin & 0x08)	GPIO_InitStructure.Pin |= GPIO_PIN_12;	// PB12
			if(pin & 0x10)	GPIO_InitStructure.Pin |= GPIO_PIN_13;	// PB13
			if(pin & 0x20)	GPIO_InitStructure.Pin |= GPIO_PIN_14;	// PB14
			if(pin & 0x40)	GPIO_InitStructure.Pin |= GPIO_PIN_15;	// PB15
			if(pin & 0x80)	GPIO_InitStructure.Pin |= GPIO_PIN_6; 	// PB6
			HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
		}

		/* PORTC */
		if(pin & 0x02){
			__HAL_RCC_GPIOC_CLK_ENABLE();
			GPIO_InitStructure.Pin = 0x0000;
			if(pin & 0x02)	GPIO_InitStructure.Pin |= GPIO_PIN_0;	// PB7
			HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);
		}

	}else if(port==1){
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.Mode  = mode;
		GPIO_InitStructure.Pull  = GPIO_NOPULL;
		GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

		/* PORTC */
		if(pin & 0x47)
		{
			__HAL_RCC_GPIOC_CLK_ENABLE();
			GPIO_InitStructure.Pin = 0x0000;
			if(pin & 0x01)	GPIO_InitStructure.Pin |= GPIO_PIN_8;	// PC8
			if(pin & 0x02)	GPIO_InitStructure.Pin |= GPIO_PIN_9;	// PC9
			if(pin & 0x04)	GPIO_InitStructure.Pin |= GPIO_PIN_11;	// PC11
			if(pin & 0x40)	GPIO_InitStructure.Pin |= GPIO_PIN_3;  // PC3
			HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);
		}
		/* PORTD */
		if(pin & 0xA0)
		{
			__HAL_RCC_GPIOD_CLK_ENABLE();
			GPIO_InitStructure.Pin = 0x0000;
			if(pin & 0x20)	GPIO_InitStructure.Pin |= GPIO_PIN_2;	// PD2
			if(pin & 0x80)	GPIO_InitStructure.Pin |= GPIO_PIN_7;	// PD7
			HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
		}
		/* PORTE */
		if(pin & 0x18)
		{
			__HAL_RCC_GPIOE_CLK_ENABLE();
			GPIO_InitStructure.Pin = 0x0000;
			if(pin & 0x08)	GPIO_InitStructure.Pin |= GPIO_PIN_2;	// PE2
			if(pin & 0x10)	GPIO_InitStructure.Pin |= GPIO_PIN_3;	// PE3
			HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);
		}
	}
}

inline void digitalIO::OutputPin(unsigned int status)
{
	*((uint32_t*)DIO_ODR_ADDR_BB[(m_port)][(m_pin)]) = (status);
}

inline void digitalIO::TogglePin()
{
	*((uint32_t*)DIO_ODR_ADDR_BB[(m_port)][(m_pin)]) ^= 1;
}

inline int digitalIO::CheckPin()
{
	return *((unsigned long*)DIO_IDR_ADDR_BB[(m_port)][(m_pin)]);
}

}

