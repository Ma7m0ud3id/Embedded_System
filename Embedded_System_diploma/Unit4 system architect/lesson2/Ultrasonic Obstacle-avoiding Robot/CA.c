/*
 * CA.c
 *
 *  Created on: Jul 21, 2023
 *      Author: mahmo
 */
#include "CA.h"
#include "states.h"
#include <stdio.h>
extern void (* CA_state)();
void send_distance(int distance);
  int CA_distance,speed,thresout=50;
void init_CA(){

    speed=0;
    signal_motor(speed);
	printf("================================================CA start working\n");

}
void send_distance(int distance){
			CA_distance=distance;
}
STATE_Define (working_CA){

	send_distance(CA_distance);
	if(CA_distance<=thresout){
		speed=0;
		signal_motor(speed);
		 CA_state=STATE (working_CA);
	}else{
		speed=30;
		signal_motor(speed);
		 CA_state=STATE (working_CA);
	}
}


