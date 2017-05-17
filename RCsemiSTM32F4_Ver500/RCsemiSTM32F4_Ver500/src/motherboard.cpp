/*
 * motherboard.cpp
 *
 *  Created on: 2017/04/19
 *      Author: mugi111
 */

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_rcc.h>
#include <stm32f4xx_hal_gpio.h>
#include "motherboard.h"

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

motherboard::PushSW::PushSW()
{

}

int motherboard::PushSW::isPushed()
{

	return 0;
}

motherboard::RotarySW::RotarySW()
{

}

unsigned int motherboard::RotarySW::Check()
{

	return 0;
}

}
