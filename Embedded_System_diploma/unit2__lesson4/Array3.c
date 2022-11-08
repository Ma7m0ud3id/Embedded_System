/*
 * main.c
 *
 *  Created on: Nov 4, 2022
 *      Author: mahmo
 */

#include <stdio.h>
#include <stdlib.h>
int main(void){
 int x;
 printf("Enter number of element\t ");
 fflush(stdin);fflush(stdout);
 scanf("%d",&x);
 float arr[x];
 float y=0;
 for(int i =0;i<x;i++){
 	   printf("Enter number\t ");
 	   fflush(stdin);fflush(stdout);
 	   scanf("%f",&arr[i]);
        y+=arr[i];

 	 }
 printf(" %f",y/x);
 return 0;
}
