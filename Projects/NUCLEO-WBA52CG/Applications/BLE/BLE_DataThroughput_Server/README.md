## __BLE_DataThroughput_Server Application Description__

How to demonstrate Point-to-Point communication using BLE component (as GATT server or GATT client).

The Nucleo board flashed with BLE_DataThroughput_Server application acts as GATT Server and the Client could be located on a nucleo board flashed with BLE_DataThroughput_Client or in a phone, using the ST BLE Toolbox application.

Data transfer via notification from server to client or/and write from client to server. Use of a timer that enables to calculate the throughput at application level. 


### __Keywords__

Connectivity, BLE, BLE protocol, BLE pairing, BLE profile


### __Directory contents__

  - BLE_DataThroughput_Server/Core/Inc/app_common.h                                   App Common application configuration file for STM32WPAN Middleware. 
  - BLE_DataThroughput_Server/Core/Inc/app_conf.h                                     Application configuration file for STM32WPAN Middleware. 
  - BLE_DataThroughput_Server/Core/Inc/app_entry.h                                    Interface to the application 
  - BLE_DataThroughput_Server/Core/Inc/main.h                                         Header for main.c file. This file contains the common defines of the application.
  - BLE_DataThroughput_Server/Core/Inc/stm32wbaxx_hal_conf.h                          HAL configuration file. 
  - BLE_DataThroughput_Server/Core/Inc/stm32wbaxx_it.h                                This file contains the headers of the interrupt handlers. 
  - BLE_DataThroughput_Server/Core/Inc/stm32wbaxx_nucleo_conf.h                       STM32WBAXX nucleo board configuration file. This file should be copied to the application folder and renamed
to stm32wbaxx_nucleo_conf.h .
  - BLE_DataThroughput_Server/Core/Inc/utilities_conf.h                               Header for configuration file for STM32 Utilities. 
  - BLE_DataThroughput_Server/STM32_WPAN/App/app_ble.h                                Header for ble application 
  - BLE_DataThroughput_Server/STM32_WPAN/App/ble_conf.h                               Configuration file for BLE Middleware. 
  - BLE_DataThroughput_Server/STM32_WPAN/App/ble_dbg_conf.h                           Debug configuration file for BLE Middleware. 
  - BLE_DataThroughput_Server/STM32_WPAN/App/dt_serv.h                                Header for service1.c 
  - BLE_DataThroughput_Server/STM32_WPAN/App/dt_serv_app.h                            Header for service1_app.c 
  - BLE_DataThroughput_Server/STM32_WPAN/Target/bpka.h                                This file contains the interface of the BLE PKA module. 
  - BLE_DataThroughput_Server/STM32_WPAN/Target/host_stack_if.h                       This file contains the interface for the stack tasks 
  - BLE_DataThroughput_Server/STM32_WPAN/Target/ll_sys_if.h                           Header file for ll_sys_if.c
  - BLE_DataThroughput_Server/System/Config/Debug_GPIO/app_debug.h                    Real Time Debug module application APIs and signal table 
  - BLE_DataThroughput_Server/System/Config/Debug_GPIO/app_debug_signal_def.h         Real Time Debug module application signal definition 
  - BLE_DataThroughput_Server/System/Config/Debug_GPIO/debug_config.h                 Real Time Debug module general configuration file 
  - BLE_DataThroughput_Server/System/Config/Flash/simple_nvm_arbiter_conf.h           Configuration header for simple_nvm_arbiter.c module 
  - BLE_DataThroughput_Server/System/Config/LowPower/app_sys.h                        Header for app_sys.c 
  - BLE_DataThroughput_Server/System/Interfaces/hw.h                                  This file contains the interface of STM32 HW drivers. 
  - BLE_DataThroughput_Server/System/Interfaces/hw_if.h                               Hardware Interface 
  - BLE_DataThroughput_Server/System/Interfaces/stm32_lpm_if.h                        Header for stm32_lpm_if.c module (device specific LP management) 
  - BLE_DataThroughput_Server/System/Interfaces/timer_if.h                            Configuration of the timer_if.c instances 
  - BLE_DataThroughput_Server/System/Interfaces/usart_if.h                            Header file for stm32_adv_trace interface file 
  - BLE_DataThroughput_Server/System/Modules/adc_ctrl.h                               Header for ADC client manager module 
  - BLE_DataThroughput_Server/System/Modules/ble_timer.h                              This header defines the timer functions used by the BLE stack 
  - BLE_DataThroughput_Server/System/Modules/dbg_trace.h                              Header for dbg_trace.c 
  - BLE_DataThroughput_Server/System/Modules/general_config.h                         This file contains definitions that can be changed to configure some modules of the STM32 firmware application.
  - BLE_DataThroughput_Server/System/Modules/otp.h                                    Header file for One Time Programmable (OTP) area 
  - BLE_DataThroughput_Server/System/Modules/scm.h                                    Header for scm.c module 
  - BLE_DataThroughput_Server/System/Modules/stm_list.h                               Header file for linked list library. 
  - BLE_DataThroughput_Server/System/Modules/utilities_common.h                       Common file to utilities 
  - BLE_DataThroughput_Server/System/Modules/baes/baes.h                              This file contains the interface of the basic AES software module. 
  - BLE_DataThroughput_Server/System/Modules/baes/baes_global.h                       This file contains the internal definitions of the AES software module.
  - BLE_DataThroughput_Server/System/Modules/Flash/flash_driver.h                     Header for flash_driver.c module 
  - BLE_DataThroughput_Server/System/Modules/Flash/flash_manager.h                    Header for flash_manager.c module 
  - BLE_DataThroughput_Server/System/Modules/Flash/rf_timing_synchro.h                Header for rf_timing_synchro.c module 
  - BLE_DataThroughput_Server/System/Modules/Flash/simple_nvm_arbiter.h               Header for simple_nvm_arbiter.c module 
  - BLE_DataThroughput_Server/System/Modules/Flash/simple_nvm_arbiter_common.h        Common header of simple_nvm_arbiter.c module 
  - BLE_DataThroughput_Server/System/Modules/MemoryManager/advanced_memory_manager.h  Header for advance_memory_manager.c module 
  - BLE_DataThroughput_Server/System/Modules/MemoryManager/stm32_mm.h                 Header for stm32_mm.c module 
  - BLE_DataThroughput_Server/System/Modules/Nvm/nvm.h                                This file contains the interface of the NVM manager. 
  - BLE_DataThroughput_Server/System/Modules/RTDebug/debug_signals.h                  Real Time Debug module System and Link Layer signal definition 
  - BLE_DataThroughput_Server/System/Modules/RTDebug/local_debug_tables.h             Real Time Debug module System and Link Layer signal  
  - BLE_DataThroughput_Server/System/Modules/RTDebug/RTDebug.h                        Real Time Debug module API declaration 
  - BLE_DataThroughput_Server/Core/Src/app_entry.c                                    Entry point of the application 
  - BLE_DataThroughput_Server/Core/Src/main.c                                         Main program body
  - BLE_DataThroughput_Server/Core/Src/stm32wbaxx_hal_msp.c                           This file provides code for the MSP Initialization and de-Initialization codes.
  - BLE_DataThroughput_Server/Core/Src/stm32wbaxx_it.c                                Interrupt Service Routines. 
  - BLE_DataThroughput_Server/Core/Src/system_stm32wbaxx.c                            CMSIS Cortex-M33 Device Peripheral Access Layer System Source File 
  - BLE_DataThroughput_Server/STM32_WPAN/App/app_ble.c                                BLE Application 
  - BLE_DataThroughput_Server/STM32_WPAN/App/dt_serv.c                                service1 definition. 
  - BLE_DataThroughput_Server/STM32_WPAN/App/dt_serv_app.c                            service1_app application definition. 
  - BLE_DataThroughput_Server/STM32_WPAN/Target/bleplat.c                             This file implements the platform functions for BLE stack library. 
  - BLE_DataThroughput_Server/STM32_WPAN/Target/bpka.c                                This file implements the BLE PKA module. 
  - BLE_DataThroughput_Server/STM32_WPAN/Target/host_stack_if.c                       Source file for the stack tasks 
  - BLE_DataThroughput_Server/STM32_WPAN/Target/linklayer_plat.c                      Source file for the linklayer plateform adaptation layer 
  - BLE_DataThroughput_Server/STM32_WPAN/Target/ll_sys_if.c                           Source file for initiating the system sequencer 
  - BLE_DataThroughput_Server/STM32_WPAN/Target/power_table.c                         This file contains supported power tables 
  - BLE_DataThroughput_Server/System/Config/Debug_GPIO/app_debug.c                    Real Time Debug module application side APIs 
  - BLE_DataThroughput_Server/System/Interfaces/hw_aes.c                              This file contains the AES driver for STM32WBA 
  - BLE_DataThroughput_Server/System/Interfaces/hw_otp.c                              This file contains the OTP driver. 
  - BLE_DataThroughput_Server/System/Interfaces/hw_pka.c                              This file contains the PKA driver for STM32WBA 
  - BLE_DataThroughput_Server/System/Interfaces/hw_rng.c                              This file contains the RNG driver for STM32WBA 
  - BLE_DataThroughput_Server/System/Interfaces/pka_p256.c                            This file is an optional part of the PKA driver for STM32WBA. It is dedicated to the P256 elliptic curve.
  - BLE_DataThroughput_Server/System/Interfaces/stm32_lpm_if.c                        Low layer function to enter/exit low power modes (stop, sleep) 
  - BLE_DataThroughput_Server/System/Interfaces/timer_if.c                            Configure RTC Alarm, Tick and Calendar manager 
  - BLE_DataThroughput_Server/System/Interfaces/usart_if.c                            Source file for interfacing the stm32_adv_trace to hardware 
  - BLE_DataThroughput_Server/System/Modules/adc_ctrl.c                               Header for ADC client manager module 
  - BLE_DataThroughput_Server/System/Modules/app_sys.c                                Application system for STM32WPAN Middleware. 
  - BLE_DataThroughput_Server/System/Modules/ble_timer.c                              This module implements the timer core functions 
  - BLE_DataThroughput_Server/System/Modules/otp.c                                    Source file for One Time Programmable (OTP) area 
  - BLE_DataThroughput_Server/System/Modules/scm.c                                    Functions for the System Clock Manager. 
  - BLE_DataThroughput_Server/System/Modules/stm_list.c                               TCircular Linked List Implementation. 
  - BLE_DataThroughput_Server/System/Modules/baes/baes_cmac.c                         This file contains the AES CMAC implementation. 
  - BLE_DataThroughput_Server/System/Modules/baes/baes_ecb.c                          This file contains the AES ECB functions implementation. 
  - BLE_DataThroughput_Server/System/Modules/Flash/flash_driver.c                     The Flash Driver module is the interface layer between Flash management modules and HAL Flash drivers
  - BLE_DataThroughput_Server/System/Modules/Flash/flash_manager.c                    The Flash Manager module provides an interface to write raw data from SRAM to FLASH
  - BLE_DataThroughput_Server/System/Modules/Flash/rf_timing_synchro.c                The RF Timing Synchronization module provides an interface to synchronize the flash processing versus the RF activity to make
sure the RF timing is not broken
  - BLE_DataThroughput_Server/System/Modules/Flash/simple_nvm_arbiter.c               The Simple NVM arbiter module provides an interface to write and/or restore data from SRAM to FLASH with use of NVMs.
  - BLE_DataThroughput_Server/System/Modules/MemoryManager/advanced_memory_manager.c  Memory Manager 
  - BLE_DataThroughput_Server/System/Modules/MemoryManager/stm32_mm.c                 Memory Manager
  - BLE_DataThroughput_Server/System/Modules/Nvm/nvm_emul.c                           This file implements the RAM version of the NVM manager for STM32WBX. It is made for test purpose.
  - BLE_DataThroughput_Server/System/Modules/RTDebug/RTDebug.c                        Real Time Debug module API definition 


### __Hardware and Software environment__

  - This example runs on STM32WBA52xx devices.
    Connect the Nucleo Board to your PC with a USB cable type A to mini-B to ST-LINK connector (USB_STLINK).


### __How to use it?__

In order to make the program work, you must do the following:

 - Open IAR toolchain 
 - Rebuild all files and flash the board with the executable file.
 - Two ways for using the application: 

__1. Use of two nucleo boards__ 

Two STM32WBA nucleo boards are used, one central/client (flashed with BLE_DataThroughput_Client) and one peripheral/server (flashed with BLE_DataThroughput_Server). 

The GATT server board support a Data transfer service with a transmission characteristic that supports notification.

The GATT client board support a Data transfer by writing without response to the GATT server board Reception characteristic.

The board flashed with BLE_DataThroughput_Server is defined as GAP peripheral.

Open a VT100 terminal on Central and Peripheral side (ST Link Com Port, @115200 bauds).

At reset application initialization is done.

 - The peripheral device starts advertising.
 - Push B1 on central: the central device scans and automatically connects to the peripheral (use of CFG_DEV_ID_DT_SERVER). 
 - After connection:
 - the client starts to search the data transfer service and characteristic.
 - the client enables the notification of the transmission characteristic.

On server side when connected:

 - B1 starts (blue LED is ON)/stops (blue LED is OFF) notification.
 - B2 sends L2CAP connection update - toggle 26.25 ms/11.25 ms
 - B3 PHY toggle

On server side when idle:
 - B2 clear database

On client side when connected:

 - B1 starts (blue LED is ON)/stops (blue LED is OFF) write without response.
 - B2 sends pairing request

On client side when idle:

 - B2 clear database

On client terminal receiving the current notification, the number of bytes per second is displayed.

On server terminal receiving the current write without response, the number of bytes per second is displayed.
  
In app_conf.h :

 - if #define CFG_TX_PHY    2 and #define CFG_RX_PHY    2, link is set to 2M at connection
 - if #define CFG_TX_PHY    1 and #define CFG_RX_PHY    1, link stays at 1M


__2. Use of one nucleo board and a smartphone__

 Install the ST BLE Toolbox application on the android device:
 
   - <a href="https://play.google.com/store/apps/details?id=com.st.dit.stbletoolbox"> ST BLE Toolbox Android</a>
   - <a href="https://apps.apple.com/us/app/st-ble-toolbox/id1531295550"> ST BLE Toolbox iOS</a>

One STM32WBA52 Nucleo board is used as GATT Server and GAP peripheral (flashed with BLE_DataThroughput_Server).

This board can be connected with a smartphone supporting ST BLE Toolbox application.

Start a scan and choose DT_XX (XX LSB byte of BD address) board to connect.

Same use of buttons on server side.
