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
//#include"Stm32f103x8.h"
#include "Stm32f103x8.h"
#include "Stm32f103x8_EXTI_drivers.h"
#include "Stm32f103x8_gpio_drivers.h"
#include "Stm32f103x8_USART_drivers.h"
#include "Stm32f103x8_SPI_drivers.h"
#include "Lcd.h"
#include "Keypad.h"

void Clock_Init()
{
	//open clock of AFIO
	RCC_AFIO_CLK_EN();
	//open clock of GPIOA
	RCC_GPIOA_CLK_EN();

	//open clock of GPIOB
	RCC_GPIOB_CLK_EN();
}


void GPIO_Init()
{
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
}
void __delay__(uint32_t x)
{
	uint32_t i, j;

	for(i = 0; i < x; i++)
		for(j = 0; j < 255; j++);
}
void INT_ACTION(void)
{
	GPIOx_TOGGELE_PIN(GPIOB, GPIO_PIN_13);
}


EXTI_Configer_t EXTI_CONGIG;
int main(void)
{

	Clock_Init();

	GPIO_Init();

    __asm("nop\n\t"
    		"nop\n\t"
    		"nop\n\t");

    volatile unsigned char var1;
    __asm("MOV %[out1],#0xFF"
    		:[out1] "=r"(var1));


    __asm("mov R0,%[IN0]"
    		:
    		:[IN0] "r"(var1));


	EXTI_CONGIG.exti_conf = EXTI9PB9;
	EXTI_CONGIG.trigger_case = EXTI_Trigger_Falling;
	EXTI_CONGIG.IRQ_EN = EXTI_IRQ_Enable;
	EXTI_CONGIG.P_IRQ_call_back = INT_ACTION;
	MCAL_EXTI_GPIO_INIT(&EXTI_CONGIG);


	while(1){



	}
}
