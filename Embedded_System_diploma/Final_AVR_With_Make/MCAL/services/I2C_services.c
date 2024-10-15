/*
 * I2C_services.c
 *
 * Created: 10/15/2024 6:16:29 PM
 *  Author: mahmo
 */ 

#include "../inc/I2C_services.h"

ES_t Communication_enuInitMaster(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = I2C_enuInitMaster();

	return Local_enuErrorState;
}

ES_t Communication_enuInitSlave(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = I2C_enuInitSlave();

	return Local_enuErrorState;
}

ES_t Communication_enuSendFrame(Communication_Frame_t *Copy_uniSentFrame)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = I2C_enuStartCondition();

	Copy_uniSentFrame->Check_Sum = Copy_uniSentFrame->dat1 + Copy_uniSentFrame->dat2 + Copy_uniSentFrame->dat3 + Copy_uniSentFrame->dat4 + Copy_uniSentFrame->dat5;

	if(Local_enuErrorState == ES_OK)
	{
		Local_enuErrorState = I2C_enuSendSlaveAddress(Slave_Address, 0);

		if(Local_enuErrorState == ES_OK)
		{
			uint8_t Local_u8Iterator;
			for( Local_u8Iterator = 0; Local_u8Iterator < 6; Local_u8Iterator++)
			{
				Local_enuErrorState = I2C_enuMasterSendData(Copy_uniSentFrame->Data[Local_u8Iterator]);
				if(Local_enuErrorState == ES_OK)
				{
					continue;
				}
				else
				{
					Local_enuErrorState = ES_NOK;
					break;
				}
			}
		}
		else
		{
			Local_enuErrorState = ES_NOK;
		}


	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

	I2C_enuStopCondition();

	return Local_enuErrorState;
}

ES_t Communication_enuReceiveFrame(Communication_Frame_t *Copy_uniReceivedFrame)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = I2C_enuSlaveCheckItsAdress();

	uint8_t Local_u8CheckSum = 0;

	if(Local_enuErrorState == ES_OK)
	{
		uint8_t Local_u8Iterator;
		for(Local_u8Iterator = 0; Local_u8Iterator < 6; Local_u8Iterator++)
		{
			Local_enuErrorState = I2C_enuSlaveRecieveData(&Copy_uniReceivedFrame->Data[Local_u8Iterator]);
			if(Local_enuErrorState == ES_OK)
			{

				continue;
			}
			else
			{
				Local_enuErrorState = ES_NOK;
				break;
			}
		}


		Local_u8CheckSum = Copy_uniReceivedFrame->dat1 + Copy_uniReceivedFrame->dat2 + Copy_uniReceivedFrame->dat3 + Copy_uniReceivedFrame->dat4 + Copy_uniReceivedFrame->dat5;

		if(Local_u8CheckSum == Copy_uniReceivedFrame->Check_Sum)
		{
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_NOK;
		}
	}

	return Local_enuErrorState;
}