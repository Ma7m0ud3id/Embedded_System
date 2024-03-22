/*
 * Timer.h
 *
 * Created: 2/18/2024 2:22:05 PM
 *  Author: mahmo
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "DIO.h"

//****************************************************************
//@ref TIMER_NAME 
//****************************************************************
typedef enum {
	
	TIMER0=0,
	TIMER1,
	TIMER2
	
}Timer_Name_;

typedef struct{
	
 Timer_Name_ timer_name; //refer to timer name @ref TIMER_NAME 
 
 uint8_t Wave_Form;/*These bits control the counting sequence of the counter, the source for the maximum (TOP)
                     counter value, and what type of Waveform Generation to be used. Modes of operation sup
                     ported by the Timer/Counter unit are: Normal mode, Clear Timer on Compare Match (CTC)
                     mode, and two types of Pulse Width Modulation (PWM) modes. @ ref Wave_Form */
 
 uint8_t Compare_Output_Mode;/* These bits control the Output Compare pin (OC0) behavior. If one or both of the COM01:0 bits
                               are set, the OC0 output overrides the normal port functionality of the I/O pin it is connected to.
                               However @ ref Compare_Output_Mode  */
 
 
 uint8_t Clock_Select;     /*The three Clock Select bits select the clock source to be used by the Timer/Counter.
						   @ ref Clock_Select */
 
 
 uint8_t Intial_Timer;   /*It is intial value of counter*/
 
 
 
 /*uint8_t  Output_Compare;  /* It is value
                           The Output Compare Register contains an 8-bit value that is continuously compared with the
                           counter value (TCNT)*/
 
 //uint8_t Interrupt_Mask;    /*anable masked of timer interrupt @ ref Interrupt_Mask*/
 
 uint8_t Asynchronous_Status; /* this discripe if timer work by Asynchronous clock or not @ ref Asynchronous_Status */
 
 
 
 void(*Timer_Call_Back_Compare)(); /* the function that excuted when ISR of timer_Compare */
 
  void(*Timer_Call_Back_overflow)(); /* the function that excuted when ISR of timer_overflow */
							 	
}Timer_Configration;





//****************************************************************
//ref @Wave_Form
//****************************************************************
//TCCR0
#define Timer_0_Normal             (uint8_t)(0)  
#define Timer_0_PWM_Phase          (uint8_t)((1<<6) )// (uint8_t)(TCCR0 &(0xF7))
#define Timer_0_CTC                (uint8_t)((1<<3) )
#define Timer_0_Fast_PWM           (uint8_t)((1<<3)|(1<<6))
//TCCR2
#define Timer_2_Normal             (uint8_t)(0)
#define Timer_2_PWM_Phase          (uint8_t)((1<<6) )// (uint8_t)(TCCR0 &(0xF7))
#define Timer_2_CTC                (uint8_t)((1<<3) )
#define Timer_2_Fast_PWM           (uint8_t)((1<<3)|(1<<6))

//****************************************************************
//@ ref Compare_Output_Mode
//****************************************************************
//TCCR0
#define Timer_0_Normal_OC0_disconnected            (uint8_t)((0b00<<4))
#define Timer_0_Toggle_OC0                         (uint8_t)((0b01<<4))
#define Timer_0_Clear_OC0                          (uint8_t)((0b10<<4))
#define Timer_0_Set_OC0                            (uint8_t)((0b11<<4))
//TCCR2
#define Timer_2_Normal_OC0_disconnected            (uint8_t)((0b00<<4))
#define Timer_2_Toggle_OC0                         (uint8_t)((0b01<<4))
#define Timer_2_Clear_OC0                          (uint8_t)((0b10<<4))
#define Timer_2_Set_OC0                            (uint8_t)((0b11<<4))


//****************************************************************
//@ ref Clock_Select
//****************************************************************
//TCCR0
#define Timer_0_No_clock_source              (uint8_t)((0<<0))
#define Timer_0_No_prescaling                (uint8_t)((1<<0))
#define Timer_0_prescaling_8                 (uint8_t)((2<<0))
#define Timer_0_prescaling_64                (uint8_t)((3<<0))
#define Timer_0_prescaling_256               (uint8_t)((4<<0))
#define Timer_0_prescaling_1024              (uint8_t)((5<<0))
#define Timer_0_External_clock_falling_edge  (uint8_t)((6<<0))
#define Timer_0_External_clock_rising_edge   (uint8_t)((7<<0))
//TCCR2
#define Timer_2_No_clock_source              ((uint8_t))((0<<0))
#define Timer_2_No_prescaling                (uint8_t)((1<<0))
#define Timer_2_prescaling_8                 (uint8_t)((2<<0))
#define Timer_2_prescaling_32                (uint8_t)((3<<0))
#define Timer_2_prescaling_64                (uint8_t)((4<<0))
#define Timer_2_prescaling_128               (uint8_t)((5<<0))
#define Timer_2_prescaling_256               (uint8_t)((6<<0))
#define Timer_2_prescaling_1024              (uint8_t)((7<<0))

//****************************************************************
//@ ref Asynchronous_Status
//****************************************************************


#define Timer_0_NON                      (uint8_t)(0);
#define Timer_2_synchronous              (uint8_t)(*ASSR &=~(1<<3))
#define Timer_2_Asynchronous             (uint8_t)((1<<3))


//****************************************************************
                  //@ ref Interrupt_Mask
//****************************************************************
#define Timer_NON_Mask_Compere_overflow_polling()              (*TIMSK&=~(0xFF))


#define Timer_0_Mask_Compere()                                 (*TIMSK|=1<<1)
#define Timer_0_NON_Mask_Compere()                             (*TIMSK&=~(1<<1))
#define Timer_0_Mask_overflow()                                (*TIMSK|=1<<0)
#define Timer_0_NON_Mask_overflow()                            (*TIMSK&=~(1<<0))
#define Timer_0_Mask_Compere_overflow()                        (*TIMSK|=(1<<0)|(1<<1))
#define Timer_0_NON_Mask_Compere_overflow()                    (*TIMSK&=~((1<<0)|(1<<1)))


#define Timer_1_Mask_Compere()                                 (*TIMSK|=1<<1)
#define Timer_1_NON_Mask_Compere()                             (*TIMSK&=~(1<<1))
#define Timer_1_Mask_overflow()                                (*TIMSK|=1<<0)
#define Timer_1_NON_Mask_overflow()                            (*TIMSK&=~(1<<0))
#define Timer_1_Mask_Compere_overflow()                        (*TIMSK|=(1<<0)|(1<<1))
#define Timer_1_NON_Mask_Compere_overflow()                    (*TIMSK&=~((1<<0)|(1<<1)))


#define Timer_2_Mask_Compere()                                 (*TIMSK|=1<<7)
#define Timer_2_NON_Mask_Compere()                             (*TIMSK&=~(1<<7))
#define Timer_2_Mask_overflow()                                (*TIMSK|=1<<6)
#define Timer_2_NON_Mask_overflow()                            (*TIMSK&=~(1<<6))
#define Timer_2_Mask_Compere_overflow()                        (*TIMSK|=(1<<7)|(1<<6))
#define Timer_2_NON_Mask_Compere_overflow()                    (*TIMSK&=~((1<<7)|(1<<6)))


//****************************************************************
                   //@ Enable Interrupt_Mask
//****************************************************************

#define Global_Interrupt()                                 (*SREG|=(1<<7))
#define NON_Global_Interrupt()                             (*SREG&=~(1<<7))




//****************************************************************
                          //FUNCTION
//****************************************************************

void Timer_Init(Timer_Configration *Timer_config);
void Timer_Stop(Timer_Configration *Timer_config);

void Timer_Set_Compare(Timer_Name_ _Timer,uint8_t Output_Compare);
uint8_t Timer_Get_Value(Timer_Configration *Timer_config);

void Timer_Delay(Timer_Name_ _Timer,uint8_t second_number);

void Timer_PWM(Timer_Configration *Timer_config,uint8_t value);

void Timer_Servo(Timer_Configration *Timer_config,uint8_t Phase);
void P_F_Delay_overflow(void);

#endif /* TIMER_H_ */