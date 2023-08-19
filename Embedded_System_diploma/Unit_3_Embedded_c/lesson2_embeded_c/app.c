#include "uart.h"
unsigned char letter [100]="learn_in_deepth:Mahmoud";
unsigned char const letter_2 [100]="learn_in_deepth:Mahmoud";
void main(void)
{
	 Uart_Send_String (letter);
}