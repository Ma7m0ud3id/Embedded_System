/*
 * Keypad.h
 *
 *  Created on: Sep 28, 2023
 *      Author: mahmo
 */

#ifndef INCLUDE_KEYPAD_H_
#define INCLUDE_KEYPAD_H_

#include "../include/Keypad.h"

#include "Stm32f103x8_gpio_drivers.h"


#define Keypad GPIOB
//#define Keypad_control DDRC
//#define Keypad_Pin PINC



#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_9

void Keypad_Init (void);
unsigned char Keypad_Result (void);


#endif /* INCLUDE_KEYPAD_H_ */
