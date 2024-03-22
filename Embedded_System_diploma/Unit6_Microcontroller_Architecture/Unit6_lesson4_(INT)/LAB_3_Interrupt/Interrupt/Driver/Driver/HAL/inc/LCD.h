/*
 * IncFile1.h
 *
 * Created: 12/6/2023 7:19:16 PM
 *  Author: mahmo
 */ 







#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include <util/delay.h>
#define F_CPU 1000000UL

//LCD PORT
#define lcd_port *PORTA
#define Dir_lcd_port *DDRA

//(RS_RW_Enabel) PORT
#define lcd_control *PORTB
#define Dir_lcd_control *DDRB

//
#define RS_switch 1
#define RW_switch 2
#define E_switch 3
#define Shift 0
//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

//FUNCTION

void Lcd_init ();
void LCD_check_lcd_isbusy (void);
void LCD_lcd_kick (void);
void Send_command (unsigned char command);
void LCD_WRITE_CHAR (unsigned char data);
void Send_string (char* data);
void gotoXY (unsigned char line,unsigned char posetion);
void LCD_clear_screen();









#endif /* LCD_H_ */