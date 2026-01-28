################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../.settings/.metadata/.plugins/org.eclipse.cdt.make.core/specs.c 

OBJS += \
./.settings/.metadata/.plugins/org.eclipse.cdt.make.core/specs.o 

C_DEPS += \
./.settings/.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 


# Each subdirectory must supply rules for building sources it contributes
.settings/.metadata/.plugins/org.eclipse.cdt.make.core/%.o .settings/.metadata/.plugins/org.eclipse.cdt.make.core/%.su .settings/.metadata/.plugins/org.eclipse.cdt.make.core/%.cyclo: ../.settings/.metadata/.plugins/org.eclipse.cdt.make.core/%.c .settings/.metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32WB1Mxx -c -I../../Core/Inc -I../../STM32_WPAN/App -I../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../../Utilities/lpm/tiny_lpm -I../../Middlewares/ST/STM32_WPAN -I../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../../Middlewares/ST/STM32_WPAN/utilities -I../../Middlewares/ST/STM32_WPAN/ble/core -I../../Middlewares/ST/STM32_WPAN/ble/core/auto -I../../Middlewares/ST/STM32_WPAN/ble/core/template -I../../Middlewares/ST/STM32_WPAN/ble/svc/Inc -I../../Middlewares/ST/STM32_WPAN/ble/svc/Src -I../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../Utilities/sequencer -I../../Middlewares/ST/STM32_WPAN/ble -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean--2e-settings-2f--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-make-2e-core

clean--2e-settings-2f--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-make-2e-core:
	-$(RM) ./.settings/.metadata/.plugins/org.eclipse.cdt.make.core/specs.cyclo ./.settings/.metadata/.plugins/org.eclipse.cdt.make.core/specs.d ./.settings/.metadata/.plugins/org.eclipse.cdt.make.core/specs.o ./.settings/.metadata/.plugins/org.eclipse.cdt.make.core/specs.su

.PHONY: clean--2e-settings-2f--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-make-2e-core

