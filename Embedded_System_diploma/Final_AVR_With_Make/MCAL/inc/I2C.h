/*
 * I2C.h
 *
 * Created: 10/15/2024 5:35:54 PM
 *  Author: mahmo
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "Private.h"
#include "DIO.h"

#define SCL_FREQUENCY						100000UL
#define I2C_PRESCALER						I2C_PRESCALER_1

#define ECU_ADDRESS							0b00000001

#define I2C_ONE								1
#define I2C_MAX_SLAVES						127


/* Macro for setting the TWBR value based on CPU frequency and SCL frequency */
#define TWBR_VALUE							( (F_CPU - 16*SCL_FREQUENCY) / (2*SCL_FREQUENCY * I2C_PRESCALER) )
#define SET_TWBR_VALUE						TWBR = TWBR_VALUE

/* I2C prescaler values */
#define I2C_PRESCALER_1						1
#define I2C_PRESCALER_4						4
#define I2C_PRESCALER_16					16
#define I2C_PRESCALER_64					64


#define SET_I2C_PRESCALER_1					TWSR&=~(1<<0) &(~(1<<1))


#define SET_I2C_PRESCALER_4					TWSR&=~(1<<1);\
                                             TWSR|= (1<<0)

#define SET_I2C_PRESCALER_16				TWSR&=~(1<<0);\
                                            TWSR|= (1<<1)

#define SET_I2C_PRESCALER_64				TWSR|= (1<<0) | (1<<1)



#define SET_I2C_ENABLE						TWCR|=(1<<2)



#define SET_ECU_ADDRESS					TWAR=((ECU_ADDRESS<<1)|0x01)




#define SET_START_CONDITION					TWCR|= (1<<5);
#define CLEAR_START_CONDITION				TWCR&=~(1<<5);
#define SET_STOP_CONDITION					TWCR|= (1<<4);
#define SET_ACKNOWLEDGE						TWCR|= (1<<6);


#define CLEAR_FLAG							TWCR|= (1<<7);
#define WAIT_FLAG							!((TWCR>>7) & 1)


#define SET_SLAVE_ADDRESS(Address)			TWDR=(Address<<1)
#define SET_SLAVE_ACTION(Action)			TWDR|=Action




/* Macros for checking I2C status */
#define START_CONDITION_TRANSMIT			(TWSR & 0xf8) == 0x08
#define REPEAT_START_CONDITION_TRANSMIT		(TWSR & 0xf8) == 0x10
#define SLA_WRITE_TRANSMIT					(TWSR & 0xf8) == 0x18
#define SLA_READ_TRANSMIT					(TWSR & 0xf8) == 0x40
#define MASTER_DATA_TRANSMIT				(TWSR & 0xf8) == 0x28
#define SLAVE_DATA_RECIEVED					(TWSR & 0xf8) == 0x80
#define SLAVE_WRITE_RECIEVE_ADDRESS			(TWSR & 0xf8) == 0x60
#define SLAVE_READ_RECIEVE_ADDRESS			(TWSR & 0xf8) == 0xA8




/* ================================================================ */
/* =========== APIs Supported by "MCAL SPI DRIVER" ================ */
/* ================================================================ */





ES_t I2C_enuInitMaster	(void);

ES_t I2C_enuInitSlave	(void);

ES_t I2C_enuStartCondition	(void);

ES_t I2C_enuRepeatStartCondition	(void);

ES_t I2C_enuStopCondition	(void);

ES_t I2C_enuSendSlaveAddress	(uint8_t Copy_u8SlaveAddress , uint8_t Copy_u8Action);

ES_t I2C_enuSlaveCheckItsAdress (void);

ES_t I2C_enuMasterSendData	(uint8_t Copy_u8Data);

ES_t I2C_enuSlaveRecieveData	(uint8_t * Copy_Pu8Data);




#endif /* I2C_H_ */