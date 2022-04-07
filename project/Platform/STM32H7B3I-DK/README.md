Platform project
================

The **Platform** project configures the hardware of the evaluation board
and is a CMSIS-RTOS2 based software template that can be further expanded.

RTOS: Keil RTX5 Real-Time Operating System
------------------------------------------

The real-time operating system [Keil RTX5](https://arm-software.github.io/CMSIS_5/RTOS2/html/rtx5_impl.html) implements the resource management. 

It is configured with the following settings:

- [Global Dynamic Memory size](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#systemConfig): 32768 bytes
- [Default Thread Stack size](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#threadConfig): 3072 bytes
- [Event Recorder Configuration](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#evtrecConfig)
  - [Global Initialization](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#evtrecConfigGlobIni): 1
    - Start Recording: 1

Refer to [Configure RTX v5](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html) for a detailed description of all configuration options.

Board: STMicroelectronics STM32H7B3I-DK
---------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.
**STM32CubeMX** default settings for STM32H7B3I-DK are taken as starting point for board configuration.
To check all settings open STCubeGenerated.ioc in **STM32CubeMX** or click on play button in RTE: Device: STM32Cube Framework (API): STM32CubeMX component.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32H7B3LIH6Q
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

All following settings are changes to default configuration:

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| CPU (default)           | 280 MHz

### Pinout & Configuration - Connectivity

| Peripheral   | Mode / Settings                                 | NVIC Settings | DMA Settings                                     | Note
|:-------------|:------------------------------------------------|:--------------|:-------------------------------------------------|:-------------------------------
| SDMMC1       | SD 4 bits Wide bus,                             | Enabled=yes   | no                                               | microSD Card holder
| SPI2         | Full-Duplex Master, Hardware NSS Signal=Disable | Enabled=yes   | SPI2_RX = DMA1 Stream 0, SPI2_TX = DMA1 Stream 1 | On-board WiFi Module (ISM43340)
| UART4        | Asynchronous, Hardware Flow Control=Disable     | Enabled=yes   | no                                               | Arduino UNO R3 connector (CN11)

**STDIO** is routed to ST-LINK Virtual COM port (UART1)

### Pinout & Configuration - System Core - GPIO

| GPIO        | Signal / Label | GPIO Settings                       | Usage
|:------------|:---------------|:------------------------------------|:-----------------------------------
| PH13        | UART4_TX       | Alternate Function, Speed=Very High | Arduino UNO R3 connector TX/D1 line
| PH14        | UART4_RX       | Alternate Function, Speed=Very High | Arduino UNO R3 connector RX/D0 line

### Pinout & Configuration - System Core - NVIC

| NVIC Interrupt                          | Preempt Priority | Code Generation
|:----------------------------------------|:-----------------|:--------------------------------------
| System service call via SWI instruction | 14               | none
| Pendable request for system service     | 15               | none
| Time base: System tick timer            | 15               | none
| DMA1 stream0 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| DMA1 stream1 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| SPI2 global                             | 8                | Generate IRQ handler, Call HAL handler
| SDMMC1 global interrupt                 | 8                | Call HAL handler
| USART4 global interrupt                 | 8                | Generate IRQ handler, Call HAL handler

### Project Manager - Advanced Settings

| Function Name     | Settings
|:------------------|:-----------------------------
| MX_SDMMC1_SD_Init | Do Not Generate Function Call
| MX_SPI2_Init      | Do Not Generate Function Call
| MX_UART4_Init     | Do Not Generate Function Call

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:---------------
| MCI0         | SDMMC1
| USART4       | UART4 (ARDUINO)
| WiFi0        | SPI2 (ISM43340)

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-------------------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD3 RED (PG11)
| vioLED1           | LD2 BLUE (PG2)
