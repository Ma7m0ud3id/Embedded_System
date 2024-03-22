/*
 * DIO.h
 *
 * Created: 12/6/2023 7:20:08 PM
 *  Author: mahmo
 */ 


#ifndef DIO_H_
#define DIO_H_



#include "Private.h"
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