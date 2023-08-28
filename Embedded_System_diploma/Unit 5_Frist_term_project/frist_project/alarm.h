/*
 * alarm.h
 *
 *  Created on: Aug 20, 2023
 *      Author: mahmo
 */



#ifndef ALARM_H_
#define ALARM_H_
#include"states.h"

extern void (*pr_alarm)();
enum{

	alarm_working,
}alarm_stats;

void inti_alarm();
DEFINE_FUNCTION(alarm_working);

#endif /* ALARM_H_ */
