/*
 * Alarm.c
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */

#include "Alarm.h"
#include "driver.h"
extern void (*pr_A) ();
void inti_alarm(){

}
void Start_Alarm(){
	pr_A=DEFINE(ALARM___ON);
}
void Close_Alarm(){
	pr_A=DEFINE(ALARM___OFF);
}
/*DEFINE_FUNCTION(WAITING){
	a_states=WAITING;
	pr_A=DEFINE(WAITING);


}*/
DEFINE_FUNCTION(ALARM___ON){
	a_states=ALARM___ON;
	Set_Alarm_actuator(0);
	Delay(6000);
	//pr_A=DEFINE(WAITING);

}
DEFINE_FUNCTION(ALARM___OFF){
	a_states=ALARM___OFF;
	Set_Alarm_actuator(1);
	//pr_A=DEFINE(WAITING);
}
