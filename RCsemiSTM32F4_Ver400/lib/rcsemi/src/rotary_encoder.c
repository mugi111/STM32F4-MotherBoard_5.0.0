/***************************************************************************
 *	@ファイル名		:	rotary_encoder.c
 *	@概要		:	ロータリーエンコーダポートの初期化と，読み取りを提供する．
 *					ポートはENC0-2があり，使用するタイマ，GPIOは以下のとおり，
 *					ENC0	:TIM3	A:PB4  / B:PB5
 *					ENC1	:TIM4	A:PD12 / B:PD13
 *					ENC2	:TIM9	A:PE5  / B:PE6
 *	@バージョン		:	3.0.0
 *	@開発者			:	キネクト
 *	@Ver3.0.0移行	:	むぎ
 *	@使用環境		:	STM32F407VG, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "rotary_encoder.h"

/* -------------------------------------------------
 * @関数名	:	ENCn_Init
 * @概要		:	ロータリーエンコーダの初期化をする
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void ENC0_Init(void)
{
	/* クロックを供給 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	/* GPIOの初期化 */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;	// プルアップ抵抗は外部で接続済み
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* GPIOピンをタイマとして利用する設定 */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_TIM3);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3);

	/* タイマの設定 */
	TIM_DeInit(TIM3);	// 必要ないかもしれない
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period 		= 0xffff;	// 最大値
	TIM_TimeBaseStructure.TIM_Prescaler 	= 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode 	= TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* ロータリーエンコーダ設定 */
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12,
							   TIM_ICPolarity_Rising,
							   TIM_ICPolarity_Rising);
	// タイマを有効化
	TIM_Cmd(TIM3, ENABLE);
}

void ENC1_Init(void)
{
	/* クロックを供給 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	/* GPIOの初期化 */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;	// プルアップ抵抗は外部で接続済み
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* GPIOピンをタイマとして利用する設定 */
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);

	/* タイマの設定 */
	TIM_DeInit(TIM4);	// 必要ないかもしれない
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period 		= 0xffff;	// 最大値
	TIM_TimeBaseStructure.TIM_Prescaler 	= 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode 	= TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	/* ロータリーエンコーダ設定 */
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12,
							   TIM_ICPolarity_Rising,
							   TIM_ICPolarity_Rising);
	// タイマを有効化
	TIM_Cmd(TIM4, ENABLE);
}

void ENC2_Init(void)
{
	/* クロックを供給 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);

	/* GPIOの初期化 */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;	// プルアップ抵抗は外部で接続済み
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	/* GPIOピンをタイマとして利用する設定 */
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_TIM9);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_TIM9);

	/* タイマの設定 */
	TIM_DeInit(TIM9);	// 必要ないかもしれない
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period 		= 0xffff;	// 最大値
	TIM_TimeBaseStructure.TIM_Prescaler 	= 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode 	= TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM9, &TIM_TimeBaseStructure);

	/* ロータリーエンコーダ設定 */
	TIM_EncoderInterfaceConfig(TIM9, TIM_EncoderMode_TI12,
							   TIM_ICPolarity_Rising,
							   TIM_ICPolarity_Rising);
	// タイマを有効化
	TIM_Cmd(TIM9, ENABLE);
}
