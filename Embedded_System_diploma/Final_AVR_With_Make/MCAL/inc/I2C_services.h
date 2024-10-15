/*
 * I2C_services.h
 *
 * Created: 10/15/2024 6:16:08 PM
 *  Author: mahmo
 */ 


#ifndef I2C_SERVICES_H_
#define I2C_SERVICES_H_

#include "I2C.h"

/* slave address of MCU2 */
#define Slave_Address			0b00000001

typedef union
{
	uint8_t Data[6];
	struct
	{
		uint8_t dat1;
		uint8_t dat2;
		uint8_t dat3;
		uint8_t dat4;
		uint8_t dat5;
		uint8_t Check_Sum;
	};
}Communication_Frame_t;

ES_t Communication_enuInitMaster(void);

ES_t Communication_enuInitSlave(void);

ES_t Communication_enuSendFrame(Communication_Frame_t *Copy_uniSentFrame);

ES_t Communication_enuReceiveFrame(Communication_Frame_t *Copy_uniReceivedFrame);




#endif /* I2C_SERVICES_H_ */