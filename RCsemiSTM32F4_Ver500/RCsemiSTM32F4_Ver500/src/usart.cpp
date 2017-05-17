/*
 * usart.cpp
 *
 *  Created on: 2017/04/19
 *      Author: mugi111
 */

#include "usart.h"
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_usart.h>
#include <stm32f4xx_hal_rcc.h>
#include <stm32f4xx_hal_gpio.h>

namespace RCsemi{

usart::usart(int baud)
{
	usart::ctrl_buffer.recvPtr_in = 0;
	usart::ctrl_buffer.recvPtr_out = 0;

	__HAL_RCC_USART6_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.Pin		= GPIO_PIN_6 | GPIO_PIN_7;
	GPIO_InitStructure.Mode	= GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull	= GPIO_PULLUP;
	GPIO_InitStructure.Speed	= GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Alternate = GPIO_AF8_USART6;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.BaudRate = baud/* * (SystemCoreClock / 168000000)*/;
	USART_InitStructure.WordLength = USART_WORDLENGTH_8B;
	USART_InitStructure.StopBits = USART_STOPBITS_1;
	USART_InitStructure.Parity = USART_PARITY_NONE;
	USART_InitStructure.Mode = USART_MODE_TX_RX;
//	HAL_USART_Init(USART6, &USART_InitStructure);
	//TODO: \‘¢‘Ì‚©ŠÖ”‚ğ’T‚µo‚µ‚Ä‚¨‚¢‚Ä

}

int usart::ctrl_RecvByte()
{
	int data;
	int time0;

//	time0 = *****;
	while(ctrl_buffer.recvPtr_in == ctrl_buffer.recvPtr_out)
	{
//		if((*****-time0) > CTRL_RECV_TIMEOUT_MS)	return -1;
	}
//TODO: *****•”‚Ítimer‚ªI‚í‚Á‚½‚çsystemtimer_ms_check‚ğ
	data = ctrl_buffer.buff[ctrl_buffer.recvPtr_out];

	if(++ctrl_buffer.recvPtr_out == RECV_RINGBUFF_SIZE)
	{
		ctrl_buffer.recvPtr_out = 0;
	}
	return data;
}

int usart::ctrl_RecvString(char *buf, int max)
{
	int i;
	for(i = 0; i < max-i; i++)
	{
		*buf = ctrl_RecvByte();

		if(*buf == -1)	return -1;
		if(*buf == '\r')
		{
			*buf = 0;
			return i+1;
		}
		if(*buf == 0x08)
		{
			buf -= 2;
			i -= 2;
		}
		if(*buf != '\n')	buf++;
		else				i--;
	}
	*buf = 0;
	return i+1;
}

void usart::ctrl_SendByte(uint8_t byte)
{
//	while (USART_GetFlagStatus(USART6, USART_FLAG_TC) == RESET);
//	USART_SendData(USART6, byte);
}

void usart::ctrl_SendString(char *str)
{
	while(*str)
	{
		if(*str++ == '\n')	ctrl_SendByte('\r');
		else				ctrl_SendByte(*str++);
	}
}

}
