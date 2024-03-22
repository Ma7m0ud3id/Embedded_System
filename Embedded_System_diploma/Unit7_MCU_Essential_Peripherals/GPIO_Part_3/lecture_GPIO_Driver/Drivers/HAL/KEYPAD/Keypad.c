/*
 * Keypad.c
 *
 *  Created on: Sep 28, 2023
 *      Author: mahmo
 */

#include "../include/Keypad.h"
int Row []={R0,R1,R2,R3};
int Culom []={C0,C1,C2,C3};
GPIO_Pinconfige_t keypad_confg;

void Keypad_Init (void){
	keypad_confg.Pin_Number=R0;
	keypad_confg.Mode=GPIO_MODE_OUTPUT_PP;
	keypad_confg.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(Keypad, &keypad_confg);
	//************************************
	keypad_confg.Pin_Number=R1;
	keypad_confg.Mode=GPIO_MODE_OUTPUT_PP;
	keypad_confg.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(Keypad, &keypad_confg);
	//************************************
	keypad_confg.Pin_Number=R2;
	keypad_confg.Mode=GPIO_MODE_OUTPUT_PP;
	keypad_confg.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(Keypad, &keypad_confg);
	//************************************
	keypad_confg.Pin_Number=R3;
	keypad_confg.Mode=GPIO_MODE_OUTPUT_PP;
	keypad_confg.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(Keypad, &keypad_confg);
	//************************************

	//Keypad_control &= ~((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
	keypad_confg.Pin_Number=C0;
	keypad_confg.Mode=GPIO_MODE_OUTPUT_PP;
	keypad_confg.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(Keypad, &keypad_confg);
	//************************************
	keypad_confg.Pin_Number=C1;
	keypad_confg.Mode=GPIO_MODE_OUTPUT_PP;
	keypad_confg.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(Keypad, &keypad_confg);
	//************************************
	keypad_confg.Pin_Number=C2;
	keypad_confg.Mode=GPIO_MODE_OUTPUT_PP;
	keypad_confg.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(Keypad, &keypad_confg);
	//************************************
	keypad_confg.Pin_Number=C3;
	keypad_confg.Mode=GPIO_MODE_OUTPUT_PP;
	keypad_confg.Speed=GPIO_MODE_speed_10_MHz;
	GPIOx_init(Keypad, &keypad_confg);
	//************************************
	//Keypad_control |=((1<<C0)|(1<<C1)|(1<<C2)|(1<<C3));
	/*GPIOx_WRITE_PIN(Keypad, R0, GPIO_PIN_SET);
	GPIOx_WRITE_PIN(Keypad, R1, GPIO_PIN_SET);
	GPIOx_WRITE_PIN(Keypad, R2, GPIO_PIN_SET);
	GPIOx_WRITE_PIN(Keypad, R3, GPIO_PIN_SET);
	GPIOx_WRITE_PIN(Keypad, C0, GPIO_PIN_SET);
	GPIOx_WRITE_PIN(Keypad, C1, GPIO_PIN_SET);
	GPIOx_WRITE_PIN(Keypad, C2, GPIO_PIN_SET);
	GPIOx_WRITE_PIN(Keypad, C3, GPIO_PIN_SET);*/
	GPIOx_WRITE_PORT(Keypad, 0xFF);
	//Keypad=0xFF;
}
unsigned char Keypad_Result (void){

	int i,j;
	for (i=0;i<4;i++)
	{
		GPIOx_WRITE_PIN(Keypad, Culom[0], GPIO_PIN_SET);
		GPIOx_WRITE_PIN(Keypad, Culom[1], GPIO_PIN_SET);
		GPIOx_WRITE_PIN(Keypad, Culom[2], GPIO_PIN_SET);
		GPIOx_WRITE_PIN(Keypad, Culom[3], GPIO_PIN_SET);
		//Keypad |= ((1<<Culom[0]) | (1<<Culom[1]) | (1<<Culom[2]) | (1<<Culom[3]));
		GPIOx_WRITE_PIN(Keypad,Culom[i], GPIO_PIN_RESET);
		//GPIOx_WRITE_PORT(Keypad, Culom[i]);
		//Keypad &=~(1<<Culom[i]);
		//!(GPIOx_READ_PORT(Keypad)& Row[j])___condetion
		for(j = 0; j < 4; j++){

			       // UNder is option becouse protous has problem
			        GPIOx_WRITE_PIN(Keypad, Culom[0], GPIO_PIN_SET);
					GPIOx_WRITE_PIN(Keypad, Culom[1], GPIO_PIN_SET);
					GPIOx_WRITE_PIN(Keypad, Culom[2], GPIO_PIN_SET);
					GPIOx_WRITE_PIN(Keypad, Culom[3], GPIO_PIN_SET);
					GPIOx_WRITE_PIN(Keypad, Row[0], GPIO_PIN_SET);
					GPIOx_WRITE_PIN(Keypad, Row[1], GPIO_PIN_SET);
					GPIOx_WRITE_PIN(Keypad, Row[2], GPIO_PIN_SET);
					GPIOx_WRITE_PIN(Keypad, Row[3], GPIO_PIN_SET);
					//***************************************************
					//Keypad |= ((1<<Culom[0]) | (1<<Culom[1]) | (1<<Culom[2]) | (1<<Culom[3]));
					GPIOx_WRITE_PIN(Keypad,Culom[i], GPIO_PIN_RESET);
			if (!(GPIOx_READ_PORT(Keypad)& Row[j]))
			{
				while(!(GPIOx_READ_PORT(Keypad)& Row[j]));
				switch(i){
				case (0):
											if (j == 0) return '7';
											else if (j == 1) return '4';
											else if (j == 2) return '1';
											else if (j == 3) return '?';
				break;
				case (1):
											if (j == 0) return '8';
											else if (j == 1) return '5';
											else if (j == 2) return '2';
											else if (j == 3) return '0';
				break;
				case (2):
											if (j == 0) return '9';
											else if (j == 1) return '6';
											else if (j == 2) return '3';
											else if (j == 3) return '=';
				break;
				case (3):
											if (j == 0) return '/';
											else if (j == 1) return '*';
											else if (j == 2) return '-';
											else if (j == 3) return '+';
				break;
				}
			}
		}
	}
	return 'A';

}
