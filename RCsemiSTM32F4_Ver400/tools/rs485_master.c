/***************************************************************************
 *	@�t�@�C����		:	rs485_master.c
 *	@�T�v		:	LAN�|�[�g�ʐM�ɂ�����}�X�^�[���̋@�\��񋟂���D
 *					�ʐM�̑�܂��ȕ��@�͈ȉ��̒ʂ�C
 *
 *					(1)Master������SendFrame��p���āA
 *					�@�@ �E�_�~�[�f�[�^
 *					�@�@ �E���M��A�h���X
 *					�@�@ �E���M�R�}���h
 *					�@�@ �E���M�f�[�^��(�o�C�g)
 *					�@�@ �E���M�f�[�^
 *					�@�@ �E�`�F�b�N�T��
 *					  �@ �𑗐M����
 *					(2)Slave������̃f�[�^��ReceiveFrame��p���Ď�M����
 * ------------------------------RS485�ʐM�f�[�^���M�v���g�R�� ------------------------------------
 * 9bit�V���A���ʐM�ɂ��C�A�h���X�ƃf�[�^����ʂ���D�A�h���X��9bit�ڂ�high�C�f�[�^��low�Ƃ���D
 * 9bit�V���A���ʐM�́C�p���e�B�r�b�g�������I�ɑ��삷�邱�ƂŁC�قƂ�ǂ�UART�Ŏ����ł���D
 * ���Ɏ����t���[���P�ʂŒʐM���s���D
 * +------------+---------+---------+-------------+---------+----------+
 * | Dummy byte | Address | Command | Data length | Data... | CheckSum |
 * +------------+---------+---------+-------------+---------+----------+
 * (1)�擪��Dummy byte�́CRS485�̒ʐM���C�����ЂƂ����Ȃ����ߑ��M�E��M���g�����V�[�oIC(LTC485)�Ő؂�ւ���ۂ�
 * �؂�ւ��Ɏ኱���Ԃ������邽�߁C�ŏ��̃f�[�^�͌������鋰�ꂪ����.�����dummy�𑗐M����Ƃ������̂ł���DDummy byte
 * ��0xff�œ��ꂷ��D
 * (2)Address�͏��4bits���@�\�ʃA�h���X�C����4bits���i���o�[�Ƃ���D�i���o�[�́C�ڑ�����X���[�u�����̃X�C�b�`
 * �ȂǂŐ؂�ւ��邱�Ƃ̂ł�����̂Ƃ���D
 * (3)Command��1byte�̃R�}���h�f�[�^�ł���D
 * (4)Data length�͂��̂��Ƃɑ���Data�̑�����1byte�Ɋi�[����D���������čő呗�M�f�[�^��255bytes�ł���D
 * CheckSum��1byte�͊܂܂Ȃ��D
 * (5)Data�ɂ͑��M�������f�[�^���i�[����D
 * (6)CheckSum�ɂ́CAddress����Data�܂ł̑S�Ă̘a���Ƃ�C����8bits���i�[����D
 * ����
 * �E���{�b�g�̃��C���}�C�R�����}�X�^�[(�A�h���X0x00)�C���[�^�[�h���C�o�Ȃǂ̊e����X���[�u�ƂȂ�ʐM����
 * �E�}�X�^�[���������R�ɒʐM�J�n�����邱�Ƃ��ł��C�X���[�u�͎����̃A�h���X�̃t���[������M�����Ƃ��݈̂�x�����ʐM���J�n�ł���D
 * �ECheckSum����v���Ȃ������Ƃ��́C�f�[�^��j������D�t���[���̍đ��̓v���g�R���ł͒�`���Ȃ��D
 * �ELPC���̃^�C���A�E�g���Ԃ�10ms�Ƃ���DSTM���̃^�C���A�E�g���Ԃ�1ms�Ƃ��Ă���.
 * ----------------------------------------------------------------------------------------

 *	@�o�[�W����		:	1.1.0
 *	@�J����		:	�����P��
 *				:	�L�l�N�g
 *				:	���c�ߍ�
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver2, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "terunet.h"
#include "rs485_master.h"
#include "timer.h"

/* -------------------------------------------------
 * @�֐���		:	RS485_Motor_Drive
 * @�T�v			:	RS485�ɂ�PWM�̏���1�����M����
 * @����-addr	:	���M��̃A�h���X
 *�@          -ch		:	���[�^�ԍ�
 *�@          -value	:	PWM�̒l
 * @�߂�l		:	RS485�Ŏ�M�����f�[�^
 * ---------------------------------------------- */
int RS485_Motor_Drive(u8 addr, u8 ch, int duty, u8 recvData[])
{
	u8 sendVal;
	u8 data[2];

	if     (duty ==  RS485_BRAKEVALUE)	sendVal = 127;
	else if(duty == -RS485_BRAKEVALUE)	sendVal = 127;
	else							sendVal = (u8)(duty&0xff);

	data[0] = ch;
	data[1] = sendVal;

	Terunet_SendFrame((RS485_BASEADDR_MD|(addr&0x0F)), RS485_SetSingleMotorPWM, 2, data);
	return Terunet_ReceiveFrame(recvData, RS485_SetSingleMotorPWM);
}

/* -------------------------------------------------
 * @�֐���		:	RS485_fastMotor_Drive_LPC1
 * @�T�v			:	RS485�ɂ�PWM�̏���1�߂�LPC�ɑ��M��
 * 					��
 * @����  -ch		:	���[�^�ԍ�
 *�@          -duty	:	PWM�̒l
 * @�߂�l		:	RS485�Ŏ�M�����f�[�^
 * ---------------------------------------------- */
int RS485_fastMotor_Drive_LPC1(u8 ch, short int duty, u8 recvData[])
{
	u8 sendVal;
	static u8 data[8];

	if     (duty ==  RS485_BRAKEVALUE)	sendVal = 127;
	else if(duty == -RS485_BRAKEVALUE)	sendVal = 127;
	else							sendVal = (u8)(duty&0xff);
	data[ch] = sendVal;

	Terunet_SendFrame(RS485_BASEADDR_MD|(0x01&0x0F), RS485_SetMotorPWM, 8, data);
	return 0;//RS485_ReceiveFrame(recvData, RS485_SetMotorPWM);
}

int RS485_fastMotor_Drive_LPC2(u8 ch, short int duty, u8 recvData[])
{
	u8 sendVal;
	static u8 data[8];

	if     (duty ==  RS485_BRAKEVALUE)	sendVal = 127;
	else if(duty == -RS485_BRAKEVALUE)	sendVal = 127;
	else							sendVal = (u8)(duty&0xff);
	data[ch] = sendVal;

	Terunet_SendFrame(RS485_BASEADDR_MD|(0x02&0x0F), RS485_SetMotorPWM, 8, data);
	return Terunet_ReceiveFrame(recvData, RS485_SetMotorPWM);
}
