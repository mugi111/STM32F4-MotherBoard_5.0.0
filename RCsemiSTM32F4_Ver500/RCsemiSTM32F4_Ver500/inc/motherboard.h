/*
 * motherboard.h
 *
 *  Created on: 2017/04/19
 *      Author: mugi111
 */

#ifndef MOTHERBOARD_H_
#define MOTHERBOARD_H_

namespace RCsemi{
class motherboard{
public:
	class LED{
		LED();

		void TurnOff();
		void TurnOn();
		void Toggle();
	};

	class PushSW{
		PushSW();

		int isPushed();
	};

	class RotarySW{
		RotarySW();

		unsigned int Check();
	};


};/* end class */

}/* end namespace */

#endif /* MOTHERBOARD_H_ */
