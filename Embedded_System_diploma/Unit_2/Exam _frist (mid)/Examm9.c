/*
 * Examm9.c
 *
 *  Created on: Dec 2, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
void fun (char x [],int y){
	for(int i=y+1;i<strlen(x);i++){
		     	    	 printf("%c",x[i]);
		     	 }
		     printf(" ");
		     for(int i=0;i<y;i++){
		          	 printf("%c",x[i]);
		            	   }
		    }

int main(){
	char x[100];
	int y=0;
		 printf("Enter  String ");
	     fflush(stdin);fflush(stdout);
	     gets(x);
	     //printf("%d\n",strlen(x));
	     //printf("%c\n",x[4]);
	     for(int i=0;i<strlen(x);i++){
	    	 if(x[i]==' '){
	    		 y=i;
	    	 }
	     }
	     fun(x,y);}







