/*
 * Alarm_Manger.c
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */

#include "Alarm_Manger.h"
#include "driver.h"
extern void (*pr_am) ();
void Hight_Pressure(){
	pr_am=DEFINE(ALARM_ON);
}
DEFINE_FUNCTION(ALARM_OFF){
	AM_states=ALARM_OFF;
    Close_Alarm();
	pr_am=DEFINE(ALARM_OFF);
}
DEFINE_FUNCTION(ALARM_ON){
	AM_states=ALARM_ON;
	Start_Alarm();
	 
	//Close_Alarm();
	pr_am=DEFINE(ALARM_OFF);

}
