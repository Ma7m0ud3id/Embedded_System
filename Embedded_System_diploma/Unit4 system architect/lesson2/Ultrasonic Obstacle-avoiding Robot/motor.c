/*
 * motor.c
 *
 *  Created on: Jul 21, 2023
 *      Author: mahmo
 */

#include "motor.h"
#include <stdio.h>
extern void (* MO_state)();
int motor=0;
void init_motor(){


	printf("================================================motor start working\n");
}
void signal_motor(int speed){
		motor=speed;
}
STATE_Define (Idial){
	motor__st=Idial;
	printf("================================================speed : %d \n ",motor);
	MO_state=STATE(Driving);


}
STATE_Define (Driving){

	printf("================================================Driving state\n");
	MO_state=STATE (Idial);

}

