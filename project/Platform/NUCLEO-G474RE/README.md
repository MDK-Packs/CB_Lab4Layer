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

Board: STMicroelectronics NUCLEO-G474RE
---------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32G474RETx
| RCC                     | High Speed Clock (HSI): RC oscillator
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HSE                     |  24 MHz
| HCLK                    | 170 MHz
| FCLK                    | 170 MHz
| APB1                    | 170 MHz
| APB2                    | 170 MHz
| To LPUART1              | 170 MHz

### GPIO Configuration and usage

| GPIO        | Signal / Label | GPIO Settings                                 | Usage
|:------------|:---------------|:----------------------------------------------|:-----
| PA2         | LPUART1_TX     | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (VCP_TX)
| PA3         | LPUART1_RX     | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (VCP_RX)
| PC7         | ARDUINO_IO_D9  | Input mode                                    | Arduino UNO R3 pin D9
| PB6         | ARDUINO_IO_D10 | Output Push Pull, Level=High, Speed=Very High | Arduino UNO R3 pin D10
| PC13        | vioBUTTON0     | not configured via CubeMX                     | Button USER
| PA5         | vioLED0        | not configured via CubeMX                     | User LED LD2

### NVIC Configuration

 - Priority Group = 4 bits for preemption priority 0 bits for subpriority

| NVIC Interrupt                          | Preempt Priority | Code Generation
|:----------------------------------------|:-----------------|:---------------
| Non maskable interrupt                  | 0                | Generate IRQ handler
| Hard fault interrupt                    | 0                | Generate IRQ handler
| Memory Management fault                 | 0                | Generate IRQ handler
| Prefetch fault, memory access fault     | 0                | Generate IRQ handler
| Undefined instruction or illegal state  | 0                | Generate IRQ handler
| System service call via SWI instruction | 0                | none
| Debug monitor                           | 0                | Generate IRQ handler
| Pendable request for system service     | 0                | none
| Time base: System tick timer            | 0                | none

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA                                             | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:------------------------------------------------|:----
| LPUART1      | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no                                              | ST-LINK Virtual COM port

**STDIO** is routed to ST-LINK Virtual COM port (LPUART1)

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
|              | 

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD2 GREEN (PA5)
