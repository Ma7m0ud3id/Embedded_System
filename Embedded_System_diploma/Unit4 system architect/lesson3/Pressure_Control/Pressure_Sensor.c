/*
 * Pressure_Sensor.c
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */
#include "Pressure_Sensor.h"
#include "driver.h"
extern void (*pr_ps) ();
int actual_pressure;

void inti_sensor(){

}
DEFINE_FUNCTION(PS_READING){
	PS_states =PS_READING;
	actual_pressure=getPressureVal();
	pr_ps=DEFINE(PS_SENDING);
}
DEFINE_FUNCTION(PS_SENDING){
	PS_states=PS_SENDING;
	Get_Pressure_Val( actual_pressure);
	pr_ps=DEFINE(PS_READING);

}

