/*
 * flash_memory.c
 *
 *  Created on: Aug 20, 2023
 *      Author: mahmo
 */
#include "driver.h"
#include"flash_memory.h"
#include"states.h"
#include <stdio.h>
int actual_pressure;
 void (*pr_flash)();
void send_pressure(int actual){
	actual_pressure=actual;
}

void init_flash(){
	//printf("===================================flash start");
	//pr_flash=DEFINE(flash_working);
}
DEFINE_FUNCTION(flash_working){
	flash_stats=flash_working;
	pr_flash=DEFINE(flash_working);
}


