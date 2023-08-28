/*
 * main.c
 *
 *  Created on: Aug 22, 2023
 *      Author: mahmo
 */

#include<stdio.h>
#include<string.h>
#include "header.h"
struct sinfo{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[10];
}st[55];
int choose;
struct sinfo* pr_add=&st[0];
struct sinfo* pr_search=&st[0];
struct sinfo* pr_tail=&st[50];
void add_student_file();
void add_student_manually();
void find_rl();
void find_fn();
void find_c();
void tot_s();
void del_s();
void up_s();
void show_s();
int main(){
	DPRINTF("Welcome to the Student Management System\n");
    int x=1;
	while (x) {

	DPRINTF("Choose The Task that you want to perform\n");
	DPRINTF("1. Add the Student Details Manually\n");
	DPRINTF("2. Add the Student Details From Text File\n");
    DPRINTF("3. Find the Student Details by Roll Number\n");
	DPRINTF("4. Find the Student Details by First Name\n") ;
	DPRINTF("5. Find the Student Details by Course Id\n");
	DPRINTF("6. Find the Total number of Students\n");
	DPRINTF("7. Delete the Students Details by Roll Number\n");
	DPRINTF("8. Update the Students Details by Roll Number\n");
	DPRINTF("9. Show all information\n");
	DPRINTF("10. To Exit\n");
	DPRINTF("Enter your choice to perform the task: ");
	SS
    DSCANF("%d",&choose);
	switch(choose){
	   case 1:
		   add_student_manually();
		   break;
	   case 2:
	   	   add_student_file();
	   	   break;
	   case 3:
	   	   find_rl();
	   	   break;
	   case 4:
	   	   find_fn();
	   	   break;
	   case 5:
	   	   find_c();
	   	   break;
	   case 6:
		   tot_s();
	   	   break;
	   case 7:
		   del_s();
	   	   break;
	   case 8:
		   up_s();
	   	   break;
	   case 9:
		   show_s();
	   	   break;
	   case 10:
	   	   x=0;
	   	  break;

	}

	}
	//exit_loop: ;
	return 0;
}

void add_student_manually(){
    if(pr_add==&st[50]){
    	DPRINTF("------------------------------------------------------\n");
    	DPRINTF("Queue is fullllllllllllllllll............\n");

    }else{

	DPRINTF("------------------------------------------------------\n");
	DPRINTF("Add the Students Details \n");
	DPRINTF("------------------------------------------------------\n");
	DPRINTF("Enter the Roll Number: ");
	SS
	scanf("%d",&pr_add->roll);
	DPRINTF("Enter the first name of student: ");
	SS
	scanf("%s",&pr_add->fname[0]);
	DPRINTF("Enter the last name of student: ");
	SS
	scanf("%s",&pr_add->lname[0]);
	DPRINTF("Enter the GPA you obtained: ");
	SS
	scanf("%f",&pr_add->GPA);
	DPRINTF("Enter the course ID of each course \n");
	DPRINTF("Course 1 id:");
	SS
    scanf("%d",&pr_add->cid[0]);
	DPRINTF("Course 2 id:");
	SS
	scanf("%d",&pr_add->cid[1]);
	DPRINTF("Course 3 id:");
	SS
	scanf("%d",&pr_add->cid[2]);
	DPRINTF("Course 4 id:");
	SS
	scanf("%d",&pr_add->cid[3]);
    DPRINTF("Course 5 id:");
	SS
	scanf("%d",&pr_add->cid[4]);
	DPRINTF("Course 6 id:");
	SS
	scanf("%d",&pr_add->cid[5]);
	DPRINTF("[INFO] Student Details is added Successfully \n");
	pr_add++;
    }


}

void add_student_file(){
	if(pr_add==&st[50]){
	    	DPRINTF("------------------------------------------------------\n");
	    	DPRINTF("Queue is fullllllllllllllllll............\n");

	}else{
		DPRINTF("------------------------------------------------------\n");
		DPRINTF("Add the Students Details \n");
		DPRINTF("------------------------------------------------------\n");
	int z=1;
    while(z){
     SS
	 scanf("%d %s %s %f %d %d %d %d %d %d",&pr_add->roll,&pr_add->fname[0],&pr_add->lname[0]
	 			,&pr_add->GPA,&pr_add->cid[0],&pr_add->cid[1],&pr_add->cid[2],&pr_add->cid[3],&pr_add->cid[4],&pr_add->cid[5]);
     pr_add++;
     DPRINTF("Compleete........ \n");
     SS
     scanf("%d",&z);
    }
  }
}

void find_rl(){
	int check,V=0;
	DPRINTF("------------------------------------------------------\n");
	if(pr_add==&st[0]){
		DPRINTF("Queue is Empty............................\n");
	}else{
		DPRINTF("Enter the Roll Number of the student:");
		SS
		scanf("%d",&check);
		for(;pr_search!=pr_add;){
			if(check==pr_search->roll){
				DPRINTF("The Students Details are\n");
				DPRINTFV("The First name is %s \n",pr_search->fname);
				DPRINTFV("The Last name is %s \n",pr_search->lname);
				DPRINTFV("The GPA is %f \n",pr_search->GPA);
				DPRINTF("Enter the course of each course\n");
				DPRINTFV("The course ID are %d \n",pr_search->cid[0]);
				DPRINTFV("The course ID are %d \n",pr_search->cid[1]);
				DPRINTFV("The course ID are %d \n",pr_search->cid[2]);
				DPRINTFV("The course ID are %d \n",pr_search->cid[3]);
				DPRINTFV("The course ID are %d \n",pr_search->cid[4]);
				DPRINTFV("The course ID are %d \n",pr_search->cid[5]);
				V=1;
				break;
			} pr_search++;
		}if(V!=1){DPRINTFV("[ERROR] Roll Number %d not found  \n",check);}
		pr_search=&st[0];
	}
}
void find_fn(){
	char check[50];
	int V,S=0;
		DPRINTF("------------------------------------------------------\n");
		if(pr_add==&st[0]){
			DPRINTF("Queue is Empty............................\n");
		}else{
			DPRINTF("Enter the Frist Name of the student:");
			SS
			scanf("%s",check);
			for(;pr_search!=pr_add;){
				V=strcmp(check,pr_search->fname);
				if(V==0){
					DPRINTF("The Students Details are\n");
					DPRINTFV("The First name is %s \n",pr_search->fname);
					DPRINTFV("The Last name is %s \n",pr_search->lname);
					DPRINTFV("The Roll Number is %d \n",pr_search->roll);
					DPRINTFV("The GPA is %f \n",pr_search->GPA);
					DPRINTF("Enter the course of each course\n");
					DPRINTFV("The course ID are %d \n",pr_search->cid[0]);
					DPRINTFV("The course ID are %d \n",pr_search->cid[1]);
					DPRINTFV("The course ID are %d \n",pr_search->cid[2]);
					DPRINTFV("The course ID are %d \n",pr_search->cid[3]);
					DPRINTFV("The course ID are %d \n",pr_search->cid[4]);
					DPRINTFV("The course ID are %d \n",pr_search->cid[5]);
					S=1;
				} pr_search++;
			}if(S!=1){DPRINTFV("[ERROR] Frist Name %s not found \n",check);}
			pr_search=&st[0];
		}
}
void find_c(){
	int check,V=0;
		DPRINTF("------------------------------------------------------\n");
		if(pr_add==&st[0]){
			DPRINTF("Queue is Empty............................\n");
		}else{
			DPRINTF("Enter the Course ID :");
			SS
			scanf("%d",&check);
			for(;pr_search!=pr_add;){
			   for(int i=0;i<6;i++){
				if(check==pr_search->cid[i]){
					DPRINTF("The Students Details are\n");
					DPRINTFV("The First name is %s \n",pr_search->fname);
					DPRINTFV("The Last name is %s \n",pr_search->lname);
					DPRINTFV("The GPA is %f \n",pr_search->GPA);
					V=1;


				}
			} pr_search++;
			}if(V!=1){DPRINTFV("[ERROR] Course ID %d not found  \n",check);}
			pr_search=&st[0];

		}
}
void tot_s(){
	int V=0;
			DPRINTF("------------------------------------------------------\n");
			if(pr_add==&st[0]){
				DPRINTF("Queue is Empty............................\n");
			}else{
				for(;pr_search!=pr_add;){
				   V++;
				   pr_search++;
				}
				DPRINTFV("The total number Student is %d \n",V);
			    DPRINTF("You can add up to 50 Students:\n");
				DPRINTFV("You can add %d more Students:\n",50-V);
				pr_search=&st[0];

			}
}
void del_s(){
	int check,V=0;
		DPRINTF("------------------------------------------------------\n");
		if(pr_add==&st[0]){
			DPRINTF("Queue is Empty............................\n");
		}else{
			DPRINTF("Enter the Roll Number which you want to delet:");
			SS
			scanf("%d",&check);
			for(;pr_search<=pr_add;){
				if(check==pr_search->roll){
					if(pr_search==pr_add-1){
						DPRINTF("[INFO] The Roll Number is removed Successfully\n");
						V=1;
					    pr_add--;
					}else{
						pr_tail=pr_search+1;
						check=pr_search->roll;
						pr_search->GPA= pr_tail->GPA;
					    strcpy(pr_search->fname, pr_tail->fname);
						strcpy(pr_search->lname, pr_tail->lname);
						pr_search->roll= pr_tail->roll;
						pr_search->cid[0]= pr_tail->cid[0];
						pr_search->cid[1]= pr_tail->cid[1];
						pr_search->cid[2]= pr_tail->cid[2];
						pr_search->cid[3]= pr_tail->cid[3];
						pr_search->cid[4]= pr_tail->cid[4];
						pr_search->cid[5]= pr_tail->cid[5];
						DPRINTF("[INFO] The Roll Number is removed Successfully\n");
						V=1;
						pr_add--;
					}


				}
				pr_search++;
			}if(V!=1){DPRINTFV("[ERROR] Roll Number %d not found  \n",check);}
			pr_search=&st[0];
		}
}
void up_s(){
	int check,number,MU,V=0,arr[10];
	char namee [50];
	float mu;
			DPRINTF("------------------------------------------------------\n");
			if(pr_add==&st[0]){
				DPRINTF("Queue is Empty............................\n");
			}else{
				DPRINTF("Enter the Roll Number to updata th Entry:");
				SS
				scanf("%d",&check);
				SS
				DPRINTF("1. Frist Name\n");
				DPRINTF("2. Last Name\n");
				DPRINTF("3. Roll Number\n");
				DPRINTF("4. GPA\n");
				DPRINTF("5. Courses\n");
				SS
				scanf("%d",&number);
				SS
				for(;pr_search!=pr_add;){
					if(check==pr_search->roll){
						switch(number){
						case 1:
							DPRINTF("Enter the New Frist Name:");
							SS
							scanf("%s",namee);
							strcpy(pr_search->fname,namee);
							break;
						case 2:
				            DPRINTF("Enter the New Last Name:");
							SS
							scanf("%s",namee);
							strcpy(pr_search->lname,namee);
							break;
						case 3:
							DPRINTF("Enter the New Roll Number:");
							SS
							scanf("%d",&MU);
							pr_search->roll=MU;
							break;
						case 4:
							DPRINTF("Enter the New GPA:");
							SS
							scanf("%f",&mu);
							pr_search->GPA=mu;
							break;
						case 5:
							for(int i=0;i<6;i++){
								DPRINTFV("Enter the New %d Courses:",i+1);
								SS
								scanf("%d",&arr[i]);
								pr_search->cid[i]=arr[i];

							}
							break;

						}
						DPRINTF("[INFO] UPDATED Successfully\n");
						V=1;

					}
					pr_search++;
				}if(V!=1){DPRINTFV("[ERROR] Roll Number %d not found  \n",check);}
				pr_search=&st[0];
			}
}
void show_s(){

			DPRINTF("------------------------------------------------------\n");
			if(pr_add==&st[0]){
				DPRINTF("Queue is Empty............................\n");
			}else{

				for(;pr_search!=pr_add;){
						DPRINTF("The Students Details are\n");
						DPRINTFV("The First name is %s \n",pr_search->fname);
						DPRINTFV("The Last name is %s \n",pr_search->lname);
						DPRINTFV("The Roll Number is %d \n",pr_search->roll);
						DPRINTFV("The GPA is %f \n",pr_search->GPA);
						DPRINTF("Enter the course of each course\n");
						DPRINTFV("The course ID are %d \n",pr_search->cid[0]);
						DPRINTFV("The course ID are %d \n",pr_search->cid[1]);
						DPRINTFV("The course ID are %d \n",pr_search->cid[2]);
						DPRINTFV("The course ID are %d \n",pr_search->cid[3]);
						DPRINTFV("The course ID are %d \n",pr_search->cid[4]);
						DPRINTFV("The course ID are %d \n",pr_search->cid[5]);

					 pr_search++;
				}
				pr_search=&st[0];
			}
}
