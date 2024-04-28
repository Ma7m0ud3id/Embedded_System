/*
 * Scheduler.h
 *
 *  Created on: Apr 18, 2024
 *      Author: mahmo
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "CortexMx_OS_Porting.h"


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Task AutoStart States:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
enum Task_AutoStart_t
{
	No_AutoStart,
	Yes_AutoStart
};

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Task States:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
enum Task_State_t
{
	Suspend_State,
	Waiting_State,
	Ready_State,
	Running_State
};


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Task Blocking or Not:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
enum Blocking_t
{
	Blocking_Disable,
	Blocking_Enable
};

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Task Timing Waiting Configuration:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
struct Task_Timing_Waiting_t
{
	enum Blocking_t Task_Blocking;
	unsigned int Ticks_Count;
};

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Task Reference Configuration:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct
{
	unsigned int  Task_Stack_Size;
	unsigned char Task_Priority;
	void (*PF_Task_Entry) (void);	//Pointer to Task C Function
	enum Task_AutoStart_t Task_AutoStart;

	unsigned int _S_PSP_Task;	//Not Entered by user
	unsigned int _E_PSP_Task;	//Not Entered by user
	unsigned int *Current_PSP_Task;	//This is the last address of PSP(SP) before we switch to another task

	char Task_Name[30];

	enum Task_State_t Task_State;	//Not Entered by user

	struct Task_Timing_Waiting_t Task_Timing_Waiting;
}Task_Ref_t;


/*
 * ======================================================================
 * 			APIs Supported by "Scheduler"
 * ======================================================================
 */


MYRTOS_errorID MYRTOS_init(void);
MYRTOS_errorID MYRTOS_Create_Task(Task_Ref_t* Task_Ref_Config);

#endif /* INC_SCHEDULER_H_ */
