/*
 * LM35.c
 *
 * Created: 2/13/2024 9:56:45 PM
 *  Author: mahmo
 */ 
#include "LM35.h"

LM35_Configration lm35_con;
uint16_t data;
uint32_t volt;
void Init_LM35(LM35_Configration* LM35_Config){
	lm35_con=*LM35_Config;
	ADC_INIT(lm35_con.type,lm35_con.prescaler);
}
uint16_t Get_Analog_Data (LM35_Configration* LM35_Config){
	
	data=ADC_READ(lm35_con.ch);
	return data;
	
	
}
uint32_t Get_Tem_Data (LM35_Configration* LM35_Config){
	
	data=ADC_READ(lm35_con.ch);
	volt=(5.0 * data * 100) / 1024;
	return volt;
	
}