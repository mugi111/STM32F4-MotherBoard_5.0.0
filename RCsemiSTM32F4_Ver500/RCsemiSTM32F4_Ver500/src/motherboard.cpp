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
motherboard::motherboard()
{
//LED PUSH ROTARY init
}

void motherboard::LED_TurnOff()
{

}

void motherboard::LED_TurnOn()
{

}

void motherboard::LED_Toggle()
{

}

int motherboard::PushSW_isPushed()
{

	return 0;
}

unsigned int RotarySW_Check()
{

	return 0;
}

}