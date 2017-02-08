/***************************************************************************
 *	@ファイル名		:	motor.c
 *	@概要		:	DIGITAL-IOポートでモータを制御するためのPWM初期化と動作を行う．
 *					標準のモータドライバを使うことを想定している．
 *	@バージョン		:	2.0.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver3, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "motor.h"
#include "digitalIO.h"

_motor_status_t gMotor_status[3] = {{{0}}};

/* デューティ比を回転を表す2bitに変換する */
#define DUTY_TO_DIR(duty) ((duty) == BRAKEVALUE	? 0x03 : \
						   (duty) < 0			? 0x02 : \
						   (duty) > 0	 		? 0x01 : 0x00)

/* 絶対値を求める */
#define ABS_VAL(val) ((val) < 0 ? -(val) : (val))

/* 貫通電流が発生するパターンかを判別する */
#define IS_SHORTCURRENT_PATTERN(dir_now, dir_old)	((dir_now) != (dir_old) && (dir_now) && (dir_old))

/* -------------------------------------------------
 * @関数名			:	MotorDriver_Init
 * @概要				:	モータポートの初期化をするが，
 * 						出力設定などはDigitalIO_Initを
 * 						使用すること．
 * @引数-enable_bits	:	12bitでモータポートを使用するか否かを
 * 						決定します．1:有効/0:無効
 * @戻り値			:	なし
 * ---------------------------------------------- */
void MotorDriver_Init(u16 enable_bits)
{
	int i;
	for(i = 0; i < 12; i++)
	{
		if(enable_bits & (1<<i))	gMotor_status[i>>2].isEnable[i&3] = 1;
		else						gMotor_status[i>>2].isEnable[i&3] = 0;
	}
}

/* -------------------------------------------------
 * @関数名		:	Motor_Drive
 * @概要			:	モータポートからPWMを出力する
 * 					Digital-IOを出力設定してから呼び出すこと
 * @引数-ch		:	出力するチャンネル番号、0からの通し番号
 *　          -duty	:	dutyの値、ただし
 *　          				正の値は正転、負の値は逆転、
 *　          				BRAKEVALUEはショートブレーキを示す．
 * @戻り値		:	なし
 * ---------------------------------------------- */
void Motor_Drive(u8 ch, short duty)
{
	u8 port = ch>>2;	// 0:0-3 / 1:4-7
	ch &= 0x02; 		// 0-2に制限

	u8 dir_now = DUTY_TO_DIR(duty);
	u8 dir_old = gMotor_status[port].dir_old[ch];

	if(gMotor_status[port].isEnable[ch])	gMotor_status[port].duty[ch] = ABS_VAL(duty);
	else									gMotor_status[port].duty[ch] = 0;

	/****************************	貫通電流対策	***********************************/
	if(gMotor_status[port].deadtime[ch])
	{
		if(IS_SHORTCURRENT_PATTERN(dir_now, dir_old))
		{
			gMotor_status[port].dir_save[ch] = dir_now;
		}
		else
		{
			gMotor_status[port].deadtime[ch] = 0;
			gMotor_status[port].dir		[ch] = dir_now;
			gMotor_status[port].dir_old [ch] = dir_now;
		}
	}
	else
	{
		if(IS_SHORTCURRENT_PATTERN(dir_now, dir_old))
		{
			gMotor_status[port].deadtime[ch] = MOTOR_DEADTIME_10US;
			gMotor_status[port].dir		[ch] = 0;
			gMotor_status[port].dir_save[ch] = dir_now;
		}
		else
		{
			gMotor_status[port].dir	   [ch] = dir_now;
			gMotor_status[port].dir_old[ch] = dir_now;
		}
	}
	/******************************************************************************/
}
