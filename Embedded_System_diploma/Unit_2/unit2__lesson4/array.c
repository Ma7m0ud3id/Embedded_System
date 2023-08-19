#include <stdio.h>
#include <stdlib.h>

int main(void){
 int x,z;
 float y;

 printf("Enter number of element\t ");

 fflush(stdin);fflush(stdout);

 scanf("%d",&x);

 float arr[x];
 float arr1[x+1];

 for(int i =0;i<x;i++){
 	   printf("Enter number\t ");
 	   fflush(stdin);fflush(stdout);
 	   scanf("%f",&arr[i]);


 	 }
 printf("Enter number to be inserted \t ");
  	fflush(stdin);fflush(stdout);
  	 scanf("%f",&y);
 printf("Enter the location \t ");
  	  	fflush(stdin);fflush(stdout);
  	  	 scanf("%d",&z);

  for(int i=0;i<z;i++)
    {
        arr1[i]=arr[i];
    }

    arr1[z]=y;

    for(int i=z+1;i<x+1;i++)
    {
        arr1[i]=arr[i-1];
    }

  for(int i =0;i<x+1;i++){
	  printf("%f\n",arr1[i]);
  }

 return 0;
}
