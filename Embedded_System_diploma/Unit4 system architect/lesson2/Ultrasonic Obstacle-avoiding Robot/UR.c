/*
 * UR.c
 *
 *  Created on: Jul 21, 2023
 *      Author: mahmo
 */

#include "UR.h"
#include "states.h"
#include <stdio.h>
extern void (* US_state)();

void init_UR(){


	printf("================================================US start working\n");
}
STATE_Define (working_UR){
	US_state=working_UR;
	int distance;
	distance=generat_random(45,55,1);

	printf("================================================distance : %d \n ",distance);
	send_distance(distance);
	US_state=STATE (working_UR);

}
int generat_random(int l,int r,int count){
	int i;
	for(i=0;i<count;i++){
		int rand_num=(rand()%( r-1+1))+1;
		return rand_num;
	}

}
