/*
 * pointer_Q5.c
 *
 *  Created on: Jun 20, 2023
 *      Author: mahmo
 */
#include <stdio.h>
struct person{
	char name [100];
	char id [20];
};

 void main(){
	 struct person* person [10] ;
	 struct person person1={"mahmoud","156589"};
	 person[0] = &person1;
	 printf("Exmployee Name : %s \nEmployee ID :  %s",person[0]->name,person[0]->id);

}
