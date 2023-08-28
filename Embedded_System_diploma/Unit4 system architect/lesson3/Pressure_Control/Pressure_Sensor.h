/*
 * Pressure_Sensor.h
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
#include "States.h"
void (*pr_ps) ();
enum{

	PS_READING,
	PS_SENDING,
}PS_states;

void inti_sensor();
DEFINE_FUNCTION(PS_READING);
DEFINE_FUNCTION(PS_SENDING);


#endif /* PRESSURE_SENSOR_H_ */
