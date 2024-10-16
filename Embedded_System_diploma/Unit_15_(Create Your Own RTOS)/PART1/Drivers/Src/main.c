/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
//Learn-in-depth
//Mahmoud 3id
//Mastering_Embedded System online diploma
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "core_cm3.h"
//#include"Stm32f103x8.h"
#include "Stm32f103x8.h"
#include "Stm32f103x8_EXTI_drivers.h"
#include "Stm32f103x8_gpio_drivers.h"
#include "Stm32f103x8_USART_drivers.h"
#include "Stm32f103x8_SPI_drivers.h"
#include "Lcd.h"
#include "Keypad.h"
#include "MYRTOS_ERROR_STATE.h"
#include "Scheduler.h"
extern unsigned int _estack;

#define OS_Stack_Size			512
#define TaskA_Stack_Size		100
#define TaskB_Stack_Size		100

/*Bonders of Main Stack Pointer (MSP)*/
unsigned int _S_MSP = (unsigned int)&_estack;
unsigned int _E_MSP;

/*Bonders of Process Stack Pointer of TaskA (PSP_TA)*/
unsigned int _S_PSP_TaskA;
unsigned int _E_PSP_TaskA;


/*Bonders of Process Stack Pointer of TaskB (PSP_TB)*/
unsigned int _S_PSP_TaskB;
unsigned int _E_PSP_TaskB;








void Main_OS(void)
{
	/* OS Stack */
	_E_MSP = (_S_MSP - OS_Stack_Size);

	/* TaskA Stack */
	_S_PSP_TaskA = (_E_MSP - 8);
	_E_PSP_TaskA = (_S_PSP_TaskA - TaskA_Stack_Size);

	/* TaskB Stack */
	_S_PSP_TaskB = (_E_PSP_TaskA - 8);
	_E_PSP_TaskB = (_S_PSP_TaskB - TaskB_Stack_Size);



	while(1)
	{

	}
}


int main(void)
{
	MYRTOS_errorID OS_ERROR;
	HW_init();


	if(MYRTOS_init()!=ES_NoError){
		while(1);
	}


}
