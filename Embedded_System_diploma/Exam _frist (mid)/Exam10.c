/*
 * Exam10.c
 *
 *  Created on: Dec 2, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
int fun (char arr [],int y[],int t){
	int c=0,n=0;
    for(int i=0;i<t;i++){
    	if(arr[i]=='1'){
    		if(arr[i+1]=='1'){
    			c++;}
    		else{
    			++c;
    			y[n]=c;
    			c=0;
    			++n;}}}
    int max = y[0];
    for (int i = 0; i < n; i++) {
           if(y[i] > max)
               max = arr[i];}
    return max;
}
int main(){
	char x[100];
	int y [100];
		 printf("Enter  number ");
	     fflush(stdin);fflush(stdout);
	     scanf("%s",&x);
	     int t=strlen(x);
	      printf("max number %d",fun(x,y,t));
}

