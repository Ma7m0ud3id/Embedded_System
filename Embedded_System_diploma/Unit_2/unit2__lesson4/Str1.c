/*
 * Str1.c
 *
 *  Created on: Nov 5, 2022
 *      Author: mahmo
 */

#include <stdio.h>
#include <stdlib.h>
int main(void){
char text [100];
char c;
int count=0;
printf("Enter String :");
fflush(stdin);fflush(stdout);
gets(text);
printf("Enter character to find fequancy");
fflush(stdin);fflush(stdout);
scanf("%c",&c);
for(int i=0;i<strlen(text);i++){
	if(c==text[i]){
		count++;
	}
}
printf("Frequancy of %c :%d",c,count);

}

