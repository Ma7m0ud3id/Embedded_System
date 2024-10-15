/*
 * UART.h
 *
 * Created: 4/24/2024 5:18:58 PM
 *  Author: mahmo
 */ 


#ifndef UART_H_
#define UART_H_

#include "Private.h"
#include "ERROR_STAT.h"
#include "DIO.h"
//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct  
{
	uint8_t UART_MODE;        //  selects between TX RX mode
	                          // This parameter can be a value of @ref UART MODE
							  
	uint8_t UART_TYPE;		 //  selects between Asynchronous and Synchronous mode
	                          // This parameter can be a value of @ref UART TYPE
							  
    uint16_t UART_Baud_Rate;      // Specifies Baurder Rate (speed of frequancy to send and recieve data)
                                  // This parameter can be a value of @ref UART Baud Rate define

    uint8_t DATA_SIZE;     // Specifies frame of data size (5 or 6 or 7 or8 or 9 bit)
                          // This parameter can be a value of @ref USART DATA SIZE define

    uint8_t Parity;          // Specifies Parity to check  Error  in data
                             // This parameter can be a value of @ref USART Parity define

    uint8_t STOP_MODE;        // Specifies the stop bin in frame of data
                              // This parameter can be a value of @ref USART STOP define
							  
	uint8_t Select_Interrupt;  // Specifies Select_Interrupt which Interrupt can used
	                           // This parameter can be a value of @ref Select_Interrupt define
	
	void (* IRQ_FUNCTION_RX_Complete )(void) ;    // Specifies  Interrupt Function IRQ_FUNCTION_RX_Complete
	void (* IRQ_FUNCTION_TX_Complete )(void) ;    // Specifies  Interrupt Function IRQ_FUNCTION_TX_Complete
	void (* IRQ_FUNCTION_Register_Empty )(void) ;    // Specifies  Interrupt Function IRQ_FUNCTION_Register_Empty	                                              
}USART_Pinconfige_t;


//@ref UART MODE
#define UART_TX                  (uint8_t)(1<<3)
#define UART_RX                  (uint8_t)(1<<4)
#define UART_TX_RX               (uint8_t)((1<<4)|(1<<3))


//@ref UART TYPE
#define Asynchronous (uint8_t)0
#define synchronous  (uint8_t)(1<<6)

//@ref UART Baud Rate define 

//_RESET_U2X
#define USART_BaudRate_2400_RESET_U2X                   207
#define USART_BaudRate_4800_RESET_U2X                   103
#define USART_BaudRate_9600_RESET_U2X                   51
#define USART_BaudRate_14400_RESET_U2X                  34
#define USART_BaudRate_19200_RESET_U2X                  25
#define USART_BaudRate_28800_RESET_U2X                  16
#define USART_BaudRate_38400_RESET_U2X                  12
#define USART_BaudRate_57600_RESET_U2X                  8
#define USART_BaudRate_76800_RESET_U2X                  6
#define USART_BaudRate_115200_RESET_U2X                 3
#define USART_BaudRate_230400_RESET_U2X                 1
#define USART_BaudRate_250000_RESET_U2X                 1
#define USART_BaudRate_500000_RESET_U2X                 0
#define USART_BaudRate_1000000_RESET_U2X                0

//_SET_U2X
#define USART_BaudRate_2400_SET_U2X                   416
#define USART_BaudRate_4800_SET_U2X                   207
#define USART_BaudRate_9600_SET_U2X                   103
#define USART_BaudRate_14400_SET_U2X                  68
#define USART_BaudRate_19200_SET_U2X                  51
#define USART_BaudRate_28800_SET_U2X                  34
#define USART_BaudRate_38400_SET_U2X                  25
#define USART_BaudRate_57600_SET_U2X                  16
#define USART_BaudRate_76800_SET_U2X                  12
#define USART_BaudRate_115200_SET_U2X                 8
#define USART_BaudRate_230400_SET_U2X                 3
#define USART_BaudRate_250000_SET_U2X                 3
#define USART_BaudRate_500000_SET_U2X                 1
#define USART_BaudRate_1000000_SET_U2X                0


//@ref USART DATA SIZE define
#define USART_5_BIT                 (uint8_t)(0)
#define USART_6_BIT                 (uint8_t)(1<<1)
#define USART_7_BIT                 (uint8_t)(2<<1)
#define USART_8_BIT                 (uint8_t)(3<<1)
#define USART_9_BIT                 (uint8_t)(7<<1)//just check


//@ref USART Parity define
#define USART_NON_PARITY            (uint8_t)(0<<4)
#define USART_EVEN_PARITY           (uint8_t)(2<<4)
#define USART_ODD_PARITY            (uint8_t)(3<<4)

//@ref USART STOP define
#define USART_1_STOP_BIT                  (uint8_t)(0<<3)
#define USART_2_STOP_BIT                   (uint8_t)(1<<3)

#define  RX_Complete_Interrupt_Enable        (*UCSRB|=(1<<7))
#define  RX_Complete_Interrupt_Disable        (*UCSRB&=~(1<<7))
#define  TX_Complete_Interrupt_Enable        (*UCSRB|=(1<<6))
#define  TX_Complete_Interrupt_Disable        (*UCSRB&=~(1<<6))
#define  Register_Empty_Interrupt_Enable     (*UCSRB|=(1<<5))
#define  Register_Empty_Interrupt_Disable     (*UCSRB&=~(1<<5))

//@ref Select_Interrupt define
typedef enum {
	RX_Complete,
	TX_Complete,
	Register_Empty,
	RX_Complete_TX_Complete,
	RX_Complete_Register_Empty,
	TX_Complete_Register_Empty,
	RX_Complete_TX_Complete_Register_Empty,
	DIS_RX_Complete_TX_Complete_Register_Empty
}eslect_interrupt; 



//#define UARTDIV(_PCLK_, _BAUD_)  (uint16_t) (_PCLK_/(16 * _BAUD_ ))

enum Booling_Micanism{
	UART_ENABLE,
	UART_DISABLE
};


/*
 *
* ===============================================
* APIs Supported by "MCAL USART DRIVER"
* ===============================================
*/

_errorID MCAL_UART_Init(USART_Pinconfige_t* USART_conf);
_errorID MCAL_UART_DeInit();
_errorID MCAL_UART_GPIO_Set_Pins();
_errorID MCAL_UART_SendData(uint16_t* DATA,enum Booling_Micanism Enable);
uint16_t MCAL_UART_ReceiveData(enum Booling_Micanism Enable);
_errorID MCAL_UART_WAIT_TC();

#endif /* UART_H_ */