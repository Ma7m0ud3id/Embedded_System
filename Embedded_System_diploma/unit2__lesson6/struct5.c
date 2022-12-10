/*
 * struct5.c
 *
 *  Created on: Dec 10, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
#define pi 3.14
int main(){
float x;
printf("Enter reduis : ");
    fflush(stdin);fflush(stdout);
     scanf("%f",&x);
     printf("Radius = %0.2f\n",pi*x*x);
     printf("This is line no.: %d\n", __LINE__);
     printf("Name of this file: %s\n", __FILE__);
     printf("Current Date: %s\n", __DATE__);
     printf("Current Time: %s\n", __TIME__);
     printf("Compilation success: %d\n", __STDC__);

}

