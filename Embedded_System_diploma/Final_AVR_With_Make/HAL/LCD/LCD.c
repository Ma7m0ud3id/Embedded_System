/*
 * LCD.c
 *
 * Created: 12/6/2023 7:20:32 PM
 *  Author: mahmo
 */ 






#include "../inc/LCD.h"
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
void LCD_lcd_kick(){
	lcd_control |= (1 << E_switch);
	_delay_ms(50);
	lcd_control &= ~(1 << E_switch);
}

void LCD_check_lcd_isbusy(){
	Dir_lcd_port &= ~(0xFF<<Shift);
	lcd_control |= (1 << RW_switch);
	lcd_control &= ~(1 << RS_switch);
	LCD_lcd_kick();
	Dir_lcd_port |= (0xFF<<Shift);
	lcd_control &= ~(1 << RW_switch);
	
}


void Send_command (unsigned char command){
	
	LCD_check_lcd_isbusy();
	#ifdef EIGHT_BIT_MODE
	Dir_lcd_control |= ((1<<RW_switch)|(1<<RS_switch));
	lcd_control &= ~((1<<RW_switch)|(1<<RS_switch));
	lcd_port=command;
	_delay_ms(1);
	LCD_lcd_kick();
    #endif
	/*#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	lcd_port = command;
	lcd_control &= ~((1 << RS_switch) | (1<<RW_switch));
	_delay_ms(1);
	LCD_lcd_kick();
	#endif*/
	#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	//lcd_port = (lcd_port & 0x0F) | (command & 0xF0);
	lcd_port = (lcd_port & 0x87) | ((command >>1) & 0x78);//phisical lcd
	lcd_control &= ~ ((1<<RW_switch)|(1<<RS_switch));
	LCD_lcd_kick ();
	//lcd_port = (lcd_port & 0x0F) | (command << 4);
	lcd_port = (lcd_port & 0x87 ) | ((command <<3) & 0x78);//phisical lcd
	lcd_control &= ~ ((1<<RW_switch)|(1<<RS_switch));
	LCD_lcd_kick();
    #endif
	
	
	
}
void LCD_clear_screen(){
	Send_command(LCD_CLEAR_SCREEN);
}
void Lcd_init (){
	_delay_ms(20);
	//Lcd_ispusy();
	Dir_lcd_control |= ((1<<RW_switch)|(1<<RS_switch)|(1<<E_switch));
	lcd_control &= ~((1<<RW_switch)|(1<<RS_switch)|(1<<E_switch));
	Dir_lcd_port = 0xFF;
	_delay_ms(15);
	LCD_clear_screen();
	#ifdef EIGHT_BIT_MODE
	   Send_command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE
	Send_command(0x02);
	Send_command(LCD_FUNCTION_4BIT_2LINES);
    #endif
	Send_command(LCD_ENTRY_MODE);
	Send_command(LCD_BEGIN_AT_FIRST_ROW);
	Send_command(LCD_DISP_ON);
	
	
}
/*void LCD_INIT(){
	_delay_ms(20);
	Dir_lcd_control |= (1<<E_switch | 1<<RS_switch | 1<<RW_switch);
	lcd_control &= ~ (1<<E_switch | 1<<RS_switch | 1<<RW_switch);
	Dir_lcd_port = 0xFF;
	_delay_ms(15);
	LCD_clear_screen();
	#ifdef EIGHT_BIT_MODE
	Send_command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE
	#endif
	Send_command(LCD_ENTRY_MODE);
	Send_command(LCD_BEGIN_AT_FIRST_ROW);
	Send_command(LCD_DISP_ON_CURSOR_BLINK);
}*/



/*void Send_char (unsigned char data){
	
	#ifdef EIGHT_BIT_MODE
	Lcd_ispusy();
	Dir_lcd_control |= ((1<<RW_switch)|(1<<RS_switch));
	lcd_control &= ~(1<<RW_switch);
	lcd_control |=(1<<RS_switch);
	PORTA=data;
	_delay_ms(1);
	Kick();
	#endif
	#ifdef FOUR_BIT_MODE
	#endif
}*/
void LCD_WRITE_CHAR(unsigned char character){
	#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	lcd_port = character;
	lcd_control &= ~(1 << RW_switch);
	lcd_control |= (1 << RS_switch);
	_delay_ms(1);
	LCD_lcd_kick();
	#endif
	#ifdef FOUR_BIT_MODE
	//LCD_check_lcd_isbusy();
	//lcd_port = (lcd_port & 0x0F) | (character & 0xF0);
	lcd_port = (lcd_port & 0x87) | ((character >>1) & 0x78);//phisical lcd
	lcd_control |= 1<<RS_switch; //turn RS ON for Data mode.
	lcd_control &= ~ (1<<RW_switch);//turn RW off so you can write.
	LCD_lcd_kick();
	//lcd_port = (lcd_port & 0x0F) | (character << 4);
	lcd_port = (lcd_port & 0x87 ) | ((character << 3) & 0x78);//phisical lcd
	lcd_control |= 1<<RS_switch; //turn RS ON for Data mode.
	lcd_control &= ~ (1<<RW_switch);//turn RW off so you can write.
	LCD_lcd_kick ();
	#endif
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
void Send_string (char* data){
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
void LCD_WRITE_S_CHAR (unsigned char* data, uint8_t position){
	Send_command(0x40);
	uint8_t i;
	for(i=0;i<8;i++){
		LCD_WRITE_CHAR(data[i]);
	}
	gotoXY(1,position);
	LCD_WRITE_CHAR(0);
}
void LCD_WRITE_NUMBER (uint32_t data){
	char string_number[20];
	sprintf(string_number,"%d",data);
	Send_string(string_number);
}


