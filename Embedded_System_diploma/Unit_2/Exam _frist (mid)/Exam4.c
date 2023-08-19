/*
 * Exam4.c
 *
 *  Created on: Dec 2, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
void fun (char arr [],int t){
	while(t>=0){
	    	 printf("%c",arr[t]);
	    	 --t;}
}
int main(){
	char x[100];
	 printf("Enter  number ");
     fflush(stdin);fflush(stdout);
     scanf("%s",&x);
     int t=strlen(x)-1;
     fun(x,t);






}

