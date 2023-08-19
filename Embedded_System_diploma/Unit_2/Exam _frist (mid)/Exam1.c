/*
 * Exam1.c
 *
 *  Created on: Dec 2, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
static int sum=0;
int ma ( int x){
 int n=0;
n=x%10;
sum+=n;
if(x!=0){
	ma(x/10);
}
else {

	return sum;
}
}
int main (){
    int x;
printf("Enter  number ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	printf("%d",ma(x));

}


