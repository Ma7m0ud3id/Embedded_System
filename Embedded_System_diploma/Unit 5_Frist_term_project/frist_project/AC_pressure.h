/*
 * AC_pressure.h
 *
 *  Created on: Aug 20, 2023
 *      Author: mahmo
 */


#ifndef AC_PRESSURE_H_
#define AC_PRESSURE_H_
#include"states.h"

extern void (* pr_AC) ();
enum{
	WORKING_AC,
}AC_STATS;

DEFINE_FUNCTION(WORKING_AC);

#endif /* AC_PRESSURE_H_ */
