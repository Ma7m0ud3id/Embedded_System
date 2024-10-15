
#include "MCAL/inc/EXTI.h"
#include "MCAL/inc/DIO.h"
#include "MCAL/inc/ADC.h"
#include "MCAL/inc/SPI.h"
#include "MCAL/inc/UART.h"
#include "MCAL/inc/I2C_services.h"


#include "HAL/inc/LCD.h"
#include "HAL/inc/Keypad.h"
#include "HAL/inc/LM35.h"
#include "HAL/inc/LDR.h"
#include "HAL/inc/soil.h"
#include "HAL/inc/HiH5030.h"


//#define Master_Mode
#define  Slave_Mode





int main(void)
{
	
	
	
#ifdef Master_Mode
      /* initialize communication */
      Communication_enuInitMaster();
#endif	

#ifdef 	Slave_Mode
      /* initialize communication */
      Communication_enuInitSlave();
     
#endif
   
	
/*#ifdef Master_Mode
      I2C_enuStartCondition();
#endif

#ifdef Slave_Mode
    Send_string("Slave");
	RXdata ='a';
	_delay_ms(1000);
#endif	*/
#ifdef Master_Mode

     Communication_Frame_t Local_uniCommFrame;


     Local_uniCommFrame.dat1 = 10;
     Local_uniCommFrame.dat2 = 20;
     Local_uniCommFrame.dat3 = 30;
     Local_uniCommFrame.dat4 = 40;
     Local_uniCommFrame.dat5 = 50;
	 
	 Communication_enuSendFrame(&Local_uniCommFrame);
	 
	 
	 
#endif

#ifdef 	Slave_Mode
       Communication_Frame_t Local_uniCommFrame;
	   
	   Communication_enuReceiveFrame(&Local_uniCommFrame);

#endif


  
	
}