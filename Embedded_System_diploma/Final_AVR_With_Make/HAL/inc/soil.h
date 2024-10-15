/*
 * soil.h
 *
 * Created: 7/14/2024 7:31:29 PM
 *  Author: mahmo
 */ 


#ifndef SOIL_H_
#define SOIL_H_

#include "../../MCAL/inc/ADC.h"


typedef struct
{
	Type_volt type;
	Prescaler prescaler;
	ADC_Chanal ch;
	
	
}soil_Configration;
void Init_soil(soil_Configration* soil_Config);
void DIS_Init_soil();
uint16_t soil_Get_Analog_Data (soil_Configration* soil_Config);
uint32_t soil_Get_Tem_Data (soil_Configration* soil_Config);






#endif /* SOIL_H_ */