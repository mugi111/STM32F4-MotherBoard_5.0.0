/***************************************************************************
 *	@�t�@�C����		:	rs485_master.h
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

#ifndef __RS485_MASTER_H__
#define __RS485_MASTER_H__

#define RS485_BAUDRATE	115200

typedef enum {
//
	RS485_Req_Response = 0x01,
	RS485_ReadDeviceID,
	RS485_ReadDeviceDescription,
	RS485_ReadFrameDescription,
	RS485_ReadSystemVer,
// MotorDriver
	RS485_SetMotorPWM,
	RS485_ReadMotorCurrent,
	RS485_ReadMotorVoltage,
// Sensor value
	RS485_ReadSensorValue,
// IO Port
	RS485_WriteIOPort,
	RS485_WriteIOPortOR,
	RS485_WriteIOPortAND,
	RS485_WriteIOPortXOR,
	RS485_ReadIOPort,
// ServoMotor
	RS485_SetServoPulse,
// Display
	RS485_SetDisplayPos,
	RS485_WriteDisplayString,
// Undefined device
	RS485_WriteData,
	RS485_ReadData,
	RS485_SetSingleMotorPWM,
} eRS485_list_t;

/* MotorDriver */
#define RS485_BASEADDR_MD		0xD0
/* ADC */
#define RS485_BASEADDR_ADC		0xA0
/* Other device */
#define RS485_BASEADDR_OTHER	0xE0
/* brake value */
#define RS485_BRAKEVALUE		32099

/* -------------------------------------------------
 * @�֐���			:	RS485_Motor_Drive
 * @�T�v				:	RS485�Ń��[�^�h���C�o��ch��duty��
 * 						���M����
 * @����-addr		:	���M��̃A�h���X
 *�@          -ch			:	���[�^�ԍ�
 *�@          -value		:	PWM�̒l
 *�@          -recvData	:	��M�f�[�^
 * @�߂�l			:	�ʐM����:0 / ���s:-1
 * ---------------------------------------------- */
int RS485_Motor_Drive(u8 addr, u8 ch, int duty, u8 recvData[]);

int RS485_fastMotor_Drive_LPC1(u8 ch, short int duty, u8 recvData[]);
int RS485_fastMotor_Drive_LPC2(u8 ch, short int duty, u8 recvData[]);

#endif /* __RS485_MASTER_H__ */
