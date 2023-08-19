/*
 * FIFO_C_CODE.c
 *
 *  Created on: Jul 18, 2023
 *      Author: mahmo
 */

#include "FIFO.h"
unsigned int stack[wight];


int main(){

	s_fifo_t lifo1;
	unsigned int i,temp;
	FIFO_init(&lifo1,stack,wight);

	for(i=0;i<7;i++){
			ENQUEUE(&lifo1,i);
	}
	for(i=0;i<7;i++){
		DNQUEUE(&lifo1,&temp);
		//fflush(stdout);fflush(stdin);
		if(i>=wight){
			printf("=====================%d\n",i);
		}else{
			printf("=====================%d\n",temp);
		}


	}
	return 0;

}
