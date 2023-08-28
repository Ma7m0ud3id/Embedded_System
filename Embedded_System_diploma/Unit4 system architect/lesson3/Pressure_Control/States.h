/*
 * States.h
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */

#ifndef STATES_H_
#define STATES_H_
#include <stdio.h>
#include <stdlib.h>
#define DEFINE(_state_) ST_##_state_
#define DEFINE_FUNCTION(__STATE__) void ST_##__STATE__()


void Get_Pressure_Val(int actual_pressure);
void Store_Pressure(int actual_pressure);
void Hight_Pressure();
void Start_Alarm();
void Close_Alarm();
#endif /* STATES_H_ */
