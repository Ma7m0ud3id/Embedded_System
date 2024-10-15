/*
 * UART.c
 *
 * Created: 4/24/2024 5:19:42 PM
 *  Author: mahmo
 */ 
#include "../inc/UART.h"
#define PCLK 8000000U

USART_Pinconfige_t UART_config;
uint16_t data;
void Get_Select_Interrupt(eslect_interrupt Select);

_errorID MCAL_UART_Init(USART_Pinconfige_t* USART_conf){
	_errorID Local_enuErrorState=ES_NoError;
	UART_config=*USART_conf;
	
	
	
	//Set  Baud Rate
	*UBRRH &=~(1<<7);////UBRRH==>UBRRH
	//select working no UCSRC
	*UBRRH=(uint8_t)(UART_config.UART_Baud_Rate>>8);
	*UBRRL=(uint8_t)UART_config.UART_Baud_Rate;
	
	//RESET U2x 
	*UCSRA&=~(1<<1);
	
	
	
	
	
	
	
	//Set Fram********************************
	
	
	/*
		• Bit 7 – URSEL: Register Select
		This bit selects between accessing the UCSRC or the UBRRH Register. It is read as one when
		reading UCSRC. The URSEL must be one when writing the UCSRC.
    */
	*UBRRH |=(1<<7);
	if (UART_config.DATA_SIZE==USART_9_BIT)
	{
		//Set Fram 9 BIT
		
		
		//UBRRH==>UCSRC
		*UBRRH|=(uint8_t)USART_8_BIT;//??? ??? ??? 4 ?? ?? ????????? ?? ??? ???? ?? ?????? ???? 
		*UCSRB|=(1<<2);	
	} 
	else
	{
		
		*UBRRH |=(uint8_t)UART_config.DATA_SIZE;
		*UCSRB&=~(1<<2);	
	}
	//Set Type
	*UBRRH |=UART_config.UART_TYPE;
	//Set Parity
	*UBRRH |=UART_config.Parity;
	//Set Stop
	*UBRRH |=UART_config.STOP_MODE;
	
	//Set_UART_Interrupt
	Get_Select_Interrupt(UART_config.Select_Interrupt);
	
	//Enable TX RX
	*UCSRB|=UART_config.UART_MODE;
	
	return Local_enuErrorState;
}
_errorID MCAL_UART_DeInit(){
	_errorID Local_enuErrorState=ES_NoError;
	*UBRRH |=(1<<7);
	*UBRRH=134;
	*UCSRB=0;
	*UCSRA=0; 
	
	return Local_enuErrorState;
}
_errorID MCAL_UART_GPIO_Set_Pins(){
	_errorID Local_enuErrorState=ES_NoError;
	DIR_PIN(DDRD,PIN0,INPUT);
	DIR_PIN(DDRD,PIN1,OUTPUT);
	return Local_enuErrorState;
}
_errorID MCAL_UART_SendData(uint16_t* DATA,enum Booling_Micanism Enable){//uint16_t* DATA
	_errorID Local_enuErrorState=ES_NoError;
	data=DATA;
	if (Enable==UART_ENABLE)
	{
		//Booling_Micanism
		while(!((*UCSRA>>5)&1));
	}
		
		if (UART_config.DATA_SIZE!=USART_9_BIT)
		{
			
			*UDR=(uint8_t)*DATA;
			
		}
		else
		{
			
			if (*DATA &(uint16_t) 0x100)
			{
				*UCSRB|=(1<<0);
				
			}else{
				*UCSRB &=~(1<<0);
			}
			*UDR=(uint8_t)*DATA;
		}
	
	
	
	return Local_enuErrorState;
}
uint16_t MCAL_UART_ReceiveData(enum Booling_Micanism Enable){
	_errorID Local_enuErrorState=ES_NoError;
	
	if (Enable==UART_ENABLE)
	{
		//Booling_Micanism
		while(!((*UCSRA>>7)&1));
	}
	
		
		if (UART_config.DATA_SIZE!=USART_9_BIT)
		{
			
			return *UDR;
			
		}
		else
		{
			  
			
				uint8_t status= *UCSRA;
				uint8_t resh= *UCSRB;
				uint8_t result= *UDR;
				
				if (status & (1<<4)|(1<<3)|(1<<2))
				{
					return-1;
				}else
				{
					resh=(resh>>1)&0x01;
					return ((resh<<8)|result);
					
				}
				
			
			
		}
		
	
	
	return Local_enuErrorState;
}
_errorID MCAL_UART_WAIT_TC(){
	
}

void Get_Select_Interrupt(eslect_interrupt Select){
	
	switch(Select){
		case RX_Complete:
		    //• Bit 7 – INT1: External Interrupt Request 1 Enable
		    *SREG|=(1<<7);
		     RX_Complete_Interrupt_Enable;
			 TX_Complete_Interrupt_Disable;
			 Register_Empty_Interrupt_Disable;
		     break;
		case TX_Complete:
		    //• Bit 7 – INT1: External Interrupt Request 1 Enable
		    *SREG|=(1<<7);
		     TX_Complete_Interrupt_Enable;
			 RX_Complete_Interrupt_Disable;
			 Register_Empty_Interrupt_Disable;
			 break;
		case Register_Empty:
		    //• Bit 7 – INT1: External Interrupt Request 1 Enable
		    *SREG|=(1<<7);
			RX_Complete_Interrupt_Disable;
		    TX_Complete_Interrupt_Disable;
		    Register_Empty_Interrupt_Enable;
		case RX_Complete_TX_Complete:
		     //• Bit 7 – INT1: External Interrupt Request 1 Enable
		     *SREG|=(1<<7);
			 RX_Complete_Interrupt_Enable;
		    TX_Complete_Interrupt_Enable;
			Register_Empty_Interrupt_Disable;
			break;
		case RX_Complete_Register_Empty:
		    //• Bit 7 – INT1: External Interrupt Request 1 Enable
		    *SREG|=(1<<7); 
			 RX_Complete_Interrupt_Enable;
			 Register_Empty_Interrupt_Enable;
			 TX_Complete_Interrupt_Disable;
			 break;
		case TX_Complete_Register_Empty:
		     //• Bit 7 – INT1: External Interrupt Request 1 Enable
		     *SREG|=(1<<7);
			 TX_Complete_Interrupt_Enable;
			 Register_Empty_Interrupt_Enable;
			 RX_Complete_Interrupt_Disable;
			 break;
		case RX_Complete_TX_Complete_Register_Empty:
		     //• Bit 7 – INT1: External Interrupt Request 1 Enable
		     *SREG|=(1<<7);
			 RX_Complete_Interrupt_Enable;
		     TX_Complete_Interrupt_Enable;
		     Register_Empty_Interrupt_Enable;
			 break;
		case DIS_RX_Complete_TX_Complete_Register_Empty:
		     RX_Complete_Interrupt_Disable;
			 TX_Complete_Interrupt_Disable;
			 Register_Empty_Interrupt_Disable;
			 break;
			 
	}
	
	
}



void  __vector_13 (void) __attribute__((signal));
void __vector_13 (void){
	
	
	UART_config.IRQ_FUNCTION_RX_Complete();
	
}

void  __vector_14 (void) __attribute__((signal));
void __vector_14 (void){
	
	
	
	UART_config.IRQ_FUNCTION_RX_Complete();
	
	
	
}

void  __vector_15 (void) __attribute__((signal));
void __vector_15 (void){
	unsigned char ch='*';
	MCAL_UART_SendData(&ch,UART_ENABLE);
	
	UART_config.IRQ_FUNCTION_RX_Complete();
	
}

