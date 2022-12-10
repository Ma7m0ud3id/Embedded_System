/*
 * struct4.c
 *
 *  Created on: Dec 10, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
struct student {
	char name[50];
	int roll;
	int marks;};
struct student readdata(){struct student mas;
	printf("Enter name : ");
    fflush(stdin);fflush(stdout);
     scanf("%s",&mas.name);
     printf("Enter roll :");
       fflush(stdin);fflush(stdout);
        scanf("%d",&mas.roll);
        printf("Enter makes :");
        fflush(stdin);fflush(stdout);
        scanf("%d",&mas.marks);
       return mas;}
print(struct student x){
	 printf("student name : %s\n ",x.name);
	   printf("student roll : %d \n",x.roll);
	   printf("student marks : %d \n",x.marks);}
int main(){
	struct student  students[10];
	printf("inter information of the student\n");
	for(int i=0;i<sizeof(students)/sizeof(struct student);i++){
		//printf("%d",sizeof(students)/sizeof(struct student));
		students[i] =readdata();
		printf("***************************\n");
	}
	printf("Display information of the student\n");
	for(int i=0;i<sizeof(students)/sizeof(struct student);i++){
			print(students[i]);
			printf("//////////////////////////\n");
	}


}

