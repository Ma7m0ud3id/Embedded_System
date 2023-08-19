/*
 ============================================================================
 Name        : EX4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float x,y;
		printf("Enter two numbers:");
		fflush(stdin);fflush(stdout);
		scanf("%f",&x);
		scanf("%f",&y);
		printf("Product:%f",x*y);
		return 0 ;
}
