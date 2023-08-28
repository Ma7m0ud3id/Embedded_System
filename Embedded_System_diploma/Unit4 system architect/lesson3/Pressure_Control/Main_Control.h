/*
 * Main_Control.h
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */

#ifndef MAIN_CONTROL_H_
#define MAIN_CONTROL_H_
#include "States.h"

enum{

	MC_RECEVE,
	MC_WORKING,
}MC_states;
void (*pr_mc) ();
DEFINE_FUNCTION(MC_RECEVE);
DEFINE_FUNCTION(MC_WORKING);


#endif /* MAIN_CONTROL_H_ */
