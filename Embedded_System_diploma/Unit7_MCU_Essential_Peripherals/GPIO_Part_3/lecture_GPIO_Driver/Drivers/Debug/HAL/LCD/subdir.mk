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
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit7_MCU_Essential_Peripherals/GPIO_Part_3/lecture_GPIO_Driver/Drivers/Stm32_F103C6_Drivers/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit7_MCU_Essential_Peripherals/GPIO_Part_3/lecture_GPIO_Driver/Drivers/HAL/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD/Lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

