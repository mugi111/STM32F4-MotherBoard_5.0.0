 /***************************************************************************
 *	@ファイル名		:	01_DigitalIO.c
 *	@概要		:	本サンプルはDigitalIOポートの入出力をします．
 *
 *					必要な処理はコメントの先頭に**がついていますので，
 *					必ず記入するようにしてください．
 *	@バージョン		:	3.0.0
 *	@開発者			:	キネクト
 *	@Ver3.0.0移行	:	むぎ
 *	@使用環境		:	STM32F407VG, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __01_DIGITALIO__

/******************************/
/* ↓↓　以下がサンプル　↓↓ */
/******************************/
#include <stm32f4xx.h>	// **最初にインクルードする
#include "digitalIO.h"	// **インクルードする

#include "timer.h"	// delayを使うために必要になる

int main(void)
{
	/* -------------	変数宣言	----------------- */
	int status[8];

	/* ---------------------------------------------- */

	/* -----------------	初期化	----------------- */
	SystemCoreClockUpdate();	// **最初に呼び出す

	TIM7_CMT_Init();	// delay関数を利用するための初期化

	DIO0_Init(0xFF, DIO_MODE_IN);		// **DIO0のすべてのピンを入力として初期化する．
	
	DIO1_Init(0xFF, DIO_MODE_OUT);		// **DIO1のすべてのピンを出力として初期化する．

	/* ---------------------------------------------- */

	/* -------------	メインループ	------------- */
	while(1)
	{
		status[0] = DIO_CheckPin(0, 0);	// DIO0-0の状態を読み取る
		status[1] = DIO_CheckPin(0, 1);	// DIO0-1の状態を読み取る
		status[2] = DIO_CheckPin(0, 2);	// DIO0-2の状態を読み取る
		status[3] = DIO_CheckPin(0, 3);	// DIO0-3の状態を読み取る
		status[4] = DIO_CheckPin(0, 4);	// DIO0-4の状態を読み取る
		status[5] = DIO_CheckPin(0, 5);	// DIO0-5の状態を読み取る
		status[6] = DIO_CheckPin(0, 6);	// DIO0-6の状態を読み取る
		status[7] = DIO_CheckPin(0, 7);	// DIO0-7の状態を読み取る
		
		DIO_OutputPin(1, 0, status[0]);	// 入力信号0をDIO1-0の出力に反映させる．
		DIO_OutputPin(1, 1, status[1]);	// 入力信号1をDIO1-1の出力に反映させる．
		DIO_OutputPin(1, 2, status[2]);	// 入力信号2をDIO1-2の出力に反映させる．
		DIO_OutputPin(1, 3, status[3]);	// 入力信号3をDIO1-3の出力に反映させる．
		DIO_OutputPin(1, 4, status[4]);	// 入力信号4をDIO1-4の出力に反映させる．
		DIO_OutputPin(1, 5, status[5]);	// 入力信号5をDIO1-5の出力に反映させる．
		DIO_OutputPin(1, 6, status[6]);	// 入力信号6をDIO1-6の出力に反映させる．
		DIO_OutputPin(1, 7, status[7]);	// 入力信号7をDIO1-7の出力に反映させる．

		delay_ms(100);
	}
	/* ---------------------------------------------- */

	return 0;
}
/******************************/
/* ↑↑　以上がサンプル　↑↑ */
/******************************/

#endif /* __01_DIGITALIO__ */
