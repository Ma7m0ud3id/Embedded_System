/*
 * main.c
 *
 *  Created on: Nov 4, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int row,colum ;
	printf("Enter Row and  of Matrix ");
		   fflush(stdin);
		   fflush(stdout);
		   scanf("%d%d",&row ,&colum);
	 float arr [row][colum];
	 float arr1 [colum][row];

	 printf("Enter The element of 1st matrix\n\r");
	 for(int i =0;i<row;i++){
	  for(int j=0;j<colum;j++){

	   printf("Enter a%d%d\t",i+1,j+1);
	   fflush(stdin);fflush(stdout);
	   scanf("%f",&arr[i][j]);

	  }
	 }

	 printf(" matrix\n");
	 for(int i =0;i<row;i++){
	    for(int j=0;j<colum;j++){
	     printf("%f\t",arr[i][j]);
	    }
	    printf("\n\r");}

	 for(int i =0;i<row;i++){
	 	    for(int j=0;j<colum;j++){
	 	    	arr1[j][i]=arr[i][j];
	 	    }
	 	    }
	 printf("Transpose matrix\n");
	 for(int i =0;i<colum;i++){
	 	    for(int j=0;j<row;j++){
	 	     printf("%f\t",arr1[i][j]);
	 	    }
	 	    printf("\n\r");}

	}

	//return 0;

