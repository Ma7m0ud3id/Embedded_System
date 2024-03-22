/*
 * ADC.h
 *
 * Created: 2/6/2024 1:11:18 PM
 *  Author: mahmo
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "Private.h"

typedef enum {
	AREF=0,
	AVCC,
	AV256
	
}Type_volt;

typedef enum {
	Division_2=0,
	Division2=1,
	Division4,
	Division8,
	Division16,
	Division32,
	Division64,
	Division128
	
}Prescaler;

typedef enum {
	Ch0=0,
	Ch1,
	Ch2,
	Ch3,
	Ch4,
	Ch5,
	Ch6,
	Ch7
}ADC_Chanal;



void ADC_INIT (Type_volt Volt,Prescaler prescaler);
uint16_t ADC_READ(ADC_Chanal ch);


#endif /* ADC_H_ */