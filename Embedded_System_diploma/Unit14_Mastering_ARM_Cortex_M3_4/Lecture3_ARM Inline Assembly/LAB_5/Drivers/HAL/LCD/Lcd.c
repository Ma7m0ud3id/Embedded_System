/*
 * Lcd.c
 *
 *  Created on: Sep 28, 2023
 *      Author: Mahmoud_3id
 */

#include "../include/Lcd.h"
//#include "Lcd_Header.h"

GPIO_Pinconfige_t GPIO_Config;

/*void Kick (void){
	lcd_control |=(1<<E_switch);
	_delay_ms(50);
	lcd_control &= ~(1<<E_switch);

}*/
/*void Lcd_ispusy (void){
	//_delay_ms(20);
	Dir_lcd_port &=~(0xFF<<Shift);
	lcd_control |=(1<<RW_switch);
	lcd_control &= ~(1<<RS_switch);
	Kick();
	Dir_lcd_port=0xFF;
	lcd_control &= ~(1<<RW_switch);

}*/
void my_wait(int time){
	int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<255;j++);
	}
}
void LCD_lcd_kick(){
	/*GPIO_Config.Pin_Number=E_switch;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;*/
	GPIOx_WRITE_PIN(lcd_port, E_switch, GPIO_PIN_SET);
	//lcd_control |= (1 << E_switch);
	my_wait(50);
	GPIOx_WRITE_PIN(lcd_port, E_switch, GPIO_PIN_RESET);
	//lcd_control &= ~(1 << E_switch);
}

void LCD_check_lcd_isbusy(){
	GPIO_Config.Pin_Number=GPIO_PIN_0;
	GPIO_Config.Mode=GPIO_MODE_INPUT_FLO;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_1;
	GPIO_Config.Mode=GPIO_MODE_INPUT_FLO;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_2;
	GPIO_Config.Mode=GPIO_MODE_INPUT_FLO;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_3;
	GPIO_Config.Mode=GPIO_MODE_INPUT_FLO;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_4;
	GPIO_Config.Mode=GPIO_MODE_INPUT_FLO;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_5;
	GPIO_Config.Mode=GPIO_MODE_INPUT_FLO;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_6;
	GPIO_Config.Mode=GPIO_MODE_INPUT_FLO;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_7;
	GPIO_Config.Mode=GPIO_MODE_INPUT_FLO;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************

	//Dir_lcd_port &= ~(0xFF<<Shift);
	GPIOx_WRITE_PIN(lcd_port, RW_switch, GPIO_PIN_SET);
	//lcd_control |= (1 << RW_switch);
	GPIOx_WRITE_PIN(lcd_port, RS_switch, GPIO_PIN_RESET);
	//lcd_control &= ~(1 << RS_switch);
	LCD_lcd_kick();
	GPIO_Config.Pin_Number=GPIO_PIN_0;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	GPIO_Config.Pin_Number=GPIO_PIN_1;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	GPIO_Config.Pin_Number=GPIO_PIN_2;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	GPIO_Config.Pin_Number=GPIO_PIN_3;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	GPIO_Config.Pin_Number=GPIO_PIN_4;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	GPIO_Config.Pin_Number=GPIO_PIN_5;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	GPIO_Config.Pin_Number=GPIO_PIN_6;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	GPIO_Config.Pin_Number=GPIO_PIN_7;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);

	//Dir_lcd_port |= (0xFF<<Shift);
	GPIOx_WRITE_PIN(lcd_port, RW_switch, GPIO_PIN_RESET);
	//lcd_control &= ~(1 << RW_switch);

}


void Send_command (unsigned char command){

	LCD_check_lcd_isbusy();
	//#ifdef EIGHT_BIT_MODE
	GPIO_Config.Pin_Number=RW_switch;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//******************************************
	GPIO_Config.Pin_Number=RS_switch;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);

	//Dir_lcd_control |= ((1<<RW_switch)|(1<<RS_switch));
	GPIOx_WRITE_PIN(lcd_port, RW_switch, GPIO_PIN_RESET);
	GPIOx_WRITE_PIN(lcd_port, RS_switch, GPIO_PIN_RESET);
	//lcd_control &= ~((1<<RW_switch)|(1<<RS_switch));
	GPIOx_WRITE_PORT(lcd_port, command);
	my_wait(10);
	LCD_lcd_kick();
	//#endif
	/*#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	lcd_port = (lcd_port & 0x0F) | (command & 0xF0);
	lcd_control &= ~ ((1<<RW_switch)|(1<<RS_switch));
	LCD_lcd_kick ();
	lcd_port = (lcd_port & 0x0F) | (command << 4);
	lcd_control &= ~ ((1<<RW_switch)|(1<<RS_switch));
	LCD_lcd_kick();
    #endif*/



}
void LCD_clear_screen(){
	Send_command(LCD_CLEAR_SCREEN);
}
void Lcd_init (){
	my_wait(50);
	//Lcd_ispusy();
	GPIO_Config.Pin_Number=RS_switch;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=RW_switch;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=E_switch;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	//Dir_lcd_control |= ((1<<RW_switch)|(1<<RS_switch)|(1<<E_switch));
	GPIOx_WRITE_PIN(lcd_port, E_switch,   GPIO_PIN_RESET);
	GPIOx_WRITE_PIN(lcd_port, RS_switch,  GPIO_PIN_RESET);
	GPIOx_WRITE_PIN(lcd_port, RW_switch,  GPIO_PIN_RESET);
	//lcd_control &= ~((1<<RW_switch)|(1<<RS_switch)|(1<<E_switch));
	GPIO_Config.Pin_Number=GPIO_PIN_0;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_1;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_2;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_3;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_4;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_5;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_6;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	GPIO_Config.Pin_Number=GPIO_PIN_7;
	GPIO_Config.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Config.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(lcd_port, &GPIO_Config);
	//*********************************
	//Dir_lcd_port = 0xFF;


	my_wait(15);
	LCD_clear_screen();
	//#ifdef EIGHT_BIT_MODE
	Send_command(LCD_FUNCTION_8BIT_2LINES);
	//#endif
	/*#ifdef FOUR_BIT_MODE
	Send_command(0x02);
	Send_command(LCD_FUNCTION_4BIT_2LINES);
    #endif*/
	Send_command(LCD_ENTRY_MODE);
	Send_command(LCD_BEGIN_AT_FIRST_ROW);
	Send_command(LCD_DISP_ON_CURSOR_BLINK);


}
void LCD_WRITE_CHAR(unsigned char character){
	//#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	GPIOx_WRITE_PORT(lcd_port,character);
	//lcd_port = character;
	GPIOx_WRITE_PIN(lcd_port, RW_switch, GPIO_PIN_RESET);
	//lcd_control &= ~(1 << RW_switch);
	GPIOx_WRITE_PIN(lcd_port, RS_switch, GPIO_PIN_SET);
	//lcd_control |= (1 << RS_switch);
	my_wait(1);
	LCD_lcd_kick();
	//#endif
	/*#ifdef FOUR_BIT_MODE
	//LCD_check_lcd_isbusy();
	lcd_port = (lcd_port & 0x0F) | (character & 0xF0);
	lcd_control |= 1<<RS_switch; //turn RS ON for Data mode.
	lcd_control &= ~ (1<<RW_switch);//turn RW off so you can write.
	LCD_lcd_kick();
	lcd_port = (lcd_port & 0x0F) | (character << 4);
	lcd_control |= 1<<RS_switch; //turn RS ON for Data mode.
	lcd_control &= ~ (1<<RW_switch);//turn RW off so you can write.
	LCD_lcd_kick ();
	#endif*/
}
void gotoXY (unsigned char line,unsigned char posetion){
	if(line==2){
		if (posetion < 16 && posetion >= 0)
		{
			Send_command(LCD_BEGIN_AT_SECOND_ROW+posetion);
		}

	}else if(line==1){
		if (posetion < 16 && posetion >= 0)
		{
			Send_command(LCD_BEGIN_AT_FIRST_ROW+posetion);
		}
	}
}
void LCD_Send_string (char* data){
	int count=0;
	while (*data>0)
	{

		LCD_WRITE_CHAR(*data++);
		count++;
		if (count==16)
		{
			gotoXY(2,0);
		}else if (count==32)
		{
			LCD_clear_screen();
			gotoXY(1,0);
			count = 0;
		}
	}
}
