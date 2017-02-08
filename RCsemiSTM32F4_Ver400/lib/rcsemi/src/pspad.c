/***************************************************************************
 *	@�t�@�C����		:	pspad.c
 *	@�T�v		:	Bluetooth�ɂ�����PS�R���g���[���Ƃ̒ʐM��
 *					�񋟂���D
 *	@�o�[�W����		:	3.0.0
 *	@�J����			:	�L�l�N�g
 *	@Ver3.0.0�ڍs	:	�ނ�
 *	@�g�p��		:	STM32F407VG, MB_Ver4, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "usart.h"
#include "pspad.h"
#include "timer.h"

const int gPSStick_convertTable[16] = {-2, -1,-1,-1,-1, 0,0,0,0,0,0, 1,1,1,1, 2};

/* -------------------------------------------------
 * @�֐���		:	Coincidence_Check
 * @�T�v			:	str1�̐擪����num������str2�Ɣ�r����
 * @����	-str1	:	���r�Ώە�����
 * 		-str2	:	��r������
 * 		-num	:	str1�̐擪�����r���镶����
 * @�߂�l		:	��v����1������ȊO��0��Ԃ�
   ---------------------------------------------- */
static int Coincidence_Check(const char *str1, const char *str2, int num)
{
	int i;
	for(i = 0; i < num; i++)
		if (*str1++ != *str2++)	return 0;
	return 1;
}

/* -------------------------------------------------
 * @�֐���		:	PS_CheckSum
 * @�T�v			:	PS�R���g���[������̎�M�`�F�b�N�T���𒲍�����
 * @����-psdata	:	PS�R���g���[������󂯎�����f�[�^
 * @�߂�l		:	�`�F�b�N�T�����^�Ȃ�1�A�U�Ȃ��0��Ԃ�
   ---------------------------------------------- */
static int PSdata_CheckSum(psdata_format_t *psdata)
{
	u8 sum = 0;
	int i;
	for(i = 0; i < 6; i++)	sum += psdata->bytes[i];
	if(psdata->bytes[6]-1 == sum)	return 1;
	else							return 0;
}

/* -------------------------------------------------
 * @�֐���		:	Bluetooth_BDMaster_Init
 * @�T�v			:	Bluetooth�Ƃ̒ʐM��
 * 					�������}�X�^�[�Ƃ��ď�����
 * @����-command	:	���������Ɏ����ԐM���镶����
 * @�߂�l		:	�Ȃ�
 * ---------------------------------------------- */
void Bluetooth_BDMaster_Init(char *command)
{
	char buff[128];
	Bluetooth_RecvString(buff, 128);
	while(!Coincidence_Check(buff, "OK", 2))
	{
		Bluetooth_RecvString(buff, 128);
	}
	if(command)
	{
		Bluetooth_SendString(command);
		Bluetooth_SendString("\r\n");
	}
	Bluetooth_RecvString(buff, 128);
	while(!Coincidence_Check(buff, "CONNECT", 7))
	{//Slave�Ƃ̐ڑ�����������܂őҋ@�B
		Bluetooth_RecvString(buff, 128);
	}
}

/* -------------------------------------------------
 * @�֐���		:	Bluetooth_BDSlave_Init
 * @�T�v			:	Bluetooth�Ƃ̒ʐM��
 * 					�������X���[�u�Ƃ��ď�����
 * @����-command	:	���������Ɏ����ԐM���镶����
 * @�߂�l		:	�Ȃ�
 * ---------------------------------------------- */
void Bluetooth_BDSlave_Init(char *command)
{
	char buff[128];
	Bluetooth_RecvString(buff, 128); //"OK"���󂯂��͂�
	while(!Coincidence_Check(buff, "OK", 2))
	{
		Bluetooth_RecvString(buff, 128);
	}
	if(command)
	{
		Bluetooth_SendString(command);
		Bluetooth_SendString("\r\n");
	}
	Bluetooth_RecvString(buff, 128);
	while(!Coincidence_Check(buff, "CONNECT", 7))
	{//Master�Ƃ̐ڑ�����������܂őҋ@�B
		Bluetooth_RecvString(buff, 128);
	}
}

/* -------------------------------------------------
 * @�֐���	:	Bluetooth_PSpacket_Recv
 * @�T�v		:	Bluetooth����
 * 				PS�R���g���[���̃p�P�b�g(7Byte)���󂯎��
 * @����-buf	:	�󂯎���������i�[����ϐ�
 * @�߂�l	:	��񂪎�����7���A�����łȂ����-1��Ԃ�
 * ---------------------------------------------- */
static int Bluetooth_PSpacket_Recv(u8 buf[])
{
	int data, time0;
	int i;

	/* ���R�͕s������do-while���͗��p�ł��Ȃ����� */
	data = Bluetooth_RecvByte();
	if(data == -1)	return -1;

	time0 = SystemTimer_ms_Check();
	/* �`�F�b�N�T���̃f�[�^��ǂݎ��܂Ń��[�v */
	while((data&1) == 0)
	{
		data = Bluetooth_RecvByte();
		if(data == -1)	return -1;
		if(SystemTimer_ms_Check() - time0 > PS_RECV_TIMEOUT_MS)	return -1;
	}

	for(i = 0; i < 7; i++)
	{
		buf[i] = Bluetooth_RecvByte();
		if(buf[i] == -1)	return i;
	}
	return i;
}

/* -------------------------------------------------
 * @�֐���		:	Bluetooth_PSdata_Recv
 * @�T�v			:	Bluetooth����
 * 					PS�R���g���[���̃f�[�^����M����D
 * @����-psdata	:	�R���g���[���f�[�^�i�[��̕ϐ�
 * @�߂�l		:	�Ȃ�
 * ---------------------------------------------- */
void Bluetooth_PSdata_Recv(psdata_format_t *psdata)
{
	int i;
	static int mode;
	int nBytes, sumchk = -1;
	nBytes = Bluetooth_PSpacket_Recv(psdata->bytes);
	if(nBytes == 7)	sumchk = PSdata_CheckSum(psdata);
	if(sumchk == 1)
	{
		mode = psdata->name.Mode;
		psdata->name.Error = 0;
	}
	else
	{
		psdata->bytes[0] = psdata->bytes[1] = 0;
		for(i = 2; i < 7; i++)	psdata->bytes[i] = 0x80;
		psdata->name.LStick_X = psdata->name.LStick_Y =
		psdata->name.RStick_X = psdata->name.RStick_Y = 7;
		psdata->name.Mode = mode;
		psdata->name.Error = 1;
	}
}
