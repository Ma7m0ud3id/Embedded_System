/*
 * DIO.h
 *
 * Created: 12/6/2023 7:20:08 PM
 *  Author: mahmo
 */ 


#ifndef DIO_H_
#define DIO_H_



#include <stdint.h>
//PORTA
#define PORTA    ((volatile unsigned char *)0x3B)
#define DDRA     ((volatile unsigned char *)0x3A)
#define PINA     ((volatile unsigned char *)0x39)


//PORTB
#define PORTB    ((volatile unsigned char *)0x38)
#define DDRB     ((volatile unsigned char *)0x37)
#define PINB     ((volatile unsigned char *)0x36)



//PORTC
#define PORTC    ((volatile unsigned char *)0x35)
#define DDRC     ((volatile unsigned char *)0x34)
#define PINC     ((volatile unsigned char *)0x33)




//PORTD
#define PORTD    ((volatile unsigned char *)0x32)
#define DDRD     ((volatile unsigned char *)0x31)
#define PIND     ((volatile unsigned char *)0x30)



//UART
#define UDR       ((volatile unsigned char *)0x2C)
#define UCSRA     ((volatile unsigned char *)0x2B)
#define UCSRB     ((volatile unsigned char *)0x2A)
#define UCSRC     ((volatile unsigned char *)0x40)
#define UBRRL     ((volatile unsigned char *)0x29)




//EXTI
#define SREG       ((volatile unsigned char *)0x5F)
#define MCUCR      ((volatile unsigned char *)0x55)
#define MCUCSR     ((volatile unsigned char *)0x54)
#define GICR       ((volatile unsigned char *)0x5B)
#define GIFR       ((volatile unsigned char *)0x5A)



//ADC
#define ADMUX        ((volatile unsigned char *)0x27)
#define ADCSRA       ((volatile unsigned char *)0x26)
#define ADCL         ((volatile unsigned char *)0x24)
#define ADCH         ((volatile unsigned char *)0x25)
#define SFIOR        ((volatile unsigned char *)0x50)


//Timer0
#define TCCR0        ((volatile unsigned char *)0x53)
#define TCNT0        ((volatile unsigned char *)0x52)
#define OCR0         ((volatile unsigned char *)0x5C)
//Timer1
#define TCCR1A        ((volatile unsigned char *)0x4F)
#define TCCR1B        ((volatile unsigned char *)0x4E)
#define TCNT1H        ((volatile unsigned char *)0x4D)
#define TCNT1L        ((volatile unsigned char *)0x4C)
#define OCR1AH        ((volatile unsigned char *)0x4B)
#define OCR1AL        ((volatile unsigned char *)0x4A)
#define OCR1BH        ((volatile unsigned char *)0x49)
#define OCR1BL        ((volatile unsigned char *)0x48)
#define ICR1H         ((volatile unsigned char *)0x47)
#define ICR1L         ((volatile unsigned char *)0x46)
//Timer2
#define TCCR2         ((volatile unsigned char *)0x45)
#define TCNT2         ((volatile unsigned char *)0x44)
#define OCR2          ((volatile unsigned char *)0x43)
#define ASSR          ((volatile unsigned char *)0x42)
//Reset Timer0 && Timer1 && Timer2
#define SFIOR        ((volatile unsigned char *)0x50)
//Interrupt Timer0 && Timer1 && Timer2
#define TIMSK         ((volatile unsigned char *)0x59)
#define TIFR          ((volatile unsigned char *)0x58)

/*typedef struct{
     unsigned char PORTx;
	 unsigned char DDRx;
	 unsigned char PINx;
	
}type_port;*/

//value
#define SET   1
#define RESET 0

//states
#define INPUT  0
#define OUTPUT 1

//PIN
#define  PIN0          0
#define  PIN1          1
#define  PIN2          2
#define  PIN3          3
#define  PIN4          4
#define  PIN5          5
#define  PIN6          6
#define  PIN7          7


//--------------------------------------------------------
//==========================================================
//-------------------------API------------------------------
//===========================================================

//void PORT_init(type_port * p_post_t);
void DIR_PORT (uint8_t *DDRx,uint8_t state);
void DIR_PIN (uint8_t *DDRx,uint8_t pin,uint8_t state);


uint8_t READ_PORT(uint8_t *PINx);
uint8_t READ_PIN (uint8_t *PINx,uint8_t pin);

void Set_Port(uint8_t *PORTx);
void Set_PIN(uint8_t *PORTx,uint8_t pin);

void Toggel_PIN(uint8_t *PORTx,uint8_t pin);

void Reset_Port(uint8_t *PORTx);
void Reset_PIN(uint8_t *PORTx,uint8_t pin);






#endif /* DIO_H_ */