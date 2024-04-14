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

uint8_t ch;
/*void GPIO_Init()
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
}*/
void __delay__(uint32_t x)
{
	uint32_t i, j;

	for(i = 0; i < x; i++)
		for(j = 0; j < 255; j++);
}

void UART_IRQ_CallBack(void)
{
	MCAL_UART_ReceiveData(USART1, &ch, DISABLE);
	/*LCD_Send_string(ch);
		__delay__(600);
	LCD_clear_screen();*/
	MCAL_UART_SendData(USART1, &ch, ENABLE);
}


EXTI_Configer_t EXTI_CONGIG;
int main(void)
{

	Clock_Init();
	//Lcd_init();
	//GPIO_Init();
    //**************************************Lab2_UART**********************
	/*USART_Pinconfige_t UART_CFG;
	UART_CFG.UART_MODE = USART_TX_RX;
	UART_CFG.DATA_SIZE = USART_8_BIT;
	UART_CFG.STOP_MODE = USART_1_STOP_BIT;
	UART_CFG.Parity = USART_NON_PARITY;
	UART_CFG.UART_Baud_Rate = USART_BaudRate_115200;
	UART_CFG.UART_HW_FLOW_CTL = USART_HW_FLOW_NON;
	UART_CFG.IRQ_ENABLE = USART_IRQ_ENABLE_RXNEIE;
	UART_CFG.IRQ_FUNCTION = UART_IRQ_CallBack;*/

	//**************************************Lab1_UART**********************
	USART_Pinconfige_t UART_CFG;
	UART_CFG.UART_MODE = USART_TX_RX;
	UART_CFG.DATA_SIZE = USART_8_BIT;
	UART_CFG.STOP_MODE = USART_1_STOP_BIT;
	UART_CFG.Parity = USART_NON_PARITY;
	UART_CFG.UART_Baud_Rate = USART_BaudRate_115200;
	UART_CFG.UART_HW_FLOW_CTL = USART_HW_FLOW_NON;
	UART_CFG.IRQ_ENABLE = USART_IRQ_ENABLE_NON;
	UART_CFG.IRQ_FUNCTION = NULL;

	MCAL_UART_Init(USART1, &UART_CFG);
	MCAL_UART_GPIO_Set_Pins(USART1);

	/*LCD_Send_string("USRT INIT");
	__delay__(600);
	LCD_clear_screen();*/
	while(1){
		//**************************************Lab1_UART**********************
		MCAL_UART_ReceiveData(USART1, &ch, DISABLE);
		MCAL_UART_SendData(USART1, &ch, ENABLE);



	}
}
