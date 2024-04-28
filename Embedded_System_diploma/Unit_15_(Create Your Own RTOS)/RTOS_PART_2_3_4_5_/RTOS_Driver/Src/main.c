/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */






/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


//***************************************************PART_5_LAB2***********************************************
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
//Learn-in-depth
//Mahmoud 3id
//Mastering_Embedded System online diploma
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "core_cm3.h"
//#include"Stm32f103x8.h"
#include "Stm32f103x8.h"
#include "Stm32f103x8_EXTI_drivers.h"
#include "Stm32f103x8_gpio_drivers.h"
#include "Stm32f103x8_USART_drivers.h"
#include "Stm32f103x8_SPI_drivers.h"
#include "Lcd.h"
#include "Keypad.h"
#include "Scheduler.h"


Task_Ref_t Task4 ,Task1, Task2, Task3;

unsigned char Task1_Led, Task2_Led, Task3_Led,Task4_Led;

unsigned char Buffer1={1,2,3};
unsigned char Buffer2={1,2,3};
Mutex_ref Mref1,Mref2;




void Task1_Func(void)
{

	unsigned char counter=0;
	while(1)
	{
		Task1_Led ^= 1;

		counter++;
		if(counter==100){

			MYRTOS_AcquireMutex(&Mref1,&Task1);
			MYRTOS_Active_Task(&Task2);


		}else if(counter==200){
			counter=0;
			MYRTOS_ReleaseMutex(&Mref1);
			//MYRTOS_Terminat_Task(&Task1);

		}

		//MYRTOS_TaskWait(100 , &Task1);

	}
}

void Task2_Func(void)
{


	unsigned char counter=0;
	while(1)
	{
		Task2_Led ^= 1;

		counter++;
		if(counter==100){
			MYRTOS_Active_Task(&Task3);

		}else if(counter==200){
			counter=0;
			MYRTOS_Terminat_Task(&Task2);

		}

	   //MYRTOS_TaskWait(300 , &Task2);
	}
}

void Task3_Func(void)
{


	unsigned char counter=0;
	while(1)
	{
		Task3_Led ^= 1;

		counter++;
		if(counter==100){
			MYRTOS_Active_Task(&Task4);

		}else if(counter==200){
			counter=0;
			MYRTOS_Terminat_Task(&Task3);

		}

		//MYRTOS_TaskWait(300 , &Task2);
	}
}

void Task4_Func(void)
{

	unsigned char counter=0;
	while(1)
	{
		Task4_Led ^= 1;
		//MYRTOS_TaskWait(500 , &Task3);
		counter++;
		if(counter==3){
			MYRTOS_AcquireMutex(&Mref1,&Task4);
		}
		else if(counter==200){
			counter=0;
			MYRTOS_ReleaseMutex(&Mref1);
			MYRTOS_Terminat_Task(&Task4);

		}
	}
}






int main(void)
{

	MYRTOS_errorID Local_enuErrorState = ES_NoError;

	//HW_init (Initialize Clock Tree, Rest Controller)


	HW_init();


	Local_enuErrorState = MYRTOS_init();
	if(Local_enuErrorState != ES_NoError)
		while(1);

	Mref1.PayloadSize=3;
	Mref1.Ppayload=Buffer1;
	strcpy(Mref1.MutexName, "MUTEX1");

	Mref2.PayloadSize=3;
	Mref2.Ppayload=Buffer2;
	strcpy(Mref2.MutexName, "MUTEX2");

	//Configuration of task1
	Task1.Task_Stack_Size = 1024;
	Task1.PF_Task_Entry = Task1_Func;
	Task1.Task_Priority = 4;
	strcpy(Task1.Task_Name, "Task_1");

	//Configuration of task2
	Task2.Task_Stack_Size = 1024;
	Task2.PF_Task_Entry = Task2_Func;
	Task2.Task_Priority = 3;
	strcpy(Task2.Task_Name, "Task_2");

	//Configuration of task1
	Task3.Task_Stack_Size = 1024;
	Task3.PF_Task_Entry = Task3_Func;
	Task3.Task_Priority = 2;
	strcpy(Task3.Task_Name, "Task_3");

	Task4.Task_Stack_Size = 1024;
	Task4.PF_Task_Entry = Task4_Func;
	Task4.Task_Priority = 1;
	strcpy(Task4.Task_Name, "Task_4");



	//Create the 1st Task
	Local_enuErrorState = MYRTOS_Create_Task(&Task1);
	if(Local_enuErrorState != ES_NoError)
		while(1);


	//Create the 2nd Task
	Local_enuErrorState = MYRTOS_Create_Task(&Task2);
	if(Local_enuErrorState != ES_NoError)
		while(1);

	//Create the 3rd Task
	Local_enuErrorState = MYRTOS_Create_Task(&Task3);
	if(Local_enuErrorState != ES_NoError)
		while(1);

	//Create the 4th Task
	Local_enuErrorState = MYRTOS_Create_Task(&Task4);
	if(Local_enuErrorState != ES_NoError)
		while(1);



	//Activate the 1st Task
	Local_enuErrorState = MYRTOS_Active_Task(&Task1);
	if(Local_enuErrorState != ES_NoError)
		while(1);



	Local_enuErrorState = MYRTOS_Start_OS();
	if(Local_enuErrorState != ES_NoError)
		while(1);



		while(1)
		{
		}

}





//***************************************************PART_5_LAB1***********************************************
/*#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
//Learn-in-depth
//Mahmoud 3id
//Mastering_Embedded System online diploma
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "core_cm3.h"
//#include"Stm32f103x8.h"
#include "Stm32f103x8.h"
#include "Stm32f103x8_EXTI_drivers.h"
#include "Stm32f103x8_gpio_drivers.h"
#include "Stm32f103x8_USART_drivers.h"
#include "Stm32f103x8_SPI_drivers.h"
#include "Lcd.h"
#include "Keypad.h"
#include "Scheduler.h"


Task_Ref_t Task1, Task2, Task3,Task4;

unsigned char Task1_Led, Task2_Led, Task3_Led;



void Task1_Func(void)
{

	unsigned char counter=0;
	while(1)
	{
		Task1_Led ^= 1;

		counter++;
		if(counter==100){
			MYRTOS_Active_Task(&Task2);


		}else if(counter==200){
			counter=0;
			//MYRTOS_Terminat_Task(&Task1);

		}

		//MYRTOS_TaskWait(100 , &Task1);

	}
}

void Task2_Func(void)
{


	unsigned char counter=0;
	while(1)
	{
		Task2_Led ^= 1;

		counter++;
		if(counter==100){
			MYRTOS_Active_Task(&Task3);

		}else if(counter==200){
			counter=0;
			MYRTOS_Terminat_Task(&Task2);

		}

	   //MYRTOS_TaskWait(300 , &Task2);
	}
}

void Task3_Func(void)
{

	unsigned char counter=0;
	while(1)
	{
		Task3_Led ^= 1;
		//MYRTOS_TaskWait(500 , &Task3);
		counter++;
		 if(counter==200){
			counter=0;
			MYRTOS_Terminat_Task(&Task3);

		}
	}
}






int main(void)
{

	MYRTOS_errorID Local_enuErrorState = ES_NoError;

	//HW_init (Initialize Clock Tree, Rest Controller)
	HW_init();


	Local_enuErrorState = MYRTOS_init();
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Configuration of task1
		Task1.Task_Stack_Size = 1024;
		Task1.PF_Task_Entry = Task1_Func;
		Task1.Task_Priority = 3;
		strcpy(Task1.Task_Name, "Task_1");

		//Configuration of task2
		Task2.Task_Stack_Size = 1024;
		Task2.PF_Task_Entry = Task2_Func;
		Task2.Task_Priority = 2;
		strcpy(Task2.Task_Name, "Task_2");

		//Configuration of task1
		Task3.Task_Stack_Size = 1024;
		Task3.PF_Task_Entry = Task3_Func;
		Task3.Task_Priority = 1;
		strcpy(Task3.Task_Name, "Task_3");

		//Create the 1st Task
		Local_enuErrorState = MYRTOS_Create_Task(&Task1);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Create the 2nd Task
		Local_enuErrorState = MYRTOS_Create_Task(&Task2);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Create the 3rd Task
		Local_enuErrorState = MYRTOS_Create_Task(&Task3);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Activate the 1st Task
		Local_enuErrorState = MYRTOS_Active_Task(&Task1);
		if(Local_enuErrorState != ES_NoError)
			while(1);



		Local_enuErrorState = MYRTOS_Start_OS();
		if(Local_enuErrorState != ES_NoError)
			while(1);



		while(1)
		{
		}

}


*/





















//************************************************************PART_4*************************************************

/*#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
//Learn-in-depth
//Mahmoud 3id
//Mastering_Embedded System online diploma
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "core_cm3.h"
//#include"Stm32f103x8.h"
#include "Stm32f103x8.h"
#include "Stm32f103x8_EXTI_drivers.h"
#include "Stm32f103x8_gpio_drivers.h"
#include "Stm32f103x8_USART_drivers.h"
#include "Stm32f103x8_SPI_drivers.h"
#include "Lcd.h"
#include "Keypad.h"
#include "Scheduler.h"


Task_Ref_t Task1, Task2, Task3,Task4;

unsigned char Task1_Led, Task2_Led, Task3_Led;



void Task1_Func(void)
{

	while(1)
	{
		Task1_Led ^= 1;


		MYRTOS_TaskWait(100 , &Task1);

	}
}

void Task2_Func(void)
{

	while(1)
	{
		Task2_Led ^= 1;

	   MYRTOS_TaskWait(300 , &Task2);
	}
}

void Task3_Func(void)
{

	while(1)
	{
		Task3_Led ^= 1;
		MYRTOS_TaskWait(500 , &Task3);
	}
}






int main(void)
{

	MYRTOS_errorID Local_enuErrorState = ES_NoError;

	//HW_init (Initialize Clock Tree, Rest Controller)
	HW_init();


	Local_enuErrorState = MYRTOS_init();
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Configuration of task1
		Task1.Task_Stack_Size = 1024;
		Task1.PF_Task_Entry = Task1_Func;
		Task1.Task_Priority = 3;
		strcpy(Task1.Task_Name, "Task_1");

		//Configuration of task2
		Task2.Task_Stack_Size = 1024;
		Task2.PF_Task_Entry = Task2_Func;
		Task2.Task_Priority = 3;
		strcpy(Task2.Task_Name, "Task_2");

		//Configuration of task1
		Task3.Task_Stack_Size = 1024;
		Task3.PF_Task_Entry = Task3_Func;
		Task3.Task_Priority = 3;
		strcpy(Task3.Task_Name, "Task_3");

		//Create the 1st Task
		Local_enuErrorState = MYRTOS_Create_Task(&Task1);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Create the 2nd Task
		Local_enuErrorState = MYRTOS_Create_Task(&Task2);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Create the 3rd Task
		Local_enuErrorState = MYRTOS_Create_Task(&Task3);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Activate the 1st Task
		Local_enuErrorState = MYRTOS_Active_Task(&Task1);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		Local_enuErrorState = MYRTOS_Active_Task(&Task2);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		Local_enuErrorState = MYRTOS_Active_Task(&Task3);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		Local_enuErrorState = MYRTOS_Start_OS();
		if(Local_enuErrorState != ES_NoError)
			while(1);



		while(1)
		{
		}

}
*/



//************************************************************PART_3*************************************************

/*#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
//Learn-in-depth
//Mahmoud 3id
//Mastering_Embedded System online diploma
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "core_cm3.h"
//#include"Stm32f103x8.h"
#include "Stm32f103x8.h"
#include "Stm32f103x8_EXTI_drivers.h"
#include "Stm32f103x8_gpio_drivers.h"
#include "Stm32f103x8_USART_drivers.h"
#include "Stm32f103x8_SPI_drivers.h"
#include "Lcd.h"
#include "Keypad.h"
#include "Scheduler.h"


Task_Ref_t Task1, Task2, Task3,Task4;

unsigned char Task1_Led, Task2_Led, Task3_Led;



void Task1_Func(void)
{

	while(1)
	{
		Task1_Led ^= 1;


	}
}

void Task2_Func(void)
{

	while(1)
	{
		Task2_Led ^= 1;


	}
}

void Task3_Func(void)
{

	while(1)
	{
		Task3_Led ^= 1;

	}
}






int main(void)
{

	MYRTOS_errorID Local_enuErrorState = ES_NoError;

	//HW_init (Initialize Clock Tree, Rest Controller)
	HW_init();


	Local_enuErrorState = MYRTOS_init();
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Configuration of task1
		Task1.Task_Stack_Size = 1024;
		Task1.PF_Task_Entry = Task1_Func;
		Task1.Task_Priority = 3;
		strcpy(Task1.Task_Name, "Task_1");

		//Configuration of task2
		Task2.Task_Stack_Size = 1024;
		Task2.PF_Task_Entry = Task2_Func;
		Task2.Task_Priority = 3;
		strcpy(Task2.Task_Name, "Task_2");

		//Configuration of task1
		Task3.Task_Stack_Size = 1024;
		Task3.PF_Task_Entry = Task3_Func;
		Task3.Task_Priority = 3;
		strcpy(Task3.Task_Name, "Task_3");

		//Create the 1st Task
		Local_enuErrorState = MYRTOS_Create_Task(&Task1);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Create the 2nd Task
		Local_enuErrorState = MYRTOS_Create_Task(&Task2);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Create the 3rd Task
		Local_enuErrorState = MYRTOS_Create_Task(&Task3);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		//Activate the 1st Task
		Local_enuErrorState = MYRTOS_Active_Task(&Task1);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		Local_enuErrorState = MYRTOS_Active_Task(&Task2);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		Local_enuErrorState = MYRTOS_Active_Task(&Task3);
		if(Local_enuErrorState != ES_NoError)
			while(1);

		Local_enuErrorState = MYRTOS_Start_OS();
		if(Local_enuErrorState != ES_NoError)
			while(1);



		while(1)
		{
		}

}
*/

