/*
 * Driver.c
 *
 * Created: 12/14/2023 4:15:58 PM
 * Author : mahmo
 */ 

#include "LCD.h"
#include "Keypad.h"
#include "EXTI.h"
EXTI_Typedef EXTI_con;

void Get_LED_1(){
	Toggel_PIN(PORTD,PIN5);
	//_delay_ms(200);
	//_delay_ms(2000);
}
void Get_LED_2(){
	Toggel_PIN(PORTD,PIN6);
	//_delay_ms(200);
	//_delay_ms(2000);
}
void Get_LED_3(){
	Toggel_PIN(PORTD,PIN7);
	//_delay_ms(200);
	//_delay_ms(2000);
}
int main(void)
{
	
	
	
	DIR_PIN(DDRD,PIN2,INPUT);
	DIR_PIN(DDRD,PIN3,INPUT);
	DIR_PIN(DDRB,PIN2,INPUT);
	EXTI_con.EXTI_Name=INT0;
	EXTI_con.EXTI_Mode=logical;
	EXTI_con.EXTI_Function=Get_LED_1;
	EXTI_INIT(&EXTI_con);
	EXTI_con.EXTI_Name=INT1;
	EXTI_con.EXTI_Mode=rising;
	EXTI_con.EXTI_Function=Get_LED_2;
	EXTI_INIT(&EXTI_con);
	EXTI_con.EXTI_Name=INT2;
	EXTI_con.EXTI_Mode=falling;
	EXTI_con.EXTI_Function=Get_LED_3;
	EXTI_INIT(&EXTI_con);
	DIR_PIN(DDRD,PIN5,OUTPUT);
	DIR_PIN(DDRD,PIN6,OUTPUT);
	DIR_PIN(DDRD,PIN7,OUTPUT);
	Reset_PIN(PORTD,PIN5);
	Reset_PIN(PORTD,PIN6);
	Reset_PIN(PORTD,PIN7);
	/*Toggel_PIN(PORTA,PIN0);
	_delay_ms(1000);
	Toggel_PIN(PORTA,PIN0);*/
	
	
	while(1){
		
		
	}
	/* Replace with your application code */
   
}

