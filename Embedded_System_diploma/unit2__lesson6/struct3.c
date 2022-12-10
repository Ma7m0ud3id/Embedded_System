/*
 * struct3.c
 *
 *  Created on: Dec 10, 2022
 *      Author: mahmo
 */

#include <stdio.h>
#include <stdlib.h>
struct number {
	float real ;
	float imagn;};
struct number readdata(){
	struct number mas;
     printf("Enter real :");
       fflush(stdin);fflush(stdout);
        scanf("%f",&mas.real);
        printf("Enter imagine :");
        fflush(stdin);fflush(stdout);
        scanf("%f",&mas.imagn);
       return mas;}
struct number add(struct number x,struct number y){
	struct number mas;
	mas.real=x.real + y.real;
	mas.imagn=x.imagn + y.imagn;
	return mas;
}

int main(){
	struct number x,y,z;
	printf("First number\n");
	x=readdata();
	printf("Second number\n");
	y=readdata();
	z= add(x,y);
	 printf("sum of number : %0.2f + %0.2f i",z.real,z.imagn);

}


