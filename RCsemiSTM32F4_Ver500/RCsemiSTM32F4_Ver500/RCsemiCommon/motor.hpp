
/*
 * motor.hpp
 *
 *  Created on: 2016/09/27
 *      Author: osmium
 */

#ifndef INCLUDE_MOTOR_HPP_
#define INCLUDE_MOTOR_HPP_

namespace RCsemi
{
    /*���[�^�[�̃C���^�[�t�F�[�X*/
	class Motor
	{
	public:
        /*
            �f���[�e�B�[��duty�Ń��[�^�[���h���C�u����
            �Ԃ�l�͎��ۂɐݒ肳�ꂽ�l
        */
		virtual int drive(int duty)  = 0;

        /*
            ���[�^�[�Ƀu���[�L��������.
            �Ԃ�l��true�̎��͐���.
        */
		virtual bool brake()          = 0;

        /*
            ���݂̃f���[�e�B�[���Ԃ�
        */
		virtual int getCurrentDuty() = 0;


		virtual ~Motor()             {};
	};
}

#endif
