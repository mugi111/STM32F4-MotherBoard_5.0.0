/*
 * timer.h
 *
 *  Created on: 2017/04/20
 *      Author: mugi111
 */

#ifndef TIMER_H_
#define TIMER_H_

#define SystemTime_ms_Check()	(gSystemTimer_ms)

extern int gSystemTimer_ms;

namespace RCsemi{

class timer{
	static int m_timingDelay_ms;
public:
	void TIM7_CMT_Init();
	void delay_ms(int msec);

	void TIM6_CMT_Init(uint16_t prescaler, uint16_t period);
};

} /* namespace timer */


#endif /* TIMER_H_ */
