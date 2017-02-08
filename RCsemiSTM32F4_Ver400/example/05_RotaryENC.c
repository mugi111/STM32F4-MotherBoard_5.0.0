/***************************************************************************
 *	@ファイル名		:	05_RotaryENC.c
 *	@概要		:	ロータリーエンコーダのカウント数をデバッガを用いて観測する．
 *
 *					必要な処理はコメントの先頭に**がついていますので，
 *					必ず記入するようにしてください．
 *	@バージョン		:	2.0.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver3, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __05_ROTARYENC__

/******************************/
/* ↓↓　以下がサンプル　↓↓ */
/******************************/
#include <stm32f4xx.h>	// **最初にインクルードする
#include "rotary_encoder.h"	// **インクルードする

#include <stdio.h>	// 結果確認用

int main(void)
{
	/* -------------	変数宣言	----------------- */

	/* ---------------------------------------------- */

	/* -----------------	初期化	----------------- */
	SystemCoreClockUpdate();	// **最初に呼び出す
	ENC0_Init();
	ENC1_Init();
	ENC2_Init();

	/* ---------------------------------------------- */

	/* -------------	メインループ	------------- */
	while(1)
	{
		printf("%5d %5d %5d\n", ENC0_CheckCNT(), ENC1_CheckCNT(), ENC2_CheckCNT());
	}
	/* ---------------------------------------------- */

	return 0;
}
/******************************/
/* ↑↑　以上がサンプル　↑↑ */
/******************************/

#endif /* __05_ROTARYENC__ */
