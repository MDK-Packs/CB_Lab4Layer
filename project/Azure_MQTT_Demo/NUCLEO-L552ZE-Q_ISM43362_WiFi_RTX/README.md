Azure MQTT Demo
===============

This demo application connects to the **Azure IoT Hub** through MQTT, sends messages and checks for receive confirmation.

It requires a [*registered device*](https://github.com/MDK-Packs/Documentation/blob/master/Microsoft_Azure_IoT_Hub/README.md).

The following describes the various components and the configuration settings.

Once the application is configured you can:
- Build the application.
- Connect the debugger.
- Run the application and view messages in a debug printf or terminal window.

Azure IoT Client
----------------
The file `iothub_ll_telemetry_sample_mdk.c` configures the connection to the Azure IoT Hub with these settings:
- `connectionString`: Connection string - primary key

*Note*: This setting requires user configuration!

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

Module: ISM43362 WiFi shield
----------------------------

The [ISM43362 WiFi Module](https://www2.keil.com/iot/shields/ismart43362) is connected via an Arduino header using an SPI
interface. It exposes a [CMSIS-Driver WiFi](https://arm-software.github.io/CMSIS_5/Driver/html/group__wifi__interface__gr.html).

This module was tested with firmware revision **ISM43362_M3G_L44_SPI_C6.2.1.7**. Refer to 
[ISM43362 Firmware Update](https://arm-software.github.io/CMSIS-Driver/General/html/driver_WiFi.html#driver_ISM43362) for
more information.

Board: STMicroelectronics NUCLEO-L552ZE-Q
-----------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32L552ZETxQ
| ICACHE                  | Mode: 2-ways set associative cache
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HCLK                    | 110 MHz
| FCLK                    | 110 MHz
| APB1                    | 110 MHz
| APB2                    | 110 MHz
| To USART3               | 110 MHz

### GPIO Configuration and usage

| GPIO | Signal / Label   | GPIO Settings                                 | Usage
|:-----|:-----------------|:----------------------------------------------|:-----
| PD8  | USART3_TX        | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)
| PD9  | USART3_RX        | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D0 (RX)
| PA5  | SPI1_SCK         | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D13 (SCK)
| PA6  | SPI1_MISO        | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D12 (MISO)
| PA7  | SPI1_MOSI        | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D11 (MOSI)
| PD14 | ARDUINO_IO_D10   | Output Push Pull, Level=High, Speed=Very High | Arduino UNO R3 pin D10
| PD15 | ARDUINO_IO_D9    | Input mode                                    | Arduino UNO R3 pin D9
| PC13 | vioBUTTON0       | not configured via CubeMX                     | Button USER
| PA9  | vioLED0          | not configured via CubeMX                     | LD3 RED
| PC7  | vioLED1          | not configured via CubeMX                     | LD1 GREEN
| PB7  | vioLED2          | not configured via CubeMX                     | LD2 BLUE 

### NVIC Configuration

 - Priority Group = 3 bits for preemption priority 0 bits for subpriority

| NVIC Interrupt                          | Preempt Priority | Code Generation
|:----------------------------------------|:-----------------|:---------------
| Non maskable interrupt                  | 0                | Generate IRQ handler
| Hard fault interrupt                    | 0                | Generate IRQ handler
| Memory Management fault                 | 0                | Generate IRQ handler
| Prefetch fault, memory access fault     | 0                | Generate IRQ handler
| Undefined instruction or illegal state  | 0                | Generate IRQ handler
| System service call via SWI instruction | 6                | none
| Debug monitor                           | 0                | Generate IRQ handler
| Pendable request for system service     | 7                | none
| Time base: System tick timer            | 7                | none
| USART3 global / wake-up                 | 0                | Generate IRQ handler, Call HAL handler
| SPI1 global                             | 0                | Generate IRQ handler, Call HAL handler

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:----|:----
| SPI1         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | no  | Arduino UNO R3 connector (CN7)
| USART3       | Asynchronous, Hardware Flow Control=off, Do Not Generate Initialization Function Call                              | yes | no  | Arduino UNO R3 connector (CN10)

**STDOUT** is routed to ITM

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| SPI1         | SPI1
| USART3       | USART3

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD9 RED (PD3)
| vioLED1           | LD10 GREEN (PG12)
