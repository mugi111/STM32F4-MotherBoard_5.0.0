/***************************************************************************
 *	@ファイル名		:	09_Can.c
 *	@概要		:	CAN_Test
 *	@バージョン		:	0.0.1
 *	@開発者		: mugi
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver5, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __09_CAN__

#include <stm32f4xx.h>
#include "can.h"
#include "timer.h"
#include "motherboard.h"

int main(void)
{
	SystemCoreClockUpdate();

//	u8 pushSW_State = 0;
	u8 InitSuccess = 0;
	u8 buff[8] = {1, 1, 1, 1, 1, 0, 0, 0};

	CanRxMsg RxMsg;


	MB_LED_Init();
	InitSuccess = CanInit();
	MB_PushSW_Init();
	MB_LED_TurnOn();
	FilterConfig();
    RxMsg.StdId = 0x00;
    RxMsg.IDE = CAN_ID_STD;
    RxMsg.DLC = 0;
    RxMsg.Data[0] = 0x00;
    RxMsg.Data[1] = 0x00;
	MB_LED_TurnOff();
	while(1)
	{
		MB_LED_TurnOff();
		if(InitSuccess == CAN_InitStatus_Success){
			CanSendFrame(0, 0, buff, 5, CAN_RTR_DATA);
			if(CAN_TSR_TXOK0)	MB_LED_TurnOn();
		}
		CAN_Receive(CAN1, CAN_FIFO0, &RxMsg);

//		delay_ms(1000);
	}
}


/******************************/
/* ↑↑　以上がサンプル　↑↑ */
/******************************/

#endif /* __09_Can__ */
