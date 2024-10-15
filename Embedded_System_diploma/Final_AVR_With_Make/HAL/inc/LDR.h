/*
 * LDR.h
 *
 * Created: 7/14/2024 5:35:00 PM
 *  Author: mahmo
 */ 


#ifndef LDR_H_
#define LDR_H_

#include "../../MCAL/inc/ADC.h"

typedef struct
{
	Type_volt type;
	Prescaler prescaler;
	ADC_Chanal ch;
	
	
}LDR_Configration;
void Init_LDR(LDR_Configration* LDR_Config);
void DIS_Init_LDR();
uint16_t LDR_Get_Analog_Data (LDR_Configration* LDR_Config);
uint32_t LDR_Get_Tem_Data (LDR_Configration* LDR_Config);






#endif /* LDR_H_ */