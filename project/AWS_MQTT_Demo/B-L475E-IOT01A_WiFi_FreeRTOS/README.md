AWS MQTT Demo
=============

This demo application connects to **AWS IoT** through MQTT, subscribes to topics and publishes messages.

It requires an active and [*properly configured thing*](https://github.com/MDK-Packs/Documentation/blob/master/AWS_Thing/README.md).

You can use the MQTT client in the **AWS IoT console** to watch the MQTT message exchange.

The following describes the various components and the configuration settings.

Once the application is configured you can:
- Build the application.
- Connect the debugger.
- Run the application and view messages in a debug printf or terminal window.

AWS IoT Client
--------------

The file `iot_config.h` configures the connection to AWS IoT with these settings:
- `IOT_DEMO_SERVER`: Remote Host
- `IOT_DEMO_ROOT_CA`: Trusted Server Root Certificate
- `IOT_DEMO_CLIENT_CERT`: Client Certificate
- `IOT_DEMO_PRIVATE_KEY`: Client Private Key
- `IOT_DEMO_IDENTIFIER`: Thing Identifier

*Note*: These settings require user configuration!

RTOS: FreeRTOS Real-Time Operating System
-----------------------------------------
The real-time operating system [FreeRTOS](https://github.com/ARM-software/CMSIS-FreeRTOS) implements the resource management.

It is configured with the following settings:

- Minimal stack size \[words]: 768
- Total heap size \[bytes]: 24000
- Preemption interrupt priority: 128
- Event Recorder configuration
  - Initialize Event Recorder: 1

Refer to [Configure CMSIS-FreeRTOS](https://arm-software.github.io/CMSIS-FreeRTOS/General/html/cre_freertos_proj.html#cmsis_freertos_config) for a detailed description of all configuration options.

Socket: WiFi IoT Socket
-----------------------
This implementation uses an [IoT socket](https://mdk-packs.github.io/IoT_Socket/html/index.html) layer that connects to a 
[CMSIS-Driver WiFi](https://arm-software.github.io/CMSIS_5/Driver/html/index.html).

The file `socket_startup.c` configures the WiFi connection with these settings:
 - SSID:          network identifier
 - PASSWORD:      network password
 - SECURITY_TYPE: network security

Note: These settings need to be configured by the user!

Board: STMicroelectronics B-L475E-IOT01A
----------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32L475VGtx
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 2 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HCLK                    | 80 MHz
| FCLK                    | 80 MHz
| APB1                    | 80 MHz
| APB2                    | 80 MHz
| To USART1               | 80 MHz
| To RNG                  | 48 MHz

### GPIO Configuration and usage

| GPIO | Signal / Label    | GPIO Settings                                 | Usage
|:-----|:------------------|:----------------------------------------------|:-----
| PB6  | USART1_TX         | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (ST-LINK-UART1_TX)
| PB7  | USART1_RX         | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (ST-LINK-UART1_RX)
| PC10 | SPI3_SCK          | Alternate Function, Speed=Very High           | ISM43362 pin SCK
| PC11 | SPI3_MISO         | Alternate Function, Speed=Very High           | ISM43362 pin MISO
| PC12 | SPI3_MOSI         | Alternate Function, Speed=Very High           | ISM43362 pin MOSI
| PB13 | ISM43362_WAKEUP   | Output Push Pull, Level=Low, Speed=Low        | ISM43362 pin WKUP
| PE0  | ISM43362_SPI3_NSS | Output Push Pull, Level=Low, Speed=Low        | ISM43362 pin SSN
| PE1  | ISM43362_DATARDY  | External Interrupt with Rising edge trigger   | ISM43362 pin DATARDY
| PE8  | ISM43362_RESET    | Output Push Pull, Level=Low, Speed=Low        | ISM43362 pin RSTN

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
| EXTI line 1 interrupt                   | 15               | Generate IRQ handler, Call HAL handler
| SPI3 global interrupt                   | 8                | Generate IRQ handler, Call HAL handler
| DMA2 channel1 global interrupt          | 7                | Generate IRQ handler, Call HAL handler
| DMA2 channel2 global interrupt          | 7                | Generate IRQ handler, Call HAL handler

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA                                                | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:---------------------------------------------------|:----
| SPI3         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | SPI3_RX = DMA2 Channel 1, SPI3_TX = DMA2 Channel 2 | ISM43362
| USART1       | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no                                                 | ST-LINK Virtual COM port

**STDOUT** is routed to ITM

### Security Peripherals Configuration

| Peripheral   | Mode / Settings                                                                        | IRQ | DMA                                                  | Note
|:-------------|:---------------------------------------------------------------------------------------|:----|:-----------------------------------------------------|:----
| RNG          | Activated                                                                              | no  |                                                      | Random Number Generator

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| WiFi0        | SPI3 (ISM43362)
