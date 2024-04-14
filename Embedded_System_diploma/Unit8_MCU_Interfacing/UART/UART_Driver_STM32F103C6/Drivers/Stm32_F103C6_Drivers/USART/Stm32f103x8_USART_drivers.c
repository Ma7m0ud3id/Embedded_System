/*
 * Stm32f103x8_gpio_drivers.c
 *
 *  Created on: Sep 27, 2023
 *      Author: Mahmoud_3id
 */
//----------------------------
//include
//-----------------------------
#include "Stm32f103x8_USART_drivers.h"

USART_Pinconfige_t* USART_confige=NULL;

//uint32_t DIV,FRACTION,Freq,Mode_,boudrade;

void MCAL_UART_Init(typedef_USART* USARTx,USART_Pinconfige_t* USART_conf){
	USART_confige=USART_conf;
	uint32_t pclk ,BRR  ;
//RCC_USART&UART
	if(USARTx==USART1){
		RCC_USART1_CLK_EN();
	}else if(USARTx==USART2){
		RCC_USART2_CLK_EN();
	}else if(USARTx==USART3){
		RCC_USART3_CLK_EN();
	}
	/*else if(USARTx==UART4){
		 RCC_UART4_CLK_EN();
	}else if(USARTx==UART5){
		RCC_UART5_CLK_EN();
	}*/
//Enable the USART by writing the UE bit in USART_CR1 register to 1
	USARTx->USART_CR1|= (1<<13);
//choise TX or RX confige
	USARTx->USART_CR1|=(USART_confige->UART_MODE);
//Program the M bit in USART_CR1 to define the word length
	USARTx->USART_CR1|=(USART_confige->DATA_SIZE);
//Program the number of stop bits in USART_CR2.
	USARTx->USART_CR2|=(USART_confige->STOP_MODE);
//Program the Type of parity (even or odd) to save data in USART_CR1.
	USARTx->USART_CR1|=(USART_confige->Parity);

/*Bit 9 CTSE: CTS enable
	0: CTS hardware flow control disabled
	1: CTS mode enabled, data is only transmitted when the CTS input is asserted (tied to 0). If
Bit 8 RTSE: RTS enable
0: RTS hardware flow control disabled
1: RTS interrupt enabled, data is only requested when there is space in the receive buffer

*/
	USARTx->USART_CR3|=(USART_confige->UART_HW_FLOW_CTL);

//confige Boude_Rate
//ABP1------> USART1
//ABP2------> USART2,USART3,UART4 and UART5
	if(USARTx==USART1){
		pclk=MCAL_RCC_GET_PCLK2();

	}else{
		pclk=MCAL_RCC_GET_PCLK1();
	}

	BRR = UART_BRR_Register(pclk, USART_conf->UART_Baud_Rate) ;

	 USARTx->USART_BRR = BRR ;

	if(USART_confige->IRQ_ENABLE !=USART_IRQ_ENABLE_NON){



		USARTx->USART_CR1|=(USART_confige->IRQ_ENABLE);



		if(USARTx==USART1){


			NVIC_IRQ37_USART1_EN;


			}else if(USARTx==USART2){


				NVIC_IRQ38_USART2_EN;


			}else if(USARTx==USART3){


				NVIC_IRQ39_USART3_EN;


			}else if(USARTx==UART4){


				NVIC_IRQ52_UART3_EN;


			}else if(USARTx==UART5){
				NVIC_IRQ53_UART4_EN;
			}
	}
}














void MCAL_UART_DeInit(typedef_USART* USARTx){


	//RCC_USART&UART
		if(USARTx==USART1){
			RCC_USART1_CLK_REST();
			NVIC_IRQ37_USART1_Dis;


		}else if(USARTx==USART2){
			RCC_USART2_CLK_REST();
			NVIC_IRQ38_USART2_Dis;


		}else if(USARTx==USART3){
			RCC_USART3_CLK_REST();
			NVIC_IRQ39_USART3_Dis;



		}else if(USARTx==UART4){
			 RCC_UART4_CLK_REST();
			 NVIC_IRQ52_UART3_Dis;



		}else if(USARTx==UART5){
			RCC_UART5_CLK_REST();
			NVIC_IRQ53_UART4_Dis;
		}

}



void MCAL_UART_GPIO_Set_Pins(typedef_USART* USARTx){

	GPIO_Pinconfige_t GPIO_Pinconfige;

	if(USARTx==USART1){

		//TX-------->PA9------>30
		GPIO_Pinconfige.Pin_Number=GPIO_PIN_9;
		GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
		GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
		GPIOx_init(GPIOA, &GPIO_Pinconfige);
		//RX-------->PA10------>31
		GPIO_Pinconfige.Pin_Number=GPIO_PIN_10;
		GPIO_Pinconfige.Mode=GPIO_MODE_AF_INPUT;
		GPIOx_init(GPIOA, &GPIO_Pinconfige);

		if(USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_CTS_EN||USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_RTS_CTS_EN){
			//CTS-------->PA11------>32
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_11;
			GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
			GPIOx_init(GPIOA, &GPIO_Pinconfige);



		}else if(USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_RTS_EN||USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_RTS_CTS_EN){

			//RTS-------->PA12------>33
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_12;
			GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
			GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
			GPIOx_init(GPIOA, &GPIO_Pinconfige);



		}


	}else if(USARTx==USART2){

		//TX-------->PA2------>12
		GPIO_Pinconfige.Pin_Number=GPIO_PIN_2;
		GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
		GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
		GPIOx_init(GPIOA, &GPIO_Pinconfige);
		//RX-------->PA3------>13
		GPIO_Pinconfige.Pin_Number=GPIO_PIN_3;
		GPIO_Pinconfige.Mode=GPIO_MODE_AF_INPUT;
		GPIOx_init(GPIOA, &GPIO_Pinconfige);
		if(USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_CTS_EN||USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_RTS_CTS_EN){
			//CTS-------->PA0------>10
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_0;
			GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
			GPIOx_init(GPIOA, &GPIO_Pinconfige);



		}else if(USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_RTS_EN||USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_RTS_CTS_EN){

			//RTS-------->PA1------>11
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_1;
			GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
			GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
			GPIOx_init(GPIOA, &GPIO_Pinconfige);



		}



	}else if(USARTx==USART3){
		//TX-------->PB10------>21
		GPIO_Pinconfige.Pin_Number=GPIO_PIN_10;
		GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
		GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
		GPIOx_init(GPIOB, &GPIO_Pinconfige);
		//RX-------->PB11------>13
		GPIO_Pinconfige.Pin_Number=GPIO_PIN_11;
		GPIO_Pinconfige.Mode=GPIO_MODE_AF_INPUT;
		GPIOx_init(GPIOB, &GPIO_Pinconfige);

		if(USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_CTS_EN||USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_RTS_CTS_EN){
			//CTS-------->PB13------>26
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_13;
			GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
			GPIOx_init(GPIOB, &GPIO_Pinconfige);



		}else if(USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_RTS_EN||USART_confige->UART_HW_FLOW_CTL==USART_HW_FLOW_RTS_CTS_EN){

			//RTS-------->PB14------>27
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_14;
			GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
			GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
			GPIOx_init(GPIOB, &GPIO_Pinconfige);



		}




	}



}
void MCAL_UART_SendData(typedef_USART* USARTx,uint16_t* DATA,enum Booling_Micanism Enable){



	//wait Utile TXE full
//Bit 7 TXE: Transmit data register empty
	if(Enable==ENABLE){
		while(!((USARTx->USART_SR) &(1<<7)));
	}


	if(USART_confige->DATA_SIZE ==USART_9_BIT){
		USARTx->USART_DR=((*DATA)& (uint16_t)0x01FF);

	}else if(USART_confige->DATA_SIZE ==USART_8_BIT){
		USARTx->USART_DR=((*DATA)& (uint8_t) 0xFF);
	}
}

void MCAL_UART_WAIT_TC(typedef_USART* USARTx){
	/*
	 * Bit 6 TC: Transmission complete
This bit is set by hardware if the transmission of a frame containing data is complete and if
TXE is set. An interrupt is generated if TCIE=1 in the USART_CR1 register. It is cleared by a
software sequence (a read from the USART_SR register followed by a write to the
USART_DR register). The TC bit can also be cleared by writing a '0' to it. This clearing
sequence is recommended only for multibuffer communication.
0: Transmission is not complete
1: Transmission is complete
	 */
	while(!(USARTx->USART_SR & 1<<6));

}


void MCAL_UART_ReceiveData(typedef_USART* USARTx,uint16_t* DATA,enum Booling_Micanism Enable){
	//wait Utile RXNE full
	//Bit 5 RXNE: Read data register not empty

		if(Enable==ENABLE){
			while(!( USARTx->USART_SR & 1<<5));
		}

		if(USART_confige->DATA_SIZE == USART_9_BIT){

			if(USART_confige->Parity == USART_NON_PARITY){
				*((uint16_t*)DATA) = USARTx->USART_DR;

			}else{
				*((uint16_t*)DATA) = (USARTx->USART_DR & (uint8_t) 0xFF);


			}


			}else if(USART_confige->DATA_SIZE ==USART_8_BIT){
				if(USART_confige->Parity ==USART_NON_PARITY){
					*((uint16_t*)DATA) = (USARTx->USART_DR &(uint8_t)0xFF);

			   }else{
				  *((uint16_t*)DATA) = (USARTx->USART_DR &(uint8_t)0x7F);


							}
			}







}



/* USART1 global interrupt                          */
void USART1_IRQHandler (void){
	USART_confige->IRQ_FUNCTION();

}
/* USART2 global interrupt                          */
void USART2_IRQHandler (void){
	USART_confige->IRQ_FUNCTION();

}
/* USART3 global interrupt                          */
void USART3_IRQHandler(void){
	USART_confige->IRQ_FUNCTION();

}
