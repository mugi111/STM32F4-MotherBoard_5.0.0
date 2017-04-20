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
	motherboard();

	void LED_TurnOff();
	void LED_TurnOn();
	void LED_Toggle();
	int PushSW_isPushed();
	unsigned int RotarySW_Check();



};/* end class */

}/* end namespace */

#endif /* MOTHERBOARD_H_ */
