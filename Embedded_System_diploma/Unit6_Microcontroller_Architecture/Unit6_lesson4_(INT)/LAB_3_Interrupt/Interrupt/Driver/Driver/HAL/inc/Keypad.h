/*
 * Keypad.h
 *
 * Created: 12/6/2023 7:19:56 PM
 *  Author: mahmo
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"
#include <util/delay.h>

#define Keypad *PORTC
#define Keypad_control *DDRC
#define Keypad_Pin *PINC



#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

void Keypad_Init (void);
unsigned char Keypad_Result (void);






#endif /* KEYPAD_H_ */