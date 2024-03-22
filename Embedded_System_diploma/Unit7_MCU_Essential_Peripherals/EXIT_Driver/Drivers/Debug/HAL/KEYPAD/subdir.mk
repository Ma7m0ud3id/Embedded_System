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
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit7_MCU_Essential_Peripherals/EXIT_Driver/Drivers/Stm32_F103C6_Drivers/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit7_MCU_Essential_Peripherals/EXIT_Driver/Drivers/HAL/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KEYPAD/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

