/*
 * Stm32f103x8_gpio_drivers.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mahmoud_3id
 */

#ifndef INC_STM32F103X8_SPI_DRIVERS_H_
#define INC_STM32F103X8_SPI_DRIVERS_H_
//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x8.h"
#include "Stm32f103x8_gpio_drivers.h"
#include "Stm32f103x8_RCC_drivers.h"
struct S_IRQ_Source
{
	uint8_t TXE:1;
	uint8_t RXNE:1;
	uint8_t ERRI:1;
	uint8_t Reserved:5;
};
//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct{


	uint8_t SPI_MODE;        // Specifies Master/Slave to be configured.
	                          // This parameter can be a value of @ref SPI MODE

	uint8_t SPI_Communication_MODE; // Specifies Full duplex(TX/RX) or (RX)only
                                     // This parameter can be a value of @ref SPI SPIC ommunication MODE define


	uint8_t SPI_CLOCK_Freq ;      // Specifies SPI_CLOCK_Freq (speed of frequancy to send and recieve data)
		                            // This parameter can be a value of @ref SPI CLOCK Freq define

	uint8_t DATA_SIZE;     // Specifies frame of data size (8 or 16 bit)
		                  // This parameter can be a value of @ref SPI DATA SIZE define

	uint8_t Fram_Format;          // Specifies Fram_Format to check  LSB or MSB
			                  // This parameter can be a value of @ref SPI Fram_Format define

	uint8_t NSS_MODE;        // Specifies the stop bin in frame of data
			                  // This parameter can be a value of @ref SPI NSS define

	uint8_t CLK_Polarity;       // Specifies CLK_Polarity
		                            // This parameter can be a value of @ref SPI CLK_Polarity define
	uint8_t CLKPhase;       // Specifies CLKPhase
			                     // This parameter can be a value of @ref SPI CLKPhase define

	uint8_t IRQ_ENABLE;     // Specifies ENABLE Interrupt Requist
	                        // This parameter can be a value of @ref SPI IRQ_ENABLE define

	void (* SPI_IRQ_FUNCTION )() ;    // Specifies  Interrupt Function
                                     // This parameter can be a value of @ref SPI Interrupt_Function define

}SPI_Pinconfige_t;
//-----------------------------
//Macros Configuration References

//-----------------------------

//@ref SPI MODE
//Bit 2 MSTR: Master selection --> in CR1
#define SPI_Device_Mode_Slave											(uint32_t)(0)	//0: Slave configuration
#define SPI_Device_Mode_Master											(uint32_t)(1 << 2)	//1: Master configuration
//************************************************************************************


// @ref SPI SPIC ommunication MODE define
#define SPI_Directional_2Line                 (uint32_t)(0)
#define SPI_Directional_2Line_RXONLY          (uint32_t)(1<<10)
#define SPI_Directional_1Line_receive_only    (uint32_t)(1<<15)
#define SPI_Directional_1Line_transmit_only    (uint32_t)(1<<15 | 1<<14)


//@ref SPI CLOCK Freq define
#define SPI_Freq_Div_2                   (uint32_t)(0)
#define SPI_Freq_Div_4                   (uint32_t)(1<<3)
#define SPI_Freq_Div_8                   (uint32_t)(2<<3)
#define SPI_Freq_Div_16                  (uint32_t)(3<<3)
#define SPI_Freq_Div_32                  (uint32_t)(4<<3)
#define SPI_Freq_Div_64                  (uint32_t)(5<<3)
#define SPI_Freq_Div_128                 (uint32_t)(6<<3)
#define SPI_Freq_Div_256                 (uint32_t)(7<<3)

//@ref SPI NSS define
//Hardware --> CR2
#define SPI_NSS_Hardware_Slave											(uint32_t)(0)			//0: Software slave management disabled (Hardware enabled)
#define SPI_NSS_Hardware_Master_SS_Output_Enable						(uint32_t)(1 << 2)		//1: SS output is enabled --> Bit 2 SSOE: SS output enable & 0 on Bit 9 SSM
#define SPI_NSS_Hardware_Master_SS_Output_Disable						~((uint32_t)(1 << 2))	//0: SS output is disabled --> Bit 2 SSOE: SS output enable & 0 on Bit 9 SSM
//Software --> CR1
#define SPI_NSS_Software_Internal_slave_select_Enable					(uint32_t)((1 << 9) | (1 << 8))	//1: Software slave management enabled & 1 on Bit 8 SSI: Internal slave select to enable SSI
#define SPI_NSS_Software_Internal_slave_select_Disable					(uint32_t)(1 << 9) 	//1: Software slave management enabled & 0 on Bit 8 SSI: Internal slave select to disable SSI
//************************************************************************************

//@ref SPI DATA SIZE define
#define SPI_8_BIT                            (uint32_t)(0x00000000U)
#define SPI_16_BIT                           (uint32_t)(1<<11)


//@ref SPI Fram_Format define
#define SPI_MSB                               (uint32_t)(0)
#define SPI_LSB                               (uint32_t)(1<<7)

//@ref SPI CLK_Polarity define
#define SPI_CPOL_0_idel                        (uint32_t)(0)
#define SPI_CPOL_1_idel                        (uint32_t)(1<<1)

//@ref SPI CLKPhase define
#define SPI_CPHA_Frist_Clock                    (uint32_t)(0)
#define SPI_CPHA_Second_Clock                   (uint32_t)(1<<0)

//@ref SPI IRQ_ENABLE define
#define SPI_IRQ_NON                             (uint32_t)(0)
#define SPI_IRQ_TX_EN                           (uint32_t)(1<<7)
#define SPI_IRQ_RX_EN                           (uint32_t)(1<<6)
#define SPI_IRQ_ERROR_EN                         (uint32_t)(1<<5)

enum Poling_Micanism{
	SPI_ENABLE,
	SPI_DISABLE
};
/*
 *
* ===============================================
* APIs Supported by "MCAL SPI DRIVER"
* ===============================================
*/
void MCAL_SPI_Init(typedef_SPI* SPIx,SPI_Pinconfige_t* SPI_conf);
void MCAL_SPI_DeInit(typedef_SPI* SPIx);
void MCAL_SPI_GPIO_Set_Pins(typedef_SPI* SPIx);
void MCAL_SPI_SendData(typedef_SPI* SPIx,uint16_t* DATA,enum Poling_Micanism Enable);
void MCAL_SPI_ReceiveData(typedef_SPI* SPIx,uint16_t* DATA,enum Poling_Micanism Enable);
void MCAL_SPI_Tx_Rx(typedef_SPI *SPIx, uint16_t *DATA, enum Poling_Micanism Enable);

void MCAL_SPI_WAIT_TC(typedef_SPI* SPIx);




#endif /* INC_STM32F103X8_SPI_DRIVERS_H_ */
