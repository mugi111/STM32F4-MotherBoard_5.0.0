/***************************************************************************
 *	@ファイル名		:	timer.c
 *	@概要		:	モータドライブ・delay・ロータリーエンコーダの制御を司るTIM7の
 *					インターフェースを提供する．
 *					また，delay・SystemTimerも提供している．
 *	@バージョン		:	1.2.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver2, MB_Ver3, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "timer.h"
#include "motor.h"
#include "digitalIO.h"
#include "rotary_encoder.h"

// システムタイマ，1msごとに1ずつ増加する．
int gSystemTimer_ms = 0;

// delay関数のためのカウント値
static int timingDelay_ms;

// motor.hで設定したモータの状態
extern _motor_status_t gMotor_status[3];

/* --------------------------------------------------
 * @関数名	:	TIM7_CMT_Init
 * @概要		:	モータポート・delay・ロータリーエンコーダで
 * 				利用するTIM7の初期化をする．
 * @引数		:	なし
 * @戻り値	:	なし
   ---------------------------------------------- */
void TIM7_CMT_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);

	/* TIM7のグローバル割り込み設定 */
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel					 = TIM7_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority		 = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd				 = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* TIM7の設定 */
	TIM_DeInit(TIM7);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 10-1;
	TIM_TimeBaseStructure.TIM_Period    = 84-1;
	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);

	/* TIM7の割り込みを有効化 */
	TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM7, ENABLE);
}


/* -------------------------------------------------
 * @関数名		:	delay_ms
 * @概要			:	指定時間空ループをする．
 * 					SystemCMTを初期化せずに呼び出すと，
 * 					無限ループしてしまう．
 * @引数-msec	:	ループする時間[ms]
 * @戻り値		:	なし
 * ---------------------------------------------- */
void delay_ms(int msec)
{
	timingDelay_ms = msec;
	while(timingDelay_ms);
}

/* -------------------------------------------------
 * @関数名	:	TIM7_IRQHandler
 * @概要		:	100kHzで割り込まれるルーチン
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void TIM7_IRQHandler(void)
{
	static short pwmcounter;	// PWMのためのプリスケーラ

	// 軽量化
	TIM7->SR = (u16)~TIM_IT_Update;
//	TIM_ClearITPendingBit(TIM7, TIM_IT_Update);

	/****************************	貫通電流対策	***********************************/
	int i;
	u8 port, ch;

	for(i = 0; i < 8; i++)
	{
		port = i>>2;//TODO
		ch = i&3;	//TODO
		if((gMotor_status[port].deadtime[ch]) && (--gMotor_status[port].deadtime[ch] == 0))
		{
			gMotor_status[port].dir	   [ch]	= gMotor_status[port].dir_save[ch];
			gMotor_status[port].dir_old[ch]	= gMotor_status[port].dir_save[ch];
		}
	}
	/******************************************************************************/

	/****************************	PWMのIO制御部分	*******************************/
	if(!pwmcounter)
	{
		if(gMotor_status[0].isEnable[0])
		{
			DIO_OutputPin(0, 0, gMotor_status[0].dir[0]   );
			DIO_OutputPin(0, 1, gMotor_status[0].dir[0]>>1);
		}
		if(gMotor_status[0].isEnable[1])
		{
			DIO_OutputPin(0, 2, gMotor_status[0].dir[1]   );
			DIO_OutputPin(0, 3, gMotor_status[0].dir[1]>>1);
		}
		if(gMotor_status[0].isEnable[2])
		{
			DIO_OutputPin(0, 4, gMotor_status[0].dir[2]   );
			DIO_OutputPin(0, 5, gMotor_status[0].dir[2]>>1);
		}
		if(gMotor_status[0].isEnable[3])
		{
			DIO_OutputPin(0, 6, gMotor_status[0].dir[3]   );
			DIO_OutputPin(0, 7, gMotor_status[0].dir[3]>>1);
		}
		if(gMotor_status[1].isEnable[0])
		{
			DIO_OutputPin(1, 0, gMotor_status[1].dir[0]   );
			DIO_OutputPin(1, 1, gMotor_status[1].dir[0]>>1);
		}
		if(gMotor_status[1].isEnable[1])
		{
			DIO_OutputPin(1, 2, gMotor_status[1].dir[1]   );
			DIO_OutputPin(1, 3, gMotor_status[1].dir[1]>>1);
		}
		if(gMotor_status[1].isEnable[2])
		{
			DIO_OutputPin(1, 4, gMotor_status[1].dir[2]   );
			DIO_OutputPin(1, 5, gMotor_status[1].dir[2]>>1);
		}
		if(gMotor_status[1].isEnable[3])
		{
			DIO_OutputPin(1, 6, gMotor_status[1].dir[3]   );
			DIO_OutputPin(1, 7, gMotor_status[1].dir[3]>>1);
		}
	}
	else
	{
		if(gMotor_status[0].duty[0] == pwmcounter)
		{
			DIO_OutputPin(0, 0, 0);
			DIO_OutputPin(0, 1, 0);
		}
		if(gMotor_status[0].duty[1] == pwmcounter)
		{
			DIO_OutputPin(0, 2, 0);
			DIO_OutputPin(0, 3, 0);
		}
		if(gMotor_status[0].duty[2] == pwmcounter)
		{
			DIO_OutputPin(0, 4, 0);
			DIO_OutputPin(0, 5, 0);
		}
		if(gMotor_status[0].duty[3] == pwmcounter)
		{
			DIO_OutputPin(0, 6, 0);
			DIO_OutputPin(0, 7, 0);
		}
		if(gMotor_status[1].duty[0] == pwmcounter)
		{
			DIO_OutputPin(1, 0, 0);
			DIO_OutputPin(1, 1, 0);
		}
		if(gMotor_status[1].duty[1] == pwmcounter)
		{
			DIO_OutputPin(1, 2, 0);
			DIO_OutputPin(1, 3, 0);
		}
		if(gMotor_status[1].duty[2] == pwmcounter)
		{
			DIO_OutputPin(1, 4, 0);
			DIO_OutputPin(1, 5, 0);
		}
		if(gMotor_status[1].duty[3] == pwmcounter)
		{
			DIO_OutputPin(1, 6, 0);
			DIO_OutputPin(1, 7, 0);
		}
	}
	/******************************************************************************/

	/**************	1kHzで割り込まれる部分，システムタイマ・タイミングディレイなどの処理	***************/
	if(++pwmcounter == 100)
	{
		gSystemTimer_ms++;
		if(timingDelay_ms)	timingDelay_ms--;
		pwmcounter = 0;
	}
	/******************************************************************************/
}
