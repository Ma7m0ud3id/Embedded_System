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
int main(void)
{
	
	
	DIR_PIN(DDRD,PIN4,OUTPUT);
	
	Reset_PIN(PORTD,PIN4);
	
	while(1){
		
		
		Set_PIN(PORTD,PIN4);
		_delay_ms(3000);
		Reset_PIN(PORTD,PIN4);
		_delay_ms(3000);

	}
   
}
