/*
 * Stm32f103x8_gpio_drivers.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mahmoud_3id
 */

#ifndef INC_STM32F103X8_GPIO_DRIVERS_H_
#define INC_STM32F103X8_GPIO_DRIVERS_H_
//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x8.h"
//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct{


	uint16_t Pin_Number;// Specifies the GPIO pins to be configured.
	                   // This parameter can be a value of @ref GPIO PINS_define


	uint8_t Mode;      // Specifies the operating mode for the selected pins
	                   // This parameter can be a value of @ref GPIO MODE define


	uint8_t Speed;     // Specifies the speed for the selected pins
	                  // This parameter can be a value of @ref GPIO SPEED define

}GPIO_Pinconfige_t;
//-----------------------------
//Macros Configuration References

//-----------------------------
// @ref GPIO_PINS_define
#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected  10  */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected  100  */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected  1000  */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected  10000  */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */


#define GPIO_PIN_MASK              0x0000FFFFu /* PIN mask for assert test */
/*@ref GPIO_MODE_define
0: Analog mode
1: Floating input (reset state)
2: Input with pull-up
3: Input with pull-down
4: General purpose output push-pulla
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: Alternate function INPUTH
*/
#define  GPIO_MODE_ANALOG                        0x00000000u   //Analog mode
#define  GPIO_MODE_INPUT_FLO                     0x00000001u   //Floating input
#define  GPIO_MODE_INPUT_PU                      0x00000002u   //Input with pull-up
#define  GPIO_MODE_INPUT_PD                      0x00000003u   //Input with pull-down
#define  GPIO_MODE_OUTPUT_PP                     0x00000004u   //General purpose output push-pull
#define  GPIO_MODE_OUTPUT_OD                     0x00000005u   //General purpose output Open-drain
#define  GPIO_MODE_OUTPUT_AF_PP                  0x00000006u   //Alternate function output Push-pull
#define  GPIO_MODE_OUTPUT_AF_OD                  0x00000007u   //Alternate function output Open-drain
#define  GPIO_MODE_AF_INPUT                      0x00000008u   //Alternate function INPUT


//@ref GPIO_SPEED_define
//01: Output mode, max speed 10 MHz.
//10: Output mode, max speed 2 MHz
//11: Output mode, max speed 50 MHz.
#define GPIO_MODE_speed_10_MHz        0x00000001u  //Output mode, max speed 10 MHz
#define GPIO_MODE_speed_2_MHz         0x00000002u  //Output mode, max speed 2 MHz
#define GPIO_MODE_speed_50_MHz        0x00000003u   //Output mode, max speed 50 MHz



//@ref GPIO_PIN_state
#define GPIO_PIN_SET    	1
#define GPIO_PIN_RESET      0

//@ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_Enabled    	1
#define GPIO_RETURN_LOCK_ERROR     	    0
/*
 *
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
void GPIOx_init (typedef_GPIO* GPIOx,GPIO_Pinconfige_t* GPIO_conf);
void GPIOx_deinit (typedef_GPIO* GPIOx);

//READ
uint8_t GPIOx_READ_PIN (typedef_GPIO* GPIOx,uint16_t PIN_NUM);
uint16_t GPIOx_READ_PORT (typedef_GPIO* GPIOx);

//WRITE
void GPIOx_WRITE_PIN (typedef_GPIO* GPIOx,uint16_t PIN_NUM,uint8_t Value);
void GPIOx_WRITE_PORT (typedef_GPIO* GPIOx,uint16_t Value);

//Toggle
void GPIOx_TOGGELE_PIN (typedef_GPIO* GPIOx,uint16_t PIN_NUM);

//LOKE
uint8_t GPIOx_LOKE_PIN (typedef_GPIO* GPIOx,uint16_t PIN_NUM);

#endif /* INC_STM32F103X8_GPIO_DRIVERS_H_ */
