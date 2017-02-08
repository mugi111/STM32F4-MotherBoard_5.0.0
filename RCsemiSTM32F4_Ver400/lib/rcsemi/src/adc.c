/***************************************************************************
 *	@ファイル名		:	adc.c
 *	@概要		:	ADCでマザーボード上のANALOG-INポートに印加された電圧を読み取ります．
 *					ANALOG-INは以下の8ピンで構成され，すべてADC1を使用します．
 *
 *					PA2, PA3,　PB0, PB1,	PC1, PC2, PC4, PC5
 *
 *					また，本ライブラリにおいて以下の2つのモードが存在するので，用途に合わせて
 *					使い分けるようにしてください．
 *
 *					[シングルモード]
 *					1chに対し，断続的なAD変換が行われます．つまり，AD変換を1回ずつ行います．
 *					そのため最新の印加電圧を得ることができますが，メインの処理はAD変換が終了
 *					するまで滞ることになります．
 *
 *					[連続スキャンモード]
 *					8ch(ANALOG-INすべて)に対し，連続的なAD変換が行われます．つまり，
 *					1回変換が行われた後も，一定間隔で変換をし続けます．それによってメインの処理
 *					を止めることなく変換結果を得ることができますが，読み取った時点でのデータが
 *					最新のデータでない場合があります．
 *
 *	@バージョン		:	2.0.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver3, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "adc.h"

volatile u16 adc_contscan_value[8];	// 連続複合モードの変換結果

/* -------------------------------------------------
 * @関数名	:	ADC_Single_Init
 * @概要		:	ADCを断続単一モードで初期化します．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void ADC_Single_Init(void)
{
	/* 初期化構造体 */
	GPIO_InitTypeDef	  GPIO_InitStruct;
	ADC_InitTypeDef		  ADC_InitStruct;
	ADC_CommonInitTypeDef ADC_CommonInitStruct;

	/* クロック供給 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA |
						   RCC_AHB1Periph_GPIOB |
						   RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 , ENABLE);

	/* GPIOの初期化 */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL ;
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	/* ADCの初期化 */
	ADC_DeInit();
	ADC_CommonInitStruct.ADC_Mode			  = ADC_Mode_Independent;
	ADC_CommonInitStruct.ADC_Prescaler		  = ADC_Prescaler_Div2;
	ADC_CommonInitStruct.ADC_DMAAccessMode	  = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStruct.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStruct);

	/* ADC1の初期化 */
	ADC_InitStruct.ADC_Resolution 			= ADC_Resolution_12b;
	ADC_InitStruct.ADC_ScanConvMode			= DISABLE; // 1チャンネルのみ変換
	ADC_InitStruct.ADC_ContinuousConvMode 	= DISABLE; // 単一モード、一度変換したら終了
	ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStruct.ADC_ExternalTrigConv 	= ADC_ExternalTrigConv_T1_CC1;
	ADC_InitStruct.ADC_DataAlign 			= ADC_DataAlign_Right;	// 右詰で格納
	ADC_InitStruct.ADC_NbrOfConversion 		= 1;	// 一度に変換するのは1チャンネル
	ADC_Init(ADC1, &ADC_InitStruct);

	// ADC1を有効にする
	ADC_Cmd(ADC1, ENABLE);
}

/* -------------------------------------------------
 * @関数名	:	ADC_Single_Read
 * @概要		:	AD変換をシングルモードで行います．
 * 				この処理は変換終了までループします．
 * @引数-ch	:	AD変換するチャンネル番号
 * @戻り値	:	変換結果
 * ---------------------------------------------- */
u16 ADC_Single_Read(u8 ch)
{
	if	   (ch == 0)	ADC_RegularChannelConfig(ADC1, ADC_Channel_2 , 1, ADC_SINGLECONV_CYCLE);
	else if(ch == 1)	ADC_RegularChannelConfig(ADC1, ADC_Channel_3 , 1, ADC_SINGLECONV_CYCLE);
	else if(ch == 2)	ADC_RegularChannelConfig(ADC1, ADC_Channel_8 , 1, ADC_SINGLECONV_CYCLE);
	else if(ch == 3)	ADC_RegularChannelConfig(ADC1, ADC_Channel_9 , 1, ADC_SINGLECONV_CYCLE);
	else if(ch == 4)	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SINGLECONV_CYCLE);
	else if(ch == 5)	ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 1, ADC_SINGLECONV_CYCLE);
	else if(ch == 6)	ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 1, ADC_SINGLECONV_CYCLE);
	else if(ch == 7)	ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 1, ADC_SINGLECONV_CYCLE);
	ADC_SoftwareStartConv(ADC1);	// 変換開始
	// ADCの状態がEOC(End Of Convert)でなければループ
	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
	return ADC_GetConversionValue(ADC1);
}

/* -------------------------------------------------
 * @関数名	:	ADC_ContScan_Init
 * @概要		:	ADCを連続スキャンモードで初期化し，変換結果は
 * 				配列adc_contscan_valueへ格納します．
 * 				また，格納にはDMA(Direct Memory Access)
 * 				を利用しています．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void ADC_ContScan_Init(void)
{
	/* 初期化構造体 */
	GPIO_InitTypeDef	  GPIO_InitStruct;
	DMA_InitTypeDef		  DMA_InitStruct;
	ADC_InitTypeDef		  ADC_InitStruct;
	ADC_CommonInitTypeDef ADC_CommonInitStruct;

	/* クロック供給 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2  |
						   RCC_AHB1Periph_GPIOA |
						   RCC_AHB1Periph_GPIOB |
						   RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	/* DMA2の初期化 */
	DMA_DeInit(DMA2_Stream0);
	DMA_InitStruct.DMA_Channel			  = DMA_Channel_0;
	DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
	DMA_InitStruct.DMA_Memory0BaseAddr	  = (uint32_t)&adc_contscan_value[0];	// 格納先のアドレスを指定
	DMA_InitStruct.DMA_DIR				  = DMA_DIR_PeripheralToMemory;
	DMA_InitStruct.DMA_BufferSize		  = 8;									// 格納するデータ数
	DMA_InitStruct.DMA_PeripheralInc	  = DMA_PeripheralInc_Disable;
	DMA_InitStruct.DMA_MemoryInc		  = DMA_MemoryInc_Enable;
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStruct.DMA_MemoryDataSize	  = DMA_MemoryDataSize_HalfWord;
	DMA_InitStruct.DMA_Mode				  = DMA_Mode_Circular;
	DMA_InitStruct.DMA_Priority			  = DMA_Priority_High;
	DMA_InitStruct.DMA_FIFOMode			  = DMA_FIFOMode_Disable;
	DMA_InitStruct.DMA_FIFOThreshold	  = DMA_FIFOThreshold_HalfFull;
	DMA_InitStruct.DMA_MemoryBurst		  = DMA_MemoryBurst_Single;
	DMA_InitStruct.DMA_PeripheralBurst	  = DMA_PeripheralBurst_Single;
	DMA_Init(DMA2_Stream0, &DMA_InitStruct);
	DMA_Cmd(DMA2_Stream0, ENABLE);

	/* GPIOの初期化 */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL ;
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_1 | GPIO_Pin_2 |
								GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	/* ADCの初期化 */
	ADC_DeInit();
	ADC_CommonInitStruct.ADC_Mode			  = ADC_Mode_Independent;
	ADC_CommonInitStruct.ADC_Prescaler		  = ADC_Prescaler_Div2;
	ADC_CommonInitStruct.ADC_DMAAccessMode	  = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStruct.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStruct);

	/* ADC1の初期化 */
	ADC_InitStruct.ADC_Resolution			= ADC_Resolution_12b;
	ADC_InitStruct.ADC_ScanConvMode			= ENABLE;
	ADC_InitStruct.ADC_ContinuousConvMode	= ENABLE;
	ADC_InitStruct.ADC_ExternalTrigConv		= ADC_ExternalTrigConv_T1_CC1;
	ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStruct.ADC_DataAlign			= ADC_DataAlign_Right;
	ADC_InitStruct.ADC_NbrOfConversion		= 8;
	ADC_Init(ADC1, &ADC_InitStruct);

	ADC_RegularChannelConfig(ADC1, ADC_Channel_2 , 1, ADC_CONTSCAN_CYCLE);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_3 , 2, ADC_CONTSCAN_CYCLE);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8 , 3, ADC_CONTSCAN_CYCLE);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_9 , 4, ADC_CONTSCAN_CYCLE);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 5, ADC_CONTSCAN_CYCLE);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 6, ADC_CONTSCAN_CYCLE);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 7, ADC_CONTSCAN_CYCLE);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 8, ADC_CONTSCAN_CYCLE);

	/* ADC1を有効化 */
	ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
	ADC_DMACmd(ADC1, ENABLE);
	ADC_Cmd(ADC1, ENABLE);

	// 変換開始
	ADC_SoftwareStartConv(ADC1);
}
