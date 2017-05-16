/***************************************************************************
 *	@ファイル名		:	motherboard.h
 *	@概要		:	MB上のLED，プッシュスイッチ，ロータリースイッチの機能を提供します．
 *					以下に，各要素のピン配置を示します．
 *					LED			PA15
 *					PushSW		PB10
 *					RotarySW	0:PC10, 1:PC12, 2:PE0, 3:PE1
 *	@バージョン		:	4.0.0
 *	@開発者			:	キネクト
 *	@Ver4.0.0移行	:	むぎ
 *	@使用環境		:	STM32F407VG, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "motherboard.h"

/* -------------------------------------------------
 * @関数名	:	MB_LED_Init
 * @概要		:	MB上LEDに接続されているGPIO(PA8, PA15)を
 * 				初期化します．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_Init(void)
{
	/* クロック供給 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	/* GPIO設定 */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/* -------------------------------------------------
 * @関数名	:	MB_LED_TurnOff
 * @概要		:	指定のLEDを消灯します．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_TurnOff()
{
	GPIOA->BSRRH = GPIO_Pin_15;
}

/* -------------------------------------------------
 * @関数名	:	MB_LED_TurnOn
 * @概要		:	指定のLEDを点灯します．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_TurnOn()
{
	GPIOA->BSRRL = GPIO_Pin_15;
}

/* -------------------------------------------------
 * @関数名	:	MB_LED_Toggle
 * @概要		:	指定のLEDを前回と違う状態にします．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_Toggle()
{
	GPIOA->ODR ^= GPIO_Pin_15;
}

/* -------------------------------------------------
 * @関数名	:	MB_PushSW_Init
 * @概要		:	プッシュスイッチに接続されているGPIO(PB10)の
 * 				初期化をします．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_PushSW_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/* -------------------------------------------------
 * @関数名	:	MB_PushSW_IsPushed
 * @概要		:	プッシュスイッチが押されたかどうか判定します．
 * @引数		:	なし
 * @戻り値	:	押されたら1, そうでなければ0
 * ---------------------------------------------- */
int MB_PushSW_IsPushed()
{
	return !(GPIOB->IDR & GPIO_Pin_10);
}

/* -------------------------------------------------
 * @関数名	:	MB_RotarySW_Init
 * @概要		:	ロータリースイッチに接続されている
 * 				GPIO(PC10, PC12, PE0, PE1)の初期化をします．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_RotarySW_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/* -------------------------------------------------
 * @関数名	:	MB_RotarySW_Check
 * @概要		:	ロータリースイッチが示す値(0-15)を判別します．
 * @引数		:	なし
 * @戻り値	:	ロータリースイッチの値(0-15)
 * ---------------------------------------------- */
unsigned int MB_RotarySW_Check(void)
{
	return (!(GPIOC->IDR & GPIO_Pin_10)    ) | (!(GPIOC->IDR & GPIO_Pin_12) << 1) |
		   (!(GPIOE->IDR & GPIO_Pin_0) << 2) | (!(GPIOE->IDR & GPIO_Pin_1) << 3);

}
