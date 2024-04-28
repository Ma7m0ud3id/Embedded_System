################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD/Lcd.c 

OBJS += \
./HAL/LCD/Lcd.o 

C_DEPS += \
./HAL/LCD/Lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD/Lcd.o: ../HAL/LCD/Lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/CMSIS_V5" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/HAL/include" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Ma7m0ud_RTOS/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD/Lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

