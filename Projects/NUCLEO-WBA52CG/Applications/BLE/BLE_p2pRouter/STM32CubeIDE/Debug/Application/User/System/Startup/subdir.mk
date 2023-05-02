################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
C:/Users/marciasm/OneDrive\ -\ STMicroelectronics/Documents/GitHub/STM32CubeWBA/Projects/NUCLEO-WBA52CG/Applications/BLE/BLE_p2pRouter/System/Startup/stm32wbaxx_ResetHandler.S 

OBJS += \
./Application/User/System/Startup/stm32wbaxx_ResetHandler.o 

S_UPPER_DEPS += \
./Application/User/System/Startup/stm32wbaxx_ResetHandler.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/System/Startup/stm32wbaxx_ResetHandler.o: C:/Users/marciasm/OneDrive\ -\ STMicroelectronics/Documents/GitHub/STM32CubeWBA/Projects/NUCLEO-WBA52CG/Applications/BLE/BLE_p2pRouter/System/Startup/stm32wbaxx_ResetHandler.S Application/User/System/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m33 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"Application/User/System/Startup/stm32wbaxx_ResetHandler.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Application-2f-User-2f-System-2f-Startup

clean-Application-2f-User-2f-System-2f-Startup:
	-$(RM) ./Application/User/System/Startup/stm32wbaxx_ResetHandler.d ./Application/User/System/Startup/stm32wbaxx_ResetHandler.o

.PHONY: clean-Application-2f-User-2f-System-2f-Startup

