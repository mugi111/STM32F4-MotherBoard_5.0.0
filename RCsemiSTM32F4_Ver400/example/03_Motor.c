/***************************************************************************
 *	@ファイル名		:	03_Motor.c
 *	@概要		:	DigitalIOポートからモータドライバを利用する．
 *
 *					必要な処理はコメントの先頭に**がついていますので，
 *					必ず記入するようにしてください．
 *	@バージョン		:	2.0.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver3, MB_Ver4, MB_Ver5, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __03_MOTOR__

/******************************/
/* ↓↓　以下がサンプル　↓↓ */
/******************************/
#include <stm32f4xx.h>	// **最初にインクルードする
#include "digitalIO.h"	// **インクルードする
#include "motor.h"	// **インクルードする
#include "timer.h"	// **インクルードする

#include "motherboard.h"	// 出力変化用

int main(void)
{
	/* -------------	変数宣言	----------------- */
	int rotarysw_value;

	/* ---------------------------------------------- */

	/* -----------------	初期化	----------------- */
	SystemCoreClockUpdate();	// **最初に呼び出す

	DIO0_Init(0xFF, DIO_MODE_OUT);	// **モータポートはDIOなので，初期化が必要．使い方は"01_DigitalIO.c"を参照
	DIO1_Init(0xFF, DIO_MODE_OUT);	// **モータポートはDIOなので，初期化が必要．使い方は"01_DigitalIO.c"を参照

	MotorDriver_Init(0xF0);	// **モータポートに対応するビットを1にすることで初期化される．
														// **この場合，MOTOR0-3, 8-11をモータポートとして初期化する．
														// **設定されていないMOTOR4-7はDigitalIOとして利用可能である．

	TIM7_CMT_Init();	// **PWM生成用，duty比100%であったとしても必要になる．

	MB_RotarySW_Init();	// 出力変化用

	/* ---------------------------------------------- */

	/* -------------	メインループ	------------- */
	while(1)
	{
		rotarysw_value = MB_RotarySW_Check();	// ロータリースイッチが示す値

		/* 指定されたduty比が出力される */
		Motor_Drive(0, rotarysw_value);
		Motor_Drive(1, rotarysw_value * 2);
		Motor_Drive(2, rotarysw_value * 3);
		Motor_Drive(3, rotarysw_value * 6);

		Motor_Drive(8, -rotarysw_value * 3);
		Motor_Drive(9, -rotarysw_value * 6);
		Motor_Drive(10, BRAKEVALUE);	// ショートブレーキ
		Motor_Drive(11, BRAKEVALUE);	// ショートブレーキ
		
		/* ↓↓　これはモータポートとして初期化したためやってはいけない　↓↓ */
		/*
		DIO_OutputPin(0, 0, 1);
		DIO_OutputPin(0, 1);
		DIO_OutputPin(0, 2, 1);
		DIO_OutputPin(0, 3, 1);
		...etc
		*/
		
		/* ↓↓　これはモータポートとして設定していないのでOK　↓↓ */
		DIO_OutputPin(1, 0, 1);
		DIO_OutputPin(1, 1, 0);
		DIO_OutputPin(1, 2, 1);
		DIO_OutputPin(1, 3, 0);
		DIO_OutputPin(1, 4, 1);
		DIO_OutputPin(1, 5, 0);
		DIO_OutputPin(1, 6, 1);
		DIO_OutputPin(1, 7, 0);
	}
	/* ---------------------------------------------- */

	return 0;
}
/******************************/
/* ↑↑　以上がサンプル　↑↑ */
/******************************/

#endif /* __03_MOTOR__ */
