/*
 * Struct.c
 *
 *  Created on: Dec 10, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
struct student {
	char name[50];
	int roll;
	int marks;
}std;
struct student readdata(){
	struct student mas;
	printf("Enter name : ");
    fflush(stdin);fflush(stdout);
     scanf("%s",&mas.name);
     printf("Enter roll :");
       fflush(stdin);fflush(stdout);
        scanf("%d",&mas.roll);
        printf("Enter markes :");
        fflush(stdin);fflush(stdout);
        scanf("%d",&mas.marks);
       return mas;

}
int main(){
   std =readdata();
   printf("student name : %s\n ",std.name);
   printf("student roll : %d \n",std.roll);
   printf("student marks : %d \n",std.marks);
}

