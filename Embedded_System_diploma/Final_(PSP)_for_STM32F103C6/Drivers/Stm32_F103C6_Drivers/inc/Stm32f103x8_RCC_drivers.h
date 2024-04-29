/*
 * Stm32f103x8_RCC_drivers.h
 *
 *  Created on: Dec 2, 2023
 *      Author: mahmo
 */

#ifndef INC_STM32F103X8_RCC_DRIVERS_H_
#define INC_STM32F103X8_RCC_DRIVERS_H_
#include "Stm32f103x8.h"

#define HSI_RC_CLK  (uint32_t)(8000000)
#define HSE_RC_CLK  (uint32_t)(16000000)



uint32_t MCAL_RCC_GET_PCLK1(void);
uint32_t MCAL_RCC_GET_PCLK2(void);
uint32_t MCAL_RCC_GET_AHB(void);
uint32_t MCAL_RCC_GET_SYSCLK(void);


#endif /* INC_STM32F103X8_RCC_DRIVERS_H_ */
