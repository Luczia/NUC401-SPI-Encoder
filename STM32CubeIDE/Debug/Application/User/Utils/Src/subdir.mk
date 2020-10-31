################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/Utils/Src/dwt_delay.c 

C_DEPS += \
./Application/User/Utils/Src/dwt_delay.d 

OBJS += \
./Application/User/Utils/Src/dwt_delay.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Utils/Src/dwt_delay.o: ../Application/User/Utils/Src/dwt_delay.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Utils/Src/dwt_delay.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

