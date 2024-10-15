/*
 * Keypad.c
 *
 * Created: 12/6/2023 7:20:59 PM
 *  Author: mahmo
 */ 



#include "../inc/Keypad.h"

int Row []={R0,R1,R2,R3};
int Culom []={C0,C1,C2,C3};


void Keypad_Init (void){
	Keypad_control &= ~((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
	Keypad_control |=((1<<C0)|(1<<C1)|(1<<C2)|(1<<C3));
	Keypad=0xFF;
}
unsigned char Keypad_Result (void){
	int i,j;
	for (i=0;i<4;i++)
	{
		Keypad |= ((1<<Culom[0]) | (1<<Culom[1]) | (1<<Culom[2]) | (1<<Culom[3]));
		Keypad &=~(1<<Culom[i]);
		for(j = 0; j < 4; j++){
			if (!(Keypad_Pin & (1 << Row[j])))
			{
				while(!(Keypad_Pin & (1 << Row[j])));
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