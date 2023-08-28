/*
 * AC_pressure.c
 *
 *  Created on: Aug 20, 2023
 *      Author: mahmo
 */
#include"AC_pressure.h"
#include"states.h"
#include "driver.h"
void (* pr_AC) ();
int actual_pressure;
int thresold=20;
int alarm;
void get_pressure(int pressure){
	actual_pressure=pressure;
}

DEFINE_FUNCTION(WORKING_AC){
	AC_STATS=WORKING_AC;
	send_pressure(actual_pressure);
	if(actual_pressure>=20){
		alarm=0;
		 send_alarm(alarm);
	}else{
		alarm=1;
		send_alarm(alarm);
	}
	pr_AC=DEFINE(WORKING_AC);

}

