/*
 * LM35.h
 *
 * Created: 2/13/2024 9:55:46 PM
 *  Author: mahmo
 */ 


#ifndef LM35_H_
#define LM35_H_
#include "../../MCAL/inc/ADC.h"

typedef struct  
{
	 Type_volt type;
	 Prescaler prescaler;
	 ADC_Chanal ch;
	 
	 
}LM35_Configration;
void Init_LM35(LM35_Configration* LM35_Config);
void DIS_Init_LM35();
uint16_t Get_Analog_Data (LM35_Configration* LM35_Config);
uint32_t Get_Tem_Data (LM35_Configration* LM35_Config);



#endif /* LM35_H_ */