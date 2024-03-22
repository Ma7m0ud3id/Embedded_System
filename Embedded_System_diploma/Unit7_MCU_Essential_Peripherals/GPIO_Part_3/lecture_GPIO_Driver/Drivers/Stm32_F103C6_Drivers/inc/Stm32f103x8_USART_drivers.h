/*
 * Stm32f103x8_gpio_drivers.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mahmoud_3id
 */

#ifndef INC_STM32F103X8_USART_DRIVERS_H_
#define INC_STM32F103X8_USART_DRIVERS_H_
//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x8.h"
#include "Stm32f103x8_gpio_drivers.h"
#include "Stm32f103x8_RCC_drivers.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct{


	uint8_t UART_MODE;        // Specifies TX/RX to be configured.
	                          // This parameter can be a value of @ref UART MODE

	uint32_t UART_Baud_Rate;      // Specifies Baurder Rate (speed of frequancy to send and recieve data)
		                            // This parameter can be a value of @ref UART Baud Rate define

	uint8_t DATA_SIZE;     // Specifies frame of data size (8 or 9 bit)
		                  // This parameter can be a value of @ref USART DATA SIZE define

	uint8_t Parity;          // Specifies Parity to check  Error  in data
			                  // This parameter can be a value of @ref USART Parity define

	uint8_t STOP_MODE;        // Specifies the stop bin in frame of data
			                  // This parameter can be a value of @ref USART STOP define

	uint8_t UART_HW_FLOW_CTL;      // Specifies Control Flow (CTL or RTL)
		                            // This parameter can be a value of @ref USART HW_FLOW_CTL define

	uint8_t IRQ_ENABLE;     // Specifies ENABLE Interrupt Requist
	                        // This parameter can be a value of @ref USART IRQ_ENABLE define

	void (* IRQ_FUNCTION )(void) ;    // Specifies  Interrupt Function
                                     // This parameter can be a value of @ref USART Interrupt_Function define

}USART_Pinconfige_t;
//-----------------------------
//Macros Configuration References

//-----------------------------
// @ref UART MODE
#define USART_TX                  (uint32_t)(1<<3)
#define USART_RX                  (uint32_t)(1<<2)
#define USART_TX_RX               (uint32_t)((1<<2)|(1<<3))

//@ref UART Baud Rate define
#define USART_BaudRate_2400                   2400
#define USART_BaudRate_9600                   9600
#define USART_BaudRate_19200                  19200
#define USART_BaudRate_57600                  57600
#define USART_BaudRate_115200                 115200
#define USART_BaudRate_230400                 230400
#define USART_BaudRate_460800                 460800
#define USART_BaudRate_921600                 921600
#define USART_BaudRate_2250000                2250000
#define USART_BaudRate_4500000                4500000



//@ref USART DATA SIZE define
#define USART_8_BIT                 (uint32_t)(0)
#define USART_9_BIT                 (uint32_t)(1<<12)


//@ref USART Parity define
#define USART_NON_PARITY            (uint32_t)(0)
#define USART_EVEN_PARITY           (uint32_t)(1<<10)
#define USART_ODD_PARITY            (uint32_t)(1<<10 | 1<<9)

//@ref USART STOP define
#define USART_1_STOP_BIT                  (uint32_t)(0)
#define USART_Half_STOP_BIT               (uint32_t)(1<<12)
#define USART_2_STOP_BIT                   (uint32_t)(2<<12)
#define USART_One_and_Half_STOP_BIT          (uint32_t)((3<<12))


//@ref USART HW_FLOW_CTL define
#define USART_HW_FLOW_NON                       (uint32_t)(0)
#define USART_HW_FLOW_CTS_EN                    (uint32_t) (1<<9)
#define USART_HW_FLOW_RTS_EN                    (uint32_t) (1<<8)
#define USART_HW_FLOW_RTS_CTS_EN                (uint32_t) ((1<<8)|(1<<9))

//@ref USART IRQ_ENABLE define
#define USART_IRQ_ENABLE_NON                    (uint32_t)(0)
#define USART_IRQ_ENABLE_TXE                    (uint32_t)(1<<7)
#define USART_IRQ_ENABLE_TC                     (uint32_t)(1<<6)
#define USART_IRQ_ENABLE_RXNEIE                 (uint32_t)(1<<5)
#define USART_IRQ_ENABLE_PE                     (uint32_t)(1<<8)

//@ref USART Interrupt_Function define

enum USART_IRQ_EVENT{
	USART_IRQ_TXE,
	USART_IRQ_TC,
	USART_IRQ_RXNEIE,
	USART_IRQ_ORE,
	USART_IRQ_PE
};


//BaudRate Calculation
//USARTDIV = fclk / (16 * Baudrate)
//USARTDIV_MUL100 =
// uint32((100 *fclk ) / (16 * Baudrate) == (25 *fclk ) / (4* Baudrate) )
//DIV_Mantissa_MUL100 = Integer Part (USARTDIV  )  * 100
//DIV_Mantissa = Integer Part (USARTDIV  )
//DIV_Fraction = (( USARTDIV_MUL100  - DIV_Mantissa_MUL100  ) * 16 ) / 100

#define USARTDIV(_PCLK_, _BAUD_)							(uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)						(uint32_t) ( (25 * _PCLK_ ) / (4  * _BAUD_ ))
#define Mantissa_MUL100(_PCLK_, _BAUD_)						(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)							(uint32_t) (USARTDIV(_PCLK_, _BAUD_) )
#define DIV_Fraction(_PCLK_, _BAUD_)						(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) -  Mantissa_MUL100(_PCLK_, _BAUD_) ) * 16 ) / 100 )
#define UART_BRR_Register(_PCLK_, _BAUD_)					(( Mantissa (_PCLK_, _BAUD_) ) <<4 )|( (DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )





enum Booling_Micanism{
	ENABLE,
	DISABLE
};
/*
 *
* ===============================================
* APIs Supported by "MCAL USART DRIVER"
* ===============================================
*/
void MCAL_UART_Init(typedef_USART* USARTx,USART_Pinconfige_t* USART_conf);
void MCAL_UART_DeInit(typedef_USART* USARTx);
void MCAL_UART_GPIO_Set_Pins(typedef_USART* USARTx);
void MCAL_UART_SendData(typedef_USART* USARTx,uint16_t* DATA,enum Booling_Micanism Enable);
void MCAL_UART_ReceiveData(typedef_USART* USARTx,uint16_t* DATA,enum Booling_Micanism Enable);
void MCAL_UART_WAIT_TC(typedef_USART* USARTx);




#endif /* INC_STM32F103X8_GPIO_DRIVERS_H_ */
