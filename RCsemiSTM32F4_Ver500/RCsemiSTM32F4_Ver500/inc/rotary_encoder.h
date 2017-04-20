/*
 * rotary_encoder.h
 *
 *  Created on: 2017/03/07
 *      Author: mugi111
 */

#ifndef __ROTARY_ENCODER__
#define __ROTARY_ENCODER__

namespace RCsemi{

class rotary_encoder{
	int m_ch;
public:
	rotary_encoder(int ch);

	signed short CheckCNT();
	void ClearCNT();
};

}



#endif /* __ROTARY_ENCODER__ */
