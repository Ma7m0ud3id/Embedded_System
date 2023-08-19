/*
 * struct6.c
 *
 *  Created on: Dec 10, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
union job{
	char name[32];
	float salary;
	int work_on;

}x;
struct job1{
	char name[32];
	float salary;
	int work_on;
}y;
int main(){
printf("%d\n",sizeof(x));
printf("%d",sizeof(y));
}

