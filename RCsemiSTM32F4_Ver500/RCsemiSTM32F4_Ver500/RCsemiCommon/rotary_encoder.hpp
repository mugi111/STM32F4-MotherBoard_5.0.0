/*
 * rotary_encoder.hpp
 *
 *  Created on: 2016/11/02
 *      Author: osmium
 */

#ifndef INCLUDE_ROTARY_ENCODER_HPP_
#define INCLUDE_ROTARY_ENCODER_HPP_

namespace RCsemi
{

/*���[�^���[�G���R�[�_�C���^�[�t�F�[�X*/
class RotaryEncoder
{
public:
	/*�J�E���g���N���A����*/
	virtual void clearCount() = 0;

	/*���݂̃J�E���g(count_)��Ԃ�*/
	virtual int getCount() = 0;

	virtual ~RotaryEncoder() = 0;
};

}

#endif /* INCLUDE_ROTARY_ENCODER_HPP_ */
