/***************************************************************************
 *	@ファイル名		:	pspad.h
 *	@概要		:	BluetoothにおけるPSコントローラとの通信を
 *					提供する．
 *	@バージョン		:	3.0.0
 *	@開発者			:	キネクト
 *	@Ver3.0.0移行	:	むぎ
 *	@使用環境		:	STM32F407VG, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#ifndef __PSPAD_H__
#define __PSPAD_H__

/* 型定義	============================================================= */
typedef union
{
    struct
    {
        u8 d1			: 1; /*ここまで第0バイト*/
        u8 LStick		: 1; /*左スティック押し下げ*/
        u8 L2			: 1;
        u8 L1			: 1;
        u8 UpArrow		: 1; /*左側の上矢印*/
        u8 RightArrow	: 1; /*左側の右矢印*/
        u8 DownArrow	: 1; /*左側の下矢印*/
        u8 LeftArrow	: 1; /*左側の左矢印*/
        u8 d2			: 1; /*ここまで第1バイト*/
        u8 RStick		: 1; /*右スティック押し下げ*/
        u8 R2			: 1;
        u8 R1			: 1;
        u8 Triangle		: 1; /*右側の△ボタン*/
        u8 Circle		: 1; /*右側の○ボタン*/
        u8 Cross		: 1; /*右側の×ボタン*/
        u8 Square		: 1; /*右側の□ボタン*/
        u8 d3			: 1; /*ここまで第2バイト*/
        u8 Start		: 1; /*Startボタン*/
        u8 dd3			: 2;
        u8 RStick_X		: 4;
        u8 d4			: 1; /*ここまで第3バイト*/
        u8 Select		: 1; /*Selectボタン*/
        u8 dd4			: 2;
        u8 RStick_Y		: 4;
        u8 d5			: 1; /*ここまで第4バイト*/
        u8 Mode			: 1; /*モード　アナログ：0　ディジタル：1*/
        u8 dd5			: 2;
        u8 LStick_X		: 4;
        u8 d6			: 1; /*ここまで第5バイト*/
        u8 Error		: 1; /*受信時のエラー　エラー：1　正常：0*/
        u8 dd6			: 2;
        u8 LStick_Y		: 4;
        u8 CheckSum;    	 /*チェックサム＋１を作る*/
    } name;
    u8 bytes[7];
} psdata_format_t;

/* 定数定義	============================================================= */
#define PS_RECV_TIMEOUT_MS	100

/* キーコンフィグ */
#define PS_B_R1(ps)			((ps).name.R1)
#define PS_B_R2(ps)			((ps).name.R2)
#define PS_B_L1(ps)			((ps).name.L1)
#define PS_B_L2(ps)			((ps).name.L2)
#define PS_B_TRIANGLE(ps)	((ps).name.Triangle)
#define PS_B_CIRCLE(ps)		((ps).name.Circle)
#define PS_B_CROSS(ps)		((ps).name.Cross)
#define PS_B_SQUARE(ps)		((ps).name.Square)
#define PS_B_START(ps)		((ps).name.Start)
#define PS_B_SELECT(ps)		((ps).name.Select)
#define PS_B_ARROW_U(ps)	((ps).name.UpArrow)
#define PS_B_ARROW_R(ps)	((ps).name.RightArrow)
#define PS_B_ARROW_D(ps)	((ps).name.DownArrow)
#define PS_B_ARROW_L(ps)	((ps).name.LeftArrow)
#define PS_B_STICK_R(ps)		((ps).name.RStick)
#define PS_B_STICK_L(ps)		((ps).name.LStick)
#define PS_STICK_RX(ps)		((ps).name.RStick_X)
#define PS_STICK_RY(ps)		((ps).name.RStick_Y)
#define PS_STICK_LX(ps)		((ps).name.LStick_X)
#define PS_STICK_LY(ps)		((ps).name.LStick_Y)

/* 変数プロトタイプ宣言	===================================================== */
/* PS_STICKの値を-2から2の整数値へと変換する．スティック傾き誤差を吸収できる */
extern const int gPSStick_convertTable[16];

/* 関数プロトタイプ宣言	===================================================== */
/* -------------------------------------------------
 * @関数名		:	Bluetooth_BDMaster_Init
 * @概要			:	Bluetooth(Bluetooth)との通信で
 * 					自分をマスターとして初期化
 * @引数-command	:	初期化時に自動返信する文字列
 * @戻り値		:	なし
 * ---------------------------------------------- */
void Bluetooth_BDMaster_Init(char *command);

/* -------------------------------------------------
 * @関数名		:	Bluetooth_BDSlave_Init
 * @概要			:	Bluetooth(Bluetooth)との通信で
 * 					自分をスレーブとして初期化
 * @引数-command	:	初期化時に自動返信する文字列
 * @戻り値		:	なし
 * ---------------------------------------------- */
void Bluetooth_BDSlave_Init(char *command);

/* -------------------------------------------------
 * @関数名		:	Bluetooth_PSdata_Recv
 * @概要			:	Bluetooth(電話線)から
 * 					PSコントローラのデータを受信する．
 * @引数-psdata	:	コントローラデータ格納先の変数
 * @戻り値		:	なし
 * ---------------------------------------------- */
void Bluetooth_PSdata_Recv(psdata_format_t *psdata);


#endif /* __PSPAD_H__ */
