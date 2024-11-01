################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SRC/subdir.mk
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
MOBILE_CONTROLLED_HOME.lss \

FLASH_IMAGE += \
MOBILE_CONTROLLED_HOME.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: MOBILE_CONTROLLED_HOME.elf secondary-outputs

# Tool invocations
MOBILE_CONTROLLED_HOME.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MOBILE_CONTROLLED_HOME.map -mmcu=atmega32 -o "MOBILE_CONTROLLED_HOME.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MOBILE_CONTROLLED_HOME.lss: MOBILE_CONTROLLED_HOME.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MOBILE_CONTROLLED_HOME.elf  >"MOBILE_CONTROLLED_HOME.lss"
	@echo 'Finished building: $@'
	@echo ' '

MOBILE_CONTROLLED_HOME.hex: MOBILE_CONTROLLED_HOME.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MOBILE_CONTROLLED_HOME.elf  "MOBILE_CONTROLLED_HOME.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MOBILE_CONTROLLED_HOME.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MOBILE_CONTROLLED_HOME.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MOBILE_CONTROLLED_HOME.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
