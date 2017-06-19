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

	MB_LED_Init();
	MB_PushSW_Init();
	InitSuccess = CanInit();
	MB_LED_TurnOn();

	while(1)
	{
		if(InitSuccess == CAN_InitStatus_Success){
			SendFrame(0, 0, 0, 0);
			MB_LED_TurnOff();
		}
	}
}


/******************************/
/* ↑↑　以上がサンプル　↑↑ */
/******************************/

#endif /* __09_Can__ */
