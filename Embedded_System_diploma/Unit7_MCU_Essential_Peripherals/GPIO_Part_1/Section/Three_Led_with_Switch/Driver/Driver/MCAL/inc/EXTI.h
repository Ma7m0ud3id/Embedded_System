/*
 * EXTI.h
 *
 * Created: 12/12/2023 7:58:53 PM
 *  Author: mahmo
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include "DIO.h"

typedef enum  {
	INT0,
	INT1,
	INT2
	
	
}INT_Name;

typedef enum  {
	low_level,
	logical,
	falling,
	rising
	
	
}INT_Mode;

typedef struct  
{
	INT_Name EXTI_Name; //this refer to number or name EXTI 
	                      //@ref EXTI_Name
						  
	INT_Mode EXTI_Mode ;  //this refer to  EXTI MODE
	                     //@ref EXTI_Mode

    void (* EXTI_Function)();//this refer to  EXTI_Function
                            
}EXTI_Typedef;

//@ref EXTI_Name
/*
INT0
INT1
INT2
*/

//@ref EXTI_Mode
/* 
low_level 
 logical
  falling 
  rising
 */



void EXTI_INIT(EXTI_Typedef* EXTIx);




#endif /* EXTI_H_ */