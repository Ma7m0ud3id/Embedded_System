/*
 * HIH5030.c
 *
 * Created: 7/14/2024 8:00:49 PM
 *  Author: mahmo
 */ 

#include "../inc/HiH5030.h"

HIH5030_Configration HIH5030_con;
uint16_t data;
uint32_t volt;
void Init_HIH5030(HIH5030_Configration* HIH5030_Config){
	HIH5030_con=*HIH5030_Config;
	ADC_INIT(HIH5030_con.type,HIH5030_con.prescaler);
}

void DIS_Init_HIH5030(){
	ADC_DISINIT();
}



uint16_t HIH5030_Get_Analog_Data (HIH5030_Configration* LM35_Config){
	
	data=ADC_READ(HIH5030_con.ch);
	return data;
	
	
}
uint32_t HIH5030_Get_Tem_Data (HIH5030_Configration* LM35_Config){
	
	data=ADC_READ(HIH5030_con.ch);
	volt=(5.0 * data * 1000.0) / 1024.0;
	uint16_t result =((volt- 756)/31.64);
	return result;
	
}