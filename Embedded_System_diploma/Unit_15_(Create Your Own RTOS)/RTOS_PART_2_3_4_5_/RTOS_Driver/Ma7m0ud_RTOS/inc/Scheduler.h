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
//Task Error States:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef enum
{
	ES_NoError,
	ES_Ready_Queue_Init_Error,
	ES_Error_Task_Exceeded_Stack_Size,
	ES_Error_Bubble_Sort,
	ES_Error_SysTick_coounting,
	ES_Error,
	MutexisReacedToMaxNumberOfUsers

}MYRTOS_errorID;


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




//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Mutex Reference Configuration:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct {
	unsigned char* Ppayload;
	unsigned int   PayloadSize ;
	Task_Ref_t* 	   CurrentTUser ;
	Task_Ref_t* 	   NextTUser ;
	char 		   MutexName[30]  ;
} Mutex_ref;


/*
 * ======================================================================
 * 			APIs Supported by "Scheduler"
 * ======================================================================
 */


MYRTOS_errorID MYRTOS_init(void);
MYRTOS_errorID MYRTOS_Create_Task(Task_Ref_t* Task_Ref_Config);
MYRTOS_errorID MYRTOS_Active_Task(Task_Ref_t* Task_Ref_Config);
MYRTOS_errorID MYRTOS_Terminat_Task(Task_Ref_t* Task_Ref_Config);
MYRTOS_errorID MYRTOS_Start_OS(void);
MYRTOS_errorID MYRTOS_TaskWait(unsigned int NoTICKS,Task_Ref_t* SelfTref);

MYRTOS_errorID MYRTOS_AcquireMutex(Mutex_ref* Mref , Task_Ref_t* Tref);
MYRTOS_errorID MYRTOS_ReleaseMutex(Mutex_ref* Mref);
#endif /* INC_SCHEDULER_H_ */
