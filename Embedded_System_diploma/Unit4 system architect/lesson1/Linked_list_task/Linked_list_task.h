/*
 * Linked_list_task.h
 *
 *  Created on: Jul 19, 2023
 *      Author: mahmo
 */

#ifndef LINKED_LIST_TASK_H_
#define LINKED_LIST_TASK_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)	{fflush(stdout); \
		fflush(stdin); \
		printf (__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}






//Effective Data
struct Sdata {
	int ID;
	char Name[40];
	float height;
};

//Linked List Node
struct SStudent
{
	struct Sdata Student;
	struct SStudent* PNextStudent;
};

//API****************************************
void Add_Student ();
int Delete_Student ();
void View_Nth_Student ();
void Delete_All_Students ();
void View_All_Students ();
int Num_Of_Students ();
void Reverse_List_of_Students ();
void record_list ();


#endif /* LINKED_LIST_TASK_H_ */
