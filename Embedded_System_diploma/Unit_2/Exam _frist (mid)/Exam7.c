/*
 * Exam7.c
 *
 *  Created on: Dec 2, 2022
 *      Author: mahmo
 */

#include <stdio.h>
#include <stdlib.h>
int ma(int x,int y) {
	//int n=(y-x)-1
	int sum =(y-x+1)*(x+y)/2;
	return  sum ;
}
int main(){
	int x,y;
	    printf("Enter 1st number ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&x);
		 printf("Enter 2ed number ");
			fflush(stdin);fflush(stdout);
			scanf("%d",&y);
				printf("%d",ma(x,y));
}
