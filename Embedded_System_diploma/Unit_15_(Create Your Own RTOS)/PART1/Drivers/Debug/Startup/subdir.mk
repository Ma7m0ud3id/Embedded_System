################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c6tx.s 

OBJS += \
./Startup/startup_stm32f103c6tx.o 

S_DEPS += \
./Startup/startup_stm32f103c6tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f103c6tx.o: ../Startup/startup_stm32f103c6tx.s
	arm-none-eabi-gcc -gdwarf-2 -mcpu=cortex-m3 -g3 -c -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/PART1/Drivers/Ma7m0ud_RTOS/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/PART1/Drivers/CMSIS_V5" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/PART1/Drivers/HAL/include" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/PART1/Drivers/Stm32_F103C6_Drivers/inc" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103c6tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

