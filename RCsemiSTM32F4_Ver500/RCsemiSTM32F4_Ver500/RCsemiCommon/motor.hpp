
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
    /*モーターのインターフェース*/
	class Motor
	{
	public:
        /*
            デューティー比dutyでモーターをドライブする
            返り値は実際に設定された値
        */
		virtual int drive(int duty)  = 0;

        /*
            モーターにブレーキをかける.
            返り値がtrueの時は成功.
        */
		virtual bool brake()          = 0;

        /*
            現在のデューティー比を返す
        */
		virtual int getCurrentDuty() = 0;


		virtual ~Motor()             {};
	};
}

#endif
