/*
 * pointer_Q3.c
 *
 *  Created on: Jun 20, 2023
 *      Author: mahmo
 */
#include <stdio.h>
void main(){
	char later [100];
	printf("Enter leter");
    fflush(stdout);fflush(stdin);
    scanf("%s",later);
    int x = strlen(later);
    char *pr;
    pr = &later[x-1];
    //printf("%c",*pr);
    for (int i=0;i<x;i++){
    	printf("%c",*pr);
    	pr--;
    }

}

