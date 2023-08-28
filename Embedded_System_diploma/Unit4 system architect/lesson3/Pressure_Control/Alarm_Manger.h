/*
 * Alarm_Manger.h
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */

#ifndef ALARM_MANGER_H_
#define ALARM_MANGER_H_
#include "States.h"

enum{

	ALARM_OFF,
	ALARM_ON,
}AM_states;
void (*pr_am) ();
DEFINE_FUNCTION(ALARM_OFF);
DEFINE_FUNCTION(ALARM_ON);


#endif /* ALARM_MANGER_H_ */
