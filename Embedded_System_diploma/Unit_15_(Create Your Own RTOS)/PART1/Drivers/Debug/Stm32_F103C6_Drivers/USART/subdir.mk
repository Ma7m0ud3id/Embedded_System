################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/USART/Stm32f103x8_USART_drivers.c 

OBJS += \
./Stm32_F103C6_Drivers/USART/Stm32f103x8_USART_drivers.o 

C_DEPS += \
./Stm32_F103C6_Drivers/USART/Stm32f103x8_USART_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/USART/Stm32f103x8_USART_drivers.o: ../Stm32_F103C6_Drivers/USART/Stm32f103x8_USART_drivers.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/PART1/Drivers/Ma7m0ud_RTOS/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/PART1/Drivers/CMSIS_V5" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/PART1/Drivers/Stm32_F103C6_Drivers/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/PART1/Drivers/HAL/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/USART/Stm32f103x8_USART_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

