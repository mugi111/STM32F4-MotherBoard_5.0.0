/***************************************************************************
 *	@ファイル名		:	rs485_master.h
 *	@概要		:	LANポート通信におけるマスター側の機能を提供する．
 *					通信の大まかな方法は以下の通り，
 *
 *					(1)Master側からSendFrameを用いて、
 *					　　 ・ダミーデータ
 *					　　 ・送信先アドレス
 *					　　 ・送信コマンド
 *					　　 ・送信データ数(バイト)
 *					　　 ・送信データ
 *					　　 ・チェックサム
 *					  　 を送信する
 *					(2)Slave側からのデータをReceiveFrameを用いて受信する
 * ------------------------------RS485通信データ送信プロトコル ------------------------------------
 * 9bitシリアル通信により，アドレスとデータを区別する．アドレスは9bit目がhigh，データはlowとする．
 * 9bitシリアル通信は，パリティビットを強制的に操作することで，ほとんどのUARTで実装できる．
 * 次に示すフレーム単位で通信を行う．
 * +------------+---------+---------+-------------+---------+----------+
 * | Dummy byte | Address | Command | Data length | Data... | CheckSum |
 * +------------+---------+---------+-------------+---------+----------+
 * (1)先頭のDummy byteは，RS485の通信ラインがひとつしかないため送信・受信をトランシーバIC(LTC485)で切り替える際に
 * 切り替えに若干時間がかかるため，最初のデータは欠落する恐れがある.よってdummyを送信するというものである．Dummy byte
 * は0xffで統一する．
 * (2)Addressは上位4bitsを機能別アドレス，下位4bitsをナンバーとする．ナンバーは，接続するスレーブが基板上のスイッチ
 * などで切り替えることのできるものとする．
 * (3)Commandは1byteのコマンドデータである．
 * (4)Data lengthはそのあとに続くDataの総数を1byteに格納する．したがって最大送信データは255bytesである．
 * CheckSumの1byteは含まない．
 * (5)Dataには送信したいデータを格納する．
 * (6)CheckSumには，AddressからDataまでの全ての和をとり，下位8bitsを格納する．
 * 注意
 * ・ロボットのメインマイコンがマスター(アドレス0x00)，モータードライバなどの各基板がスレーブとなり通信する
 * ・マスターだけが自由に通信開始をすることができ，スレーブは自分のアドレスのフレームを受信したときのみ一度だけ通信を開始できる．
 * ・CheckSumが一致しなかったときは，データを破棄する．フレームの再送はプロトコルでは定義しない．
 * ・LPC側のタイムアウト時間は10msとする．STM側のタイムアウト時間は1msとしている.
 * ----------------------------------------------------------------------------------------

 *	@バージョン		:	1.1.0
 *	@開発者		:	佐藤輝一
 *				:	キネクト
 *				:	太田那菜
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver2, Coocox CoIDE
 **************************************************************************/

#ifndef __RS485_MASTER_H__
#define __RS485_MASTER_H__

#define RS485_BAUDRATE	115200

typedef enum {
//
	RS485_Req_Response = 0x01,
	RS485_ReadDeviceID,
	RS485_ReadDeviceDescription,
	RS485_ReadFrameDescription,
	RS485_ReadSystemVer,
// MotorDriver
	RS485_SetMotorPWM,
	RS485_ReadMotorCurrent,
	RS485_ReadMotorVoltage,
// Sensor value
	RS485_ReadSensorValue,
// IO Port
	RS485_WriteIOPort,
	RS485_WriteIOPortOR,
	RS485_WriteIOPortAND,
	RS485_WriteIOPortXOR,
	RS485_ReadIOPort,
// ServoMotor
	RS485_SetServoPulse,
// Display
	RS485_SetDisplayPos,
	RS485_WriteDisplayString,
// Undefined device
	RS485_WriteData,
	RS485_ReadData,
	RS485_SetSingleMotorPWM,
} eRS485_list_t;

/* MotorDriver */
#define RS485_BASEADDR_MD		0xD0
/* ADC */
#define RS485_BASEADDR_ADC		0xA0
/* Other device */
#define RS485_BASEADDR_OTHER	0xE0
/* brake value */
#define RS485_BRAKEVALUE		32099

/* -------------------------------------------------
 * @関数名			:	RS485_Motor_Drive
 * @概要				:	RS485でモータドライバにchとdutyを
 * 						送信する
 * @引数-addr		:	送信先のアドレス
 *　          -ch			:	モータ番号
 *　          -value		:	PWMの値
 *　          -recvData	:	受信データ
 * @戻り値			:	通信成功:0 / 失敗:-1
 * ---------------------------------------------- */
int RS485_Motor_Drive(u8 addr, u8 ch, int duty, u8 recvData[]);

int RS485_fastMotor_Drive_LPC1(u8 ch, short int duty, u8 recvData[]);
int RS485_fastMotor_Drive_LPC2(u8 ch, short int duty, u8 recvData[]);

#endif /* __RS485_MASTER_H__ */
