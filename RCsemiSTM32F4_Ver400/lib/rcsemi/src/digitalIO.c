/*/***************************************************************************
 *	@ファイル名		:	digitalIO.c
 *	@概要		:	DIGITAL-IOxポートを用いて，デジタル的な入出力を行います．
 *					以下にマザーボード上に設けられているDIGITAL-IOxのピン配置を示しておきます．
 *
 *					[DIO0]	PB7 , PC0 , PB11, PB12, PA8, PA11, PA12, PB6
 *					[DIO1]	PC8 , PC9 , PC11, PE2 , PE3 , PD2 , PC3 , PD6
 *
 *	@バージョン		:	4.0.0
 *	@開発者			:	キネクト
 *	@Ver4.0.0移行	:	むぎ
 *	@使用環境		:	STM32F407VG, MB_Ver5, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "stm32f4xx_gpio.h"
#include "digitalIO.h"

/* TODO: 2次元配列へのアクセスが遅いという意見もあります */
/* bit banding */
/* bit_word_addr = bit_band_base + (byte_offset * 32) + (bit_number * 4) */
// GPIOB : 0x40020400 GPIOC : 0x40020800 GPIOD : 0x40020C00 GPIOE : 0x40021000
// GPIOx_ODR : 0x14
/* TODO: 計算と変更*/
const u32 DIO_ODR_ADDR_BB[2][8] =
{
		{	0x4240829C, 0x42410280, 0x424082AC, 0x424082B0, 0x424002A0, 0x424002AC, 0x424002B0, 0x42408298	},
		{	0x424102A0, 0x424102A4, 0x424102AC, 0x42420288, 0x4242028C, 0x42418288, 0x4241028C, 0x42418298	}
};
// GPIOx_IDR : 0x10
const u32 DIO_IDR_ADDR_BB[2][8] =
{
		{	0x4240821C, 0x42410200, 0x4240822C, 0x42408230, 0x42408234, 0x4240022C, 0x42400230, 0x42408218	},
		{	0x42410220, 0x42410224, 0x4241022C, 0x42420208, 0x4242020C, 0x42418208, 0x4241020C, 0x42420298	}
};

/* ------------------------------------------------------------
 * @関数名		:	DIO0_Init
 * @概要			:	Digital-IO0の初期化をします．
 * @引数-pin	:	設定するピンを8bit(1:対象/0:対象外)で表す．
 * 			-mode	:	DIO_MODE_INを設定すると入力として初期化
 * 	   					DIO_MODE_OUTを設定すると出力として初期化
 * @使用例		: 上位4bitを入力，下位4bitを出力で初期化するとき．
 *							DIO0_Init(0xF0, DIO_MODE_IN);
 *							DIO0_Init(0x0F, DIO_MODE_OUT);
   --------------------------------------------------------- */
void DIO0_Init(u8 pin, GPIOMode_TypeDef mode)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = mode;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	/* PORTB */
	if(pin & 0xFD){
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = 0x0000;
		if(pin & 0x01)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_7;	// PB7
		if(pin & 0x04)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_11;	// PB11
		if(pin & 0x08)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_12;	// PB12
		if(pin & 0x10)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_13;	// PB13
		if(pin & 0x20)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_14;	// PB14
		if(pin & 0x40)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_15;	// PB15
		if(pin & 0x80)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_6;  // PB6
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}

	/* PORTC */
	if(pin & 0x02){
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
		GPIO_InitStructure.GPIO_Pin = 0x0000;
		if(pin & 0x02)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_0;	// PB7
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	}
}

/* ------------------------------------------------------------
 * @関数名		:	DIO1_Init
 * @概要			:	Digital-IO1の初期化をします．
 * @引数-pin	:	設定するピンを8bit(1:対象/0:対象外)で表す．
 * 			-mode	:	DIO_MODE_INを設定すると入力として初期化
 * 	   					DIO_MODE_OUTを設定すると出力として初期化
 * @使用例		: 上位4bitを入力，下位4bitを出力で初期化するとき．
 *							DIO1_Init(0xF0, DIO_MODE_IN);
 *							DIO1_Init(0x0F, DIO_MODE_OUT);
   --------------------------------------------------------- */
void DIO1_Init(u8 pin, GPIOMode_TypeDef mode)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = mode;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	/* PORTC */
	if(pin & 0x47)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
		GPIO_InitStructure.GPIO_Pin = 0x0000;
		if(pin & 0x01)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_8;	// PC8
		if(pin & 0x02)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_9;	// PC9
		if(pin & 0x04)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_11;	// PC11
		if(pin & 0x40)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_3;  // PC3
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	}
	/* PORTD */
	if(pin & 0xA0)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
		GPIO_InitStructure.GPIO_Pin = 0x0000;
		if(pin & 0x20)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_2;	// PD2
		if(pin & 0x80)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_7;	// PD7
		GPIO_Init(GPIOD, &GPIO_InitStructure);
	}
	/* PORTE */
	if(pin & 0x18)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
		GPIO_InitStructure.GPIO_Pin = 0x0000;
		if(pin & 0x08)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_2;	// PE2
		if(pin & 0x10)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_3;	// PE3
		GPIO_Init(GPIOE, &GPIO_InitStructure);
	}
}

