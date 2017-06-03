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

	MB_LED_Init();
	MB_PushSW_Init();
	CanInit();

	while(1)
	{
		if(MB_PushSW_IsPushed()){
			MB_LED_Toggle();
			SendFrame(0, 0, 0, 0);
		}
	}
}


/******************************/
/* �����@�ȏオ�T���v���@���� */
/******************************/

#endif /* __09_Can__ */
