################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include GlcdTextLine/subdir.mk
-include GlcdText/subdir.mk
-include GlcdSimpleText/subdir.mk
-include GlcdRectangle/subdir.mk
-include GlcdPoint/subdir.mk
-include GlcdGraphicState/subdir.mk
-include GlcdDrawer/subdir.mk
-include GlcdBitmapRender/subdir.mk
-include GlcdBitmapImage/subdir.mk
-include GlcdBitmapFont/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
libArduinoGlcdLibrary.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: libArduinoGlcdLibrary.a secondary-outputs

# Tool invocations
libArduinoGlcdLibrary.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR Archiver'
	avr-ar -r  "libArduinoGlcdLibrary.a" $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

libArduinoGlcdLibrary.lss: libArduinoGlcdLibrary.a
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S libArduinoGlcdLibrary.a  >"libArduinoGlcdLibrary.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: libArduinoGlcdLibrary.a
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p libArduinoGlcdLibrary.a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(LSS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(ARCHIVES)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) libArduinoGlcdLibrary.a
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
