/*
 * Exam5.c
 *
 *  Created on: Dec 2, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
int fun (int x){
	int y=0,z=0;
	while(x>0){
	y=x%2;
	x=x/2;
    printf("%d",y);
	if(y==1){
		z++;
	}
  }
	return z;
}
int main(){
int x;
   printf("Enter  number ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&x);
    printf("\n%d",fun(x));
}

