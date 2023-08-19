/*
 * Str3.c
 *
 *  Created on: Nov 5, 2022
 *      Author: mahmo
 */
#include <stdio.h>
#include <stdlib.h>
int main(void){
	char text [100];
	char c;
	int i,count =0;
	printf("Enter String :");
	fflush(stdin);fflush(stdout);
	scanf("%s",&text);
	printf("Lenght of String : %s \n",text);
	i=strlen(text)-1;
	printf("Lenght of String : %d\n",i);
	//printf("Lenght of String : %c \n",text[5]=="0"?"Y":"N");
	while(i>=0){
		printf("%c",text[i]);
		//count++;
		i--;
	}
	//printf("Lenght of String : %d",count);
}
