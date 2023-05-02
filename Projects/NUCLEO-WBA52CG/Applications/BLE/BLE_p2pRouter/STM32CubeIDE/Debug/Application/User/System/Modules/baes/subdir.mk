################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/marciasm/OneDrive\ -\ STMicroelectronics/Documents/GitHub/STM32CubeWBA/Projects/NUCLEO-WBA52CG/Applications/BLE/BLE_p2pRouter/System/Modules/baes/baes_cmac.c \
C:/Users/marciasm/OneDrive\ -\ STMicroelectronics/Documents/GitHub/STM32CubeWBA/Projects/NUCLEO-WBA52CG/Applications/BLE/BLE_p2pRouter/System/Modules/baes/baes_ecb.c 

OBJS += \
./Application/User/System/Modules/baes/baes_cmac.o \
./Application/User/System/Modules/baes/baes_ecb.o 

C_DEPS += \
./Application/User/System/Modules/baes/baes_cmac.d \
./Application/User/System/Modules/baes/baes_ecb.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/System/Modules/baes/baes_cmac.o: C:/Users/marciasm/OneDrive\ -\ STMicroelectronics/Documents/GitHub/STM32CubeWBA/Projects/NUCLEO-WBA52CG/Applications/BLE/BLE_p2pRouter/System/Modules/baes/baes_cmac.c Application/User/System/Modules/baes/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_ASSERT -DUSE_FULL_LL_DRIVER -DPHY_2_10_a -DPHY_40nm_2_30_a_A1 -DNVM_ADAPT -DBLE -DUSE_HAL_DRIVER -DSTM32WBA52xx -c -I../../Core/Inc -I../../System/Interfaces -I../../System/Modules -I../../System/Modules/baes -I../../System/Modules/Flash -I../../System/Modules/MemoryManager -I../../System/Modules/Nvm -I../../System/Modules/RTDebug -I../../System/Config/Debug_GPIO -I../../System/Config/LowPower -I../../System/Config/Flash -I../../STM32_WPAN/App -I../../STM32_WPAN/Target -I../../../../../../../Drivers/STM32WBAxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32WBAxx_HAL_Driver/Inc/Legacy -I../../../../../../../Utilities/trace/adv_trace -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/tim_serv -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Middlewares/ST/STM32_WPAN -I../../../../../../../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/config/ble_basic -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/svc/Src -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WBAxx/Include -I../../../../../../../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc -I../../../../../../../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc/_40nm_reg_files -I../../../../../../../Middlewares/ST/STM32_WPAN/link_layer/ll_sys/inc -I../../../../../../../Middlewares/ST/STM32_WPAN/ble -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/stack/include -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/stack/include/auto -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/svc/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/STM32WBAxx_Nucleo -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Application/User/System/Modules/baes/baes_cmac.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/System/Modules/baes/baes_ecb.o: C:/Users/marciasm/OneDrive\ -\ STMicroelectronics/Documents/GitHub/STM32CubeWBA/Projects/NUCLEO-WBA52CG/Applications/BLE/BLE_p2pRouter/System/Modules/baes/baes_ecb.c Application/User/System/Modules/baes/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_ASSERT -DUSE_FULL_LL_DRIVER -DPHY_2_10_a -DPHY_40nm_2_30_a_A1 -DNVM_ADAPT -DBLE -DUSE_HAL_DRIVER -DSTM32WBA52xx -c -I../../Core/Inc -I../../System/Interfaces -I../../System/Modules -I../../System/Modules/baes -I../../System/Modules/Flash -I../../System/Modules/MemoryManager -I../../System/Modules/Nvm -I../../System/Modules/RTDebug -I../../System/Config/Debug_GPIO -I../../System/Config/LowPower -I../../System/Config/Flash -I../../STM32_WPAN/App -I../../STM32_WPAN/Target -I../../../../../../../Drivers/STM32WBAxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32WBAxx_HAL_Driver/Inc/Legacy -I../../../../../../../Utilities/trace/adv_trace -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/tim_serv -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Middlewares/ST/STM32_WPAN -I../../../../../../../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/config/ble_basic -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/svc/Src -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WBAxx/Include -I../../../../../../../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc -I../../../../../../../Middlewares/ST/STM32_WPAN/link_layer/ll_cmd_lib/inc/_40nm_reg_files -I../../../../../../../Middlewares/ST/STM32_WPAN/link_layer/ll_sys/inc -I../../../../../../../Middlewares/ST/STM32_WPAN/ble -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/stack/include -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/stack/include/auto -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/svc/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/STM32WBAxx_Nucleo -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Application/User/System/Modules/baes/baes_ecb.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-System-2f-Modules-2f-baes

clean-Application-2f-User-2f-System-2f-Modules-2f-baes:
	-$(RM) ./Application/User/System/Modules/baes/baes_cmac.cyclo ./Application/User/System/Modules/baes/baes_cmac.d ./Application/User/System/Modules/baes/baes_cmac.o ./Application/User/System/Modules/baes/baes_cmac.su ./Application/User/System/Modules/baes/baes_ecb.cyclo ./Application/User/System/Modules/baes/baes_ecb.d ./Application/User/System/Modules/baes/baes_ecb.o ./Application/User/System/Modules/baes/baes_ecb.su

.PHONY: clean-Application-2f-User-2f-System-2f-Modules-2f-baes

