/*
 * fun3.c
 *
 *  Created on: Nov 14, 2022
 *      Author: mahmo
 */


#include <stdio.h>
#include <stdlib.h>
void revers(char x[],int y){
	printf("%c",x[y-1]);
	--y;
	if(y<0){
		return 0;
	}
	revers(x,y);
}
int main(){
	char x [100];
	printf("Enter sentance ");
	fflush(stdin);fflush(stdout);
	gets(x);
	//printf(" %s",x);
	int z= strlen(x);
	revers(x,z);


}
