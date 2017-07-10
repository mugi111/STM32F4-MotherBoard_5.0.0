/***************************************************************************
 *	@�t�@�C����		:	adc.c
 *	@�T�v		:	ADC�Ń}�U�[�{�[�h���ANALOG-IN�|�[�g�Ɉ�����ꂽ�d����ǂݎ��܂��D
 *					ANALOG-IN�͈ȉ���8�s���ō\������C���ׂ�ADC1���g�p���܂��D
 *
 *					PA2, PA3,�@PB0, PB1,	PC1, PC2, PC4, PC5
 *
 *					�܂��C�{���C�u�����ɂ����Ĉȉ���2�̃��[�h�����݂���̂ŁC�p�r�ɍ��킹��
 *					�g��������悤�ɂ��Ă��������D
 *
 *					[�V���O�����[�h]
 *					1ch�ɑ΂��C�f���I��AD�ϊ����s���܂��D�܂�CAD�ϊ���1�񂸂s���܂��D
 *					���̂��ߍŐV�̈���d���𓾂邱�Ƃ��ł��܂����C���C���̏�����AD�ϊ����I��
 *					����܂ő؂邱�ƂɂȂ�܂��D
 *
 *					[�A���X�L�������[�h]
 *					8ch(ANALOG-IN���ׂ�)�ɑ΂��C�A���I��AD�ϊ����s���܂��D�܂�C
 *					1��ϊ����s��ꂽ����C���Ԋu�ŕϊ����������܂��D����ɂ���ă��C���̏���
 *					���~�߂邱�ƂȂ��ϊ����ʂ𓾂邱�Ƃ��ł��܂����C�ǂݎ�������_�ł̃f�[�^��
 *					�ŐV�̃f�[�^�łȂ��ꍇ������܂��D
 *
 *	@�o�[�W����		:	2.0.0
 *	@�J����		:	�L�l�N�g
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver3, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "adc.h"

volatile u16 adc_contscan_value[8];	// �A���������[�h�̕ϊ�����

/* -------------------------------------------------
 * @�֐���	:	ADC_Single_Init
 * @�T�v		:	ADC��f���P�ꃂ�[�h�ŏ��������܂��D
 * @����		:	�Ȃ�
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void ADC_Single_Init(void)
{
	/* �������\���� */
	GPIO_InitTypeDef	  GPIO_InitStruct;
	ADC_InitTypeDef		  ADC_InitStruct;
	ADC_CommonInitTypeDef ADC_CommonInitStruct;

	/* �N���b�N���� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA |
						   RCC_AHB1Periph_GPIOB |
						   RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 , ENABLE);

	/* GPIO�̏����� */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL ;
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	/* ADC�̏����� */
	ADC_DeInit();
	ADC_CommonInitStruct.ADC_Mode			  = ADC_Mode_Independent;
	ADC_CommonInitStruct.ADC_Prescaler		  = ADC_Prescaler_Div2;
	ADC_CommonInitStruct.ADC_DMAAccessMode	  = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStruct.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStruct);

	/* ADC1�̏����� */
	ADC_InitStruct.ADC_Resolution 			= ADC_Resolution_12b;
	ADC_InitStruct.ADC_ScanConvMode			= DISABLE; // 1�`�����l���̂ݕϊ�
	ADC_InitStruct.ADC_ContinuousConvMode 	= DISABLE; // �P�ꃂ�[�h�A��x�ϊ�������I��
	ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStruct.ADC_ExternalTrigConv 	= ADC_ExternalTrigConv_T1_CC1;
	ADC_InitStruct.ADC_DataAlign 			= ADC_DataAlign_Right;	// �E�l�Ŋi�[
	ADC_InitStruct.ADC_NbrOfConversion 		= 1;	// ��x�ɕϊ�����̂�1�`�����l��
	ADC_Init(ADC1, &ADC_InitStruct);

	// ADC1��L���ɂ���
	ADC_Cmd(ADC1, ENABLE);
}

/* -------------------------------------------------
 * @�֐���	:	ADC_Single_Read
 * @�T�v		:	AD�ϊ����V���O�����[�h�ōs���܂��D
 * 				���̏����͕ϊ��I���܂Ń��[�v���܂��D
 * @����-ch	:	AD�ϊ�����`�����l���ԍ�
 * @�߂�l	:	�ϊ�����
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
	ADC_SoftwareStartConv(ADC1);	// �ϊ��J�n
	// ADC�̏�Ԃ�EOC(End Of Convert)�łȂ���΃��[�v
	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
	return ADC_GetConversionValue(ADC1);
}

/* -------------------------------------------------
 * @�֐���	:	ADC_ContScan_Init
 * @�T�v		:	ADC��A���X�L�������[�h�ŏ��������C�ϊ����ʂ�
 * 				�z��adc_contscan_value�֊i�[���܂��D
 * 				�܂��C�i�[�ɂ�DMA(Direct Memory Access)
 * 				�𗘗p���Ă��܂��D
 * @����		:	�Ȃ�
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void ADC_ContScan_Init(void)
{
	/* �������\���� */
	GPIO_InitTypeDef	  GPIO_InitStruct;
	DMA_InitTypeDef		  DMA_InitStruct;
	ADC_InitTypeDef		  ADC_InitStruct;
	ADC_CommonInitTypeDef ADC_CommonInitStruct;

	/* �N���b�N���� */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2  |
						   RCC_AHB1Periph_GPIOA |
						   RCC_AHB1Periph_GPIOB |
						   RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	/* DMA2�̏����� */
	DMA_DeInit(DMA2_Stream0);
	DMA_InitStruct.DMA_Channel			  = DMA_Channel_0;
	DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
	DMA_InitStruct.DMA_Memory0BaseAddr	  = (uint32_t)&adc_contscan_value[0];	// �i�[��̃A�h���X���w��
	DMA_InitStruct.DMA_DIR				  = DMA_DIR_PeripheralToMemory;
	DMA_InitStruct.DMA_BufferSize		  = 8;									// �i�[����f�[�^��
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

	/* GPIO�̏����� */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL ;
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_1 | GPIO_Pin_2 |
								GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	/* ADC�̏����� */
	ADC_DeInit();
	ADC_CommonInitStruct.ADC_Mode			  = ADC_Mode_Independent;
	ADC_CommonInitStruct.ADC_Prescaler		  = ADC_Prescaler_Div2;
	ADC_CommonInitStruct.ADC_DMAAccessMode	  = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStruct.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStruct);

	/* ADC1�̏����� */
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

	/* ADC1��L���� */
	ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
	ADC_DMACmd(ADC1, ENABLE);
	ADC_Cmd(ADC1, ENABLE);

	// �ϊ��J�n
	ADC_SoftwareStartConv(ADC1);
}
