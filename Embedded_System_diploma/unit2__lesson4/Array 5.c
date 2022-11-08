/*
 * Array 5.c
 *
 *  Created on: Nov 5, 2022
 *      Author: mahmo
 */

#include <stdio.h>
#include <stdlib.h>
int main(void){
 int x;
 float y;
 printf("Enter number of element\t ");
 fflush(stdin);fflush(stdout);
 scanf("%d",&x);
 float arr[x];
 for(int i =0;i<x;i++){
 	   printf("Enter number\t ");
 	   fflush(stdin);fflush(stdout);
 	   scanf("%f",&arr[i]);


 	 }
 printf("Enter number to be inserted \t ");
   	fflush(stdin);fflush(stdout);
   	 scanf("%f",&y);
   	for(int i =0;i<x;i++){
   	 	  if(y==arr[i]){
   	 		  printf("Number founded at location %d",i+1);
   	 		  return 0;
   	 	  }


   	 	 }
   	return 0;

}
