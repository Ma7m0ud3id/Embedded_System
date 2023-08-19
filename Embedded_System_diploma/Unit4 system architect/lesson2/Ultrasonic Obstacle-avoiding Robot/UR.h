/*
 * UR.h
 *
 *  Created on: Jul 21, 2023
 *      Author: mahmo
 */

#ifndef UR_H_
#define UR_H_
#include "states.h"
enum{
	working_UR,
}UR_state;
void init_UR();
STATE_Define(working_UR);
void (* US_state)();

#endif /* UR_H_ */
