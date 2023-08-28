/*
 * Flash_Memory.h
 *
 *  Created on: Aug 26, 2023
 *      Author: mahmo
 */

#ifndef FLASH_MEMORY_H_
#define FLASH_MEMORY_H_
#include "States.h"
enum{
    FM_WAITING,
}FM_states;
void (*pr_fm) ();
void inti_flash_memory();
DEFINE_FUNCTION(FM_WAITING);



#endif /* FLASH_MEMORY_H_ */
