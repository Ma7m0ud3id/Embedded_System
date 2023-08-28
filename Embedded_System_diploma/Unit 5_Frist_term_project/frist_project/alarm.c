/*
 * alarm.c
 *
 *  Created on: Aug 20, 2023
 *      Author: mahmo
 */
#include "driver.h"
#include"alarm.h"
#include"states.h"
#include <stdio.h>
int alarm;
int timer;
 void (*pr_alarm)();
void send_alarm(int al){
	alarm=al;
}

void inti_alarm(){

	//printf("====================================alarm working");
	/*if(alarm>=1){
		pr_alarm=DEFINE(alarm_working);
	}else{
		pr_alarm=inti_alarm;
	}*/
}
DEFINE_FUNCTION(alarm_working){
   //printf("alarm ================ alarm======================alarm");
   alarm_stats=alarm_working;
   if(alarm==0){
   	Set_Alarm_actuator(alarm);
      Delay(6000);
      alarm=1;
      Set_Alarm_actuator(alarm);
   }else{Set_Alarm_actuator(alarm);}
   
   pr_alarm=DEFINE(alarm_working);
}
