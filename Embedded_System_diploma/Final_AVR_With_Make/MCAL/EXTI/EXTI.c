/*
 * EXTI.c
 *
 * Created: 12/12/2023 7:59:06 PM
 *  Author: mahmo
 */ 

#include "../inc/EXTI.h"
/********************************************************************
                                 Variable
*********************************************************************/
EXTI_Typedef EXTI_config[3];

/********************************************************************
                                 Local Function
*********************************************************************/
uint8_t Get_index(EXTI_Typedef* EXTIx){
	uint8_t index;
	if(EXTIx->EXTI_Name==INT0){
		index=0;
		return (uint8_t)index;
		
	}else if(EXTIx->EXTI_Name==INT1){
		index=1;
	     return (uint8_t)index;
		
	}else if(EXTIx->EXTI_Name==INT2){
		index=2;
		 return (uint8_t)index;
	}else{
		index=0;
		return (uint8_t)index;
	}
}




/********************************************************************
                                 API
*********************************************************************/
void EXTI_INIT(EXTI_Typedef* EXTIx){
	uint8_t index;
	 index=Get_index( EXTIx);
	
	
	EXTI_config[index]=*EXTIx;
	
	//Enabel EXTI
	/*• Bit 7 – I: Global Interrupt Enable
	The Global Interrupt Enable bit must be set for the interrupts to be enabled. 
	The individual interrupt enable control is then performed in separate control registers. If the Global Interrupt Enable
	Register is cleared, none of the interrupts are enabled independent of the individual interrupt
	enable settings. The I-bit is cleared by hardware after an interrupt has occurred, and is set by
	the RETI instruction to enable subsequent interrupts. The I-bit can also be set and cleared by
	the application with the SEI and CLI instructions, as described in the instruction set reference.
	*/
	*SREG|=(1<<7);
	
	
	
	if(EXTI_config[index].EXTI_Name==INT0){
	//• Bit 6 – INT0: External Interrupt Request 0 Enable
	*GICR|=(1<<6);
	
		/*• Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0
	(INT0 )
	ISC01 ISC00 Description
	0 0 The low level of INT0 generates an interrupt request.
	0 1 Any logical change on INT0 generates an interrupt request.
	1 0 The falling edge of INT0 generates an interrupt request.
	1 1 The rising edge of INT0 generates an interrupt request.
	*/
	//x=EXTI_config[index]->EXTI_Mode;
	
	if(EXTI_config[index].EXTI_Mode==logical){
			*MCUCR|=(0b01<<0);
	 }else if(EXTI_config[index].EXTI_Mode==low_level){
	 *MCUCR|=(0b00<<0);
		 
	 }else if(EXTI_config[index].EXTI_Mode==falling){
		 *MCUCR|=(0b10<<0);
		 
	 }else{
		 *MCUCR|=(0b11<<0);
		 
	 }
	   
		
		
	}else if(EXTI_config[index].EXTI_Name==INT1){
	
	//• Bit 7 – INT1: External Interrupt Request 1 Enable
	*GICR|=(1<<7);
	
	//• Bit 3, 2 – ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0
	/*( INT1)
	ISC11 ISC10 Description
	0 0 The low level of INT1 generates an interrupt request.
	0 1 Any logical change on INT1 generates an interrupt request.
	1 0 The falling edge of INT1 generates an interrupt request.
	1 1 The rising edge of INT1 generates an interrupt request.
	*/
	if(EXTI_config[index].EXTI_Mode==logical){
		*MCUCR|=(0b01<<2);
	
	
	}else if(EXTI_config[index].EXTI_Mode==low_level){
		*MCUCR|=(0b00<<2);
		
		}else if(EXTI_config[index].EXTI_Mode==falling){
		*MCUCR|=(0b10<<2);
		
		}else{
		*MCUCR|=(0b11<<2);
		
	}
	
		
	}else {
	
		//• Bit 5 – INT2: External Interrupt Request 2 Enable
		*GICR|=(1<<5);
			/* Bit 6 – ISC2: Interrupt Sense Control 2
	( INT2 )
	The Asynchronous External Interrupt 2 is activated by the external pin INT2 if the SREG I-bit and
	the corresponding interrupt mask in GICR are set. If ISC2 is written to zero, a falling edge on
	INT2 activates the interrupt. If ISC2 is written to one, a rising edge on INT2 activates the interrupt. Edges on INT2 are registered asynchronously. Pulses on INT2 wider than the minimum
	pulse width given in
	*/
		
	  if(EXTI_config[index].EXTI_Mode==falling){
			*MCUCSR &=~(1<<6);
			
		}else{
			*MCUCSR |=(1<<6);
			
		}
	}
	
	
}



/*void ISR(INT0_vect){
	
	EXTI_config[index].EXTI_Function();
	
}*/
void  __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	EXTI_config[(uint8_t)0].EXTI_Function();
}

void  __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	EXTI_config[(uint8_t)1].EXTI_Function();
}

void  __vector_3 (void) __attribute__((signal));
void __vector_3 (void){
	EXTI_config[(uint8_t)2].EXTI_Function();
}


/*void ISR(INT2_vect){
	
	EXTI_config[index].EXTI_Function();
}*/