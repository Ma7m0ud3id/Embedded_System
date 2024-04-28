################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c8tx.s 

OBJS += \
./Startup/startup_stm32f103c8tx.o 

S_DEPS += \
./Startup/startup_stm32f103c8tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f103c8tx.o: ../Startup/startup_stm32f103c8tx.s
	arm-none-eabi-gcc -gdwarf-2 -mcpu=cortex-m3 -g3 -c -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/CMSIS_V5" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Stm32_F103C6_Drivers/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Ma7m0ud_RTOS/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/HAL/include" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103c8tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

