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


uint8_t IRQ_Flag = 0;
uint8_t Task_Flag = 0;

#define TaskA		1
#define TaskB		2


#define OS_Set_PSP_Val(address)							__asm volatile("MOV R0, %[IN] \n\t MSR PSP, R0" : : [IN] "r" (address))

#define OS_Set_SP_shadowto_PSP							__asm volatile("MRS R0, CONTROL \n\t MOV R1, #0x02 \n\t \
		ORR R0, R0, R1 \n\t MSR CONTROL, R0")

#define OS_Set_SP_shadowto_MSP							__asm volatile("MRS R0, CONTROL \n\t MOV R1, #0x05 \n\t \
		AND R0, R0, R1 \n\t MSR CONTROL, R0")

#define OS_Switch_Privileged_to_Unprivileged			__asm volatile("MRS R0, CONTROL \n\t MOV R1, #0x01 \n\t \
		ORR R0, R0, R1 \n\t MSR CONTROL, R0")

#define OS_Switch_Unprivileged_to_Privileged			__asm volatile("MRS R0, CONTROL \n\t MOV R1, #0x06 \n\t \
		AND R0, R0, R1 \n\t MSR CONTROL, R0")

#define OS_Generate_Exception_Inerrupt					__asm("SVC #0x3")

void TaskA_Fun(void)
{
	/* Turn on Led on PortB Pin0 & Turn off Led on PortB Pin1 */
		GPIOx_WRITE_PIN(GPIOB, GPIO_PIN_0,GPIO_PIN_SET );
		GPIOx_WRITE_PIN(GPIOB, GPIO_PIN_0,GPIO_PIN_RESET );
}

void TaskB_Fun(void)
{
	/* Turn on Led on PortB Pin1 & Turn off Led on PortB Pin0 */
		GPIOx_WRITE_PIN(GPIOB, GPIO_PIN_1,GPIO_PIN_SET );
		GPIOx_WRITE_PIN(GPIOB, GPIO_PIN_1,GPIO_PIN_RESET );
}

void OS_SVC_Services(unsigned int *Stack_Pointer)
{
	unsigned char SVC_ID;
	SVC_ID = *((unsigned char *)(((unsigned char *)Stack_Pointer[6])-2));

	switch(SVC_ID)
	{
	case 1:	//TaskA
		OS_Set_PSP_Val(_S_PSP_TaskA);
		OS_Set_SP_shadowto_PSP;
		OS_Switch_Privileged_to_Unprivileged;
		break;

	case 2:	//TaskB
		OS_Set_PSP_Val(_S_PSP_TaskB);
		OS_Set_SP_shadowto_PSP;
		OS_Switch_Privileged_to_Unprivileged;
		break;
	}
}

void OS_SVC_Set_First_Task(int SVC_ID)
{
	switch(SVC_ID)
	{
	case 1:	//TaskA
		__asm("SVC #1");
		break;

	case 2:	//TaskB
		__asm("SVC #2");
		break;
	}
}

__attribute((naked)) void SVC_Handler(void)
{
	// Check which stack we use before stacking MSP or PSP
	__asm("TST LR, #0x4 \n\t"
			"ITE EQ \n\t"
			"MRSEQ R0, MSP \n\t"
			"MRSNE R0, PSP \n\t"
			"B OS_SVC_Services");
}

void PendSV_Handler(void)
{
	if(Task_Flag == TaskA)		//switch to TaskA
	{
		OS_Set_PSP_Val(_S_PSP_TaskA);
		OS_Set_SP_shadowto_PSP;
	}
	else if(Task_Flag == TaskB)	//switch to TaskB
	{
		OS_Set_PSP_Val(_S_PSP_TaskB);
		OS_Set_SP_shadowto_PSP;
	}
	else
	{

	}
}

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

	OS_SVC_Set_First_Task(Task_Flag);

	while(1)
	{
		if(Task_Flag == TaskA)
		{
			TaskA_Fun();
		}
		else if(Task_Flag == TaskB)
		{
			TaskB_Fun();
		}
	}
}


enum CPU_ACCESS_LEVEL
{
	privileged,
	unprivileged
};

void EXTI9_CallBack(void)
{
	/* rise the flag of the task that its own order */
	if(IRQ_Flag == 0)
	{
		Task_Flag = TaskA;
		IRQ_Flag = 1;
	}
	else if(IRQ_Flag == 1)
	{
		Task_Flag = TaskB;
		IRQ_Flag = 0;
	}
	else
	{

	}

	/* set PendSV */
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}

int main(void)
{
	RCC_AFIO_CLK_EN();
	RCC_GPIOB_CLK_EN();

	GPIO_Pinconfige_t pin_config ;

	//PA1: (Mode >> Input mode(00)) (CNF >>  Floating input(01))
	pin_config.Pin_Number = GPIO_PIN_1;
	pin_config.Mode = GPIO_MODE_INPUT_FLO;
	GPIOx_init(GPIOA, &pin_config);

	//PA13: (Mode >> Input mode(00)) (CNF >>  Floating input(01))
	pin_config.Pin_Number = GPIO_PIN_13;
	pin_config.Mode = GPIO_MODE_INPUT_FLO;
	GPIOx_init(GPIOA, &pin_config);

	//PB1: (Mode >> Output mode, max speed 10 MHz(01)) (CNF >> General purpose output push-pull(00))

	pin_config.Pin_Number = GPIO_PIN_1;
	pin_config.Mode = GPIO_MODE_OUTPUT_PP;
	pin_config.Speed = GPIO_MODE_speed_10_MHz;
	GPIOx_init(GPIOB, &pin_config);

	//Pin13: (Mode >> Output mode, max speed 10 MHz(01)) (CNF >> General purpose output push-pull(00))
	pin_config.Pin_Number = GPIO_PIN_13;
	pin_config.Mode = GPIO_MODE_OUTPUT_PP;
	pin_config.Speed = GPIO_MODE_speed_10_MHz;
	GPIOx_init(GPIOB, &pin_config);

	EXTI_Configer_t EXTI_CONGIG;
	EXTI_CONGIG.exti_conf = EXTI9PB9;
	EXTI_CONGIG.trigger_case = EXTI_Trigger_Falling;
	EXTI_CONGIG.IRQ_EN = EXTI_IRQ_Enable;
	EXTI_CONGIG.P_IRQ_call_back = EXTI9_CallBack;
	MCAL_EXTI_GPIO_INIT(&EXTI_CONGIG);
	//SWITCH_CPU_ACCESS_LEVEL(unprivileged);

	IRQ_Flag = 1;
	Task_Flag = TaskA;

	Main_OS();

	/* Loop forever */
	while(1)
	{
		if(IRQ_Flag)
		{
			IRQ_Flag = 0;
		}
		else
		{

		}
	}
}
