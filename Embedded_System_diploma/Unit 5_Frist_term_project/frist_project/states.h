/*
 * states.h
 *
 *  Created on: Aug 20, 2023
 *      Author: mahmo
 */

#ifndef STATES_H_
#define STATES_H_
#include <stdio.h>
#include<stdlib.h>

#define DEFINE(_state_) ST_##_state_
#define DEFINE_FUNCTION(__STATE__) void ST_##__STATE__()



void get_pressure(int pressure);
void send_pressure(int actual);
void send_alarm(int al);

#endif /* STATES_H_ */
