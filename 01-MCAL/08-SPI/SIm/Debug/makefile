################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/SPI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/CLCD/subdir.mk
-include APPLICATION/subdir.mk
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
SPI_test.lss \

FLASH_IMAGE += \
SPI_test.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SPI_test.elf secondary-outputs

# Tool invocations
SPI_test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SPI_test.map -mmcu=atmega32 -o "SPI_test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_test.lss: SPI_test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SPI_test.elf  >"SPI_test.lss"
	@echo 'Finished building: $@'
	@echo ' '

SPI_test.hex: SPI_test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SPI_test.elf  "SPI_test.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SPI_test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SPI_test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SPI_test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
