/*
 * states.h
 *
 *  Created on: Jul 21, 2023
 *      Author: mahmo
 */

#ifndef STATES_H_
#define STATES_H_
#define STATE_Define(_state_) void ST_##_state_()

#define STATE(_state_) ST_##_state_
#include <stdio.h>
#include<stdlib.h>
void send_distance(int distance);
void signal_motor(int speed);

#endif /* STATES_H_ */
