/***************************************************************************
 *	@ファイル名		:	04_PSpad.c
 *	@概要		:	PSコントローラを使ったプログラムのひな型．
 *						これをコピペすると簡単なロボットの基盤になります
 *
 *					必要な処理はコメントの先頭に**がついていますので，
 *					必ず記入するようにしてください．
 *	@バージョン		:	3.0.0
 *	@開発者			:	キネクト
 *	@Ver3.0.0移行	:	むぎ
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver4, MB_Ver5, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __04_PSPAD__

/******************************/
/* ↓↓　以下がサンプル　↓↓ */
/******************************/
#include <stm32f4xx.h>	// **最初にインクルードする
#include "usart.h"	// **インクルードする
#include "pspad.h"	// **インクルードする


int main(void)
{
	/* -------------	変数宣言	----------------- */
	psdata_format_t psdata;	// **PSコントローラから受信したデータが格納される

	/* ---------------------------------------------- */

	/* -----------------	初期化	----------------- */
	SystemCoreClockUpdate();	// **最初に呼び出す

	TIM7_CMT_Init();	// **タイムアウト処理に必要
	
	Bluetooth_USART_Init(BT_BAUDRATE);	// **通信用のピンをUSARTとして初期化する
	Bluetooth_BDSlave_Init(0);	// **コントローラに対してマザーボード側をスレーブとみて初期化する

	/* ---------------------------------------------- */

	/* -------------	メインループ	------------- */
	while(1)
	{
#if defined(PSPAD_WIRE)	// 有線
		Modular_PSdata_Recv(&psdata);	// **コントローラの状態を受信する

#elif defined(PSPAD_WIRELESS)	// **コントローラの状態を受信する
		Bluetooth_PSdata_Recv(&psdata);
#endif

		if(PS_B_R1(psdata))				/* R1押下時にやるべきことを書く */;
		if(PS_B_R2(psdata))				/* R2押下時にやるべきことを書く */;
		if(PS_B_L1(psdata))				/* L1押下時にやるべきことを書く */;
		if(PS_B_L2(psdata))				/* L2押下時にやるべきことを書く */;
		if(PS_B_TRIANGLE(psdata))	/* △押下時にやるべきことを書く */;
		if(PS_B_CIRCLE(psdata))		/* ○押下時にやるべきことを書く */;
		if(PS_B_CROSS(psdata))		/* ×押下時にやるべきことを書く */;
		if(PS_B_SQUARE(psdata))		/* □押下時にやるべきことを書く */;
		if(PS_B_START(psdata))		/* START押下時にやるべきことを書く */;
		if(PS_B_SELECT(psdata))		/* SELECT押下時にやるべきことを書く */;
		if(PS_B_ARROW_U(psdata))	/* ↑押下時にやるべきことを書く */;
		if(PS_B_ARROW_R(psdata))	/* →押下時にやるべきことを書く */;
		if(PS_B_ARROW_D(psdata))	/* ↓押下時にやるべきことを書く */;
		if(PS_B_ARROW_L(psdata))	/* ←押下時にやるべきことを書く */;
		if(PS_B_STICK_R(psdata))	/* R3押下時にやるべきことを書く */;
		if(PS_B_STICK_L(psdata))	/* L3押下時にやるべきことを書く */;	

		// 右スティックのX軸成分によって処理を分ける
		// PS_STICK_RX(psdata)は0~15の値を表すが，
		// 数値変化がスティックの位置と比例しないため
		// gPSStick_convertTableによって-2~2の安定的な数値変化
		// へ変換できる
		switch(gPSStick_convertTable[PS_STICK_RX(psdata)])
		{
			case -2:
				/* スティックが左いっぱいに倒されたときにやるべきことを書く */
				break;
			case -1:
				/* やるべきことを書く */
				break;
			case  0:
				/* スティックが左右方向で中央のときにやるべきことを書く */
				break;
			case  1:
				/* やるべきことを書く */
				break;
			case  2:
				/* スティックが右いっぱいに倒されたときにやるべきことを書く */
				break;
		}
		
		// 右スティックのY軸成分によって処理を分ける
		// PS_STICK_RY(psdata)は0~15の値を表すが，
		// 数値変化がスティックの位置と比例しないため
		// gPSStick_convertTableによって-2~2の安定的な数値変化
		// へ変換できる
		switch(gPSStick_convertTable[PS_STICK_RY(psdata)])
		{
			case -2:
				/* スティックが左いっぱいに倒されたときにやるべきことを書く */
				break;
			case -1:
				/* やるべきことを書く */
				break;
			case  0:
				/* スティックが左右方向で中央のときにやるべきことを書く */
				break;
			case  1:
				/* やるべきことを書く */
				break;
			case  2:
				/* スティックが右いっぱいに倒されたときにやるべきことを書く */
				break;
		}
		
		// 左スティックのX軸成分によって処理を分ける
		// PS_STICK_LX(psdata)は0~15の値を表すが，
		// 数値変化がスティックの位置と比例しないため
		// gPSStick_convertTableによって-2~2の安定的な数値変化
		// へ変換できる
		switch(gPSStick_convertTable[PS_STICK_LX(psdata)])
		{
			case -2:
				/* スティックが左いっぱいに倒されたときにやるべきことを書く */
				break;
			case -1:
				/* やるべきことを書く */
				break;
			case  0:
				/* スティックが左右方向で中央のときにやるべきことを書く */
				break;
			case  1:
				/* やるべきことを書く */
				break;
			case  2:
				/* スティックが右いっぱいに倒されたときにやるべきことを書く */
				break;
		}
		
		// 左スティックのY軸成分によって処理を分ける
		// PS_STICK_LY(psdata)は0~15の値を表すが，
		// 数値変化がスティックの位置と比例しないため
		// gPSStick_convertTableによって-2~2の安定的な数値変化
		// へ変換できる
		switch(gPSStick_convertTable[PS_STICK_LY(psdata)])
		{
			case -2:
				/* スティックが左いっぱいに倒されたときにやるべきことを書く */
				break;
			case -1:
				/* やるべきことを書く */
				break;
			case  0:
				/* スティックが左右方向で中央のときにやるべきことを書く */
				break;
			case  1:
				/* やるべきことを書く */
				break;
			case  2:
				/* スティックが右いっぱいに倒されたときにやるべきことを書く */
				break;
		}
	}
	/* ---------------------------------------------- */

	return 0;
}
/******************************/
/* ↑↑　以上がサンプル　↑↑ */
/******************************/

#endif /* __04_PSPAD__ */
