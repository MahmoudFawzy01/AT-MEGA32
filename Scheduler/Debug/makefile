################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
Scheduler.lss \

FLASH_IMAGE += \
Scheduler.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Scheduler.elf secondary-outputs

# Tool invocations
Scheduler.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Scheduler.map -mmcu=atmega32 -o "Scheduler.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Scheduler.lss: Scheduler.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Scheduler.elf  >"Scheduler.lss"
	@echo 'Finished building: $@'
	@echo ' '

Scheduler.hex: Scheduler.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Scheduler.elf  "Scheduler.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Scheduler.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Scheduler.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Scheduler.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
