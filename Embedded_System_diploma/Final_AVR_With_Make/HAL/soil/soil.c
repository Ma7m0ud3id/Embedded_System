/*
 * soil.c
 *
 * Created: 7/14/2024 7:52:23 PM
 *  Author: mahmo
 */ 


/*
 * soil.c
 *
 * Created: 7/14/2024 7:31:49 PM
 *  Author: mahmo
 */ 
#include "../inc/soil.h"

soil_Configration soil_con;

uint16_t data;
uint32_t volt;
void Init_soil(soil_Configration* soil_Config){
	soil_con=*soil_Config;
	ADC_INIT(soil_con.type,soil_con.prescaler);
}

void DIS_Init_soil(){
	ADC_DISINIT();
}



uint16_t soil_Get_Analog_Data (soil_Configration* soil_Config){
	
	data=ADC_READ(soil_con.ch);
	return data;
	
	
}
uint32_t soil_Get_Tem_Data (soil_Configration* soil_Config){
	
	data=ADC_READ(soil_con.ch);
	volt=((data-300)/400)*100;
	return volt;
	
}