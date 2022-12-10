/*
 * Exam.c
 *
 *  Created on: Dec 2, 2022
 *      Author: mahmo
 */

#include <stdio.h>
#include <stdlib.h>
void fun (int arr[] , int x){
	for(int i=x-1;i>=0;i--){
		printf("%d\n",arr[i]);
     }
}
int main(){
	int x;
		printf("Enter  number of array ");
		fflush(stdin);fflush(stdout);
	   scanf("%d",&x);
	   int arr [x];
	   printf("Enter  number  ");
	   for(int i=0;i<x;i++){
			fflush(stdin);fflush(stdout);
		   scanf("%d",&arr[i]);
	   }

	   fun(arr,x);
}
//(sizeof(arr)/sizeof(arr[0]))
