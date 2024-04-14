/*
 * Stm32f103x8.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mahmoud_3id
 */

#ifndef INC_STM32F103X8_H_
#define INC_STM32F103X8_H_

//-------------------------------------
//Includes
//----------------------------------------
#include <stdint.h>
#include <stdlib.h>

//=======================================================================
//-----------------------------
//Base addresses for Memories
//-----------------------------



#define Flash_Memory_BASE                                    0x08000000UL
#define System_Memory_BASE                                   0x1FFFF000UL
#define SRAM_BASE                                            0x20000000UL
#define Peripherals_BASE                                     0x20000000UL
#define Cortex_M3_internal_Peripherals_BASE                  0x20000000UL



//=======================================================================
//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------

#define RCC_BASE    0x40021000UL

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------
//GPIO
//A, B fully included in LQFP48 Package

#define GPIOA_BASE    0x40010800UL
#define GPIOB_BASE    0x40010C00UL

//C, D fully included in LQFP48 Package

#define GPIOC_BASE    0x40011000UL
#define GPIOD_BASE    0x40011400UL

//E not included in LQFP48 Package

#define GPIOE_BASE    0x40011800UL

//EXTI
#define EXTI_BASE     0x40010400UL

//AFIO
#define AFIO_BASE     0x40010000UL


//NVIC
#define NVIC_BASE      0xE000E100UL

//USART
#define USART1_BASE      0x40013800UL

//SPI
#define SPI1_BASE        0x40013000UL

//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------
//USART
#define USART2_BASE      0x40004400UL
#define USART3_BASE      0x40004800UL

//UART
#define UART4_BASE      0x40004C00UL
#define UART5_BASE      0x40005000UL

//SPI
#define SPI2_BASE        0x40003C00UL
#define SPI3_BASE        0x40003800UL
//NON**************************************

//=========================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*
//GPIOX_register
typedef struct{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;

}typedef_GPIO;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
//RCC_register
typedef struct{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;

}typedef_RCC;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
//EXTI_register
typedef struct{
	uint32_t IMR;
	uint32_t EMR;
	uint32_t RTSR;
	uint32_t FTSR;
	uint32_t SWIER;
	uint32_t PR;

}typedef_EXTI;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
//NVIC_register
typedef struct{
	uint32_t ISER0;
	uint32_t ISER1;
	uint32_t Reserved;
	uint32_t ICER0;
	uint32_t ICER1;

}typedef_NVIC;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
//AFIO_register
typedef struct{
	uint32_t EVCR;
	uint32_t MAPR;
	uint32_t EXTICR[4];
	uint32_t RSERVED0;
	uint32_t MAPR2;

}typedef_AFIO;

//(UART & USART ) register
typedef struct{
	uint32_t USART_SR;
	uint32_t USART_DR;
	uint32_t USART_BRR;
	uint32_t USART_CR1;
	uint32_t USART_CR2;
	uint32_t USART_CR3;
	uint32_t USART_GTPR;

}typedef_USART;

//SPI register
typedef struct{
	uint32_t SPI_CR1;
	uint32_t SPI_CR2;
	uint32_t SPI_SR;
	uint32_t SPI_DR;
	uint32_t SPI_CRCPR;
	uint32_t SPI_RXCRCR;
	uint32_t SPI_TXCRCR;
	uint32_t SPI_I2SCFGR;
	uint32_t SPI_I2SPR;

}typedef_SPI;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA			((typedef_GPIO *)GPIOA_BASE)
#define GPIOB			((typedef_GPIO *)GPIOB_BASE)
#define GPIOC			((typedef_GPIO *)GPIOC_BASE)
#define GPIOD			((typedef_GPIO *)GPIOD_BASE)
#define GPIOE			((typedef_GPIO *)GPIOE_BASE)

#define RCC				((typedef_RCC *)RCC_BASE)

#define EXTI			((typedef_EXTI*)EXTI_BASE)

#define AAFIO			((typedef_AFIO*)AFIO_BASE)

#define USART1			((typedef_USART*)USART1_BASE)
#define USART2			((typedef_USART*)USART2_BASE)
#define USART3			((typedef_USART*)USART3_BASE)

#define UART4			((typedef_USART*)UART4_BASE)
#define UART5			((typedef_USART*)UART5_BASE)


#define SPI1			((typedef_USART*)SPI1_BASE)
#define SPI2			((typedef_USART*)SPI2_BASE)
#define SPI3			((typedef_USART*)SPI3_BASE)

//===================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Clock enable macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()		(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()		(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()		(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()		(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()		(RCC->APB2ENR |= 1<<6)

#define RCC_AFIO_CLK_EN()		(RCC->APB2ENR |= 1<<0)

//USRT_Enable
#define RCC_USART1_CLK_EN()		(RCC->APB2ENR |= 1<<14)
#define RCC_USART2_CLK_EN()		(RCC->APB1ENR |= 1<<17)
#define RCC_USART3_CLK_EN()		(RCC->APB1ENR |= 1<<18)
#define RCC_UART4_CLK_EN()		(RCC->APB1ENR |= 1<<19)
#define RCC_UART5_CLK_EN()		(RCC->APB1ENR |= 1<<20)

//USRT_Reset
#define RCC_USART1_CLK_REST()		(RCC->APB2RSTR |= 1<<14)
#define RCC_USART2_CLK_REST()		(RCC->APB1RSTR |= 1<<17)
#define RCC_USART3_CLK_REST()		(RCC->APB1RSTR |= 1<<18)
#define RCC_UART4_CLK_REST()		(RCC->APB1RSTR |= 1<<19)
#define RCC_UART5_CLK_REST()		(RCC->APB1RSTR |= 1<<20)


//SPI_Enable
#define RCC_SPI1_CLK_EN()		(RCC->APB2ENR |= 1<<12)
#define RCC_SPI2_CLK_EN()		(RCC->APB2ENR |= 1<<14)
#define RCC_SPI3_CLK_EN()		(RCC->APB2ENR |= 1<<15)


//SPI_Reset
#define RCC_SPI1_CLK_REST()		(RCC->APB2RSTR |= 1<<12)
#define RCC_SPI2_CLK_REST()		(RCC->APB2RSTR |= 1<<14)
#define RCC_SPI3_CLK_REST()		(RCC->APB2RSTR |= 1<<15)



//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

//EXTI_IRQ
#define  EXTI0_IRQ              6
#define  EXTI1_IRQ              7
#define  EXTI2_IRQ              8
#define  EXTI3_IRQ              9
#define  EXTI4_IRQ              10
#define  EXTI5_IRQ              23
#define  EXTI6_IRQ              23
#define  EXTI7_IRQ              23
#define  EXTI8_IRQ              23
#define  EXTI9_IRQ              23
#define  EXTI10_IRQ             40
#define  EXTI11_IRQ             40
#define  EXTI12_IRQ             40
#define  EXTI13_IRQ             40
#define  EXTI14_IRQ             40
#define  EXTI15_IRQ             40

//USART_IRQ
#define  USART1_IRQ              37
#define  USART2_IRQ              38
#define  USART3_IRQ              39
#define  USART4_IRQ              52
#define  USART5_IRQ              53

//SPI_IRQ
#define  SPI1_IRQ               35
#define  SPI2_IRQ               36
#define  SPI3_IRQ               51


#define EXTI_ISER0      *(volatile uint32_t * )(NVIC_BASE+0x000)
#define EXTI_ISER1      *(volatile uint32_t * )(NVIC_BASE+0x004)
#define EXTI_ISER2      *(volatile uint32_t * )(NVIC_BASE+0x008)
#define EXTI_ICER0      *(volatile uint32_t * )(NVIC_BASE+0x080)
#define EXTI_ICER1      *(volatile uint32_t * )(NVIC_BASE+0x084)
#define EXTI_ICER2      *(volatile uint32_t * )(NVIC_BASE+0x088)



//IRQ_DISABLE
//***********************************************************
//EXT
#define NVIC_IRQ6_EXTI0_Dis          (EXTI_ICER0 |=(1<<6))
#define	NVIC_IRQ7_EXTI1_Dis          (EXTI_ICER0 |=(1<<7))
#define	NVIC_IRQ8_EXTI2_Dis          (EXTI_ICER0 |=(1<<8))
#define	NVIC_IRQ9_EXTI3_Dis          (EXTI_ICER0 |=(1<<9))
#define	NVIC_IRQ10_EXTI4_Dis         (EXTI_ICER0 |=(1<<10))
#define	NVIC_IRQ23_EXTI5_9_Dis       (EXTI_ICER0 |=(1<<23))
#define	NVIC_IRQ40_EXTI10_15_Dis     (EXTI_ICER1 |=(1<<8))


//USART
#define	NVIC_IRQ37_USART1_Dis        (EXTI_ICER1 |=(1<<( USART1_IRQ - 32 )))
#define	NVIC_IRQ38_USART2_Dis        (EXTI_ICER1 |=(1<<( USART2_IRQ - 32 )))
#define	NVIC_IRQ39_USART3_Dis        (EXTI_ICER1 |=(1<<( USART3_IRQ - 32 )))

#define	NVIC_IRQ52_UART3_Dis        (EXTI_ICER1 |=(1<<( USART4_IRQ - 32 )))
#define	NVIC_IRQ53_UART4_Dis        (EXTI_ICER1 |=(1<<( USART5_IRQ - 32 )))


//SPI
#define	NVIC_IRQ35_SPI1_Dis        (EXTI_ICER1 |=(1<<( SPI1_IRQ - 32 )))
#define	NVIC_IRQ36_SPI2_Dis        (EXTI_ICER1 |=(1<<( SPI2_IRQ - 32 )))
#define	NVIC_IRQ51_SPI3_Dis        (EXTI_ICER1 |=(1<<( SPI3_IRQ - 32 )))

//IRQ_ENABLE
//***********************************************************
//EXT
#define NVIC_IRQ6_EXTI0_EN          (EXTI_ISER0 |=(1<<6))
#define	NVIC_IRQ7_EXTI1_EN          (EXTI_ISER0 |=(1<<7))
#define	NVIC_IRQ8_EXTI2_EN          (EXTI_ISER0 |=(1<<8))
#define	NVIC_IRQ9_EXTI3_EN          (EXTI_ISER0 |=(1<<9))
#define	NVIC_IRQ10_EXTI4_EN         (EXTI_ISER0 |=(1<<10))
#define	NVIC_IRQ23_EXTI5_9_EN       (EXTI_ISER0 |=(1<<23))
#define	NVIC_IRQ40_EXTI10_15_EN     (EXTI_ISER1 |=(1<<8))


//USART
#define	NVIC_IRQ37_USART1_EN        (EXTI_ISER1 |=(1<<( USART1_IRQ - 32 )))
#define	NVIC_IRQ38_USART2_EN        (EXTI_ISER1 |=(1<<( USART2_IRQ - 32 )))
#define	NVIC_IRQ39_USART3_EN        (EXTI_ISER1 |=(1<<( USART3_IRQ - 32 )))

#define	NVIC_IRQ52_UART3_EN        (EXTI_ISER1 |=(1<<( USART4_IRQ - 32 )))
#define	NVIC_IRQ53_UART4_EN        (EXTI_ISER1 |=(1<<( USART5_IRQ - 32 )))

//SPI
#define	NVIC_IRQ35_SPI1_EN        (EXTI_ISER1 |=(1<<( SPI1_IRQ - 32 )))
#define	NVIC_IRQ36_SPI2_EN        (EXTI_ISER1 |=(1<<( SPI2_IRQ - 32 )))
#define	NVIC_IRQ51_SPI3_EN        (EXTI_ISER1 |=(1<<( SPI3_IRQ - 32 )))

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


#endif /* INC_STM32F103X8_H_ */
