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
#include <stdint.h>
#define SYSCTL_RCGC2_R (*(unsigned int *)((unsigned int)0x400FE108))
#define GPIO_PORTF_DIR_R (*(unsigned int *)((unsigned int)0x40025400))
#define GPIO_PORTF_DATA_R (*(unsigned int *)((unsigned int)0x400253FC))
#define GPIO_PORTF_DEN_R (*(unsigned int *)((unsigned int)0x4002551c))
/*typedef volatile unsigned int vuint32_t;
typedef union{
	vuint32_t all_port;
	struct{
		unsigned reseved :13;
		unsigned pin_13 :1;

	}pin;
}pins;
volatile pins* pr =(volatile pins*) (GPIO+0x0C);*/
int main(void)
{
	volatile int Delay_Count;
	SYSCTL_RCGC2_R=0x00000020;
    for( Delay_Count =0; Delay_Count<50000;Delay_Count++);
	GPIO_PORTF_DIR_R|=(1<<3);
	GPIO_PORTF_DEN_R|=(1<<3);

    /* Loop forever */
	for(;;){
		GPIO_PORTF_DATA_R|=(1<<3);
		for( Delay_Count =0; Delay_Count<50000;Delay_Count++);
		GPIO_PORTF_DATA_R &=~(1<<3);
		for( Delay_Count =0; Delay_Count<50000;Delay_Count++);
	}
}
