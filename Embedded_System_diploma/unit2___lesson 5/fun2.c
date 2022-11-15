/*
 * fun2.c
 *
 *  Created on: Nov 14, 2022
 *      Author: mahmo
 */


#include <stdio.h>
#include <stdlib.h>
int fact(int x){
	int fac=1;
	for(int i =1;i<=x;i++){
		fac*=i;
	}
	return fac;
}
int main(){
	int n,x,i,flag=0;
	printf("Enter number ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	printf("Factorial %d",fact(n));

}
