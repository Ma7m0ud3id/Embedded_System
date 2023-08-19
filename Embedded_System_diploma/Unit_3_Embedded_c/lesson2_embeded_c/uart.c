#include "uart.h"
#define Location_Uart  *((volatile unsigned int * const)((unsigned int *)0x101f1000))
void Uart_Send_String(unsigned char *String_pointer)
{
	while(*String_pointer!='\0')
	{
		Location_Uart = (unsigned int)(*String_pointer);
         String_pointer ++ ;
	}
	

         
	
}