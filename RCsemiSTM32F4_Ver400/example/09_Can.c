/***************************************************************************
 *	@�t�@�C����		:	09_Can.c
 *	@�T�v		:	CAN_Test
 *	@�o�[�W����		:	0.0.1
 *	@�J����		: mugi
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver5, Coocox CoIDE
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
/* �����@�ȏオ�T���v���@���� */
/******************************/

#endif /* __09_Can__ */
