/***************************************************************************
 *	@ファイル名		:	07_Terunet.c
 *	@概要		:	Terunet
 *
 *					必要な処理はコメントの先頭に**がついていますので，
 *					必ず記入するようにしてください．
 *	@バージョン		:	0.0.1
 *	@開発者		:
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __09_CAN__

#include <stm32f4xx.h>
#include "can.h"
#include "timer.h"
#include "motherboard.h"

int main(void)
{
	MB_PushSW_Init();
	MB_LED_Init();
	can_init();

	while(1)
	{
		send_frame();

//			MB_LED_Toggle(0);	// LED0の状態を反転させる
//			MB_LED_Toggle(1);	// LED1の状態を反転させる

//		delay_ms(1);
	}
}




/******************************/
/* ↑↑　以上がサンプル　↑↑ */
/******************************/

#endif /* __09_Can__ */
