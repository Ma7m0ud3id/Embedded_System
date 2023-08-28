/*
 * pressure_sensor.c
 *
 *  Created on: Aug 20, 2023
 *      Author: mahmo
 */
#include"pressure_sensor.h"
#include"states.h"
#include "driver.h"
#include <stdio.h>
void (*pr_states) ();
int actual_pressure;
void inti_sensor(){
	//printf("=========================================sensor start work");
	//pr_states=DEFINE(WORKING_sensor);
}
DEFINE_FUNCTION(WORKING_sensor){
	sensor_states=WORKING_sensor;
	actual_pressure=getPressureVal();
	get_pressure(actual_pressure);
	pr_states=DEFINE(WORKING_sensor);
}

