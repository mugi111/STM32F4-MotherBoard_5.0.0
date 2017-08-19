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

	u8 InitSuccess = 0;
	u8 buff[8] = {1, 1, 1, 1, 1, 0, 0, 0};

	CanRxMsg RxMsg;


	MB_LED_Init();
	InitSuccess = CanInit();
	MB_PushSW_Init();
	MB_LED_TurnOn();
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
			if(CAN_TSR_TXOK0)		MB_LED_TurnOn();
		}
	}
}


/******************************/
/* �����@�ȏオ�T���v���@���� */
/******************************/

#endif /* __09_Can__ */
