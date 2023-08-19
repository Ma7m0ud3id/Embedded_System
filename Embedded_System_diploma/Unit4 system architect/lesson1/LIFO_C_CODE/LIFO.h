/*
 * LIFO.h
 *
 *  Created on: Jul 18, 2023
 *      Author: mahmo
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdint.h>

//Definition
#define wight 5
typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int * base;
	unsigned int * heat;
}s_lifo_t;


typedef enum {
 LIFO_NO_ERROR,
 LIFO_NULL,
 LIFO_FULL,
 LIFO_EMPTY,
}status;

//******************************************************************
//API
status LIFO_init(s_lifo_t* s_lifo,unsigned int* frist_array ,unsigned int length );
status PUSH(s_lifo_t* s_lifo,unsigned int data );
status POP(s_lifo_t* s_lifo,unsigned int* data );
status valid(s_lifo_t* s_lifo );
#endif /* LIFO_H_ */
