## __BLE_p2pClient Application Description__

Demonstrate STM32WBA acting as BLE central and GATT client.

p2pClient application scans and connects to p2pServer device.

Once connected, p2pClient can write a message to the p2pServer and receive notification from it.

### __Keywords__

Connectivity, BLE, BLE protocol

### __Directory contents__

  - BLE_p2pClient/Core/Inc/app_common.h                                             App Common application configuration file for STM32WPAN Middleware
  - BLE_p2pClient/Core/Inc/app_conf.h                                               Application configuration file for STM32WPAN Middleware
  - BLE_p2pClient/Core/Inc/app_entry.h                                              Interface to the application 
  - BLE_p2pClient/Core/Inc/main.h                                                   Header for main.c file. This file contains the common defines of the application.
  - BLE_p2pClient/Core/Inc/stm32wbaxx_hal_conf.h                                    HAL configuration file
  - BLE_p2pClient/Core/Inc/stm32wbaxx_it.h                                          This file contains the headers of the interrupt handlers
  - BLE_p2pClient/Core/Inc/stm32wbaxx_nucleo_conf.h                                 STM32WBAXX nucleo board configuration file. This file should be copied to the application folder and renamed to stm32wbaxx_nucleo_conf.h
  - BLE_p2pClient/Core/Inc/utilities_conf.h                                         Header for configuration file for STM32 Utilities
  - BLE_p2pClient/STM32_WPAN/App/app_ble.h                                          Header for ble application 
  - BLE_p2pClient/STM32_WPAN/App/ble_conf.h                                         Configuration file for BLE Middleware
  - BLE_p2pClient/STM32_WPAN/App/ble_dbg_conf.h                                     Debug configuration file for BLE Middleware
  - BLE_p2pClient/STM32_WPAN/App/gatt_client_app.h                                  Header for gatt_client_app.c module 
  - BLE_p2pClient/STM32_WPAN/Target/bpka.h                                          This file contains the interface of the BLE PKA module
  - BLE_p2pClient/STM32_WPAN/Target/host_stack_if.h                                 This file contains the interface for the stack tasks 
  - BLE_p2pClient/STM32_WPAN/Target/ll_sys_if.h                                     Header file for ll_sys_if.c
  - BLE_p2pClient/System/Config/Debug_GPIO/app_debug.h                              Real Time Debug module application APIs and signal table 
  - BLE_p2pClient/System/Config/Debug_GPIO/app_debug_signal_def.h                   Real Time Debug module application signal definition 
  - BLE_p2pClient/System/Config/Debug_GPIO/debug_config.h                           Real Time Debug module general configuration file 
  - BLE_p2pClient/System/Config/Flash/simple_nvm_arbiter_conf.h                     Configuration header for simple_nvm_arbiter.c module 
  - BLE_p2pClient/System/Config/LowPower/app_sys.h                                  Header for app_sys.c 
  - BLE_p2pClient/System/Interfaces/hw.h                                            This file contains the interface of STM32 HW drivers
  - BLE_p2pClient/System/Interfaces/hw_if.h                                         Hardware Interface 
  - BLE_p2pClient/System/Interfaces/stm32_lpm_if.h                                  Header for stm32_lpm_if.c module (device specific LP management) 
  - BLE_p2pClient/System/Interfaces/timer_if.h                                      configuration of the timer_if.c instances 
  - BLE_p2pClient/System/Interfaces/usart_if.h                                      Header file for stm32_adv_trace interface file 
  - BLE_p2pClient/System/Modules/adc_ctrl.h                                         Header for ADC client manager module 
  - BLE_p2pClient/System/Modules/ble_timer.h                                        This header defines the timer functions used by the BLE stack 
  - BLE_p2pClient/System/Modules/dbg_trace.h                                        Header for dbg_trace.c 
  - BLE_p2pClient/System/Modules/general_config.h                                   This file contains definitions that can be changed to configure some modules of the STM32 firmware application
  - BLE_p2pClient/System/Modules/otp.h                                              Header file for One Time Programmable (OTP) area 
  - BLE_p2pClient/System/Modules/scm.h                                              Header for scm.c module 
  - BLE_p2pClient/System/Modules/stm_list.h                                         Header file for linked list library
  - BLE_p2pClient/System/Modules/utilities_common.h                                 Common file to utilities 
  - BLE_p2pClient/System/Modules/baes/baes.h                                        This file contains the interface of the basic AES software module 
  - BLE_p2pClient/System/Modules/baes/baes_global.h                                 This file contains the internal definitions of the AES software module
  - BLE_p2pClient/System/Modules/Flash/flash_driver.h                               Header for flash_driver.c module 
  - BLE_p2pClient/System/Modules/Flash/flash_manager.h                              Header for flash_manager.c module 
  - BLE_p2pClient/System/Modules/Flash/rf_timing_synchro.h                          Header for rf_timing_synchro.c module 
  - BLE_p2pClient/System/Modules/Flash/simple_nvm_arbiter.h                         Header for simple_nvm_arbiter.c module 
  - BLE_p2pClient/System/Modules/Flash/simple_nvm_arbiter_common.h                  Common header of simple_nvm_arbiter.c module 
  - BLE_p2pClient/System/Modules/MemoryManager/advanced_memory_manager.h            Header for advance_memory_manager.c module 
  - BLE_p2pClient/System/Modules/MemoryManager/stm32_mm.h                           Header for stm32_mm.c module 
  - BLE_p2pClient/System/Modules/Nvm/nvm.h                                          This file contains the interface of the NVM manager
  - BLE_p2pClient/System/Modules/RTDebug/debug_signals.h                            Real Time Debug module System and Link Layer signal definition 
  - BLE_p2pClient/System/Modules/RTDebug/local_debug_tables.h                       Real Time Debug module System and Link Layer signal 
  - BLE_p2pClient/System/Modules/RTDebug/RTDebug.h                                  Real Time Debug module API declaration 
  - BLE_p2pClient/Core/Src/app_entry.c                                              Entry point of the application 
  - BLE_p2pClient/Core/Src/main.c                                                   Main program body 
  - BLE_p2pClient/Core/Src/stm32wbaxx_hal_msp.c                                     This file provides code for the MSP Initialization and de-Initialization codes
  - BLE_p2pClient/Core/Src/stm32wbaxx_it.c                                          Interrupt Service Routines
  - BLE_p2pClient/Core/Src/system_stm32wbaxx.c                                      CMSIS Cortex-M33 Device Peripheral Access Layer System Source File 
  - BLE_p2pClient/STM32_WPAN/App/app_ble.c                                          BLE Application 
  - BLE_p2pClient/STM32_WPAN/App/gatt_client_app.c                                  GATT Client Application 
  - BLE_p2pClient/STM32_WPAN/Target/bleplat.c                                       This file implements the platform functions for BLE stack library
  - BLE_p2pClient/STM32_WPAN/Target/bpka.c                                          This file implements the BLE PKA module
  - BLE_p2pClient/STM32_WPAN/Target/host_stack_if.c                                 Source file for the stack tasks 
  - BLE_p2pClient/STM32_WPAN/Target/linklayer_plat.c                                Source file for the linklayer plateform adaptation layer 
  - BLE_p2pClient/STM32_WPAN/Target/ll_sys_if.c                                     Source file for initiating the system sequencer 
  - BLE_p2pClient/STM32_WPAN/Target/power_table.c                                   This file contains supported power tables 
  - BLE_p2pClient/System/Config/Debug_GPIO/app_debug.c                              Real Time Debug module application side APIs 
  - BLE_p2pClient/System/Interfaces/hw_aes.c                                        This file contains the AES driver for STM32WBA 
  - BLE_p2pClient/System/Interfaces/hw_otp.c                                        This file contains the OTP driver
  - BLE_p2pClient/System/Interfaces/hw_pka.c                                        This file contains the PKA driver for STM32WBA 
  - BLE_p2pClient/System/Interfaces/hw_rng.c                                        This file contains the RNG driver for STM32WBA 
  - BLE_p2pClient/System/Interfaces/pka_p256.c                                      This file is an optional part of the PKA driver for STM32WBA. It is dedicated to the P256 elliptic curve
  - BLE_p2pClient/System/Interfaces/stm32_lpm_if.c                                  Low layer function to enter/exit low power modes (stop, sleep) 
  - BLE_p2pClient/System/Interfaces/timer_if.c                                      Configure RTC Alarm, Tick and Calendar manager 
  - BLE_p2pClient/System/Interfaces/usart_if.c                                      Source file for interfacing the stm32_adv_trace to hardware 
  - BLE_p2pClient/System/Modules/adc_ctrl.c                                         Header for ADC client manager module 
  - BLE_p2pClient/System/Modules/app_sys.c                                          Application system for STM32WPAN Middleware
  - BLE_p2pClient/System/Modules/ble_timer.c                                        This module implements the timer core functions 
  - BLE_p2pClient/System/Modules/otp.c                                              Source file for One Time Programmable (OTP) area 
  - BLE_p2pClient/System/Modules/scm.c                                              Functions for the System Clock Manager
  - BLE_p2pClient/System/Modules/stm_list.c                                         TCircular Linked List Implementation
  - BLE_p2pClient/System/Modules/baes/baes_cmac.c                                   This file contains the AES CMAC implementation
  - BLE_p2pClient/System/Modules/baes/baes_ecb.c                                    This file contains the AES ECB functions implementation
  - BLE_p2pClient/System/Modules/Flash/flash_driver.c                               The Flash Driver module is the interface layer between Flash management modules and HAL Flash drivers
  - BLE_p2pClient/System/Modules/Flash/flash_manager.c                              The Flash Manager module provides an interface to write raw data from SRAM to FLASH
  - BLE_p2pClient/System/Modules/Flash/rf_timing_synchro.c                          The RF Timing Synchronization module provides an interface to synchronize the flash processing versus the RF activity to make sure the RF timing is not broken
  - BLE_p2pClient/System/Modules/Flash/simple_nvm_arbiter.c                         The Simple NVM arbiter module provides an interface to write and/or restore data from SRAM to FLASH with use of NVMs
  - BLE_p2pClient/System/Modules/MemoryManager/advanced_memory_manager.c            Memory Manager 
  - BLE_p2pClient/System/Modules/MemoryManager/stm32_mm.c                           Memory Manager 
  - BLE_p2pClient/System/Modules/Nvm/nvm_emul.c                                     This file implements the RAM version of the NVM manager for STM32WBX. It is made for test purpose
  - BLE_p2pClient/System/Modules/RTDebug/RTDebug.c                                  Real Time Debug module API definition 

### __Hardware and Software environment__

  - This application runs on STM32WBA52 Nucleo board.
  - Another STM32WBAxx Nucleo board is necessary to run p2pServer application.
    
### __How to use it?__

In order to make the program work, you must do the following :

 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example
 - Power up p2pClient devices next to a p2pServer device.
 - On p2pClient device, click on button B1 to launch a scan. A connection is initiated if a p2pServer device is detected.
 - Once the p2pClient application is connected to a p2pServer:
    - On p2pClient device, click on button B1, to write a message toward connected p2pServer device.
    - On p2pServer device, click on button B1 to send a notification message toward connected p2pClient device.
 