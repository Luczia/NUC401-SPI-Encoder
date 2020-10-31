################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/system_stm32f4xx.c 

C_DEPS += \
./Drivers/CMSIS/system_stm32f4xx.d 

OBJS += \
./Drivers/CMSIS/system_stm32f4xx.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32f4xx.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/system_stm32f4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

