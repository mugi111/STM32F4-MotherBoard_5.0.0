/*
 * motor.h
 *
 *  Created on: 2017/04/25
 *      Author: mugi111
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "../RCsemiCommon/motor.hpp"

#define BRAKEVALUE			32099	// duty�̒l�����̒l�ɂ���ƃV���[�g�u���[�L�ɂȂ�
#define MOTOR_DEADTIME_10US	20		// ���[�^�쓮�̃f�b�h�^�C��*10[us]���w�肷��

namespace RCsemi{

typedef struct
{
	// 0:FREE / +:CW / -:CCW / 32099:BRAKE
	int duty[4];

	// 0:FREE / 1:CW / 2:CCW / 3:BRAKE
	uint8_t dir[4];

	uint8_t dir_save[4];
	uint8_t dir_old [4];

	int isEnable[4];
	int deadtime[4];
} _motor_status_t;

class motor : public Motor{
	int m_currentDuty;
	int m_ch;

public:
	motor(unsigned short ch);

	int drive(int duty);
	bool brake();
	int getCurrentDuty();

};

}



#endif /* MOTOR_H_ */
