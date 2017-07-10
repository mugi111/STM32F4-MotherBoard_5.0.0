/***************************************************************************
 *	@�t�@�C����		:	usart.c
 *	@�T�v		:	USART6�������⑗��M��񋟂���D
 *					USART6(Bluetooth)	TX:PC6 / RX:PC7
 *	@�o�[�W����		:	3.0.0
 *	@�J����			:	�L�l�N�g
 *	@Ver3.0.0�ڍs	:	�ނ�
 *	@�g�p��		:	STM32F407VG, MB_Ver4, Coocox CoIDE
 **************************************************************************/

/* �C���N���[�h ======================================================= */
#include <stm32f4xx.h>
#include "usart.h"
#include "timer.h"

/* �萔��` ======================================================== */
#define RECV_RINGBUFF_SIZE 16

/* �\���̒�`	======================================================== */
/* �����O�o�b�t�@�֌W */
typedef struct
{
	/* �|�C���^ */
	volatile int recvPtr_in;
	volatile int recvPtr_out;

	/* �o�b�t�@ */
	u8 buff[RECV_RINGBUFF_SIZE];

} ringBuffer_t;

/* �O���[�o���ϐ�  ==================================================== */
static ringBuffer_t bluetooth_buffer;

/* -------------------------------------------------
 * @�֐���			:	Bluetooth_USART_Init
 * @�T�v				:	Bluetooth��USART������������
 * @����-baud		:	�{�[���[�g��ݒ肷��
 * @�߂�l			:	�Ȃ�
 * ---------------------------------------------- */
void Bluetooth_USART_Init(int baud)
{
	bluetooth_buffer.recvPtr_in = 0;
	bluetooth_buffer.recvPtr_out = 0;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType	= GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd	= GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_100MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);

	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate				= baud * (SystemCoreClock / 168000000);
	USART_InitStructure.USART_WordLength			= USART_WordLength_8b;
	USART_InitStructure.USART_StopBits				= USART_StopBits_1;
	USART_InitStructure.USART_Parity				= USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl	= USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode					= USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART6, &USART_InitStructure);

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel						= USART6_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority			= 0;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	= 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd					= ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART6, ENABLE);
}


/* -------------------------------------------------
 * @�֐���	:	Bluetooth_RecvByte
 * @�T�v		:	Bluetooth����1[Byte]�̏����󂯎��
 * @����		:	�Ȃ�
 * @�߂�l	:	��M�����f�[�^
 * ---------------------------------------------- */
int Bluetooth_RecvByte(void)
{
	int data;
	int time0;

	time0 = SystemTimer_ms_Check();
	while(bluetooth_buffer.recvPtr_in == bluetooth_buffer.recvPtr_out)
	{
		if((SystemTimer_ms_Check()-time0) > BLUETOOTH_RECV_TIMEOUT_MS)	return -1;
	}

	data = bluetooth_buffer.buff[bluetooth_buffer.recvPtr_out];

	if(++bluetooth_buffer.recvPtr_out == RECV_RINGBUFF_SIZE)
	{
		bluetooth_buffer.recvPtr_out = 0;
	}
	return data;
}

/* -------------------------------------------------
 * @�֐���	:	Bluetooth_RecvString
 * @�T�v		:	Bluetooth����max[Byte]�󂯎��A
 * 				������Ƃ��ĉ��߂���
 * @����-buf	:	�󂯎����������̊i�[��
 *�@          -max	:	������̒���[Byte]
 * @�߂�l	:	�G���[
 * ---------------------------------------------- */
int	Bluetooth_RecvString(char *buf, int max)
{
	int i;
	for(i = 0; i < max-i; i++)
	{
		*buf = Bluetooth_RecvByte();

		if(*buf == -1)	return -1;
		if(*buf == '\r')
		{
			*buf = 0;
			return i+1;
		}
		if(*buf == 0x08)
		{
			buf -= 2;
			i -= 2;
		}
		if(*buf != '\n')	buf++;
		else				i--;
	}
	*buf = 0;
	return i+1;
}

/* -------------------------------------------------
 * @�֐���		:	Bluetooth_SendByte
 * @�T�v			:	Bluetooth����1[Byte]���M����
 * @����-byte	:	���M����1[Byte]����
 * @�߂�l		:	�Ȃ�
 * ---------------------------------------------- */
void Bluetooth_SendByte(u8 byte)
{
	while (USART_GetFlagStatus(USART6, USART_FLAG_TC) == RESET);
	USART_SendData(USART6, byte);
}

/* -------------------------------------------------
 * @�֐���	:	Bluetooth_SendString
 * @�T�v		:	Bluetooth���當����𑗐M����
 * @����-buf	:	���M���镶����
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void Bluetooth_SendString(char *str)
{
	while(*str)
	{
		if(*str++ == '\n')	Bluetooth_SendByte('\r');
		else				Bluetooth_SendByte(*str++);
	}
}

/* -------------------------------------------------
 * @�֐���	:	USART2_IRQHandler
 * @�T�v		:	USART2�̎�M���荞�݃��[�`��
 * ---------------------------------------------- */
void USART6_IRQHandler(void)
{
	// ��M�I��
	if(USART_GetITStatus(USART6, USART_IT_RXNE) == SET)
	{
		bluetooth_buffer.buff[bluetooth_buffer.recvPtr_in] = USART_ReceiveData(USART6);
		if(++bluetooth_buffer.recvPtr_in == RECV_RINGBUFF_SIZE)
		{
			bluetooth_buffer.recvPtr_in = 0;
		}
	}
}
