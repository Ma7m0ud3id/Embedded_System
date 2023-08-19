/*
 * fun1.c
 *
 *  Created on: Nov 14, 2022
 *      Author: mahmo
 */


#include <stdio.h>
#include <stdlib.h>
void pre(int j){
	int flag=0;
	for(int i=2;i<=j/2;i++)
		{
		if(j%i==0)
		{
		flag=1;
		return 0;
		}
		}
		if(flag==0)
		printf("%d\n",j);
}
int main(){
int n,x,i,flag=0;
printf("Enter two number ");
fflush(stdin);fflush(stdout);
scanf("%d",&n);
scanf("%d",&x);
for(int j =n;j<=x;j++){
	pre(j);
}

return 0;
 }
