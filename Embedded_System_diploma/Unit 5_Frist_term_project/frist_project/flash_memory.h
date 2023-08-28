/*
 * flash_memory.h
 *
 *  Created on: Aug 20, 2023
 *      Author: mahmo
 */



#ifndef FLASH_MEMORY_H_
#define FLASH_MEMORY_H_
#include"states.h"
enum{
	flash_working,
}flash_stats;

extern void (*pr_flash)();


void init_flash();
DEFINE_FUNCTION(flash_working);

#endif /* FLASH_MEMORY_H_ */
