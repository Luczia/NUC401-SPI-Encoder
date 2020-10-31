################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/stm32f4xx_hal_msp.c \
C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/stm32f4xx_it.c \
../Application/User/Core/syscalls.c \
../Application/User/Core/sysmem.c 

CPP_SRCS += \
C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/IcHausMu.cpp \
C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/as5048a.cpp \
C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/encoder.cpp \
C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/main.cpp 

C_DEPS += \
./Application/User/Core/stm32f4xx_hal_msp.d \
./Application/User/Core/stm32f4xx_it.d \
./Application/User/Core/syscalls.d \
./Application/User/Core/sysmem.d 

OBJS += \
./Application/User/Core/IcHausMu.o \
./Application/User/Core/as5048a.o \
./Application/User/Core/encoder.o \
./Application/User/Core/main.o \
./Application/User/Core/stm32f4xx_hal_msp.o \
./Application/User/Core/stm32f4xx_it.o \
./Application/User/Core/syscalls.o \
./Application/User/Core/sysmem.o 

CPP_DEPS += \
./Application/User/Core/IcHausMu.d \
./Application/User/Core/as5048a.d \
./Application/User/Core/encoder.d \
./Application/User/Core/main.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/IcHausMu.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/IcHausMu.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/IcHausMu.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/as5048a.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/as5048a.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/as5048a.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/encoder.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/encoder.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/encoder.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/main.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/main.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_hal_msp.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/stm32f4xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_it.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/Core/Src/stm32f4xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/syscalls.o: ../Application/User/Core/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/sysmem.o: ../Application/User/Core/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.3.0/oxio_esc/CubeMx_SPI_AS5048/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

