/*
 * HiH5030.h
 *
 * Created: 7/14/2024 8:00:23 PM
 *  Author: mahmo
 */ 


#ifndef HIH5030_H_
#define HIH5030_H_

#include "../../MCAL/inc/ADC.h"

typedef struct
{
	Type_volt type;
	Prescaler prescaler;
	ADC_Chanal ch;
	
	
}HIH5030_Configration;
void Init_HIH5030(HIH5030_Configration* HIH5030_Config);
void DIS_Init_HIH5030();
uint16_t HIH5030_Get_Analog_Data (HIH5030_Configration* HIH5030_Config);
uint32_t HIH5030_Get_Tem_Data (HIH5030_Configration* HIH5030_Config);






#endif /* HIH5030_H_ */