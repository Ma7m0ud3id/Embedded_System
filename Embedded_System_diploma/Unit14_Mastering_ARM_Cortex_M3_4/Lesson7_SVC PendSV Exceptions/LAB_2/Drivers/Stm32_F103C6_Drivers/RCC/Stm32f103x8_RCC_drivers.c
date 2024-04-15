/*
 * Stm32f103x8_gpio_drivers.c
 *
 *  Created on: Sep 27, 2023
 *      Author: Mahmoud_3id
 */
//----------------------------
//include
//-----------------------------
#include "Stm32f103x8_RCC_drivers.h"
//-----------------------------
const uint8_t APB[8U]={0,0,0,0,1,2,3,4};

const uint8_t AHB[20U]={0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9};
//------------------------------------
uint32_t MCAL_RCC_GET_SYSCLK(void){

	switch((RCC->CFGR >>2) & 0b11){
	case 0:
		return HSI_RC_CLK;
		break;
	case 1:
		return HSE_RC_CLK;
		break;
	case 2:
		return 16000000;
		break;
	}

}
uint32_t MCAL_RCC_GET_AHB(void){
	return (MCAL_RCC_GET_SYSCLK() >> AHB[(RCC->CFGR >> 4) & 0xF]);
}
//MCAL_RCC_GET_PCLK1 Path ABP1
uint32_t MCAL_RCC_GET_PCLK1(void){
	return (MCAL_RCC_GET_AHB()>> APB[(RCC->CFGR >>8) & 0b111]);

}
//MCAL_RCC_GET_PCLK2 Path ABP2
uint32_t MCAL_RCC_GET_PCLK2(void){
	return (MCAL_RCC_GET_AHB() >> APB[( RCC->CFGR >>11) & 0b111]);
}
