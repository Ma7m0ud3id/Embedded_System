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

//I2C1
#define I2C1_BASE									0x40005400UL

//I2C2
#define I2C2_BASE									0x40005800UL
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

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
}I2C_TypeDef;

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

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: I2C
//-*-*-*-*-*-*-*-*-*-*-*
#define I2C1										((I2C_TypeDef *)I2C1_BASE)
#define I2C2										((I2C_TypeDef *)I2C2_BASE)



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

//I2C Enable
#define RCC_I2C1_CLK_EN()		(RCC->APB2ENR |= 1<<21)
#define RCC_I2C2_CLK_EN()		(RCC->APB2ENR |= 1<<22)

//I2C_Reset
#define RCC_I2C1_CLK_REST()		(RCC->APB2RSTR |= 1<<21)
#define RCC_I2C2_CLK_REST()		(RCC->APB2RSTR |= 1<<22)

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

//I2C IRQ
#define I2C1_EV_IRQ									31
#define I2C1_ER_IRQ									32
#define I2C2_EV_IRQ									33
#define I2C2_ER_IRQ									34


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

//DIsable I2C interrupts
#define NVIC_I2C1_EV_IRQ31_DISABLE			(EXTI_ICER0|=(1<<I2C1_EV_IRQ));
#define NVIC_I2C1_ER_IRQ32_DISABLE			(EXTI_ICER1|=(1<<(I2C1_ER_IRQ-32)));
#define NVIC_I2C2_EV_IRQ33_DISABLE			(EXTI_ICER1|=(1<<(I2C2_EV_IRQ-32)));
#define NVIC_I2C2_ER_IRQ34_DISABLE			(EXTI_ICER1|=(1<<(I2C2_ER_IRQ-32)));

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



//enable I2C interrupts
#define NVIC_I2C1_EV_IRQ31_ENABLE			(EXTI_ISER0|=(1<<I2C1_EV_IRQ));
#define NVIC_I2C1_ER_IRQ32_ENABLE			(EXTI_ISER1|=(1<<(I2C1_ER_IRQ-32)));
#define NVIC_I2C2_EV_IRQ33_ENABLE			(EXTI_ISER1|=(1<<(I2C2_EV_IRQ-32)));
#define NVIC_I2C2_ER_IRQ34_ENABLE			(EXTI_ISER1|=(1<<(I2C2_ER_IRQ-32)));

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//======================================================================

/********************************************************/
/********************************************************/
/********************************************************/
/*******************  Bit definition  ********************/
/********************************************************/
/********************************************************/


/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */
/*******************  Bit definition for I2C_OAR1 register  *******************/
#define I2C_OAR1_ADD_Pos                    (1U)
#define I2C_OAR1_ADDMODE_Pos				(15U)
#define I2C_OAR1_ADDMODE_Msk				(0x1UL << I2C_OAR1_ADDMODE_Pos)     /*!< 0x00008000 */
#define I2C_OAR1_ADDMODE					I2C_OAR1_ADDMODE_Msk                /*!< Addressing mode (slave mode) */
/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */
/*******************  Bit definition for I2C_CCR register  *******************/
#define I2C_CCR_DUTY_Pos					(14U)
#define I2C_CCR_DUTY_Msk					(0x1UL << I2C_CCR_DUTY_Pos)     /*!< 0x00008000 */
#define I2C_CCR_DUTY						I2C_CCR_DUTY_Msk                /*!< Fm mode duty cycle */
#define I2C_CCR_F_or_S_Pos					(15U)
#define I2C_CCR_F_or_S_Msk					(0x1UL << I2C_CCR_F_or_S_Pos)     /*!< 0x00008000 */
#define I2C_CCR_F_or_S						I2C_CCR_F_or_S_Msk                /*!< I2C master mode selection */


#endif /* INC_STM32F103X8_H_ */
