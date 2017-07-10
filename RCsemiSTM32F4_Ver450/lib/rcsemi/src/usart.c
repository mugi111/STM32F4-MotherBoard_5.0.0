/***************************************************************************
 *	@ファイル名		:	usart.c
 *	@概要		:	USART6初期化や送受信を提供する．
 *					USART6(Bluetooth)	TX:PC6 / RX:PC7
 *	@バージョン		:	3.0.0
 *	@開発者			:	キネクト
 *	@Ver3.0.0移行	:	むぎ
 *	@使用環境		:	STM32F407VG, MB_Ver4, Coocox CoIDE
 **************************************************************************/

/* インクルード ======================================================= */
#include <stm32f4xx.h>
#include "usart.h"
#include "timer.h"

/* 定数定義 ======================================================== */
#define RECV_RINGBUFF_SIZE 16

/* 構造体定義	======================================================== */
/* リングバッファ関係 */
typedef struct
{
	/* ポインタ */
	volatile int recvPtr_in;
	volatile int recvPtr_out;

	/* バッファ */
	u8 buff[RECV_RINGBUFF_SIZE];

} ringBuffer_t;

/* グローバル変数  ==================================================== */
static ringBuffer_t bluetooth_buffer;

/* -------------------------------------------------
 * @関数名			:	Bluetooth_USART_Init
 * @概要				:	BluetoothのUSARTを初期化する
 * @引数-baud		:	ボーレートを設定する
 * @戻り値			:	なし
 * ---------------------------------------------- */
void Bluetooth_USART_Init(int baud)
{
	bluetooth_buffer.recvPtr_in = 0;
	bluetooth_buffer.recvPtr_out = 0;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType	= GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd	= GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_100MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);

	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate				= baud * (SystemCoreClock / 168000000);
	USART_InitStructure.USART_WordLength			= USART_WordLength_8b;
	USART_InitStructure.USART_StopBits				= USART_StopBits_1;
	USART_InitStructure.USART_Parity				= USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl	= USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode					= USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART6, &USART_InitStructure);

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel						= USART6_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority			= 0;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	= 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd					= ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART6, ENABLE);
}


/* -------------------------------------------------
 * @関数名	:	Bluetooth_RecvByte
 * @概要		:	Bluetoothから1[Byte]の情報を受け取る
 * @引数		:	なし
 * @戻り値	:	受信したデータ
 * ---------------------------------------------- */
int Bluetooth_RecvByte(void)
{
	int data;
	int time0;

	time0 = SystemTimer_ms_Check();
	while(bluetooth_buffer.recvPtr_in == bluetooth_buffer.recvPtr_out)
	{
		if((SystemTimer_ms_Check()-time0) > BLUETOOTH_RECV_TIMEOUT_MS)	return -1;
	}

	data = bluetooth_buffer.buff[bluetooth_buffer.recvPtr_out];

	if(++bluetooth_buffer.recvPtr_out == RECV_RINGBUFF_SIZE)
	{
		bluetooth_buffer.recvPtr_out = 0;
	}
	return data;
}

/* -------------------------------------------------
 * @関数名	:	Bluetooth_RecvString
 * @概要		:	Bluetoothからmax[Byte]受け取り、
 * 				文字列として解釈する
 * @引数-buf	:	受け取った文字列の格納先
 *　          -max	:	文字列の長さ[Byte]
 * @戻り値	:	エラー
 * ---------------------------------------------- */
int	Bluetooth_RecvString(char *buf, int max)
{
	int i;
	for(i = 0; i < max-i; i++)
	{
		*buf = Bluetooth_RecvByte();

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

/* -------------------------------------------------
 * @関数名		:	Bluetooth_SendByte
 * @概要			:	Bluetoothから1[Byte]送信する
 * @引数-byte	:	送信する1[Byte]文字
 * @戻り値		:	なし
 * ---------------------------------------------- */
void Bluetooth_SendByte(u8 byte)
{
	while (USART_GetFlagStatus(USART6, USART_FLAG_TC) == RESET);
	USART_SendData(USART6, byte);
}

/* -------------------------------------------------
 * @関数名	:	Bluetooth_SendString
 * @概要		:	Bluetoothから文字列を送信する
 * @引数-buf	:	送信する文字列
 * @戻り値	:	なし
 * ---------------------------------------------- */
void Bluetooth_SendString(char *str)
{
	while(*str)
	{
		if(*str++ == '\n')	Bluetooth_SendByte('\r');
		else				Bluetooth_SendByte(*str++);
	}
}

/* -------------------------------------------------
 * @関数名	:	USART2_IRQHandler
 * @概要		:	USART2の受信割り込みルーチン
 * ---------------------------------------------- */
void USART6_IRQHandler(void)
{
	// 受信終了
	if(USART_GetITStatus(USART6, USART_IT_RXNE) == SET)
	{
		bluetooth_buffer.buff[bluetooth_buffer.recvPtr_in] = USART_ReceiveData(USART6);
		if(++bluetooth_buffer.recvPtr_in == RECV_RINGBUFF_SIZE)
		{
			bluetooth_buffer.recvPtr_in = 0;
		}
	}
}
