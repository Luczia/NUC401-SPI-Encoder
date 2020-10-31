################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Application/User/Utils/Src/subdir.mk
-include Application/User/Startup/subdir.mk
-include Application/User/Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
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
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CubeMx_SPI_AS5048.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CubeMx_SPI_AS5048.list \

OBJCOPY_BIN += \
CubeMx_SPI_AS5048.bin \


# All Target
all: CubeMx_SPI_AS5048.elf secondary-outputs

# Tool invocations
CubeMx_SPI_AS5048.elf: $(OBJS) $(USER_OBJS) C:\Users\Luczia\STM32CubeIDE\workspace_1.3.0\oxio_esc\CubeMx_SPI_AS5048\STM32CubeIDE\STM32F401RETX_FLASH.ld
	arm-none-eabi-g++ -o "CubeMx_SPI_AS5048.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Luczia\STM32CubeIDE\workspace_1.3.0\oxio_esc\CubeMx_SPI_AS5048\STM32CubeIDE\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CubeMx_SPI_AS5048.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CubeMx_SPI_AS5048.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CubeMx_SPI_AS5048.list"
	@echo 'Finished building: $@'
	@echo ' '

CubeMx_SPI_AS5048.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "CubeMx_SPI_AS5048.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
