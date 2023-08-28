/*
 * pressure_sensor.h
 *
 *  Created on: Aug 20, 2023
 *      Author: mahmo
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
#include"states.h"

extern void (*pr_states) ();
enum{

	WORKING_sensor,
}sensor_states;

void inti_sensor();
DEFINE_FUNCTION(WORKING_sensor);

#endif /* PRESSURE_SENSOR_H_ */
