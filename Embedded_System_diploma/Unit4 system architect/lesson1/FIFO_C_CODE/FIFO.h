/*
 * FIFO.h
 *
 *  Created on: Jul 18, 2023
 *      Author: mahmo
 */

#ifndef FIFO_H_
#define FIFO_H_


#include <stdint.h>

//Definition
#define wight 5
typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int * base;
	unsigned int * heat;
	unsigned int * tail;
}s_fifo_t;


typedef enum {
 FIFO_NO_ERROR,
 FIFO_NULL,
 FIFO_FULL,
 FIFO_EMPTY,
}status;

//******************************************************************
//API
status FIFO_init(s_fifo_t* s_FIFO,unsigned int* frist_array ,unsigned int length );
status ENQUEUE(s_fifo_t* s_FIFO,unsigned int data );
status DNQUEUE(s_fifo_t* s_FIFO,unsigned int* data );
status valid(s_fifo_t* s_FIFO );
status display(s_fifo_t* s_FIFO );


#endif /* FIFO_H_ */
