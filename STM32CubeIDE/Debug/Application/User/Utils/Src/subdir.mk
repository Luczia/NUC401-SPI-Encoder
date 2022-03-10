################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/Utils/Src/dwt_delay.c 

C_DEPS += \
./Application/User/Utils/Src/dwt_delay.d 

OBJS += \
./Application/User/Utils/Src/dwt_delay.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Utils/Src/%.o Application/User/Utils/Src/%.su: ../Application/User/Utils/Src/%.c Application/User/Utils/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Utils-2f-Src

clean-Application-2f-User-2f-Utils-2f-Src:
	-$(RM) ./Application/User/Utils/Src/dwt_delay.d ./Application/User/Utils/Src/dwt_delay.o ./Application/User/Utils/Src/dwt_delay.su

.PHONY: clean-Application-2f-User-2f-Utils-2f-Src

