/*
 ============================================================================
 Name        : Array1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
 float arr [2][2];
 float arr1 [2][2];
 printf("Enter The element of 1st matrix\n\r");
 for(int i =0;i<2;i++){
  for(int j=0;j<2;j++){

   printf("Enter a%d%d\t",i+1,j+1);
   fflush(stdin);fflush(stdout);
   scanf("%f",&arr[i][j]);

  }
 }
 printf("Enter The element of 2st matrix\n");
 for(int i =0;i<2;i++){
   for(int j=0;j<2;j++){

    printf("Enter a%d%d\t",i+1,j+1);
    fflush(stdin);fflush(stdout);
    scanf("%f",&arr1[i][j]);

   }
  }
 printf("Sum of matrix\n");
 for(int i =0;i<2;i++){
    for(int j=0;j<2;j++){
     printf("%f\t",arr[i][j]+arr1[i][j]);
    }
    printf("\n\r");}

}
