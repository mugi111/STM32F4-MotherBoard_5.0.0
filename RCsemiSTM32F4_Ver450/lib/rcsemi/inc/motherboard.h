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

#ifndef __MB_H__
#define __MB_H__

/* 関数プロトタイプ宣言	===================================================== */
/* -------------------------------------------------
 * @関数名	:	MB_LED_Init
 * @概要		:	MB上LEDに接続されているGPIO(PA8, PA15)を
 * 				初期化します．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_Init(void);

/* -------------------------------------------------
 * @関数名	:	MB_LED_TurnOff
 * @概要		:	指定のLEDを消灯します．
 * @引数-num	:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_TurnOff();

/* -------------------------------------------------
 * @関数名	:	MB_LED_TurnOn
 * @概要		:	指定のLEDを点灯します．
 * @引数-num	:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_TurnOn();

/* -------------------------------------------------
 * @関数名	:	MB_LED_Toggle
 * @概要		:	指定のLEDを前回と違う状態にします．
 * @引数-num	:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_Toggle();

/* -------------------------------------------------
 * @関数名	:	MB_PushSW_Init
 * @概要		:	プッシュスイッチに接続されているGPIO(PB10)の
 * 				初期化をします．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_PushSW_Init();

/* -------------------------------------------------
 * @関数名	:	MB_PushSW_IsPushed
 * @概要		:	プッシュスイッチが押されたかどうか判定します．
 * @引数		:	プッシュスイッチの番号
 * @戻り値	:	押されたら1, そうでなければ0
 * ---------------------------------------------- */
int MB_PushSW_IsPushed();

/* -------------------------------------------------
 * @関数名	:	MB_RotarySW_Init
 * @概要		:	ロータリースイッチに接続されている
 * 				GPIO(PC10, PC12, PE0, PE1)の初期化をします．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_RotarySW_Init(void);

/* -------------------------------------------------
 * @関数名	:	MB_RotarySW_Check
 * @概要		:	ロータリースイッチが示す値(0-15)を判別します．
 * @引数		:	なし
 * @戻り値	:	ロータリースイッチの値(0-15)
 * ---------------------------------------------- */
unsigned int MB_RotarySW_Check(void);

#endif /* __MB_H__ */
