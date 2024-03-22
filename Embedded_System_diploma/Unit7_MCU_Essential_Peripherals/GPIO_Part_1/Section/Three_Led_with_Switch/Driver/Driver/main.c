/*
 * Driver.c
 *
 * Created: 12/14/2023 4:15:58 PM
 * Author : mahmo
 */ 

#include "LCD.h"
#include "Keypad.h"
#include "EXTI.h"
#include "DIO.h"
#include "ADC.h"
#include "LM35.h"
#include "Timer.h"
#include <util/delay.h>
unsigned char counter=0;
int main(void)
{
	DIR_PIN(DDRD,PIN0,INPUT);
	DIR_PIN(DDRD,PIN5,OUTPUT);
	DIR_PIN(DDRD,PIN6,OUTPUT);
	DIR_PIN(DDRD,PIN7,OUTPUT);
	Reset_PIN(PORTD,PIN5);
	Reset_PIN(PORTD,PIN6);
	Reset_PIN(PORTD,PIN7);
	
	while(1){
		if (READ_PIN(PIND,PIN0))
		{
			if (counter==0)
			{
				Set_PIN(PORTD,PIN5);
				_delay_ms(1000);
				Reset_PIN(PORTD,PIN5);
				counter++;
			} 
			else if(counter==1)
			{
				Set_PIN(PORTD,PIN6);
				_delay_ms(1000);
				Reset_PIN(PORTD,PIN6);
				counter++;
			}else if (counter==2)
			{
				Set_PIN(PORTD,PIN7);
				_delay_ms(1000);
				Reset_PIN(PORTD,PIN7);
				counter=0;
			}
			while(READ_PIN(PIND,PIN0));
		} 
		else
		{
			continue;
		}
		

	}
   
}
