
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
#include "Stm32f103x8_I2C_drivers.h"

#include "I2C_Slave_EEPROM.h"
#include "Lcd.h"
#include "Keypad.h"


void Enable_Clock();
unsigned char ch;
//#define MCU_Act_as_Master
#define MCU_Act_as_Slave
GPIO_Pinconfige_t GPIO_Pinconfige;


void MAHMOUD_SPI_IRQ_Callback(void){

	ch=0xf;
	MCAL_SPI_Tx_Rx(SPI1, &ch, SPI_ENABLE);
	MCAL_UART_SendData(USART1, &ch, ENABLE);
}




void UART_IRQ_Callback (void)
{
#ifdef MCU_Act_as_Master
	MCAL_UART_ReceiveData(USART1, &ch, DISABLE);
	MCAL_UART_SendData(USART1, &ch, ENABLE);
	GPIOx_WRITE_PIN(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	MCAL_SPI_Tx_Rx(SPI1, &ch, SPI_ENABLE);
	GPIOx_WRITE_PIN(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#endif
}
int main(void)
{
		/*USART_Pinconfige_t USART_con;
		Enable_Clock();
		//======================UART Init===================================
		/*
		 * Tx  --> PA9
		 * Rx  --> PA10
		 * CTS --> PA11
		 * RTS --> PA12
		 */
		/*USART_con.UART_Baud_Rate=USART_BaudRate_115200;
		USART_con.UART_HW_FLOW_CTL=USART_HW_FLOW_NON;
		USART_con.IRQ_ENABLE=USART_IRQ_ENABLE_RXNEIE;
		USART_con.IRQ_FUNCTION=UART_IRQ_Callback;
		USART_con.Parity=USART_NON_PARITY;
		USART_con.DATA_SIZE=USART_8_BIT;
		USART_con.STOP_MODE=USART_1_STOP_BIT;
		USART_con.UART_MODE=USART_TX_RX;

		MCAL_UART_Init(USART1, & USART_con);
		MCAL_UART_GPIO_Set_Pins(USART1);

		//======================SPI Init===================================
		/*
		 * SCLK --> PA5
		 * MOSI --> PA7
		 * MISO --> PA6
		 * NSS  --> PA4
		 */
		//SPI_Pinconfige_t SPI1_CFG;
		/* Common Configuration */
		/*SPI1_CFG.CLKPhase=SPI_CPHA_Second_Clock;
		SPI1_CFG.CLK_Polarity=SPI_CPOL_1_idel;
		SPI1_CFG.DATA_SIZE=SPI_8_BIT;
		SPI1_CFG.Fram_Format=SPI_MSB;
		SPI1_CFG.SPI_CLOCK_Freq=SPI_Freq_Div_8;
		SPI1_CFG.SPI_Communication_MODE=SPI_Directional_2Line;
	#ifdef MCU_Act_as_Master
		SPI1_CFG.SPI_MODE=SPI_Device_Mode_Master;
		SPI1_CFG.NSS_MODE=SPI_NSS_Software_Internal_slave_select_Enable;
		SPI1_CFG.IRQ_ENABLE=SPI_IRQ_NON;
		SPI1_CFG.SPI_IRQ_FUNCTION=NULL;




		//INIT_NSS_BIN
		GPIO_Pinconfige.Pin_Number=GPIO_PIN_4;
		GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_PP;
		GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
		GPIOx_init(GPIOA, &GPIO_Pinconfige);

		GPIOx_WRITE_PIN(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);


	#endif


	#ifdef MCU_Act_as_Slave
		SPI1_CFG.SPI_MODE=SPI_Device_Mode_Slave;
		SPI1_CFG.NSS_MODE=SPI_NSS_Hardware_Slave;
		SPI1_CFG.IRQ_ENABLE=SPI_IRQ_RX_EN;
		SPI1_CFG.SPI_IRQ_FUNCTION=MAHMOUD_SPI_IRQ_Callback;



	#endif
		MCAL_SPI_Init(SPI1, &SPI1_CFG);
		MCAL_SPI_GPIO_Set_Pins(SPI1);*/


	   /*----------------------------Test Case1-------------------------------*/
		unsigned char Write_Data[] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};
		unsigned char Read_Data[7] = {0};

		EEPROM_Init();
		EEPROM_Write_Nbytes(0xAF, Write_Data, 7);
		EEPROM_Read_Nbytes(0xAF, Read_Data, 7);


		/*----------------------------Test Case2-------------------------------*/
		Write_Data[0] = 0xA;
		Write_Data[1] = 0xB;
		Write_Data[2] = 0xC;
		Write_Data[3] = 0xD;

		EEPROM_Write_Nbytes(0xFFF, Write_Data, 4);
		EEPROM_Read_Nbytes(0xFFF, Read_Data, 4);

	while(1){

	}
	/*USART_Pinconfige_t USART_con;
	Enable_Clock();
	USART_con.UART_Baud_Rate=USART_BaudRate_115200;
	USART_con.UART_HW_FLOW_CTL=USART_HW_FLOW_NON;
	USART_con.IRQ_ENABLE=USART_IRQ_ENABLE_NON;
	USART_con.IRQ_FUNCTION=NULL;
	USART_con.Parity=USART_NON_PARITY;
	USART_con.DATA_SIZE=USART_8_BIT;
	USART_con.STOP_MODE=USART_1_STOP_BIT;
	USART_con.UART_MODE=USART_TX_RX;

	MCAL_UART_Init(USART1, & USART_con);
	MCAL_UART_GPIO_Set_Pins(USART1);




	while(1){
		MCAL_UART_ReceiveData(USART1, &ch, ENABLE);
		MCAL_UART_SendData(USART1, &ch, ENABLE);

	}*/
}










void Enable_Clock(){
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

