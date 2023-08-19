/*
 * pointer_Q4.c
 *
 *  Created on: Jun 20, 2023
 *      Author: mahmo
 */
#include <stdio.h>
void main(){
	int lenght_array;
	printf("Input the number of elements to store in the array (max 15) :\n ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&lenght_array);
	printf("Input %d number of elements in the array :\n",lenght_array);
	int array [lenght_array];
	int *pr;
	pr=&array[lenght_array-1];
	for(int i=0;i<lenght_array;i++){
		printf("element - %d :",(i+1));
		fflush(stdout);fflush(stdin);
		scanf("%d",&array[i]);
	}
	for(int i=0;i<lenght_array;i++){
			printf("element - %d : %d  :%d \n",(i+1),*pr,array[i]);
			pr--;


	}
}

