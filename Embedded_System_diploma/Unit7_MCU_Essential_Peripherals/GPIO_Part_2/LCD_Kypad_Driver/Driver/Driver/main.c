/*
 * project_1.c
 *
 * Created: 12/6/2023 7:17:09 PM
 * Author : mahmo
 */ 

#include "LCD.h"
#include "Keypad.h"

unsigned char counter=0;

int main(void)
{
	
	
	
	Lcd_init();
	Keypad_Init();
	_delay_ms(50);
	unsigned char key_pressed;
	while(1){
		
		key_pressed = Keypad_Result();
			switch(key_pressed){
			case 'A':
			break;
			case '?':
			counter=0;
			LCD_clear_screen();
			break;
			default:
			LCD_WRITE_CHAR(key_pressed);
			counter++;
			break;
		  }
		
		
		
	}
    /* Replace with your application code */
   
}