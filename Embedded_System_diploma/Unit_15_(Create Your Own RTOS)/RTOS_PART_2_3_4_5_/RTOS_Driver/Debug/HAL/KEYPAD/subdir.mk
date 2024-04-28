################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEYPAD/Keypad.c 

OBJS += \
./HAL/KEYPAD/Keypad.o 

C_DEPS += \
./HAL/KEYPAD/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KEYPAD/Keypad.o: ../HAL/KEYPAD/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/CMSIS_V5" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/HAL/include" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Ma7m0ud_RTOS/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KEYPAD/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

