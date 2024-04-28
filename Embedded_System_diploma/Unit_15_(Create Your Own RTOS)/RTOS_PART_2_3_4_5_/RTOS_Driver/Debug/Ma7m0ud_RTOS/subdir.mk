################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ma7m0ud_RTOS/CortexMx_OS_Porting.c \
../Ma7m0ud_RTOS/MYRTOS_FIFO.c \
../Ma7m0ud_RTOS/Scheduler.c 

OBJS += \
./Ma7m0ud_RTOS/CortexMx_OS_Porting.o \
./Ma7m0ud_RTOS/MYRTOS_FIFO.o \
./Ma7m0ud_RTOS/Scheduler.o 

C_DEPS += \
./Ma7m0ud_RTOS/CortexMx_OS_Porting.d \
./Ma7m0ud_RTOS/MYRTOS_FIFO.d \
./Ma7m0ud_RTOS/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
Ma7m0ud_RTOS/CortexMx_OS_Porting.o: ../Ma7m0ud_RTOS/CortexMx_OS_Porting.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/CMSIS_V5" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/HAL/include" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Ma7m0ud_RTOS/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Ma7m0ud_RTOS/CortexMx_OS_Porting.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Ma7m0ud_RTOS/MYRTOS_FIFO.o: ../Ma7m0ud_RTOS/MYRTOS_FIFO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/CMSIS_V5" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/HAL/include" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Ma7m0ud_RTOS/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Ma7m0ud_RTOS/MYRTOS_FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Ma7m0ud_RTOS/Scheduler.o: ../Ma7m0ud_RTOS/Scheduler.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/CMSIS_V5" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/HAL/include" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Ma7m0ud_RTOS/inc" -I"C:/Users/mahmo/OneDrive/Desktop/second_term_Projects/Unit 15 (Create Your Own RTOS)/RTOS_PART_2_3_4_5_/RTOS_Driver/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Ma7m0ud_RTOS/Scheduler.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

