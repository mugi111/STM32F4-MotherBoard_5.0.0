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

/*ロータリーエンコーダインターフェース*/
class RotaryEncoder
{
public:
	/*カウントをクリアする*/
	virtual void clearCount() = 0;

	/*現在のカウント(count_)を返す*/
	virtual int getCount() = 0;

	virtual ~RotaryEncoder() = 0;
};

}

#endif /* INCLUDE_ROTARY_ENCODER_HPP_ */
