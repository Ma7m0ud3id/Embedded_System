/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: mahmo
 */

#include"states.h"
#include "alarm.h"
#include "pressure_sensor.h"
#include "AC_pressure.h"
#include "flash_memory.h"
#include "driver.h"
void setup(){
	
	inti_sensor();
	inti_alarm();
	init_flash();



	pr_states=DEFINE (WORKING_sensor);
	pr_AC= DEFINE(WORKING_AC);
	pr_alarm=DEFINE (alarm_working);
    pr_flash=DEFINE (flash_working);
	
}
int main(){
	    GPIO_INITIALIZATION();
	    //Set_Alarm_actuator(1);//for test only
	    //Delay(5);
		setup();
		while(1){
			pr_states();
			pr_AC();
			pr_alarm();
			pr_flash();

			
		}
	return 0;
}

