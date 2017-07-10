/***************************************************************************
 *	@ファイル名		:	RCsemi_tools.h
 *	@概要		:	あると便利なツールをまとめたもので，
 *					必要だと思ったツールを足して言って構わない．
 *					その場合，バージョンの更新を怠らないこと．
 *					また，ある程度このファイルが膨大になってきたら，ファイルを分けたほうがよい．
 *	@バージョン		:	2.0.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver3, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "tools.h"

/* --------------------------------------------------------
 * @関数名		:	PID_control
 * @概要			:	PID制御を施す、使わない要素があればゲインを0にすること
 * @引数-pid		:	PIDを施される変数
 * @戻り値		:	なし
 * ----------------------------------------------------- */
void PID_control(_PID_t *pid)
{
	float p, i, d, c;

	// 偏差の計算
	pid->diff[0] = pid->target - pid->value;

	// 累積誤差を加算
	pid->integral += pid->diff[0];

	p = pid->KP * pid->diff[0];						// 比例
	i = pid->KI * pid->integral;					// 積分
	d = pid->KD * (pid->diff[1] - pid->diff[0]);	// 微分
	c = pid->KC;									// 定数

	// 偏差を更新
	pid->diff[1] = pid->diff[0];

	pid->act = p + i + d + c;
}

/* -------------------------------------------------------
 * @関数名			:	TIM6_CMT_Init
 * @概要				:	TIM6のCMT(コンペアマッチタイマ)を初期化する
 * @引数-prescaler	:	CMTのプリスケーラ
 *　  　　　-period		:	CMTのカウンタがリセットされる値
 * @戻り値			:	なし
 * ---------------------------------------------------- */
void TIM6_CMT_Init(u16 prescaler, u16 period)
{
	// タイマにクロックを供給
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

	/* グローバル割り込みを有効化 */
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel					 = TIM6_DAC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority		 = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd				 = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* TIM6を有効化 */
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler		= prescaler	- 1;
	TIM_TimeBaseStructure.TIM_Period    	= period	- 1;
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);

	// タイマ割り込みを有効化
	TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);

	TIM_Cmd(TIM6, ENABLE);
}

/* TIM6のタイマ割り込みを有効にしたとき，
 * 下記のように記述した関数が周期的に呼び出される．
 * 以下をソースコードにコピーして上記のTIM6_CMT_Initを呼出して使用すること．*/
/*
void TIM6_DAC_IRQHandler(void)
{
	// タイマ割り込みフラグをリセット
	TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
}
*/
