/* Includes ------------------------------------------------------------------*/
#include <stm32f4xx.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "touch_lcd.h"
#include "systick.h"
#include "user_interface.h"
#include "project.h"
#include "rotary_encoder.h"

#include "GUI.h"
#include "DIALOG.h"
#include "xprintf.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

#ifdef __P_TOUCH_PANEL__
void CreateWindow(void);

int main(void)
{
	SystemCoreClockUpdate();
	LCD_LowLevel_Config();
	LED_Config();
	PushSW_Config();
	ENC0_Config();
	ENC1_Config();
	ENC2_Config();
	ENC3_Config();

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);
	SysTick_Config(SystemCoreClock / 1000);

	GUI_Init();
	xdev_out(GUI_DispChar);
	GUI_SetFont(GUI_FONT_13_ASCII);
	GUI_GotoXY(0,0);

	GUI_DispString("STM32F4Discovery\n-STM32F407VGT6 rev.Z @240Mhz\n");
	GUI_DispString("Embedded STemWin Library\n");
	delay_ms(500);

	CreateWindow();

	while(1)
	{
		GUI_GotoXY(0, 0);
		GUI_DispDec(ENC0_Check(),6);
		GUI_DispNextLine();
		GUI_DispDec(ENC1_Check(),6);
		GUI_DispNextLine();
		GUI_DispDec(ENC2_Check(),6);
		GUI_DispNextLine();
		GUI_DispDec(ENC3_Check(),6);
		GUI_DispNextLine();
	}
	return 0;
} /* main() */

#endif //__P_TOUCH_PANEL__
