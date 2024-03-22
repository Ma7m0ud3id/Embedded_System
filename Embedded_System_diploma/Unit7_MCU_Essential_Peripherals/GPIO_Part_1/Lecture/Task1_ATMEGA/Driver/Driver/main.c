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
	DIR_PIN(DDRD,PIN5,OUTPUT);
	DIR_PIN(DDRD,PIN6,OUTPUT);
	DIR_PIN(DDRD,PIN7,OUTPUT);
	Reset_PIN(PORTD,PIN4);
	Reset_PIN(PORTD,PIN5);
	Reset_PIN(PORTD,PIN6);
	Reset_PIN(PORTD,PIN7);
	
	while(1){
		
		Set_PIN(PORTD,PIN4);
		_delay_ms(1000);
		Reset_PIN(PORTD,PIN4);
		_delay_ms(100);
		Set_PIN(PORTD,PIN5);
		_delay_ms(1000);
		Reset_PIN(PORTD,PIN5);
		_delay_ms(100);
		Set_PIN(PORTD,PIN6);
		_delay_ms(1000);
		Reset_PIN(PORTD,PIN6);
		_delay_ms(100);
		Set_PIN(PORTD,PIN7);
		_delay_ms(3000);
		Reset_PIN(PORTD,PIN7);

	}
   
}
