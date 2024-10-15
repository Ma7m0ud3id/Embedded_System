/*
 * ADC.c
 *
 * Created: 2/6/2024 1:11:43 PM
 *  Author: mahmo
 */ 
#include "../inc/ADC.h"
void ADC_INIT (Type_volt Volt,Prescaler prescaler){
	
	switch (Volt)
	{
	case AREF:
	    *ADMUX |=(0b00<<6);
		break;
	case AVCC:
	    *ADMUX |=(0b01<<6);
	    break;
	case AV256:
	     *ADMUX |=(0b11<<6);
	     break;
	}
	//Prescaler
	/*• Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
	These bits determine the division factor between the XTAL frequency and the input clock to the
	ADC.*/
	
	*ADCSRA&=0xf8;
	*ADCSRA|=prescaler;
	/*
	• Bit 7 – ADEN: ADC Enable
	Writing this bit to one enables the ADC. By writing it to zero, the ADC is turned off. Turning the
	ADC off while a conversion is in progress, will terminate this conversion.
	*/
	*ADCSRA|=(1<<7);
	
	
	
	
}
void ADC_DISINIT (){
	
	*ADMUX=0x00;
	*ADCSRA=0x00;
	*ADCSRA=0x00;
	
}






uint16_t ADC_READ(ADC_Chanal ch){
	
	//Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits
	*ADMUX&=0xE0;
	*ADMUX|=ch;
	//Bit 6 – ADSC: ADC Start Conversion
	*ADCSRA|=(1<<6);
	while((*ADCSRA>>6)&1);
	// ADC9:0: ADC Conversion Result
	uint16_t ADC_Data;
	ADC_Data&=~(0xff);
	ADC_Data|=(*ADCL);
	ADC_Data|=(*ADCH<<8);
	return ADC_Data;
	
	
}