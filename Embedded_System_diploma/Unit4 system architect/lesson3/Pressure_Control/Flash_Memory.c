/*
 * Flash_Memory.c
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */
#include "Flash_Memory.h"
int pressure;

void (*pr_fm) ();
void inti_flash_memory(){

}
void Store_Pressure(int actual_pressure){
	pressure=actual_pressure;
	pr_fm=DEFINE(FM_WAITING);
}
DEFINE_FUNCTION(FM_WAITING){
	FM_states=FM_WAITING;
	pr_fm=DEFINE(FM_WAITING);

}

