/*
 * struct2.c
 *
 *  Created on: Dec 10, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
struct distsnc {
	float inch ;
	int feet;};
struct distsnc readdata(){
	struct distsnc mas;
     printf("Enter feet :");
       fflush(stdin);fflush(stdout);
        scanf("%d",&mas.feet);
        printf("Enter inch :");
        fflush(stdin);fflush(stdout);
        scanf("%f",&mas.inch);
       return mas;}
struct distsnc add(struct distsnc x,struct distsnc y){
	struct distsnc mas;
	mas.feet=(x.feet+y.feet)+(int)(x.inch+y.inch)/12;
	mas.inch=(x.inch+y.inch)-((int)(x.inch+y.inch)/12)*12;
	return mas;
}
int main (){
 struct distsnc x,y,z;
 x =readdata();
 y =readdata();
 z= add(x,y);
 printf("feet : %d\n",z.feet);
 printf("inch : %f",z.inch);

}

