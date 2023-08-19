/*
 * LIFO.c
 *
 *  Created on: Jul 18, 2023
 *      Author: mahmo
 */

#include "LIFO.h"



status LIFO_init(s_lifo_t* s_lifo,unsigned int* frist_array ,unsigned int length ){
	s_lifo->length=length;
	s_lifo->count=0;
	s_lifo->base=frist_array;
	s_lifo->heat=s_lifo->base;
}
status PUSH(s_lifo_t* s_lifo,unsigned int data ){
	if(!s_lifo||!s_lifo->base||!s_lifo->heat){
		printf("Stack invaild====================");
		return LIFO_NULL;
	}else{
		/*if(s_lifo->heat==((s_lifo->base) * (s_lifo->length) * sizeof(unsigned int))){
					printf("Stack is full=====================");
					return LIFO_FULL;
				}else{*/
			*s_lifo->heat=data;
			printf("=================%d\n",*s_lifo->heat);
			s_lifo->heat++;
			s_lifo->count++;
			return LIFO_NO_ERROR;
		//}


	}
}
status POP(s_lifo_t* s_lifo,unsigned int* data ){
	if(!s_lifo||!s_lifo->base||!s_lifo->heat){
			printf("Stack invaild====================");
			return LIFO_NULL;
		}else{
			if(s_lifo->heat == s_lifo->base){
				printf("Stack is empty=====================");
				return LIFO_EMPTY;
			}else{
				s_lifo->heat--;
				s_lifo->count--;
				*data=*s_lifo->heat;
				return LIFO_NO_ERROR;

			}


		}
}
status valid(s_lifo_t* s_lifo );
