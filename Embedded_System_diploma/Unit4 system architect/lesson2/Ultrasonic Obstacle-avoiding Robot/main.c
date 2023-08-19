/*
 * main.c
 *
 *  Created on: Jul 21, 2023
 *      Author: mahmo
 */

#include "CA.h"
#include "motor.h"
#include "UR.h"
void setup(){
	init_UR();
	init_CA();
	init_motor();
	/*

	*/
	US_state=STATE (working_UR);
	CA_state=STATE (working_CA);
	MO_state=STATE(Idial);

}
int main(){
	volatile int delay ;
	setup();
	while(1){
		US_state();
		CA_state();
		MO_state();
		for(delay=0;delay<50000;delay++);
	}

	return 0;
}
