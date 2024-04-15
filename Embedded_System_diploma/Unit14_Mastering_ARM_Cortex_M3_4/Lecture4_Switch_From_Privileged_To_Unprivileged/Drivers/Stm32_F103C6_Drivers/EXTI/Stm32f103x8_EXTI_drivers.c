/*
 * Stm32f103x8_gpio_drivers.c
 *
 *  Created on: Sep 27, 2023
 *      Author: Mahmoud_3id
 */
//----------------------------
//include
//-----------------------------
#include "Stm32f103x8_EXTI_drivers.h"
#include "Stm32f103x8_gpio_drivers.h"
//-----------------------------


//==============================MACROS=============================
//array of pointer to functions
void(*Gp_call_back_func[15]) (void);


//-----------------------------
//==============================MACROS=============================

#define AFIO_MAPPING(x)          ( (x==GPIOA)?0:\
		                           (x==GPIOB)?1:\
				                   (x==GPIOC)?2:\
						           (x==GPIOD)?3:0 )

//-----------------------------
/*========================================
 */

/*
 * =======================================================================================
 * 										GENERIC FUNCTIONS
 * =======================================================================================
 */

void NVIC_ENABLE(uint16_t IRQ){
	switch(IRQ){
	case EXTI0:
		NVIC_IRQ6_EXTI0_EN;
		break;
	case EXTI1:
		NVIC_IRQ7_EXTI1_EN;
		break;
	case EXTI2:
		NVIC_IRQ8_EXTI2_EN;
		break;
	case EXTI3:
		NVIC_IRQ9_EXTI3_EN ;
		break;
	case EXTI4:
		NVIC_IRQ10_EXTI4_EN ;
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IRQ23_EXTI5_9_EN ;
		break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IRQ40_EXTI10_15_EN ;
		break;
	}

}


void NVIC_DISABLE(uint16_t IRQ)
{
	switch(IRQ)
	{
	case EXTI0:
		NVIC_IRQ6_EXTI0_Dis ;
		break;

	case EXTI1:
		NVIC_IRQ7_EXTI1_Dis ;
		break;

	case EXTI2:
		NVIC_IRQ8_EXTI2_Dis ;
		break;

	case EXTI3:
		NVIC_IRQ9_EXTI3_Dis ;
		break;

	case EXTI4:
		NVIC_IRQ10_EXTI4_Dis ;
		break;

	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IRQ23_EXTI5_9_Dis ;
		break;

	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IRQ40_EXTI10_15_Dis ;
		break;
	}
}
/*//internal function
 *
 */
void Updata(EXTI_Configer_t* P_EXTI_Confige){
	//1-EXTI input pin FOIN
	    GPIO_Pinconfige_t  GPIO_Confi_t;
	    GPIO_Confi_t.Pin_Number=P_EXTI_Confige->exti_conf.PIN_NUM;
	    GPIO_Confi_t.Mode=GPIO_MODE_INPUT_FLO;
		GPIOx_init(P_EXTI_Confige->exti_conf.PORT_NUM, &GPIO_Confi_t);


	//2-Enable AFIO PIN
		uint8_t index    = (P_EXTI_Confige->exti_conf.EXTI_NUM)/4;
		uint8_t position = (P_EXTI_Confige->exti_conf.EXTI_NUM %4)*4;
		AAFIO->EXTICR[index]&=~(0xf<<position);
		AAFIO->EXTICR[index] |= ((AFIO_MAPPING(P_EXTI_Confige->exti_conf.PORT_NUM  )& 0xf)<<position);
	////==============================================
		//3- enable trigger case
		//clear bit of rising
		EXTI->RTSR &= ~(1<<P_EXTI_Confige->exti_conf.EXTI_NUM);

		//clear bit of Falling
		EXTI->FTSR &= ~(1<<P_EXTI_Confige->exti_conf.EXTI_NUM);

		if(P_EXTI_Confige->trigger_case==EXTI_Trigger_Raising){
			EXTI->RTSR|=(1<<P_EXTI_Confige->exti_conf.EXTI_NUM);

		}else if(P_EXTI_Confige->trigger_case==EXTI_Trigger_Falling){
			EXTI->FTSR |=(1<<P_EXTI_Confige->exti_conf.EXTI_NUM);

		}else if(P_EXTI_Confige->trigger_case==EXTI_Trigger_Poth_Raising_falling){
			EXTI->RTSR|=(1<<P_EXTI_Confige->exti_conf.EXTI_NUM);
			EXTI->FTSR |=(1<<P_EXTI_Confige->exti_conf.EXTI_NUM);
		}
		//4-handel function call back
		Gp_call_back_func[P_EXTI_Confige->exti_conf.EXTI_NUM]=P_EXTI_Confige->P_IRQ_call_back;
		//5-//enable MASK & NVIC
		if(P_EXTI_Confige->IRQ_EN==EXTI_IRQ_Enable)
			{
				 //enable mask
			EXTI->IMR |= (1<<P_EXTI_Confige->exti_conf.EXTI_NUM);
			    //enable NVIC
			 NVIC_ENABLE(P_EXTI_Confige->exti_conf.EXTI_NUM);
			}
			else if(P_EXTI_Confige->IRQ_EN==EXTI_IRQ_Disable)
			{
				 //diable mask
			EXTI->IMR &= ~(1<<P_EXTI_Confige->exti_conf.EXTI_NUM);
			    //disable NVIC
			 NVIC_DISABLE(P_EXTI_Confige->exti_conf.EXTI_NUM);
			}
}


/**================================================================
* @Fn            - MCAL_EXTI_GPIO_INIT
* @brief         -Initializes the EXTI PINy according to the specified parameters in the PinConfig
* @param [in]    -P_EXTI_Confige
* @retval        -non
* Note           -non
* */
void MCAL_EXTI_GPIO_INIT(EXTI_Configer_t* P_EXTI_Confige){
    Updata(P_EXTI_Confige);

}



/**================================================================
* @Fn            -MCAL_EXTI_GPIO_Deinit
* @brief         -Reset all EXTI register
* @param [in]    -non
* @retval        -non
* Note           -non
*/
void MCAL_EXTI_GPIO_Deinit(void){
	//clear EXTI_Register
	EXTI->IMR=0x00000000;
	EXTI->EMR=0x00000000;
	EXTI->FTSR=0x00000000;
	EXTI->RTSR=0x00000000;
	EXTI->SWIER=0x00000000;
	EXTI->PR=0xFFFFFFFF;

	//clear NVIC_Masked
	NVIC_IRQ6_EXTI0_Dis ;
	NVIC_IRQ7_EXTI1_Dis ;
	NVIC_IRQ8_EXTI2_Dis ;
	NVIC_IRQ9_EXTI3_Dis ;
	NVIC_IRQ10_EXTI4_Dis ;
	NVIC_IRQ23_EXTI5_9_Dis ;
	NVIC_IRQ40_EXTI10_15_Dis ;

}


/**================================================================
 * @Fn					-MCAL_EXTI_GPIO_UPDAT
 * @brief 				-UPdate EXTI GPIO Function
 * @param [in] 			-P_EXTI_Confige
 * @retval 				-non
 * Note					-none
 */
void MCAL_EXTI_GPIO_UPDAT(EXTI_Configer_t* P_EXTI_Confige){

	Updata(P_EXTI_Confige);
}
//=========================================ISR==============================================
void EXTI0_IRQHandler(void)
{
	//write 1 to clear pending bit,to stop sending interrupt again
	EXTI->PR = 1<<0;
	//callback
	Gp_call_back_func[0]();
}


void EXTI1_IRQHandler(void)
{
	EXTI->PR = 1<<1;
	Gp_call_back_func[1]();
}

void EXTI2_IRQHandler(void)
{
	EXTI->PR = 1<<2;
	Gp_call_back_func[2]();
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR = 1<<3;
	Gp_call_back_func[3]();
}



void EXTI4_IRQHandler(void)
{
	EXTI->PR = 1<<4;
	Gp_call_back_func[4]();
}



void EXTI9_5_IRQHandler(void)
{
    /* here i check which interrupt is that, cause all interrupts from
	 5---9  arrived on same pin at NVIC
	so we will know which interrupt for ,by checking PR register if its one so its
	and then we write 1 on PR reg to disable interrupt  */
	if(EXTI->PR & 1<<5) { EXTI->PR  = 1<<5;   Gp_call_back_func[5](); }
	if(EXTI->PR & 1<<6) { EXTI->PR  = 1<<6;   Gp_call_back_func[6](); }
	if(EXTI->PR & 1<<7) { EXTI->PR  = 1<<7;   Gp_call_back_func[7](); }
	if(EXTI->PR & 1<<8) { EXTI->PR  = 1<<8;   Gp_call_back_func[8](); }
	if(EXTI->PR & 1<<9) { EXTI->PR  = 1<<9;   Gp_call_back_func[9](); }
}



void EXTI15_10_IRQHandler(void){

	if( EXTI->PR & 1<<10 ) { EXTI->PR |= 1<<10; Gp_call_back_func[10](); }
	if( EXTI->PR & 1<<11 ) { EXTI->PR |= 1<<11; Gp_call_back_func[11](); }
	if( EXTI->PR & 1<<12 ) { EXTI->PR |= 1<<12; Gp_call_back_func[12](); }
	if( EXTI->PR & 1<<13 ) { EXTI->PR |= 1<<13; Gp_call_back_func[13](); }
	if( EXTI->PR & 1<<14 ) { EXTI->PR |= 1<<14; Gp_call_back_func[14](); }
	if( EXTI->PR & 1<<14 ) { EXTI->PR |= 1<<15; Gp_call_back_func[15](); }
}
