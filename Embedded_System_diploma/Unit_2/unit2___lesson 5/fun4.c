/*
 * fun4.c
 *
 *  Created on: Nov 14, 2022
 *      Author: mahmo
 */


#include <stdio.h>
#include <stdlib.h>
int power(int x,int y,int res){
	if(y<=0){
		return res;
	}
	res=res*x;
	--y;
	power(x,y,res);


}
int main(){
	int n,x,pow=1;
	printf("Enter base number ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	printf("Enter power number ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	printf("%d",power(n,x,pow));

}
