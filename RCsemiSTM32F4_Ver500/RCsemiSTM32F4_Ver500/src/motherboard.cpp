/*
 * motherboard.cpp
 *
 *  Created on: 2017/04/19
 *      Author: mugi111
 */

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_rcc.h>
#include <stm32f4xx_hal_gpio.h>
#include "../inc/motherboard.h"

namespace RCsemi{

motherboard::LED::LED()
{

}

void motherboard::LED::TurnOff()
{

}

void motherboard::LED::TurnOn()
{

}

void motherboard::LED::Toggle()
{

}

int motherboard::PushSW::isPushed()
{

	return 0;
}

unsigned int motherboard::RotarySW::Check()
{

	return 0;
}

}
