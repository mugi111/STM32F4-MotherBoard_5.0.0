/***************************************************************************
 *	@ファイル名		:	02_MotherBoard.c
 *	@概要		:	マザーボード上の各機能，LED*2，プッシュスイッチ*2，
					4ビットロータリースイッチを動作させる．
 *					結果はDigitalIOの出力で確認する
 *
 *					必要な処理はコメントの先頭に**がついていますので，
 *					必ず記入するようにしてください．
 *	@バージョン		:	2.0.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver3, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __02_MB__

/******************************/
/* ↓↓　以下がサンプル　↓↓ */
/******************************/
#include <stm32f4xx.h>	// **最初にインクルードする
#include "motherboard.h"	// **インクルードする

#include "timer.h"	// delayを使うために必要になる

#include "digitalIO.h"	// 状態確認用

int main(void)
{
	/* -------------	変数宣言	----------------- */
	int pushsw_status[2];
	u8 rotarysw_value;

	/* ---------------------------------------------- */

	/* -----------------	初期化	----------------- */
	SystemCoreClockUpdate();	// **最初に呼び出す
	TIM7_CMT_Init();	// delay関数を利用するための初期化

	MB_LED_Init();		// **マザーボード上のLED*2を初期化する
	MB_PushSW_Init();	// **マザーボード上のプッシュスイッチ*2を初期化する
	MB_RotarySW_Init();	// **マザーボード上のロータリースイッチを初期化する

	DIO0_Init(0x3F, DIO_MODE_OUT);	// 使い方は"01_DigitalIO.c"を参照

	/* ---------------------------------------------- */

	MB_LED_TurnOn(0);	// LED0を点灯させる
	MB_LED_TurnOff(1);	// LED1を消灯させる

	/* -------------	メインループ	------------- */
	while(1)
	{
		pushsw_status[0] = MB_PushSW_IsPushed(0);	// プッシュスイッチ0が押されている:1 else :0
		pushsw_status[1] = MB_PushSW_IsPushed(1);	// プッシュスイッチ1が押されている:1 else :0

		rotarysw_value = MB_RotarySW_Check();	// ロータリースイッチが示す値(0-15)

		MB_LED_Toggle(0);	// LED0の状態を反転させる
		MB_LED_Toggle(1);	// LED1の状態を反転させる

		/* プッシュスイッチの状態を出力する */
		DIO_OutputPin(0, 0, pushsw_status[0]);
		DIO_OutputPin(0, 1, pushsw_status[1]);
		
		/* ロータリースイッチの値を4bit値として出力する */
		if(rotarysw_value & 0x01)	DIO_OutputPin(0, 2, 1);
		else						DIO_OutputPin(0, 2, 0);
		if(rotarysw_value & 0x02)	DIO_OutputPin(0, 3, 1);
		else						DIO_OutputPin(0, 3, 0);
		if(rotarysw_value & 0x04)	DIO_OutputPin(0, 4, 1);
		else						DIO_OutputPin(0, 4, 0);
		if(rotarysw_value & 0x08)	DIO_OutputPin(0, 5, 1);
		else						DIO_OutputPin(0, 5, 0);

		delay_ms(50);
	}
	/* ---------------------------------------------- */

	return 0;
}
/******************************/
/* ↑↑　以上がサンプル　↑↑ */
/******************************/

#endif /* __02_MB__ */
