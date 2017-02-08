/***************************************************************************
 *	@�t�@�C����		:	07_Terunet.c
 *	@�T�v		:	Terunet
 *
 *					�K�v�ȏ����̓R�����g�̐擪��**�����Ă��܂��̂ŁC
 *					�K���L������悤�ɂ��Ă��������D
 *	@�o�[�W����		:	0.0.1
 *	@�J����		:
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver4, Coocox CoIDE
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

//			MB_LED_Toggle(0);	// LED0�̏�Ԃ𔽓]������
//			MB_LED_Toggle(1);	// LED1�̏�Ԃ𔽓]������

//		delay_ms(1);
	}
}




/******************************/
/* �����@�ȏオ�T���v���@���� */
/******************************/

#endif /* __09_Can__ */
