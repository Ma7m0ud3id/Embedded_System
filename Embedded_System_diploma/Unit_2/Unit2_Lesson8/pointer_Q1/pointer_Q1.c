/*
 * pointer_Q1.c
 *
 *  Created on: Jul 10, 2023
 *      Author: mahmo
 */

#include <stdio.h>
int main(){

	int *pr,x,y;
	printf("Address of m :");
	fflush(stdout);fflush(stdin);
	scanf("%d",&y);
	printf("Value of m :");
	fflush(stdout);fflush(stdin);
	scanf("%d",&x);
	*pr=x;
	pr=&x;
	printf("Address of pointer ab :%u\n",pr);
	printf("Content of pointer ab : %d",*pr);
	return 0;
}
