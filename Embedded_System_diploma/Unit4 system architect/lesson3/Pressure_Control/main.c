/*
 * main.c
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */
#include "States.h"
#include "Pressure_Sensor.h"
#include "Main_Control.h"
#include "Alarm_Manger.h"
#include "Alarm.h"
#include "Flash_Memory.h"
#include "driver.h"
void setup(){
	inti_sensor();
	inti_alarm();
	inti_flash_memory();



	pr_ps=DEFINE (PS_READING);
	pr_mc=DEFINE (MC_RECEVE);
	pr_am=DEFINE (ALARM_OFF);
	pr_A= DEFINE(ALARM___OFF);
	pr_fm= DEFINE(FM_WAITING);
}
int main(){
	GPIO_INITIALIZATION ();
	setup();
	while(1){

		pr_ps();
		pr_mc();
		pr_am();
		pr_A();
		pr_fm();


	}

	return 0;
}

