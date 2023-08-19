/*
 ============================================================================
 Name        : EX7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	        float a,b,test=0;
			printf("Enter value of a:");
			fflush(stdin);fflush(stdout);
			scanf("%f",&a);
			printf("Enter value of b:");
			fflush(stdin);fflush(stdout);
			scanf("%f",&b);
			test = a;
			a = b;
			b=test;
			printf("After swapping, value of a =%f\r\n",a);
			printf("After swapping, value of b =%f",b);
			return 0 ;
}
