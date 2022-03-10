################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/main.c \
C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/stm32f4xx_hal_msp.c \
C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/stm32f4xx_it.c \
../Application/User/Core/syscalls.c \
../Application/User/Core/sysmem.c 

CPP_SRCS += \
C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/IcHausMu.cpp \
C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/application.cpp \
C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/as5048a.cpp \
C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/cpp_link.cpp \
C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/encoder.cpp 

C_DEPS += \
./Application/User/Core/main.d \
./Application/User/Core/stm32f4xx_hal_msp.d \
./Application/User/Core/stm32f4xx_it.d \
./Application/User/Core/syscalls.d \
./Application/User/Core/sysmem.d 

OBJS += \
./Application/User/Core/IcHausMu.o \
./Application/User/Core/application.o \
./Application/User/Core/as5048a.o \
./Application/User/Core/cpp_link.o \
./Application/User/Core/encoder.o \
./Application/User/Core/main.o \
./Application/User/Core/stm32f4xx_hal_msp.o \
./Application/User/Core/stm32f4xx_it.o \
./Application/User/Core/syscalls.o \
./Application/User/Core/sysmem.o 

CPP_DEPS += \
./Application/User/Core/IcHausMu.d \
./Application/User/Core/application.d \
./Application/User/Core/as5048a.d \
./Application/User/Core/cpp_link.d \
./Application/User/Core/encoder.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/IcHausMu.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/IcHausMu.cpp Application/User/Core/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/application.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/application.cpp Application/User/Core/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/as5048a.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/as5048a.cpp Application/User/Core/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/cpp_link.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/cpp_link.cpp Application/User/Core/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/encoder.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/encoder.cpp Application/User/Core/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/main.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/main.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_hal_msp.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/stm32f4xx_hal_msp.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_it.o: C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/Core/Src/stm32f4xx_it.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/%.o Application/User/Core/%.su: ../Application/User/Core/%.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -c -I../../Core/Inc -I"C:/Users/Luczia/STM32CubeIDE/workspace_1.9.0/NUC401-SPI-Encoder/STM32CubeIDE/Application/User/Utils/Inc" -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Core

clean-Application-2f-User-2f-Core:
	-$(RM) ./Application/User/Core/IcHausMu.d ./Application/User/Core/IcHausMu.o ./Application/User/Core/IcHausMu.su ./Application/User/Core/application.d ./Application/User/Core/application.o ./Application/User/Core/application.su ./Application/User/Core/as5048a.d ./Application/User/Core/as5048a.o ./Application/User/Core/as5048a.su ./Application/User/Core/cpp_link.d ./Application/User/Core/cpp_link.o ./Application/User/Core/cpp_link.su ./Application/User/Core/encoder.d ./Application/User/Core/encoder.o ./Application/User/Core/encoder.su ./Application/User/Core/main.d ./Application/User/Core/main.o ./Application/User/Core/main.su ./Application/User/Core/stm32f4xx_hal_msp.d ./Application/User/Core/stm32f4xx_hal_msp.o ./Application/User/Core/stm32f4xx_hal_msp.su ./Application/User/Core/stm32f4xx_it.d ./Application/User/Core/stm32f4xx_it.o ./Application/User/Core/stm32f4xx_it.su ./Application/User/Core/syscalls.d ./Application/User/Core/syscalls.o ./Application/User/Core/syscalls.su ./Application/User/Core/sysmem.d ./Application/User/Core/sysmem.o ./Application/User/Core/sysmem.su

.PHONY: clean-Application-2f-User-2f-Core

