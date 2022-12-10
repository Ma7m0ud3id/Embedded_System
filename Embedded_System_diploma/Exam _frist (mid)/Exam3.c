/*
 * Exam3.c
 *
 *  Created on: Dec 2, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
int ma(int x,int y){
	for(int i=x;i<=y;i++){
		int z=0;
		for(int j=1;j<=i;j++){
			if(i%j==0){
				z++;}}
		if(z==2){
			printf("%d\n",i);
		}
	}
}
int main (){
	int x,y;
    printf("Enter 1st number ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	 printf("Enter 2ed number ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&y);
			ma(x,y);
}

