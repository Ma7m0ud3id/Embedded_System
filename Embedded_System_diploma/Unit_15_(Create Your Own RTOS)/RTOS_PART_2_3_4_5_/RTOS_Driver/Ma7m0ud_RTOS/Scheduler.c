/*
 * Scheduler.c
 *
 *  Created on: Apr 18, 2024
 *      Author: mahmo
 */

/*
 * ------------
 * | Includes |
 * ------------
 */
#include "Scheduler.h"
#include "MYRTOS_FIFO.h"

//define a macro contain the maximum number of tasks
//#define Max_Num_of_Tasks			100



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//OS States:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
enum OS_Mode_t
{
	OS_Suspend,
	OS_Running
};


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//OS Control Configuration:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
struct
{
	Task_Ref_t* OS_Tasks[100];	//Task Scheduler Table

	unsigned int _S_MSP_OS;
	unsigned int _E_MSP_OS;
	unsigned int PSP_Task_Locator;

	unsigned int No_of_Active_Tasks;

	Task_Ref_t* Current_Task;
	Task_Ref_t* Next_Task;

	enum OS_Mode_t OS_State;

}OS_Control_t;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//OS SVC ID:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef enum
{
	SVC_Activate_Task,
	SVC_Terminate_Task,
	SVC_Task_Waiting_Time,
	SVC_AquireMutex,
	SVC_ReleaseMutex
}SVC_ID_t;

FIFO_Buf_t Ready_Queue;

FIFO_Buf_t* Ready_Queue_FIFO[100];

Task_Ref_t MYRTOS_IDLE_TASK;


/*
 *          ^
 * Priority |
 *          |                 -------                      -------
 *          |                 | SVC |                      | SVC |		<--- Reorder Scheduler Table, Update Ready Queue
 *          |                 -------                      -------
 *          |                |       |                    |       |
 *          |                |       |                    |       |
 *          |                |       |                    |       |
 *          |                |       |                    |       |
 *          |                |       |                    |       |
 *          |                |       |                    |       |
 *          |                |       |                    |       |
 *          |                |        ----------          |        ----------
 *          |                |        | PendSV |          |        | PendSV |		<--- Switch Context/Restore for current & next task
 *          |                |        ----------          |        ----------
 *          |                |                  |         |                  |
 *          |                |                  |         |                  |
 *          |                |                  |         |                  |
 *          |                |                  |         |                  |
 *          |                |                  |         |                  |
 *          |                |                  |         |                  |
 *          |       ---------                    ---------                    ---------
 *          |       | Task1 |                    | Task2 |                    | Task1 |
 *          |       ---------                    ---------                    ---------
 *          |
 *          |
 *          |
 *          |________________________________________________________________________________________ Time
 *
 *          				<< Task1 Priority == Task2 Priority    >>
 *          				<< Round Robin between Task1 and Task2 >>
 *          				<< This when we Activate the two tasks >>
 */

/*
 *          ^
 * Priority |
 *          |                 -----------                      -----------
 *          |                 | SysTick |                      | SysTick |		<--- Decide What Current and Next
 *          |                 -----------                      -----------
 *          |                |           |                    |           |
 *          |                |           |                    |           |
 *          |                |           |                    |           |
 *          |                |           |                    |           |
 *          |                |           |                    |           |
 *          |                |           |                    |           |
 *          |                |           |                    |           |
 *          |                |            ----------          |            ----------
 *          |                |            | PendSV |          |            | PendSV |		<--- Switch Context/Restore for current & next task
 *          |                |            ----------          |            ----------
 *          |                |                      |         |                      |
 *          |                |                      |         |                      |
 *          |                |                      |         |                      |
 *          |                |                      |         |                      |
 *          |                |                      |         |                      |
 *          |                |                      |         |                      |
 *          |       ---------                        ---------                        ---------
 *          |       | Task1 |                        | Task2 |                        | Task1 |
 *          |       ---------                        ---------                        ---------
 *          |
 *          |
 *          |
 *          |________________________________________________________________________________________ Time
 *                           ^                                ^
 *                           |                                |
 *                           1ms (Ticker)                     1ms (Ticker)
 *
 *          				<< Task1 Priority == Task2 Priority    >>
 *          				<< Round Robin between Task1 and Task2 >>
 *          				<< Each Task work for 1ms              >>
 */
__attribute ((naked)) void PendSV_Handler(void)
{
	//Switch Context/Restore of our tasks

	/*
	 * ----------------------------------------
	 * | Save The Context of the current task |
	 * ----------------------------------------
	 */

	/*
	 * 1. Get the Current_PSP from CPU registers
	 * |-------|
	 * |  xPSR |
	 * |  PC   |
	 * |  LR   |
	 * |  R12  |
	 * |  R3   |
	 * |  R2   |
	 * |  R1   |
	 * |  R0   |	<-- Current PSP
	 * |-------|
	 */
	OS_Get_PSP_Val(OS_Control_t.Current_Task->Current_PSP_Task);

	/*
	 * 2. Save the registers from R4 to R11
	 * |-------|
	 * |  R4   |
	 * |  R5   |
	 * |  R6   |
	 * |  R7   |
	 * |  R8   |
	 * |  R9   |
	 * |  R10  |
	 * |  R11  |
	 * |-------|
	 */
	//using this Current_PSP (Pointer) tp store (R4 to R11)
	OS_Control_t.Current_Task->Current_PSP_Task-- ;
	__asm volatile("mov %0,r4 " : "=r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task-- ;
	__asm volatile("mov %0,r5 " : "=r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task-- ;
	__asm volatile("mov %0,r6 " : "=r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task-- ;
	__asm volatile("mov %0,r7 " : "=r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task-- ;
	__asm volatile("mov %0,r8 " : "=r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task-- ;
	__asm volatile("mov %0,r9 " : "=r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task-- ;
	__asm volatile("mov %0,r10 " : "=r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task-- ;
	__asm volatile("mov %0,r11 " : "=r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );

	/*
	 * 3. Save the Current Value of PSP --> it Saved in Current_PSP_Task
	 * |-------|
	 * |  R4   |
	 * |  R5   |
	 * |  R6   |
	 * |  R7   |
	 * |  R8   |
	 * |  R9   |
	 * |  R10  |
	 * |  R11  |		<-- Current_PSP_Task
	 * |-------|
	 */

	/*
	 * -----------------------------------------------------------------------------------------------
	 * |=============================================================================================|
	 * -----------------------------------------------------------------------------------------------
	 */



	/*
	 * ----------------------------------------
	 * | Restore The Context of the Next task |
	 * ----------------------------------------
	 */
	if (OS_Control_t.Next_Task != NULL){
	   OS_Control_t.Current_Task = OS_Control_t.Next_Task;
	   OS_Control_t.Next_Task = NULL;
	}
	/*
	 * 1. Write the values of registers from memory to CPU registers
	 * |-------|
	 * |  R4   |
	 * |  R5   |
	 * |  R6   |
	 * |  R7   |
	 * |  R8   |
	 * |  R9   |
	 * |  R10  |
	 * |  R11  |		<-- Current_PSP_Task
	 * |-------|
	 */
	__asm volatile("mov r11,%0 " : : "r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task++ ;
	__asm volatile("mov r10,%0 " : : "r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task++ ;
	__asm volatile("mov r9,%0 " : : "r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task++ ;
	__asm volatile("mov r8,%0 " : : "r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task++ ;
	__asm volatile("mov r7,%0 " : : "r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task++ ;
	__asm volatile("mov r6,%0 " : : "r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task++ ;
	__asm volatile("mov r5,%0 " : : "r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task++ ;
	__asm volatile("mov r4,%0 " : : "r" (*(OS_Control_t.Current_Task->Current_PSP_Task))  );
	OS_Control_t.Current_Task->Current_PSP_Task++ ;

	/*
	 * 2.Set PSP with Current_PSP_Task
	 */
	OS_Set_PSP_Val(OS_Control_t.Current_Task->Current_PSP_Task);

	/*
	 * 3.The other registers will restored automatically by CPU
	 * |-------| |-----------------------------|
	 * |  xPSR | |*****************************|
	 * |  PC   | |*****************************|
	 * |  LR   | |*****************************|
	 * |  R12  | |<CPU read them automatically>|
	 * |  R3   | |*****************************|
	 * |  R2   | |*****************************|
	 * |  R1   | |*****************************|
	 * |  R0   |	<-- Current PSP		<-- PSP
	 * |-------| |-----------------------------|
	 * |  R4   | |*****************************|
	 * |  R5   | |*****************************|
	 * |  R6   | |*****************************|
	 * |  R7   | |***<we read them manually>***|
	 * |  R8   | |*****************************|
	 * |  R9   | |*****************************|
	 * |  R10  | |*****************************|
	 * |  R11  | |*****************************|
	 * |-------| |-----------------------------|
	 */

	/*
	 * 4. Branch to LR to return from Interrupt handler
	 * LR --> contain EXC_RETURN Code
	 */
	__asm volatile("BX LR");
}


unsigned char IdleTaskLed ;
void IDLE_TASK_FUNC(void){


	while(1)
		{
		    IdleTaskLed ^= 1 ;
			__asm("NOP");
		}
}



void MyRTOS_Create_MainStack(){

	OS_Control_t._S_MSP_OS=(unsigned int)&(_estack);
	OS_Control_t._E_MSP_OS= OS_Control_t._S_MSP_OS-Main_Stack_Size;

	OS_Control_t.PSP_Task_Locator=OS_Control_t._E_MSP_OS-8;

}


MYRTOS_errorID MYRTOS_init(void){


	MYRTOS_errorID MYRTOS_init_Error=ES_NoError;


	//Updata OS Mode --> OS_Suspend
	OS_Control_t.OS_State = OS_Suspend;

	//Specify the Main Stack for OS
	MyRTOS_Create_MainStack();


	if(FIFO_init(&Ready_Queue, Ready_Queue_FIFO, 100) != FIFO_NO_ERROR)
	{
		MYRTOS_init_Error = ES_Ready_Queue_Init_Error;
	}

	//Configure IDLE Task
	strcpy(MYRTOS_IDLE_TASK.Task_Name,"IDEL TASK");
	MYRTOS_IDLE_TASK.Task_Priority=255;
	MYRTOS_IDLE_TASK.PF_Task_Entry=IDLE_TASK_FUNC;
	MYRTOS_IDLE_TASK.Task_Stack_Size=300;

	MYRTOS_init_Error=MYRTOS_Create_Task(&MYRTOS_IDLE_TASK);








	return MYRTOS_init_Error;
}



void MYRTOS_Create_STack_Task(Task_Ref_t* Task_Ref_CFG){

	/*
		 * Task Frame:
		 * --------------------------------------------
		 * |This Part is saved/restored automatically |
		 * --------------------------------------------
		 * |-------|
		 * |  xPSR |
		 * |  PC   |	//Next Task Instruction which will fetched
		 * |  LR   |	//Return register which is saved in CPU while Task1 running before Task Switching
		 * |  R12  |
		 * |  R3   |
		 * |  R2   |
		 * |  R1   |
		 * |  R0   |
		 * |-------|
		 * ----------------------------------------------
		 * |This Part is saved/restored by us (manually)|
		 * ----------------------------------------------
		 * |-------|
		 * |  R4   |
		 * |  R5   |
		 * |  R6   |
		 * |  R7   |
		 * |  R8   |
		 * |  R9   |
		 * |  R10  |
		 * |  R11  |
		 * |-------|
		 */

	Task_Ref_CFG->Current_PSP_Task = (unsigned int *)(Task_Ref_CFG->_S_PSP_Task);

	Task_Ref_CFG->Current_PSP_Task--;
	*(Task_Ref_CFG->Current_PSP_Task) = 0x01000000;	//DUMMY xPSR --> you must put T = 1 to avoid Bus Fault (Thumb2 Technology)

	Task_Ref_CFG->Current_PSP_Task--;
	*(Task_Ref_CFG->Current_PSP_Task) = (unsigned int)(Task_Ref_CFG->PF_Task_Entry);	//DUMMY PC

	Task_Ref_CFG->Current_PSP_Task--;
	*(Task_Ref_CFG->Current_PSP_Task) = 0xFFFFFFFD;	//DUMMY LR --> (EXECUTION RETURN CODE --> Thread Mode, PSP)

	//Still 13 General Purpose Register --> We dummy them to 0
	for(int i = 0; i < 13; i++)
	{
		Task_Ref_CFG->Current_PSP_Task--;
		*(Task_Ref_CFG->Current_PSP_Task) = 0;
	}





}


MYRTOS_errorID MYRTOS_Create_Task(Task_Ref_t* Task_Ref_Config){

	MYRTOS_errorID Local_enuErrorState = ES_NoError;

		/*
		 * --> SRAM
		 * -------------
		 * | _S_MSP_   |
		 * |    MSP    |
		 * | _E_MSP_   |
		 * -------------
		 * |  8 Byte   |
		 * -------------
		 * | _S_PSP_   |
		 * | Task1_PSP |
		 * | _E_PSP_   |
		 * -------------
		 * |  8 Byte   |
		 * -------------
		 * | _S_PSP_   |
		 * | Task2_PSP |
		 * | _E_PSP_   |
		 * -------------
		 * |  8 Byte   |
		 * -------------
		 * |   ....    |
		 * |   ....    |
		 * |   ....    |
		 * |   ....    |
		 * -------------
		 * | _eheap    |
		 * -------------
		 */

	// Check if task stack size exceeded the PSP stack size
		if((OS_Control_t.PSP_Task_Locator - Task_Ref_Config->Task_Stack_Size) < (unsigned int)(&(_eheap)))
		{

		     Local_enuErrorState = ES_Error_Task_Exceeded_Stack_Size;
		}

		if(Local_enuErrorState == ES_NoError)
		{
			//Create Its Own PSP Stack
			Task_Ref_Config->_S_PSP_Task = OS_Control_t.PSP_Task_Locator;
			Task_Ref_Config->_E_PSP_Task = (Task_Ref_Config->_S_PSP_Task - Task_Ref_Config->Task_Stack_Size);

			//Aligned 8 bytes spaces between PSP (Task) and PSP (Other Task)
			OS_Control_t.PSP_Task_Locator = (Task_Ref_Config->_E_PSP_Task - 8);
		}

		//Initialize PSP Task Stack
		MYRTOS_Create_STack_Task(Task_Ref_Config);

		//update sch Table
		OS_Control_t.OS_Tasks[OS_Control_t.No_of_Active_Tasks++] = Task_Ref_Config;

		//Task State Update --> Suspend State
		Task_Ref_Config->Task_State = Suspend_State;



		return Local_enuErrorState;
}



void Bubble_Sort_Tasks(void)
{
	unsigned int i, j, Num_Tasks;
	Task_Ref_t *Temp;

	Num_Tasks = OS_Control_t.No_of_Active_Tasks;

	for(i = 0; i < Num_Tasks; i++)
	{
		for(j = 0; j < Num_Tasks - i - 1; j++)
		{
			if(OS_Control_t.OS_Tasks[j]->Task_Priority > OS_Control_t.OS_Tasks[j+1]->Task_Priority)
			{
				Temp = OS_Control_t.OS_Tasks[j];
				OS_Control_t.OS_Tasks[j] = OS_Control_t.OS_Tasks[j+1];
				OS_Control_t.OS_Tasks[j+1] = Temp;
			}
		}
	}
}



MYRTOS_errorID MyRTOS_Reorder_Scheduler_Tabel(void){
	MYRTOS_errorID Local_enuErrorState = ES_NoError;

	//Sort Scheduler Table (OS_Control --> Tasks[100]) --> with Bubble Sort
		//Base on Priority --> (high priority(low number) then low priority(high number))
		Bubble_Sort_Tasks();

	return Local_enuErrorState;
}


MYRTOS_errorID MyRTOS_Update_Ready_Queue(void){
	MYRTOS_errorID Local_enuErrorState = ES_NoError;

	Task_Ref_t *Top_Ready_Queue = NULL;
		unsigned int i = 0;

		Task_Ref_t *P_Curr_Task = NULL;
		Task_Ref_t *P_Next_Task = NULL;

		//Free Ready Queue
		while(FIFO_dequeue(&Ready_Queue, &Top_Ready_Queue) != FIFO_EMPTY);

		//Update Ready Queue
		while(i < OS_Control_t.No_of_Active_Tasks)
		{
			P_Curr_Task = OS_Control_t.OS_Tasks[i];
			P_Next_Task = OS_Control_t.OS_Tasks[i+1];

			/*
			 * ------------------
			 * |Scheduler Table:|
			 * ------------------
			 *
			 * |----------|----------|
			 * | Task1 (1)|  suspend |
			 * |----------|----------|
			 * | Task2 (2)|  waiting |
			 * |----------|----------|
			 * | Task3 (2)|  waiting |
			 * |----------|----------|
			 * | Task4 (3)|  waiting |
			 * |----------|----------|
			 * |    0     |    0     |
			 * |----------|----------|
			 * |    0     |    0     |
			 * |----------|----------|
			 */

			if(P_Curr_Task->Task_State !=Suspend_State){



				//This if we reach to the end of the scheduler table
				if(P_Next_Task->Task_State==Suspend_State){
					FIFO_enqueue(&Ready_Queue, P_Curr_Task);
					P_Curr_Task->Task_State = Ready_State;
					break;
				}
				if(P_Curr_Task->Task_Priority < P_Next_Task->Task_Priority)
				{
					//This if the next task is low priority from the current then we push current to ready queue
					FIFO_enqueue(&Ready_Queue, P_Curr_Task);
					P_Curr_Task->Task_State = Ready_State;
					break;
				}
				else if(P_Curr_Task->Task_Priority == P_Next_Task->Task_Priority)
				{
					//This if the next task is equal the current task in priority then we push current to ready queue
					//and we will continue to the relation of next task with its next
					FIFO_enqueue(&Ready_Queue, P_Curr_Task);
					P_Curr_Task->Task_State = Ready_State;
				}
				else if(P_Curr_Task->Task_Priority > P_Next_Task->Task_Priority)
				{
					//This can't happen because we sort the scheduler table with bubble sort
					Local_enuErrorState = ES_Error_Bubble_Sort;
					break ;
				}
			}

			i++;
		}



	return Local_enuErrorState;
}


void OS_Decide_What_Next(void){

	//This in case The Queue is empty and OS_Control_t.Current_Task->Task_State != Suspend_State
	//This happen when we have only one task and this task is interrupting by svc
	//we need to continue in running it
	if(Ready_Queue.counter == 0 && OS_Control_t.Current_Task->Task_State != Suspend_State)
	{
		OS_Control_t.Current_Task->Task_State = Running_State;




		//add Task to Ready Queue to run it till the task is terminate
		FIFO_enqueue(&Ready_Queue, OS_Control_t.Current_Task);
		OS_Control_t.Next_Task = OS_Control_t.Current_Task;


	}else{


		//dequeue the top of ready queue because this is should running next
		FIFO_dequeue(&Ready_Queue, &OS_Control_t.Next_Task);
		OS_Control_t.Next_Task->Task_State = Running_State;



		//check if the next task priority is equal the current task priority to work with Round Robin Algorithm
		//check if the user doesn't terminate the current task so we will run it
		if((OS_Control_t.Current_Task->Task_Priority == OS_Control_t.Next_Task->Task_Priority) && (OS_Control_t.Current_Task->Task_State != Suspend_State))
		{


			//enqueue the current task in the Ready Queue so that the other task will be on top and current will be after it
			//we do this because we run with Round Robin Algorithm
			FIFO_enqueue(&Ready_Queue, OS_Control_t.Current_Task);
			OS_Control_t.Current_Task->Task_State = Ready_State;
		}
	}




}



MYRTOS_errorID OS_SVC_Services(unsigned int *Stack_Pointer)
{
	MYRTOS_errorID Local_enuErrorState = ES_NoError;
	unsigned char SVC_ID;

	SVC_ID = *((unsigned char *)(((unsigned char *)Stack_Pointer[6])-2));



	if(SVC_ID==SVC_Activate_Task || SVC_ID==SVC_Terminate_Task ){
		Local_enuErrorState = MyRTOS_Reorder_Scheduler_Tabel();
		if(Local_enuErrorState !=ES_NoError){
			while(1);
		}

		Local_enuErrorState = MyRTOS_Update_Ready_Queue();
		if(Local_enuErrorState !=ES_NoError){
			while(1);
		}
		if(OS_Control_t.OS_State == OS_Running)
		{
			if(strcmp(OS_Control_t.Current_Task->Task_Name, "IDEL TASK") != 0)
			{
				//Decide What task should run Next
				OS_Decide_What_Next();

				//Trigger OS_PendSV (Switch Context/Restore for our Tasks)
				Trigger_OS_PendSV();
			}
		}


	}else if(SVC_ID==SVC_Task_Waiting_Time){

		Local_enuErrorState = MyRTOS_Reorder_Scheduler_Tabel();
		if(Local_enuErrorState !=ES_NoError){
			while(1);
		}

		Local_enuErrorState = MyRTOS_Update_Ready_Queue();
		if(Local_enuErrorState !=ES_NoError){
			while(1);
		}
	}

	/*switch(SVC_ID)
	{
	case SVC_Activate_Task:
	case SVC_Terminate_Task:
		//Update Scheduler Table
		Local_enuErrorState = MyRTOS_Reorder_Scheduler_Tabel();
		if(Local_enuErrorState !=ES_NoError){
			while(1);
		}


		//Update Ready Queue
		Local_enuErrorState = MyRTOS_Update_Ready_Queue();
		if(Local_enuErrorState !=ES_NoError){
			while(1);
		}


		break;

	case SVC_Task_Waiting_Time:

		break;*/


	return Local_enuErrorState;
}




MYRTOS_errorID MYRTOS_OS_SVC_Set(SVC_ID_t svc_id)
{
	MYRTOS_errorID Local_enuErrorState = ES_NoError;

	//we will use svc to reorder Task_Scheduler and update Ready_Queue
	switch(svc_id)
	{
	case SVC_Activate_Task:
		__asm("SVC #0x00");
		break;

	case SVC_Terminate_Task:
		__asm("SVC #0x01");
		break;

	case SVC_Task_Waiting_Time:
		__asm("SVC #0x02");
		break;

	case SVC_AquireMutex:
		__asm("SVC #0x03");  //Assignment Task
		break;

	case SVC_ReleaseMutex:
		__asm("SVC #0x04"); //Assignment Task
		break;
	}

	return Local_enuErrorState;
}




MYRTOS_errorID MYRTOS_Active_Task(Task_Ref_t* Task_Ref_Config){

	MYRTOS_errorID Local_enuErrorState = ES_NoError;
	Task_Ref_Config->Task_State=Waiting_State;
	MYRTOS_OS_SVC_Set(SVC_Activate_Task);





	return Local_enuErrorState;

}
MYRTOS_errorID MYRTOS_Terminat_Task(Task_Ref_t* Task_Ref_Config){
	MYRTOS_errorID Local_enuErrorState = ES_NoError;

	Task_Ref_Config->Task_State=Suspend_State;

	MYRTOS_OS_SVC_Set(SVC_Terminate_Task);





	return Local_enuErrorState;
}


MYRTOS_errorID MYRTOS_TaskWait(unsigned int NoTICKS,Task_Ref_t* SelfTref){
	MYRTOS_errorID Local_enuErrorState = ES_NoError;
	SelfTref->Task_Timing_Waiting.Task_Blocking=Blocking_Enable;
	SelfTref->Task_Timing_Waiting.Ticks_Count=NoTICKS;

	SelfTref->Task_State=Suspend_State;

	Local_enuErrorState=MYRTOS_OS_SVC_Set(SVC_Task_Waiting_Time);

	return Local_enuErrorState;
}


void MYRTOS_Update_TasksWaitingTime()
{
	for (int i =0; i < OS_Control_t.No_of_Active_Tasks ; i++  )
	{
		if (OS_Control_t.OS_Tasks[i]->Task_State == Suspend_State) //it is blocking until meet the time line
		{
			if (OS_Control_t.OS_Tasks[i]->Task_Timing_Waiting.Task_Blocking == Blocking_Enable)
			{
				OS_Control_t.OS_Tasks[i]->Task_Timing_Waiting.Ticks_Count-- ;
				if (OS_Control_t.OS_Tasks[i]->Task_Timing_Waiting.Ticks_Count == 1)
				{
					OS_Control_t.OS_Tasks[i]->Task_Timing_Waiting.Task_Blocking = Blocking_Disable ;
					OS_Control_t.OS_Tasks[i]->Task_State = Waiting_State ;
					MYRTOS_OS_SVC_Set(SVC_Task_Waiting_Time);
				}
			}
		}
	}
}

MYRTOS_errorID MYRTOS_AcquireMutex(Mutex_ref* Mref , Task_Ref_t* Tref){

	MYRTOS_errorID Local_enuErrorState = ES_NoError;

	if(Mref->CurrentTUser==NULL){

		Mref->CurrentTUser=Tref;
	}else{

		if(Mref->NextTUser==NULL){
			Mref->NextTUser=Tref;
			Tref->Task_State=Suspend_State;
			Local_enuErrorState=MYRTOS_OS_SVC_Set(SVC_Terminate_Task);

		}else{
			return MutexisReacedToMaxNumberOfUsers ;
		}
	}

	return Local_enuErrorState;

}
MYRTOS_errorID MYRTOS_ReleaseMutex(Mutex_ref* Mref){
	MYRTOS_errorID Local_enuErrorState = ES_NoError;
	if(Mref->CurrentTUser!=NULL){
		Mref->CurrentTUser=Mref->NextTUser;
		Mref->NextTUser=NULL;
		Mref->CurrentTUser->Task_State=Waiting_State;
		Local_enuErrorState = MYRTOS_OS_SVC_Set(SVC_Activate_Task);
	}


	return Local_enuErrorState;
}



MYRTOS_errorID MYRTOS_Start_OS(void){


	MYRTOS_errorID Local_enuErrorState=ES_NoError;
	unsigned int Function_State = 1;

	//Enter the OS in Running Mode instead of Suspend Mode
	OS_Control_t.OS_State = OS_Running;

	//Set Default Task --> IDLE Task
	OS_Control_t.Current_Task = &MYRTOS_IDLE_TASK;

	//Activate IDLE Task --> Run IDLE Task
	Local_enuErrorState = MYRTOS_Active_Task(&MYRTOS_IDLE_TASK);

	//Start Ticker --> 1ms
	Function_State = OS_Start_Ticker();
	if(Function_State)
		Local_enuErrorState = ES_Error_SysTick_coounting;

	//Set PSP with PSP of Current Task
	OS_Set_PSP_Val(OS_Control_t.Current_Task->Current_PSP_Task);

	//Set SP shadow to PSP instead of MSP
	OS_Set_SP_shadowto_PSP;

	//Switch from Privileged to Unprivileged
	OS_Switch_Privileged_to_Unprivileged;

	//Run Current Task
	OS_Control_t.Current_Task->PF_Task_Entry();

	return Local_enuErrorState;
}

















