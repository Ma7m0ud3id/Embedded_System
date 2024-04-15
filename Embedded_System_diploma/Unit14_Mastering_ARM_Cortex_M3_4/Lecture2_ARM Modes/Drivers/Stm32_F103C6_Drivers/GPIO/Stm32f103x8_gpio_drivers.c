/*
 * Stm32f103x8_gpio_drivers.c
 *
 *  Created on: Sep 27, 2023
 *      Author: Mahmoud_3id
 */
//----------------------------
//include
//-----------------------------
#include "Stm32f103x8_gpio_drivers.h"
//-----------------------------
uint8_t get_pin(uint16_t Pin_Number){
	switch (Pin_Number)
		{
		//from pin 0 t0 7 CRL
		case GPIO_PIN_0:
			return 0 ;
			break ;
		case GPIO_PIN_1:
			return 4 ;
			break ;
		case GPIO_PIN_2:
			return 8 ;
			break ;
		case GPIO_PIN_3:
			return 12 ;
			break ;

		case GPIO_PIN_4:
			return 16 ;
			break ;

		case GPIO_PIN_5:
			return 20 ;
			break ;

		case GPIO_PIN_6:
			return 24 ;
			break ;

		case GPIO_PIN_7:
			return 28 ;
			break ;

			//from pin 8 t0 15 CRH
		case GPIO_PIN_8:
			return 0 ;
			break ;
		case GPIO_PIN_9:
			return 4 ;
			break ;

		case GPIO_PIN_10:
			return 8 ;
			break ;

		case GPIO_PIN_11:
			return 12 ;
			break ;

		case GPIO_PIN_12:
			return 16 ;
			break ;


		case GPIO_PIN_13:
			return 20 ;
			break ;

		case GPIO_PIN_14:
			return 24 ;
			break ;

		case GPIO_PIN_15:
			return 28 ;
			break ;



		}

}
/**================================================================
* @Fn            - GPIOx_init
* @brief         -Initializes the GPIOx PINy according to the specified parameters in the PinConfig
* @param [in]    -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
* @param [out]   -GPIO_conf pointer to a GPIO PinConfig t structure that contains the configuration information for the specified GPIO PIN
* @retval        -non
* Note           -Stm32F103C6 MCU has GPIO A, B, C,D, E Modules But LQFP48 Package has only GPIO A, B, PART of C/D exported as external PINS from MCU
*/
void GPIOx_init (typedef_GPIO* GPIOx,GPIO_Pinconfige_t* GPIO_conf){
	uint32_t* config=NULL;
	config=(GPIO_conf->Pin_Number)>GPIO_PIN_8?&GPIOx->CRH:&GPIOx->CRL;
	uint8_t pinVal =0;
	*(config) &= (~(0xf <<get_pin(GPIO_conf->Pin_Number)));



	if(GPIO_conf->Mode==GPIO_MODE_OUTPUT_PP||GPIO_conf->Mode==GPIO_MODE_OUTPUT_OD||GPIO_conf->Mode==GPIO_MODE_OUTPUT_AF_PP||GPIO_conf->Mode==GPIO_MODE_OUTPUT_AF_OD){
		pinVal= (((GPIO_conf->Mode -4)<<2) | (GPIO_conf->Speed) & 0x0f);



	}else{


		if(GPIO_conf->Mode==GPIO_MODE_ANALOG||GPIO_conf->Mode==GPIO_MODE_INPUT_FLO){
			pinVal=(((GPIO_conf->Mode<<2)|0x00)& 0x0f);



		}
		else if (GPIO_conf->Mode == GPIO_MODE_AF_INPUT) // consider it floating input
		{
			pinVal = ((((GPIO_MODE_INPUT_FLO)<<2) | 0x0) & 0xf );

		}

		//in case of PULL UP & PULL DOWN
		else
		{
			pinVal = ((((GPIO_MODE_INPUT_PU)<<2) | 0x0) & 0xf );
			if(GPIO_conf->Mode == GPIO_MODE_INPUT_PU)
			{
				//PxODR = 1 Input pull-up :Table 20. Port bit configuration table
				GPIOx->ODR = GPIO_conf->Pin_Number;

			}
			else
			{
				//PxODR = 1 Input pull-up :Table 20. Port bit configuration table
				GPIOx->ODR &= ~(GPIO_conf->Pin_Number);
			}

		}
	}
	(*config) |= ((pinVal)<< get_pin(GPIO_conf->Pin_Number));

}

/**================================================================
* @Fn            -GPIOx_init
* @brief         -Reset all GPIO register
* @param [in]    -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
* @param [out]   -GPIO_conf pointer to a GPIO PinConfig t structure that contains the configuration information for the specified GPIO PIN
* @retval        -non
* Note           -non
*/
void GPIOx_deinit (typedef_GPIO* GPIOx){
	//or you can use the reset Controller
		//APB2 peripheral reset register (RCC->APB2RSTR)
		//Set and cleared by software.
		if (GPIOx == GPIOA)
		{
			RCC->APB2RSTR |= (1<<2); //Bit 2 IOPARST: IO port A reset
			RCC->APB2RSTR &= ~(1<<2);
		}
		if (GPIOx == GPIOB)
		{
			RCC->APB2RSTR |= (1<<3); //Bit 3 IOPARST: IO port B reset
			RCC->APB2RSTR &= ~(1<<3);
		}
		if (GPIOx == GPIOC)
		{
			RCC->APB2RSTR |= (1<<4); //Bit 4 IOPARST: IO port C reset
			RCC->APB2RSTR &= ~(1<<4);
		}
		if (GPIOx == GPIOD)
		{
			RCC->APB2RSTR |= (1<<5); //Bit 5 IOPARST: IO port D reset
			RCC->APB2RSTR &= ~(1<<5);
		}
		if (GPIOx == GPIOE)
		{
			RCC->APB2RSTR |= (1<<6); //Bit 6 IOPARST: IO port E reset
			RCC->APB2RSTR &= ~(1<<6);
		}

}
/**================================================================
 * @Fn				-GPIOx_READ_PIN
 * @brief 			-Read Specific PIN
 * @param [in] 	    -GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 	    -PinNumber: Set Pin Number according @ref GPIO_PINS_define
 * @retval 		    -the input pin value (two values based on @ref GPIO_PIN_state )
 * Note			    -none
 */

//READ
uint8_t GPIOx_READ_PIN (typedef_GPIO* GPIOx,uint16_t PIN_NUM){

	  uint8_t BitStatus;

		if ((GPIOx->IDR & PIN_NUM) != (uint32_t)GPIO_PIN_RESET)
		{
			BitStatus = GPIO_PIN_SET;
		}
		else
		{
			BitStatus = GPIO_PIN_RESET;
		}
		return BitStatus;

}
/**================================================================
 * @Fn					-GPIOx_READ_PORT
 * @brief 				-read the input port VALUE
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 				-the input port VALUE
 * Note					-none
 */
uint16_t GPIOx_READ_PORT (typedef_GPIO* GPIOx){
	uint16_t result;
	result =(uint16_t) (GPIOx->IDR);
	return result;

}
/**================================================================
 * @Fn					-MCAL_GPIO_WritePin
 * @brief 				-write on specific input pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 *@param [in] 			-PinNumber:  specifies the port bit to read. Set by @ref GPIO_PINS_define
 *@param [in] 			-Value: Pin Value
 * @retval 			    -none
 * Note				    -none
 */
//WRITE
void GPIOx_WRITE_PIN (typedef_GPIO* GPIOx,uint16_t PIN_NUM,uint8_t Value){
	if (Value !=GPIO_PIN_RESET)
			//		GPIOx->ODR |= PinNumber ;
			//		or
			//		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
			//		These bits are write-only and can be accessed in Word mode only.
			//		0: No action on the corresponding ODRx bit
			//		1: Set the corresponding ODRx bit

			GPIOx->BSRR = (uint32_t)PIN_NUM;

		else
		{
			//		Bits 31:16 BRy: Port x Reset bit y (y= 0 .. 15)
			//		These bits are write-only and can be accessed in Word mode only.
			//		0: No action on the corresponding ODRx bit
			//		1: Reset the corresponding ODRx bit
			GPIOx->BRR =(uint32_t) PIN_NUM;
		}

}

/**================================================================
/**================================================================
 * @Fn					-MCAL_GPIO_WritePort
 * @brief 				-write on output port
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 				-none
 * Note					-none
 */
void GPIOx_WRITE_PORT (typedef_GPIO* GPIOx,uint16_t Value){
	GPIOx->ODR =(uint32_t)Value;

}
/**================================================================
 * @Fn					-MCAL_GPIO_TogglePin
 * @brief 				-Toggles the specified GPIO pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinNumber: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 			    -none
 * Note				    -none
*/
void GPIOx_TOGGELE_PIN (typedef_GPIO* GPIOx,uint16_t PIN_NUM){
	GPIOx->ODR^=(PIN_NUM);

}
/**================================================================
 * @Fn					-MCAL_GPIO_LockPin
 * @brief 				-The locking mechanism allows the IO configuration to be frozen
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in] 		    -PIN_NUM: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 			    -non
 * Note				    -none
 */
//LOKE
uint8_t GPIOx_LOKE_PIN (typedef_GPIO* GPIOx,uint16_t PIN_NUM){

	//	Bit 16 LCKK[16]: Lock key
		//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
		//	0: Port configuration lock key not active
		//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
		//	LOCK key writing sequence:
		//	Write 1
		//	Write 0
		//	Write 1
		//	Read 0
		//	Read 1 (this read is optional but confirms that the lock is active)
		//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
		//	Any error in the lock sequence will abort the lock.
		//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
		//	These bits are read write but can only be written when the LCKK bit is 0.
		//	0: Port configuration not locked
		//	1: Port configuration locked

		//	Set LCKK[16]
		volatile uint32_t temp = 1<<16;

		//	set the key
		temp |= PIN_NUM;

		//	Write 1
		GPIOx->LCKR = temp;
		//	Write 0
		GPIOx->LCKR = PIN_NUM;
		//	Write 1
		GPIOx->LCKR = temp;
		//	Read 0
		temp =GPIOx->LCKR;
		//	Read 1 (this read is optional but confirms that the lock is active)
		if((uint32_t)(GPIOx->LCKR) & 1)
		{
			return GPIO_RETURN_LOCK_Enabled;
		}
		else
		{
			return GPIO_RETURN_LOCK_ERROR;
		}

}

