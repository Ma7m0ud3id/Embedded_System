/*
 * Main_Control.c
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */
#include "Main_Control.h"

extern void (*pr_mc) ();
int Pressure,thresold=20;
void Get_Pressure_Val(int actual_pressure){
	Pressure=actual_pressure;
	pr_mc=DEFINE(MC_WORKING);
}
DEFINE_FUNCTION(MC_RECEVE){
	MC_states=MC_RECEVE;
	//pr_mc=DEFINE(MC_WORKING);
	pr_mc=DEFINE(MC_RECEVE);


}
DEFINE_FUNCTION(MC_WORKING){
	MC_states=MC_WORKING;
	Store_Pressure( Pressure);
	if(Pressure>20){
		Hight_Pressure();
		pr_mc=DEFINE(MC_RECEVE);
	}else{
		pr_mc=DEFINE(MC_RECEVE);
	}

}

