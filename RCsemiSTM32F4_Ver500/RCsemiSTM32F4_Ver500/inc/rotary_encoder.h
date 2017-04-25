/*
 * rotary_encoder.h
 *
 *  Created on: 2017/03/07
 *      Author: mugi111
 */

#ifndef __ROTARY_ENCODER__
#define __ROTARY_ENCODER__

#include "../RCsemiCommon/rotary_encoder.hpp"

namespace RCsemi{

class rotary_encoder : public RotaryEncoder{
	int m_ch;
public:
	rotary_encoder(int ch);

	int getCount();
	void clearCount();
};

}



#endif /* __ROTARY_ENCODER__ */
