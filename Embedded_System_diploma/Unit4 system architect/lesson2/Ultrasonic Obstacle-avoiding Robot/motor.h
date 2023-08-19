/*
 * motor.h
 *
 *  Created on: Jul 21, 2023
 *      Author: mahmo
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "states.h"
enum{
	Idial,
	Driving,
}motor__st;
void init_motor();
STATE_Define(Idial);
STATE_Define(Driving);
void (* MO_state)();

#endif /* MOTOR_H_ */
