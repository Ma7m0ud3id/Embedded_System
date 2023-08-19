/*
 * FIFO.c
 *
 *  Created on: Jul 18, 2023
 *      Author: mahmo
 */
#include "FIFO.h"
#include <stdio.h>
status FIFO_init(s_fifo_t* s_fifo,unsigned int* frist_array ,unsigned int length ){
	s_fifo->length=length;
	s_fifo->count=0;
	s_fifo->base=frist_array;
	s_fifo->heat=s_fifo->base;
	s_fifo->tail=s_fifo->base;
}
status ENQUEUE(s_fifo_t* s_fifo,unsigned int data ){
	if(!s_fifo||!s_fifo->base||!s_fifo->heat){
		printf("Stack invaild====================");
		return FIFO_NULL;
	}else{
		if(s_fifo->count==(wight)){
					printf("Stack is full=====================");
					printf("==%d\n",data);
					return FIFO_FULL;
				}else{
			*s_fifo->heat=data;
			printf("=================%d\n",*s_fifo->heat);
			//printf("**********************%d\n",s_fifo->count);
			s_fifo->heat++;
			s_fifo->count++;

			return FIFO_NO_ERROR;
		}


	}
}
status DNQUEUE(s_fifo_t* s_fifo,unsigned int* data ){
	if(!s_fifo||!s_fifo->base||!s_fifo->heat){
			printf("Stack invaild====================");
			return FIFO_NULL;
		}else{
			if(s_fifo->count==0){
				printf("Stack is empty==");

				return FIFO_EMPTY;
			}else{
				*data=*s_fifo->tail;
				//printf("**********************%d\n",s_fifo->count);
				s_fifo->tail++;
				s_fifo->count--;

				return FIFO_NO_ERROR;

			}


		}
}
status valid(s_fifo_t* s_fifo );
