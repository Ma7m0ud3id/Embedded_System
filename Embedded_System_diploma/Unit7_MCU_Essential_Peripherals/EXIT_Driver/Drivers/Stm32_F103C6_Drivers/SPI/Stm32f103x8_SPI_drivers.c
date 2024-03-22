/*
 * Stm32f103x8_gpio_drivers.c
 *
 *  Created on: Sep 27, 2023
 *      Author: Mahmoud_3id
 */
//----------------------------
//include
//-----------------------------
#include "Stm32f103x8_SPI_drivers.h"

SPI_Pinconfige_t* SPI_confige=NULL;

//uint32_t DIV,FRACTION,Freq,Mode_,boudrade;

void MCAL_SPI_Init(typedef_SPI* SPIx,SPI_Pinconfige_t* SPI_conf){
	SPI_confige=SPI_conf;
		//uint32_t pclk ,BRR  ;
	//Sefety register
	uint16_t Tmpreg_CR1 = 0;
	uint16_t Tmpreg_CR2 = 0;
	//RCC_SPI
		if(SPIx ==SPI1){
			RCC_SPI1_CLK_EN();
		}else if(SPIx==SPI2){
			RCC_SPI2_CLK_EN();
		}else if(SPIx==SPI3){
			RCC_SPI3_CLK_EN();
		}

		/*Bit 6 SPE: SPI enable
		0: Peripheral disabled
		1: Peripheral enabled*/
		Tmpreg_CR1 |=(1<<6);
// Set the DFF bit to define 8- or 16-bit data frame format
		Tmpreg_CR1 |= (SPI_confige->DATA_SIZE);
//Select the CPOL and CPHA bits to define one of the four relationships between the
//		data transfer and the serial clock
		Tmpreg_CR1 |= (SPI_confige->CLK_Polarity);
		Tmpreg_CR1 |= (SPI_confige->CLKPhase);
//The frame format (MSB-first or LSB-first depending on the value of the LSBFIRST bit in
//		the SPI_CR1 register)
		Tmpreg_CR1 |= (SPI_confige->Fram_Format);
//NSS MODE
		if(SPI_confige->NSS_MODE== SPI_NSS_Hardware_Master_SS_Output_Enable){
			Tmpreg_CR2 |= SPI_conf->NSS_MODE;

		}else if(SPI_confige->NSS_MODE==SPI_NSS_Hardware_Master_SS_Output_Disable){

			Tmpreg_CR2 |= SPI_conf->NSS_MODE;
		}

		else{
			Tmpreg_CR1 |= SPI_conf->NSS_MODE;
		}
	//SPI Mode
		Tmpreg_CR1 |= (SPI_confige->SPI_MODE);
	//SPI Communication
		Tmpreg_CR1 |= (SPI_confige->SPI_Communication_MODE);
	//SPI Freq
		Tmpreg_CR1 |= (SPI_confige->SPI_CLOCK_Freq);
	//SPI IRQ
		if( SPI_confige->IRQ_ENABLE!=SPI_IRQ_NON){



			Tmpreg_CR2 |= SPI_conf->IRQ_ENABLE;



			if(SPIx==SPI1){


				NVIC_IRQ35_SPI1_EN;


			}else if(SPIx==SPI2){


				NVIC_IRQ36_SPI2_EN;


			}else if(SPIx==SPI3){


				NVIC_IRQ51_SPI3_EN;
			}
		}

   SPIx->SPI_CR1=Tmpreg_CR1;
   SPIx->SPI_CR2=Tmpreg_CR2;

}




void MCAL_SPI_DeInit(typedef_SPI* SPIx){
	if(SPIx==SPI1){

		RCC_SPI1_CLK_REST();
		NVIC_IRQ35_SPI1_Dis;

	}else if(SPIx==SPI2){

		RCC_SPI2_CLK_REST();
		NVIC_IRQ36_SPI2_Dis;

	}else if(SPIx==SPI3){

		RCC_SPI3_CLK_REST();
		NVIC_IRQ51_SPI3_Dis;
	}


}


void MCAL_SPI_GPIO_Set_Pins(typedef_SPI* SPIx){

	GPIO_Pinconfige_t GPIO_Pinconfige;

	/*
	 * SCLK:
	 * 		Master	-->  Alternate function push-pull
	 * 		Slave	-->  Input floating
	 * MOSI:
	 * 		Full duplex / master						--> Alternate function push-pull
	 * 		Full duplex / slave							--> Input floating / Input pull-up
	 * MISO:
	 * 		Full duplex / master 						--> Input floating / Input pull-up
	 * 		Full duplex / slave (point to point) 		--> Alternate function push-pull
	 * 		Full duplex / slave (multi-slave)			--> Alternate function open drain
	 * NSS:
	 * 		Hardware master /slave 						--> Input floating/ Input pull-up / Input pull-down
	 * 		Hardware master/ NSS output enabled			--> Alternate function push-pull
	 * 		Software Not used. 							--> Can be used as a GPIO
	 */
	if(SPIx==SPI1){

		if(SPI_confige->SPI_MODE==SPI_Device_Mode_Master){
			//SCK
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_5;
			GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
			GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
			GPIOx_init(GPIOA, &GPIO_Pinconfige);

			//MOSI_PIN
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_7;
			GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
			GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
			GPIOx_init(GPIOA, &GPIO_Pinconfige);

			//MISO_PIN
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_6;
			GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
			GPIOx_init(GPIOA, &GPIO_Pinconfige);


			if(SPI_confige->NSS_MODE==SPI_NSS_Hardware_Master_SS_Output_Disable){

				//NSS
				GPIO_Pinconfige.Pin_Number=GPIO_PIN_4;
				GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
				GPIOx_init(GPIOA, &GPIO_Pinconfige);
			}else if(SPI_confige->NSS_MODE==SPI_NSS_Hardware_Master_SS_Output_Enable){
				//NSS
				GPIO_Pinconfige.Pin_Number=GPIO_PIN_4;
				GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
				GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
				GPIOx_init(GPIOA, &GPIO_Pinconfige);

			}
		}else if(SPI_confige->SPI_MODE==SPI_Device_Mode_Slave){

			//SCK
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_5;
			GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
			GPIOx_init(GPIOA, &GPIO_Pinconfige);

			//MOSI_PIN
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_7;
			GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
			GPIOx_init(GPIOA, &GPIO_Pinconfige);

			//MISO_PIN
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_6;
			GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
			GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
			GPIOx_init(GPIOA, &GPIO_Pinconfige);

			if(SPI_confige->NSS_MODE==SPI_NSS_Hardware_Slave){
				//NSS
				GPIO_Pinconfige.Pin_Number=GPIO_PIN_4;
				GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
				GPIOx_init(GPIOA, &GPIO_Pinconfige);
			}

		}

	}else if(SPIx==SPI2){


		if(SPI_confige->SPI_MODE==SPI_Device_Mode_Master){
			//SCK
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_13;
			GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
			GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
			GPIOx_init(GPIOB, &GPIO_Pinconfige);

			//MOSI_PIN
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_15;
			GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
			GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
			GPIOx_init(GPIOB, &GPIO_Pinconfige);

			//MISO_PIN
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_14;
			GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
			GPIOx_init(GPIOB, &GPIO_Pinconfige);


			if(SPI_confige->NSS_MODE==SPI_NSS_Hardware_Master_SS_Output_Disable){

				//NSS
				GPIO_Pinconfige.Pin_Number=GPIO_PIN_12;
				GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
				GPIOx_init(GPIOB, &GPIO_Pinconfige);
			}else if(SPI_confige->NSS_MODE==SPI_NSS_Hardware_Master_SS_Output_Enable){
				//NSS
				GPIO_Pinconfige.Pin_Number=GPIO_PIN_12;
				GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
				GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
				GPIOx_init(GPIOB, &GPIO_Pinconfige);

			}
		}else if(SPI_confige->SPI_MODE==SPI_Device_Mode_Slave){

			//SCK
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_13;
			GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
			GPIOx_init(GPIOB, &GPIO_Pinconfige);

			//MOSI_PIN
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_15;
			GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
			GPIOx_init(GPIOB, &GPIO_Pinconfige);

			//MISO_PIN
			GPIO_Pinconfige.Pin_Number=GPIO_PIN_14;
			GPIO_Pinconfige.Mode=GPIO_MODE_OUTPUT_AF_PP;
			GPIO_Pinconfige.Speed=GPIO_MODE_speed_10_MHz;
			GPIOx_init(GPIOB, &GPIO_Pinconfige);

			if(SPI_confige->NSS_MODE==SPI_NSS_Hardware_Slave){
				//NSS
				GPIO_Pinconfige.Pin_Number=GPIO_PIN_12;
				GPIO_Pinconfige.Mode=GPIO_MODE_INPUT_FLO;
				GPIOx_init(GPIOB, &GPIO_Pinconfige);
			}

		}









	}else if(SPIx==SPI3){

	}
}


void MCAL_SPI_SendData(typedef_SPI* SPIx,uint16_t* DATA,enum Poling_Micanism Enable){

	if(Enable== SPI_ENABLE){
		while(!(SPIx->SPI_SR)&(1<<1));
	}

	if(SPI_confige->DATA_SIZE==SPI_8_BIT){
		SPIx->SPI_DR=((*DATA)&(uint8_t)0xFF);

	}else if(SPI_confige->DATA_SIZE==SPI_16_BIT){
		SPIx->SPI_DR=*DATA;
	}




}



void MCAL_SPI_WAIT_TC(typedef_SPI* SPIx){

	/*Bits 15:8 Reserved, must be kept at reset value.
	Bit 7 BSY: Busy flag
	0: SPI (or I2S) not busy
	1: SPI (or I2S) is busy in communication or Tx buffer is not empty
	This flag is set and cleared by hardware.
	Note: BSY flag must be used with caution: refer to Section 25.3.7 and Section 25.3.8.
	Bit 6 OVR: Overrun flag
	0: No overrun occurred
	1: Overrun occurred
	This flag is set by hardware and reset by a software sequence. Refer to Section 25.4.7 for
	the software sequence*/

	while(!((SPIx->SPI_SR & 1<<6) | (SPIx->SPI_SR & 1<<7) ));

}


void MCAL_SPI_ReceiveData(typedef_SPI* SPIx,uint16_t* DATA,enum Poling_Micanism Enable){

	if(Enable== SPI_ENABLE){
			while(!(SPIx->SPI_SR)&(1<<0));
		}
	if(SPI_confige->DATA_SIZE==SPI_8_BIT){
		*DATA=(((uint16_t)SPIx->SPI_DR)&(uint8_t)0xFF);

	}else if(SPI_confige->DATA_SIZE==SPI_16_BIT){
		SPIx->SPI_DR=*DATA;
	}

		*DATA=(uint16_t)SPIx->SPI_DR;

}

void MCAL_SPI_Tx_Rx(typedef_SPI *SPIx, uint16_t *DATA, enum Poling_Micanism Enable){
	if(Enable== SPI_ENABLE){
		while(!(SPIx->SPI_SR)&(1<<1));
	}
	SPIx->SPI_DR=*DATA;

	if(Enable== SPI_ENABLE){
		while(!(SPIx->SPI_SR)&(1<<0));
	}
	*DATA=SPIx->SPI_DR;
}


/* SPI1 global interrupt                          */
void SPI1_IRQHandler (void){
	/*struct S_IRQ_Source irq_src;
	irq_src.TXE = ((SPI1->SR >> 1) & 1);
	irq_src.RXNE = ((SPI1->SR >> 2) & 1);
	irq_src.ERRI = ((SPI1->SR >> 5) & 1);*/
	SPI_confige->SPI_IRQ_FUNCTION();

}
/* SPI2 global interrupt                          */
void SPI2_IRQHandler (void){
	/*struct S_IRQ_Source irq_src;
	irq_src.TXE = ((SPI1->SR >> 1) & 1);
	irq_src.RXNE = ((SPI1->SR >> 2) & 1);
	irq_src.ERRI = ((SPI1->SR >> 5) & 1);*/
	SPI_confige->SPI_IRQ_FUNCTION();

}
/* SPI3 global interrupt                          */
void SPI3_IRQHandler(void){
	/*struct S_IRQ_Source irq_src;
	irq_src.TXE = ((SPI1->SR >> 1) & 1);
	irq_src.RXNE = ((SPI1->SR >> 2) & 1);
	irq_src.ERRI = ((SPI1->SR >> 5) & 1);*/
	SPI_confige->SPI_IRQ_FUNCTION();

}
