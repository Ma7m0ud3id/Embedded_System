/*
 * Alarm.h
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */

#ifndef ALARM_H_
#define ALARM_H_
#include "States.h"
enum{
    WAITING,
	ALARM___ON,
	ALARM___OFF,
}a_states;
void (*pr_A) ();
void inti_alarm();
DEFINE_FUNCTION(WAITING);
DEFINE_FUNCTION(ALARM___ON);
DEFINE_FUNCTION(ALARM___OFF);


#endif /* ALARM_H_ */
