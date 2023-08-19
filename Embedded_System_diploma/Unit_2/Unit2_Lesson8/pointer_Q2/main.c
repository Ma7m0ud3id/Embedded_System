/*
 * main.c
 *
 *  Created on: Jun 20, 2023
 *      Author: mahmo
 */
#include <stdio.h>
int main(){
	short c=65;
	short *pr;
	pr=&c;
	int i =0;
	for(;i<26;i++){
		printf("%c  ",*pr);
		c++;
	}

  return 0;
}

