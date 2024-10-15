/*
 * LM35.c
 *
 * Created: 2/13/2024 9:56:45 PM
 *  Author: mahmo
 */ 

#include "../inc/LDR.h"

LDR_Configration LDR_con;
uint16_t data;
uint32_t volt;

void Init_LDR(LDR_Configration* LDR_Config){
	LDR_con=*LDR_Config;
	ADC_INIT(LDR_con.type,LDR_con.prescaler);
}

void DIS_Init_LDR(){
	ADC_DISINIT();
}



uint16_t LDR_Get_Analog_Data (LDR_Configration* LDR_Config){
	
	data=ADC_READ(LDR_con.ch);
	return data;
	
	
}
/*uint32_t Get_Tem_Data (LM35_Configration* LM35_Config){
	
	data=ADC_READ(lm35_con.ch);
	volt=(5.0 * data * 100) / 1024;
	return volt;
	
}*/