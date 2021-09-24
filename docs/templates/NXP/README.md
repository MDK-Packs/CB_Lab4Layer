Platform project
================

The **Platform** project configures the hardware of the evaluation board
and is a CMSIS-RTOS2 based software template that can be further expanded.

RTOS: Keil RTX5 Real-Time Operating System
------------------------------------------

The real-time operating system [Keil RTX5](https://arm-software.github.io/CMSIS_5/RTOS2/html/rtx5_impl.html) implements the resource management. 

It is configured with the following settings:

- [Global Dynamic Memory size](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#systemConfig): 24000 bytes
- [Default Thread Stack size](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#threadConfig): 3072 bytes
- [Event Recorder Configuration](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#evtrecConfig)
  - [Global Initialization](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html#evtrecConfigGlobIni): 1
    - Start Recording: 1

Refer to [Configure RTX v5](https://arm-software.github.io/CMSIS_5/RTOS2/html/config_rtx5.html) for a detailed description of all configuration options.

Board: 'specific board name'
--------------------------

The tables below list the device configuration for this board. The board layer for the NXP 'specific board name' is using the software component `::Board Support: SDK Project Template: project_template (Variant: 'specific board name')` from `NXP appropriate` pack.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.

The example project can be re-configured to work on custom hardware. Refer to ["Configuring Example Projects with MCUXpresso Config Tools"](https://github.com/MDK-Packs/Documentation/tree/master/Using_MCUXpresso) for information.

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

| Functional Group       | Pin | Peripheral | Signal      | Identifier         | Pin Settings                                        | Usage
|:-----------------------|:----|:-----------|:------------|:-------------------|:----------------------------------------------------|:-----
| BOARD_InitDEBUG_UART   | K14 | LPUART1    | TX          | UART1_TXD          | default                                             | UART1 TX for debug console (GPIO_AD_B0_12)

### NVIC Configuration

| NVIC Interrupt      | Priority
|:--------------------|:--------
| ENET                | 8

**STDIO** is routed to debug console through Virtual COM port (DAP-Link, peripheral = LPUART1, baudrate = 115200)

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| USART3       | LPUART3

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | User Button SW8 (WAKEUP)
