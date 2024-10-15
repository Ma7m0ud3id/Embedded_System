/*
 * Timer.c
 *
 * Created: 2/18/2024 2:22:30 PM
 *  Author: mahmo
 */ 
#include "../inc/Timer.h"


//****************************************************************
                          //Variable
//****************************************************************

Timer_Configration Time_con [3];
uint8_t Timer_Index= 0;


//function get_counter_reminder
static uint8_t counter=0;
static uint8_t Reminder_output_compare=0;

//function P_F_Delay_overflow
static uint8_t counter_compare=1;


static Timer_Name_ select_Timer =TIMER0;

//****************************************************************
                      //Internal FUNCTION
//****************************************************************

uint8_t Get_Timer_Index(Timer_Name_ name){
    if (name==TIMER0)
    {
		return (uint8_t)(0);
    } 
    else if(name==TIMER1)
    {
		return (uint8_t)(1);
    }
	else if(name==TIMER2)
	{
		return (uint8_t)(2);
	}else{
		return (uint8_t)(0);
	}
	
}


//**************************************

uint8_t get_counter_reminder(uint8_t second){
	//uint32_t value=382*second;
	uint32_t value=381*second;
	counter=(uint8_t)(value/100);
	value=value%100;
	Reminder_output_compare=(uint8_t)(256-((value*256)/100));
	return counter;
}

//********************************************

//********************************************
/*void P_F_Delay_Compare(void){
	
	 if (select_Timer==TIMER0)
	 {
		 Timer_0_Mask_Compere();
		 Timer_Set_Compare(select_Timer,Reminder_output_compare);
		 
	 }
	 else if(select_Timer==TIMER1)
	 {
		 
	 }
	 else if(select_Timer==TIMER2)
	 {
		 Timer_2_Mask_Compere();
		 Timer_Set_Compare(select_Timer,Reminder_output_compare);
	 }else
	 {
		 Timer_0_NON_Mask_Compere();
	 }
}*/



//****************************************************************
                          //FUNCTION
//****************************************************************

void Timer_Init(Timer_Configration *Timer_config){
	
	Timer_Index=Get_Timer_Index(Timer_config->timer_name);
	Time_con[Timer_Index]= *Timer_config;
	if (Timer_Index==(uint8_t)0)
	{
		/*Bit 6, 3 – WGM01:0: Waveform Generation Mode
		These bits control the counting sequence of the counter, the source for the maximum (TOP)
		counter value, and what type of Waveform Generation to be used. Modes of operation sup
		ported by the Timer/Counter unit are: Normal mode, Clear Timer on Compare Match (CTC)
		mode, and two types of Pulse Width Modulation (PWM) modes. See Table 38 and “Modes of*/
		*TCCR0|=Time_con[Timer_Index].Wave_Form;
		//*TCCR0&=~(1<<6);
		/* Bit 5:4 – COM01:0: Compare Match Output Mode
		 These bits control the Output Compare pin (OC0) behavior. If one or both of the COM01:0 bits
		 are set, the OC0 output overrides the normal port functionality of the I/O pin it is connected to.
		 However, note that the Data Direction Register (DDR) bit corresponding to the OC0 pin must be
		 set in order to enable the output driver.*/
		*TCCR0|=Time_con[Timer_Index].Compare_Output_Mode;
		
		 /*Bit 2:0 – CS02:0: Clock Select
		 The three Clock Select bits select the clock source to be used by the Timer/Counter.*/
		 *TCCR0|=Time_con[Timer_Index].Clock_Select;
		 
		 /*The Timer/Counter Register gives direct access, both for read and write operations, to the
		 Timer/Counter unit 8-bit counter. Writing to the TCNT0 Register blocks (removes) the compare
		 match on the following timer clock. Modifying the counter (TCNT0) while the counter is running,
		 introduces a risk of missing a compare match between TCNT0 and the OCR0 Register.*/
		 
		 *TCNT0 =Time_con[Timer_Index].Intial_Timer;
		 
		
		 
		 
		 //Enabel EXTI
	/*• Bit 7 – I: Global Interrupt Enable
	The Global Interrupt Enable bit must be set for the interrupts to be enabled. 
	The individual interrupt enable control is then performed in separate control registers. If the Global Interrupt Enable
	Register is cleared, none of the interrupts are enabled independent of the individual interrupt
	enable settings. The I-bit is cleared by hardware after an interrupt has occurred, and is set by
	the RETI instruction to enable subsequent interrupts. The I-bit can also be set and cleared by
	the application with the SEI and CLI instructions, as described in the instruction set reference.
	*/
	//Global_Interrupt();//********************************************************
		 
		 /* • Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
		  • Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable*/
		 
		// *TIMSK|=Time_con[Timer_Index].Interrupt_Mask;//**********************************************
		 
		
	} 
	else if(Timer_Index==(uint8_t)1)
	{
	}
	else if (Timer_Index==(uint8_t)2)
	{
		/* • Bit 6, 3 – WGM21:0: Waveform Generation Mode
		 These bits control the counting sequence of the counter, the source for the maximum (TOP)
		 counter value, and what type of waveform generation to be used. Modes of operation supported
		 by the Timer/Counter unit are: Normal mode, Clear Timer on Compare match (CTC) mode, and
		 two types of Pulse Width Modulation (PWM) modes. See Table 50 and “Modes of Operation” on
		 page 118.*/
		*TCCR2|=Time_con[Timer_Index].Wave_Form;
		
		 /*• Bit 5:4 – COM21:0: Compare Match Output Mode
		 These bits control the Output Compare pin (OC2) behavior. If one or both of the COM21:0 bits
		 are set, the OC2 output overrides the normal port functionality of the I/O pin it is connected to.
		 However, note that the Data Direction Register (DDR) bit corresponding to OC2 pin must be set
		 in order to enable the output driver.*/
		*TCCR2|=Time_con[Timer_Index].Compare_Output_Mode; 
		
		 /*Bit 2:0 – CS22:0: Clock Select
		 The three Clock Select bits select the clock source to be used by the Timer/Counter,
		 nooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooot that*********************
		 
		 No clock source (Timer/Counter stopped).
		 0 0 1 clkT2S/(No prescaling)
		 0 1 0 clkT2S/8 (From prescaler)
		 0 1 1 clkT2S/32 (From prescaler)
		 1 0 0 clkT2S/64 (From prescaler)
		 1 0 1 clkT2S/128 (From prescaler)
		 1 1 0 clkT2S/256 (From prescaler)
		 1 1 1 clkT2S/1024 (From prescaler)
		 */
		 *TCCR2|=Time_con[Timer_Index].Clock_Select; 
		 
		 /*
		 The Timer/Counter Register gives direct access, both for read and write operations, to the
		 Timer/Counter unit 8-bit counter. Writing to the TCNT2 Register blocks (removes) the compare
		 match on the following timer clock. Modifying the counter (TCNT2) while the counter is running,
		 introduces a risk of missing a compare match between TCNT2 and the OCR2 Register.
		 */
		 *TCNT2=Time_con[Timer_Index].Intial_Timer;
		 
		
		 
		 /*
		 • Bit 3 – AS2: Asynchronous Timer/Counter2
		 When AS2 is written to zero, Timer/Counter 2 is clocked from the I/O clock, clkI/O. When AS2 is
		 written to one, Timer/Counter2 is clocked from a Crystal Oscillator connected to the Timer Oscil
		 lator 1 (TOSC1) pin. When the value of AS2 is changed, the contents of TCNT2, OCR2, and
		 TCCR2 might be corrupted.
		 */
		 *ASSR|=Time_con[Timer_Index].Asynchronous_Status;
		 
		 
		//Enabel EXTI
	/*• Bit 7 – I: Global Interrupt Enable
	The Global Interrupt Enable bit must be set for the interrupts to be enabled. 
	The individual interrupt enable control is then performed in separate control registers. If the Global Interrupt Enable
	Register is cleared, none of the interrupts are enabled independent of the individual interrupt
	enable settings. The I-bit is cleared by hardware after an interrupt has occurred, and is set by
	the RETI instruction to enable subsequent interrupts. The I-bit can also be set and cleared by
	the application with the SEI and CLI instructions, as described in the instruction set reference.
	*/
	//Global_Interrupt();//***************************************************************
		 
		 /*
		  • Bit 7 – OCIE2: Timer/Counter2 Output Compare Match Interrupt Enable
		   • Bit 6 – TOIE2: Timer/Counter2 Overflow Interrupt Enable
		 */
		 
		 //*TIMSK|=Time_con[Timer_Index].Interrupt_Mask;//**********************************************
		 
	}
	
}


void Timer_Stop(Timer_Configration *Timer_config){
	Timer_Index=Get_Timer_Index(Timer_config->timer_name);
	
	if (Timer_Index==(uint8_t)0)
	{
		
		*TCCR0 &=0x00;
		
		
		 *TCNT0 &=0x00;
		 
		 *OCR0 &=0x00;

		 
		 
		
	} 
	else if(Timer_Index==(uint8_t)1)
	{
	}
	else if (Timer_Index==(uint8_t)2)
	{
		
		*TCCR2 &=0x00;
		
		
		 *TCNT2 &=0x00;
		 
		
		 *OCR2&=0x00;
		 
		 
		 *ASSR &=0x00;
		 
		 
		 
	}
	

	
	
}

uint8_t Timer_Get_Value(Timer_Name_ _Timer){
	
	Timer_Index=Get_Timer_Index(_Timer);
	
	if (Timer_Index==(uint8_t)0)
	{
		
		/*The Timer/Counter Register gives direct access, both for read and write operations, to the
		 Timer/Counter unit 8-bit counter. Writing to the TCNT0 Register blocks (removes) the compare
		 match on the following timer clock. Modifying the counter (TCNT0) while the counter is running,
		 introduces a risk of missing a compare match between TCNT0 and the OCR0 Register.*/
		
		return *TCNT0;
		
		
		
	}
	else if(Timer_Index==(uint8_t)1)
	{
	}
	else if (Timer_Index==(uint8_t)2)
	{
		
		 /*
		 The Timer/Counter Register gives direct access, both for read and write operations, to the
		 Timer/Counter unit 8-bit counter. Writing to the TCNT2 Register blocks (removes) the compare
		 match on the following timer clock. Modifying the counter (TCNT2) while the counter is running,
		 introduces a risk of missing a compare match between TCNT2 and the OCR2 Register.
		 */
		  return *TCNT2 ;
		
		

		
	}
	
	
	
}

void Timer_Set_Compare(Timer_Name_ _Timer,uint8_t Output_Compare){
	
	Timer_Index=Get_Timer_Index(_Timer);
	
	if (Timer_Index==(uint8_t)0)
	{
		
		 /*The Output Compare Register contains an 8-bit value that is continuously compared with the
		 counter value (TCNT0). A match can be used to generate an output compare interrupt, or to
		 generate a waveform output on the OC0 pin.*/
		 
		 *OCR0 = Output_Compare;
		 Global_Interrupt();
		 Timer_0_Mask_Compere();
		
		
		
	}
	else if(Timer_Index==(uint8_t)1)
	{
	}
	else if (Timer_Index==(uint8_t)2)
	{
		
		  /*
		 The Output Compare Register contains an 8-bit value that is continuously compared with the
		 counter value (TCNT2). A match can be used to generate an output compare interrupt, or to
		 generate a waveform output on the OC2 pin.
		 */
		  
		 *OCR2 =Output_Compare;
		 Global_Interrupt();
		 Timer_2_Mask_Compere();
		
		

		
	}
	
	
}

uint8_t F_Delay_overflow(void){
	if(counter_compare==counter){
		counter_compare=1;
		return (uint8_t)0;
		
		/*if (select_Timer==TIMER0)
		{
			
			Timer_Set_Compare(select_Timer,Reminder_output_compare);
			
		}
		else if(select_Timer==TIMER1)
		{
			
		}
		else if(select_Timer==TIMER2)
		{
			
			Timer_Set_Compare(select_Timer,Reminder_output_compare);
		}else
		{
			Timer_0_NON_Mask_Compere();
		}*/
		
	 }else{
		counter_compare++;
		return (uint8_t)1;
	}
}

void Timer_Delay(Timer_Name_ _Timer,uint8_t second_number){
	
	
	Timer_Index=Get_Timer_Index(_Timer);
	
	if (Timer_Index==(uint8_t)0)
	{
		
		
		 counter=get_counter_reminder(second_number);
		 ++counter;
		 
		 
		 /*The Timer/Counter Register gives direct access, both for read and write operations, to the
		 Timer/Counter unit 8-bit counter. Writing to the TCNT0 Register blocks (removes) the compare
		 match on the following timer clock. Modifying the counter (TCNT0) while the counter is running,
		 introduces a risk of missing a compare match between TCNT0 and the OCR0 Register.*/
		  Time_con[0].Intial_Timer=Reminder_output_compare;
		 *TCNT0 =Reminder_output_compare;
		 
		 select_Timer=TIMER0;
		 Timer_0_Mask_overflow();
		 Global_Interrupt();
		 
		 //Timer_0_NON_Mask_Compere();
		
		
		
	}
	else if(Timer_Index==(uint8_t)1)
	{
	}
	else if (Timer_Index==(uint8_t)2)
	{
		
		 
		counter=get_counter_reminder(second_number);
		counter++;
		 /*
		 The Timer/Counter Register gives direct access, both for read and write operations, to the
		 Timer/Counter unit 8-bit counter. Writing to the TCNT2 Register blocks (removes) the compare
		 match on the following timer clock. Modifying the counter (TCNT2) while the counter is running,
		 introduces a risk of missing a compare match between TCNT2 and the OCR2 Register.
		 */
		 Time_con[2].Intial_Timer=Reminder_output_compare;
		 *TCNT2 =Reminder_output_compare;
		 
		 
		select_Timer=TIMER2;
		Timer_2_Mask_overflow();
		Global_Interrupt();
		
        //Timer_2_NON_Mask_Compere();
		
	}
	
	
	
}

void Timer_PWM(Timer_Configration *Timer_config,uint8_t value){
	
	
}

void Timer_Servo(Timer_Configration *Timer_config,uint8_t Phase){
	
}


//****************************************************************
                      //Interrupt FUNCTION
//****************************************************************


//Timer/Counter0 Compare Match
void  __vector_10 (void) __attribute__((signal));
void __vector_10 (void){
	Time_con[0].Timer_Call_Back_Compare();
}


//Timer/Counter0 Overflow
void  __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
	Time_con[0].Timer_Call_Back_overflow();
}


//Timer/Counter2 Compare Match
void  __vector_4 (void) __attribute__((signal));
void __vector_4 (void){
	Time_con[2].Timer_Call_Back_Compare();
}


//Timer/Counter2 Overflow
void  __vector_5 (void) __attribute__((signal));
void __vector_5 (void){
	Time_con[2].Timer_Call_Back_overflow();
}









