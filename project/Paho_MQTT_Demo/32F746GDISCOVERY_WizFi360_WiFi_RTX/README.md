Paho MQTT Demo
==============

This demo application connects to **Eclipse Paho** through MQTT, subscribes to topics and publishes messages.

The following describes the various components and the configuration settings.

Once the application is configured you can:
- Build the application.
- Connect the debugger.
- Run the application and view messages in a debug printf or terminal window.

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

Socket: WiFi IoT Socket
-----------------------
This implementation uses an [IoT socket](https://mdk-packs.github.io/IoT_Socket/html/index.html) layer that connects to a 
[CMSIS-Driver WiFi](https://arm-software.github.io/CMSIS_5/Driver/html/index.html).

The file `socket_startup.c` configures the WiFi connection with these settings:
 - SSID:          network identifier
 - PASSWORD:      network password
 - SECURITY_TYPE: network security

Note: These settings need to be configured by the user!

Module: WizFi360 WiFi shield
----------------------------

The [WizFi360 WiFi Shield](https://www2.keil.com/iot/shields/wizfi360) is connected via an Arduino header using a USART
interface. It exposes a [CMSIS-Driver WiFi](https://arm-software.github.io/CMSIS_5/Driver/html/group__wifi__interface__gr.html).

This module was tested with the AT command set firmware revision **1.1.0.9**. Refer to 
[WizFi360 Firmware Update Guide](http://wizwiki.net/wiki/doku.php?id=products:wizfi360:wizfi360ds:start#firmware_update_guide)
for more information.

Board: STMicroelectronics 32F746GDISCOVERY
------------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32F746NGHx
| RCC                     | High Speed Clock (HSE): Crystal/Ceramic Resonator
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HSE                     |  25 MHz
| HCLK                    | 216 MHz
| FCLK                    | 216 MHz
| APB1                    |  54 MHz
| APB2                    | 108 MHz
| To USART6               | 108 MHz

### GPIO Configuration and usage

| GPIO        | Signal / Label | GPIO Settings                                 | Usage
|:------------|:---------------|:----------------------------------------------|:-----
| PC6         | USART6_TX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)
| PC7         | USART6_RX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D0 (RX)
| PH0/OSC_IN  | RCC_OSC_IN     |                                               | External Oscillator (HSE)
| PH1/OSC_OUT | RCC_OSC_OUT    |                                               | External Oscillator (HSE)

### NVIC Configuration

 - Priority Group = 4 bits for preemption priority 0 bits for subpriority

| NVIC Interrupt                          | Preempt Priority | Code Generation
|:----------------------------------------|:-----------------|:---------------
| Non maskable interrupt                  | 0                | Generate IRQ handler
| Hard fault interrupt                    | 0                | Generate IRQ handler
| Memory Management fault                 | 0                | Generate IRQ handler
| Prefetch fault, memory access fault     | 0                | Generate IRQ handler
| Undefined instruction or illegal state  | 0                | Generate IRQ handler
| System service call via SWI instruction | 14               | none
| Debug monitor                           | 0                | Generate IRQ handler
| Pendable request for system service     | 15               | none
| Time base: System tick timer            | 15               | none
| USART6 global interrupt                 | 0                | none

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                        | IRQ | DMA | Note
|:-------------|:---------------------------------------------------------------------------------------|:----|:----|:----
| USART6       | Asynchronous, Hardware Flow Control=off, Do Not Generate Initialization Function Call  | yes | no  | Arduino UNO R3 connector (CN4)

**STDOUT** is routed to ITM

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| USART6       | USART6
