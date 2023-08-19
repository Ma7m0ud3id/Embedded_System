################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
lesson1_embeded_c.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
lesson1_embeded_c.list \

OBJCOPY_HEX += \
lesson1_embeded_c.hex \

OBJCOPY_BIN += \
lesson1_embeded_c.bin \

OBJCOPY_SREC += \
lesson1_embeded_c.srec \


# All Target
all: lesson1_embeded_c.elf secondary-outputs

# Tool invocations
lesson1_embeded_c.elf: $(OBJS) $(USER_OBJS) C:\Users\mahmo\STM32CubeIDE\workspace_1.4.0\lesson1_embeded_c\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "lesson1_embeded_c.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\mahmo\STM32CubeIDE\workspace_1.4.0\lesson1_embeded_c\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="lesson1_embeded_c.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

lesson1_embeded_c.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "lesson1_embeded_c.list"
	@echo 'Finished building: $@'
	@echo ' '

lesson1_embeded_c.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "lesson1_embeded_c.hex"
	@echo 'Finished building: $@'
	@echo ' '

lesson1_embeded_c.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "lesson1_embeded_c.bin"
	@echo 'Finished building: $@'
	@echo ' '

lesson1_embeded_c.srec: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O srec $(EXECUTABLES) "lesson1_embeded_c.srec"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN) $(OBJCOPY_SREC)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
