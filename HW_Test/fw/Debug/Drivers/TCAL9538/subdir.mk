################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/TCAL9538/TCAL9538.cpp 

OBJS += \
./Drivers/TCAL9538/TCAL9538.o 

CPP_DEPS += \
./Drivers/TCAL9538/TCAL9538.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/TCAL9538/%.o Drivers/TCAL9538/%.su Drivers/TCAL9538/%.cyclo: ../Drivers/TCAL9538/%.cpp Drivers/TCAL9538/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32WB1Mxx -c -I../Core/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc -I../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-TCAL9538

clean-Drivers-2f-TCAL9538:
	-$(RM) ./Drivers/TCAL9538/TCAL9538.cyclo ./Drivers/TCAL9538/TCAL9538.d ./Drivers/TCAL9538/TCAL9538.o ./Drivers/TCAL9538/TCAL9538.su

.PHONY: clean-Drivers-2f-TCAL9538

