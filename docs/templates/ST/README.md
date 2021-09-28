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

Board: 'specific board name'
--------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | device name
| RCC                     | High Speed Clock (HSI): RC oscillator
| Heap                    | 64 kB (configured in appropriate file)
| Stack (MSP)             | 1 kB (configured in appropriate file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| LSE                     |   8 MHz

### GPIO Configuration and usage

| GPIO        | Signal / Label | GPIO Settings                                 | Usage
|:------------|:---------------|:----------------------------------------------|:-----
| PB6         | USART1_TX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)

### NVIC Configuration

 - Priority Group = 4 bits for preemption priority 0 bits for subpriority

| NVIC Interrupt                          | Preempt Priority | Code Generation
|:----------------------------------------|:-----------------|:---------------
| Non maskable interrupt                  | 0                | Generate IRQ handler

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA                                              | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:---------------------------------------- --------|:----
| SPI1         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | SPI1_RX = DMA1 Stream 2, SPI1_TX = DMA1 Stream 3 | Arduino UNO R3 connector (CN7)
                                            | Arduino UNO R3 connector (CN10)

**STDIO** is routed to ST-LINK Virtual COM port

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| USART3       | LPUART3

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | User Button SW8 (WAKEUP)
