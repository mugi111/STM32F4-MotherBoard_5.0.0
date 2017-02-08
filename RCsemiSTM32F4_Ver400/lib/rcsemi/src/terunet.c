/***************************************************************************
 *	@�t�@�C����		:	terunet.c
 *	@�T�v		:	terunet�ʐM�̑���M�֐���񋟂���D
 *
 *					�ʐM�̑�܂��ȕ��@�͈ȉ��̒ʂ�C
 *
 *					(1)Master������SendFrame��p���āC
 *					�@�@ �E�_�~�[�f�[�^
 *					�@�@ �E���M��A�h���X
 *					�@�@ �E���M�R�}���h
 *					�@�@ �E���M�f�[�^��(�o�C�g)
 *					�@�@ �E���M�f�[�^
 *					�@�@ �E�`�F�b�N�T��
 *					  �@ �𑗐M����D
 *					(2)Slave������ReceiveFrame��p���āC
 *					�@�@ �E�R�}���h
 *					�@�@ �E�f�[�^��(�o�C�g)
 *					�@�@ �E�f�[�^
 *					�@�@ �E�`�F�b�N�T��
 *					�@�@����M����D
 * ------------------------------Terunet�ʐM�f�[�^���M�v���g�R�� ------------------------------------
 *�@�E9bit�V���A���ʐM�̃v���g�R������"Terunet"�Ƃ���D
 * �E9bit�V���A���ʐM�ɂ��C�A�h���X�ƃf�[�^����ʂ���D9bit�ڂ�HIGH�̏ꍇ�̓A�h���X�CLOW�̏ꍇ�̓f�[�^�Ƃ���D
 * �E9bit�V���A���ʐM�́C�p���e�B�r�b�g�������I�ɑ��삷�邱�ƂŎ������邽�߁C�قƂ�ǂ�UART�Ŏ����ł���D
 *
 * ���Ɏ����t���[���P�ʂŒʐM���s���D
 * +------------+---------+---------+-------------+---------+----------+
 * | Dummy byte | Address | Command | Data length | Data... | CheckSum |
 * +------------+---------+---------+-------------+---------+----------+
 *
 * (1)�擪��Dummy byte�́CRS485�̒ʐM���C�����ЂƂ����Ȃ����ߑ��M�E��M���g�����V�[�oIC(LTC485�Ȃ�)�Ő؂�ւ���ۂ�
 *    �؂�ւ��Ɏ኱���Ԃ������邽�߁C�ŏ��̃f�[�^���������鋰�ꂪ����.�����dummy�𑗐M����Ƃ������̂ł���DDummy byte
 *    ��0xff�œ��ꂷ��D
 * (2)Address�͏��4bits���@�\�ʃA�h���X�C����4bits���i���o�[�Ƃ���D
 * (3)Command��1byte�̃R�}���h�f�[�^�ł���D����ŁC�ʐM���Ă���f�[�^�̎�ނ����ʂł���D
 * (4)Data length�͂��̂��Ƃɑ���Data�̑�����1byte�Ɋi�[����D���������čő呗�M�f�[�^����255[byte]�ł���D
 *    �������CCheckSum��1byte�̓f�[�^���Ɋ܂܂Ȃ��Ƃ���D
 * (5)Data�ɂ͑��M�������f�[�^��Data length�Ŏw�肵���o�C�g�������i�[����D
 * (6)CheckSum�ɂ́CCommand����Data�̏I�[�܂ł̑��a�̉���8bit���i�[����D
 *
 * ����
 * �E���{�b�g�̃��C���}�C�R�����}�X�^�[(�A�h���X0x00)�C���[�^�[�h���C�o�Ȃǂ̊e����X���[�u�ƂȂ�ʐM����D
 * �E�}�X�^�[���������R�ɒʐM�J�n�����邱�Ƃ��ł��C�X���[�u�͎����̃A�h���X�̃t���[������M�����Ƃ��݈̂�x�����ʐM���J�n�ł���D
 * �ECheckSum����v���Ȃ������Ƃ��́C�f�[�^��j������D�t���[���̍đ��̓v���g�R���ł͒�`���Ȃ��D
 * ----------------------------------------------------------------------------------------
 *	@�o�[�W����		:	3.0.0
 *	@�J����			:	�����P��
 *					:	���c�ߍ�
 *					:	�L�l�N�g
 *	@Ver3.0.0�ڍs	:	�ނ�
 *	@�g�p��		:	STM32F407VG, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "timer.h"
#include "terunet.h"

/* -------------------------------------------------
 * @�֐���		:	Terunet_Init
 * @�T�v			:	Terunet(USART4)�̏�����
 * @����-baud	:	Terunet�ʐM�̃{�[���[�g
 * @�߂�l		:	�Ȃ�
 * ---------------------------------------------- */
void Terunet_Init(int baud)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	USART_InitStructure.USART_BaudRate = baud * (SystemCoreClock / 168000000);
	USART_InitStructure.USART_WordLength = USART_WordLength_9b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_UART4);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_UART4);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_Init(UART4, &USART_InitStructure);
	USART_Cmd(UART4, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	GPIOE->BSRRH = GPIO_Pin_4;
}

/* ------------------------------------------------
 * @�֐���	:	Terunet_ReceiveData
 * @�T�v		:	Terunet(USART4)����1[Byte]�󂯎��
 * @����		:	��M�f�[�^�i�[��
 * @�߂�l	:	����:0 / ���s:-1
 * --------------------------------------------- */
int	Terunet_ReceiveData(u16* recvData)
{
	GPIOE->BSRRH = GPIO_Pin_4;		// �ʐM����͂ɐݒ�

	int time0 = SystemTimer_ms_Check();
	while(USART_GetFlagStatus(UART4, USART_FLAG_RXNE) == RESET)
	{
		if(SystemTimer_ms_Check()-time0 > TERUNET_RECV_TIMEOUT_MS)
		{
			return -1;
		}
	}

	*recvData = USART_ReceiveData(UART4);

	return 0;
}

/* ------------------------------------------------
 * @�֐���			:	Terunet_FrameReceive
 * @�T�v				:	Terunet(USART4)����1�t���[������M���A
 * 						��͌�A��M�f�[�^���o�b�t�@�Ɋi�[����
 * @����	-recvData	:	��M�f�[�^���i�[����o�b�t�@
 * 		-cmd		:	�ʐM�R�}���h
 * @�߂�l			:	��M�����f�[�^�����������ǂ���
 * --------------------------------------------- */
int Terunet_ReceiveFrame (u8 recvData[], u8 cmd)
{
	u16 buff;
	u8 dataLength;
	u8 checkSum = 0x00;
	int time0 = SystemTimer_ms_Check();
	int i;

	/* address	------------------------ */
	do
	{
		Terunet_ReceiveData(&buff);
		if(SystemTimer_ms_Check()-time0 > TERUNET_RECV_TIMEOUT_MS)
		{
			return -1;
		}
	}
	while(buff != (TERUNET_MYADDRESS | 0x100));
	/* --------------------------------- */

	/* cmd	---------------------------- */
	Terunet_ReceiveData(&buff);
	if(cmd != buff)	return -1;
	checkSum += buff;
	/* --------------------------------- */

	/* data length	-------------------- */
	Terunet_ReceiveData(&buff);
	checkSum += buff;
	dataLength = (u8)buff;
	/* --------------------------------- */

	/* data	---------------------------- */
	for(i = 0; i < dataLength; i++)
	{
		Terunet_ReceiveData(&buff);
		recvData[i] = (u8)buff;
		checkSum += recvData[i];
	}
	/* --------------------------------- */

	/* checksum	------------------------ */
	Terunet_ReceiveData(&buff);
	if(buff != checkSum)	return -1;
	/* --------------------------------- */

	return 0;
}
/* -----------------------------------------------
 * @�֐���		:	Terunet_SendData
 * @�T�v			:	Terunet(USART4)��1[Byte]���M����
 * @����-data	:	���M����f�[�^
 * @�߂�l		:	�Ȃ�
 * ------------------------------------------- */
void Terunet_SendData(u8 data)
{
	GPIOE->BSRRL = GPIO_Pin_4;		// �ʐM���o�͂ɐݒ�
	USART_SendData(UART4, data);
	while(USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET);
}

/* ----------------------------------------------
 * @�֐���		:	Terunet_SendAddr
 * @�T�v			:	Terunet(USART4)�ɃA�h���X�𑗐M����
 * @����-addr	:	���M����A�h���X
 * @�߂�l		:	�Ȃ�
 * ------------------------------------------- */
void Terunet_SendAddr(u8 addr)
{
	GPIOE->BSRRL = GPIO_Pin_4;		// �ʐM���o�͂ɐݒ�
	USART_SendData(UART4, addr|0x100);
	while(USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET);
}

/* ----------------------------------------------
 * @�֐���		:	Terunet_SendFrame
 * @�T�v			:	Terunet(USART4)�Ƀf�[�^�t���[���𑗐M����
 * @����			:	�����̃A�h���X, �g�������@�\�̃R�}���h,
 * 					data length, data(�z��)
 * @�߂�l		:	�Ȃ�
 * ------------------------------------------- */
void Terunet_SendFrame(u8 slaveAddr, u8 cmd, u8 dataLength, const u8 data[])
{
	u8 checkSum = 0x00;
	int i;

	Terunet_SendData(0xFF);		//DummyData
	Terunet_SendAddr(slaveAddr);
	Terunet_SendData(cmd);
	Terunet_SendData(dataLength);

	for(i = 0; i < dataLength; i++)
	{
		Terunet_SendData(data[i]);
		checkSum += data[i];
	}

	checkSum += cmd + dataLength;
	Terunet_SendData(checkSum);
}
