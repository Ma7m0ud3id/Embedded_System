/*
 * MYRTOS_ERROR_STATE.h
 *
 *  Created on: Apr 18, 2024
 *      Author: mahmo
 */

#ifndef INC_MYRTOS_ERROR_STATE_H_
#define INC_MYRTOS_ERROR_STATE_H_


typedef enum
{
	ES_NoError,
	ES_Ready_Queue_Init_Error,
	ES_Error_Task_Exceeded_Stack_Size,
	ES_Error_Bubble_Sort,
	ES_Error_SysTick_coounting,
	ES_Error

}MYRTOS_errorID;



#endif /* INC_MYRTOS_ERROR_STATE_H_ */
