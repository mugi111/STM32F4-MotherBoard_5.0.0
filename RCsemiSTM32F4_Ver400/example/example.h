/***************************************************************************
 *	@ファイル名		:	example.h
 *	@概要		:	実行するサンプルをコメントアウトからはずすと，サンプルが実行されます．
 *					コメントアウトを外すサンプルは一つにしないとコンパイルエラーが発生します．
 *					以下に各サンプルの概要を示します．
 *
 *					[00_Model.c]		:	すべてのひな形を示すサンプルです．
 *											サンプル自体は何の動作もしません．
 *					[01_DigitalIO.c]	:	DigitalIOポートの入出力をします．
 *					[02_MotherBoard.c]	:	マザーボード上の各機能，LED*2，プッシュスイッチ*2，
 *											4ビットロータリースイッチを動作させる．
 *											結果はDigitalIOの出力で確認する
 *					[03_Motor.c]		:	DigitalIOポートからモータドライバを利用する．
 *					[04_PSpad.c]		:	PSコントローラを使ってモータを制御する．
 *											簡単なロボットはこれを基にプログラムしていくとよい．
 *					[05_RotaryENC.c]	:
 *					[06_ADC.c]			:
 *					[07_Terunet.c]		:
 *
 *	@バージョン		:	2.0.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver3, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

//#define __00_MODEL__		1
//#define __01_DIGITALIO__	1
#define __02_MB__			1
//#define __03_MOTOR__		1
//#define __04_PSPAD__		1
//#define __05_ROTARYENC__	1
//#define __06_ADC__		1
//#define __07_TERUNET__	1
//#define __09_CAN__		1

//#define __08_TOUCH_PANEL__

#endif /* __EXAMPLE_H__ */
