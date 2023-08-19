/*
 * LIFO_C_CODE.c
 *
 *  Created on: Jul 18, 2023
 *      Author: mahmo
 */
#include "LIFO.h"
unsigned int stack[wight];


int main(){

	s_lifo_t lifo1,lifo2;
	unsigned int i,temp;
	LIFO_init(&lifo1,stack,wight);
	for(i=0;i<wight;i++){
			PUSH(&lifo1,i);
	}
	for(i=0;i<wight;i++){
		POP(&lifo1,&temp);
		//fflush(stdout);fflush(stdin);
		printf("=====================%d\n",temp);

	}

}

