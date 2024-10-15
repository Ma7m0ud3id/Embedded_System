/*
 * SPI.h
 *
 * Created: 7/14/2024 8:30:00 PM
 *  Author: mahmo
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "Private.h"
#include "DIO.h"


typedef struct
{
	uint8_t Device_Mode ;       //this parameter specific SPI master or slave mode
	//set based on @ref_SPI_Device_Mode
	
	uint8_t Data_Order ;       //this parameter specific SPI  2_line or 1_line and bidirectional or unidirectional
	//set based on @ref_SPI_Communiction_Mode
	
	uint8_t Baud_Rate ;       //this parameter specific SPI Baud Rate Fclk/2 max not need in slave mode
	// set based on @ref_SPI_Baud_Rate
	
	uint8_t    CLK_Speed ;   // this parameter specific SPI CLOCK Speed normal or double
	// set base on @Ref SPI_CLK_Speed
	
	uint8_t CLK_Polarity ;    //this parameter specific SPI polarity idle high or idle low
	//set based on @ref_SPI_CLK_Polarity

	uint8_t CLK_Phase  ;		//this parameter specific SPI Phase first edge or second edge
	//set based on @ref_SPI_CLK_Phase
	
	uint8_t IRQ_Enable ;      //this parameter specific SPI Interrupt request enable
	//set based on @ref_SPI_IRQ_Enable
	
	void (*P_IRQ_CallBack)(void);    //c function   callBack when interrupt happen
}SPI_Config;


//@ref_SPI_Device_Mode
#define SPI_Mode_Master                              (uint8_t)(1<<4)
#define SPI_Mode_slave                               (uint8_t)(0)

//@ref_SPI_Data_Order
#define SPI_Data_Order_MSB_First                     (uint8_t)(0)
#define SPI_Data_Order_LSB_First                     (uint8_t)(1<<5)

//@ref_SPI_Baud_Rate
//Normal Speed
#define SPI_Baud_Rate_4                              (uint8_t)(0)
#define SPI_Baud_Rate_16                             (uint8_t)(1<<0)
#define SPI_Baud_Rate_64                             (uint8_t)(1<<1)
#define SPI_Baud_Rate_128                            (uint8_t)(3<<0)

//Double Speed
#define SPI_Baud_Rate_Double_Speed_2                 (uint8_t)(0)
#define SPI_Baud_Rate_Double_Speed_8                 (uint8_t)(1<<0)
#define SPI_Baud_Rate_Double_Speed_3                 (uint8_t)(1<<1)
#define SPI_Baud_Rate_Double_Speed_64                (uint8_t)(3<<0)

// @ref_SPI_CLK_Polarity
#define SPI_CLK_Polarity_LOW_idle                     (uint8_t)(0)
#define SPI_CLK_Polarity_HIGH_idle                    (uint8_t)(1<<3)

//@ref_SPI_CLK_Phase
#define SPI_CLK_Phase_first_edge                     (uint8_t)(0)
#define SPI_CLK_Phase_second_edge                    (uint8_t)(1<<2)

//@ref_SPI_IRQ_Enable
#define SPI_IR_Enable_NONE                           (uint8_t)(0)
#define SPI_IRQ_Enable_TXC                           (uint8_t)(1<<7)

//@Ref SPI_CLK_Speed
#define SPI_CLK_Speed_Normal                         0
#define SPI_CLK_Speed_Double                         1
enum Polling_Mechanism
{
	SPI_disable,
	SPI_enable
};
/* ================================================================ */
/* =========== APIs Supported by "MCAL SPI DRIVER" ================ */
/* ================================================================ */

void MCAL_SPI_Init(SPI_TypeDef_t *SPIx , SPI_Config *cfg);
void MCAL_SPI_DeInit(SPI_TypeDef_t *SPIx);

void MCAL_SPI_GPIO_Set_Pins(SPI_TypeDef_t *SPIx);

void MCAL_SPI_Send_Data(SPI_TypeDef_t *SPIx , uint16_t *pTxBuffer ,enum Polling_Mechanism polling_En);
void MCAL_SPI_Recieve_Data(SPI_TypeDef_t *SPIx, uint16_t *pRxBuffer, enum Polling_Mechanism Polling_En);

void MCAL_SPI_TX_RX(SPI_TypeDef_t *SPIx, uint16_t *pTxBuffer, enum Polling_Mechanism Polling_En);


#endif /* SPI_H_ */