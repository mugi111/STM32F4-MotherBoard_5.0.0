/***************************************************************************
 *	@ファイル名		:	terunet.c
 *	@概要		:	terunet通信の送受信関数を提供する．
 *
 *					通信の大まかな方法は以下の通り，
 *
 *					(1)Master側からSendFrameを用いて，
 *					　　 ・ダミーデータ
 *					　　 ・送信先アドレス
 *					　　 ・送信コマンド
 *					　　 ・送信データ数(バイト)
 *					　　 ・送信データ
 *					　　 ・チェックサム
 *					  　 を送信する．
 *					(2)Slave側からReceiveFrameを用いて，
 *					　　 ・コマンド
 *					　　 ・データ数(バイト)
 *					　　 ・データ
 *					　　 ・チェックサム
 *					　　を受信する．
 * ------------------------------Terunet通信データ送信プロトコル ------------------------------------
 *　・9bitシリアル通信のプロトコル名は"Terunet"とする．
 * ・9bitシリアル通信により，アドレスとデータを区別する．9bit目がHIGHの場合はアドレス，LOWの場合はデータとする．
 * ・9bitシリアル通信は，パリティビットを強制的に操作することで実現するため，ほとんどのUARTで実装できる．
 *
 * 次に示すフレーム単位で通信を行う．
 * +------------+---------+---------+-------------+---------+----------+
 * | Dummy byte | Address | Command | Data length | Data... | CheckSum |
 * +------------+---------+---------+-------------+---------+----------+
 *
 * (1)先頭のDummy byteは，RS485の通信ラインがひとつしかないため送信・受信をトランシーバIC(LTC485など)で切り替える際の
 *    切り替えに若干時間がかかるため，最初のデータを欠落する恐れがある.よってdummyを送信するというものである．Dummy byte
 *    は0xffで統一する．
 * (2)Addressは上位4bitsを機能別アドレス，下位4bitsをナンバーとする．
 * (3)Commandは1byteのコマンドデータである．これで，通信しているデータの種類が判別できる．
 * (4)Data lengthはそのあとに続くDataの総数を1byteに格納する．したがって最大送信データ数は255[byte]である．
 *    ただし，CheckSumの1byteはデータ数に含まないとする．
 * (5)Dataには送信したいデータをData lengthで指定したバイト数だけ格納する．
 * (6)CheckSumには，CommandからDataの終端までの総和の下位8bitを格納する．
 *
 * 注意
 * ・ロボットのメインマイコンがマスター(アドレス0x00)，モータードライバなどの各基板がスレーブとなり通信する．
 * ・マスターだけが自由に通信開始をすることができ，スレーブは自分のアドレスのフレームを受信したときのみ一度だけ通信を開始できる．
 * ・CheckSumが一致しなかったときは，データを破棄する．フレームの再送はプロトコルでは定義しない．
 * ----------------------------------------------------------------------------------------
 *	@バージョン		:	3.0.0
 *	@開発者			:	佐藤輝一
 *					:	太田那菜
 *					:	キネクト
 *	@Ver3.0.0移行	:	むぎ
 *	@使用環境		:	STM32F407VG, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "timer.h"
#include "terunet.h"

/* -------------------------------------------------
 * @関数名		:	Terunet_Init
 * @概要			:	Terunet(USART4)の初期化
 * @引数-baud	:	Terunet通信のボーレート
 * @戻り値		:	なし
 * ---------------------------------------------- */
void Terunet_Init(int baud)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	USART_InitStructure.USART_BaudRate = baud * (SystemCoreClock / 168000000);
	USART_InitStructure.USART_WordLength = USART_WordLength_9b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_UART4);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_UART4);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_Init(UART4, &USART_InitStructure);
	USART_Cmd(UART4, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	GPIOE->BSRRH = GPIO_Pin_4;
}

/* ------------------------------------------------
 * @関数名	:	Terunet_ReceiveData
 * @概要		:	Terunet(USART4)から1[Byte]受け取る
 * @引数		:	受信データ格納先
 * @戻り値	:	成功:0 / 失敗:-1
 * --------------------------------------------- */
int	Terunet_ReceiveData(u16* recvData)
{
	GPIOE->BSRRH = GPIO_Pin_4;		// 通信を入力に設定

	int time0 = SystemTimer_ms_Check();
	while(USART_GetFlagStatus(UART4, USART_FLAG_RXNE) == RESET)
	{
		if(SystemTimer_ms_Check()-time0 > TERUNET_RECV_TIMEOUT_MS)
		{
			return -1;
		}
	}

	*recvData = USART_ReceiveData(UART4);

	return 0;
}

/* ------------------------------------------------
 * @関数名			:	Terunet_FrameReceive
 * @概要				:	Terunet(USART4)から1フレームを受信し、
 * 						解析後、受信データをバッファに格納する
 * @引数	-recvData	:	受信データを格納するバッファ
 * 		-cmd		:	通信コマンド
 * @戻り値			:	受信したデータが正しいかどうか
 * --------------------------------------------- */
int Terunet_ReceiveFrame (u8 recvData[], u8 cmd)
{
	u16 buff;
	u8 dataLength;
	u8 checkSum = 0x00;
	int time0 = SystemTimer_ms_Check();
	int i;

	/* address	------------------------ */
	do
	{
		Terunet_ReceiveData(&buff);
		if(SystemTimer_ms_Check()-time0 > TERUNET_RECV_TIMEOUT_MS)
		{
			return -1;
		}
	}
	while(buff != (TERUNET_MYADDRESS | 0x100));
	/* --------------------------------- */

	/* cmd	---------------------------- */
	Terunet_ReceiveData(&buff);
	if(cmd != buff)	return -1;
	checkSum += buff;
	/* --------------------------------- */

	/* data length	-------------------- */
	Terunet_ReceiveData(&buff);
	checkSum += buff;
	dataLength = (u8)buff;
	/* --------------------------------- */

	/* data	---------------------------- */
	for(i = 0; i < dataLength; i++)
	{
		Terunet_ReceiveData(&buff);
		recvData[i] = (u8)buff;
		checkSum += recvData[i];
	}
	/* --------------------------------- */

	/* checksum	------------------------ */
	Terunet_ReceiveData(&buff);
	if(buff != checkSum)	return -1;
	/* --------------------------------- */

	return 0;
}
/* -----------------------------------------------
 * @関数名		:	Terunet_SendData
 * @概要			:	Terunet(USART4)に1[Byte]送信する
 * @引数-data	:	送信するデータ
 * @戻り値		:	なし
 * ------------------------------------------- */
void Terunet_SendData(u8 data)
{
	GPIOE->BSRRL = GPIO_Pin_4;		// 通信を出力に設定
	USART_SendData(UART4, data);
	while(USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET);
}

/* ----------------------------------------------
 * @関数名		:	Terunet_SendAddr
 * @概要			:	Terunet(USART4)にアドレスを送信する
 * @引数-addr	:	送信するアドレス
 * @戻り値		:	なし
 * ------------------------------------------- */
void Terunet_SendAddr(u8 addr)
{
	GPIOE->BSRRL = GPIO_Pin_4;		// 通信を出力に設定
	USART_SendData(UART4, addr|0x100);
	while(USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET);
}

/* ----------------------------------------------
 * @関数名		:	Terunet_SendFrame
 * @概要			:	Terunet(USART4)にデータフレームを送信する
 * @引数			:	送り先のアドレス, 使いたい機能のコマンド,
 * 					data length, data(配列)
 * @戻り値		:	なし
 * ------------------------------------------- */
void Terunet_SendFrame(u8 slaveAddr, u8 cmd, u8 dataLength, const u8 data[])
{
	u8 checkSum = 0x00;
	int i;

	Terunet_SendData(0xFF);		//DummyData
	Terunet_SendAddr(slaveAddr);
	Terunet_SendData(cmd);
	Terunet_SendData(dataLength);

	for(i = 0; i < dataLength; i++)
	{
		Terunet_SendData(data[i]);
		checkSum += data[i];
	}

	checkSum += cmd + dataLength;
	Terunet_SendData(checkSum);
}
