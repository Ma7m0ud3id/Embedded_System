/*
 * CA.h
 *
 *  Created on: Jul 21, 2023
 *      Author: mahmo
 */

#ifndef CA_H_
#define CA_H_
#include "states.h"
enum{
	working_CA,
}motor_state;
void init_CA();
STATE_Define(working_CA);
void (* CA_state)();


#endif /* CA_H_ */
