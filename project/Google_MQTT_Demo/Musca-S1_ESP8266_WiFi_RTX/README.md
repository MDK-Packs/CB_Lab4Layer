Google MQTT Demo
================

This demo application connects to **Google Cloud IoT** through MQTT and publishes messages.

It requires a [*registered device*](https://github.com/MDK-Packs/Documentation/blob/master/Google_Cloud/README.md).

The following describes the various components and the configuration settings.

Once the application is configured you can:
- Build the application.
- Connect the debugger.
- Run the application and view messages in a debug printf or terminal window.

Google IoT Client
-----------------
The file `demo.c` configures the connection to Google IoT with these settings:
- `PROJECT_ID`: Project ID
- `CLOUD_REGION`: Cloud region
- `REGISTRY_ID`: Registry ID
- `DEVICE_ID`: Device ID

*Note*: These settings need to be configured by the user!

The file `pkey.h` configures the device private key.

*Note*: The device private key needs to be provided by the user!

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

Module: ESP8266 WiFi shield
---------------------------

The WiFi shield based on [ESP8266 SoC](https://www.espressif.com/en/products/socs/esp8266) is connected via an Arduino
header using a USART interface. It exposes a
[CMSIS-Driver WiFi](https://arm-software.github.io/CMSIS_5/Driver/html/group__wifi__interface__gr.html).

This module was tested with the ESP8266 AT command set firmware revision **1.6.2**. Refer to 
[Espressif Product Support Download](https://www.espressif.com/en/support/download/all) for more information.

Board: Arm Musca-S1
-------------------

The tables below list the device configuration for this board.

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | Musca-S1:CM33-0
| Heap                    | 64 kB (configured in linker scatter file)
| Stack (MSP)             | 1 kB (configured in linker scatter file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| System                  | 50 MHz

### GPIO Configuration and usage

| Peripheral              | Signal          | Pin   | Usage
|:------------------------|:----------------|:------|:-----
| UART0                   | USART0_RX       | PA0   | Arduino UNO R3 pin D0 (RX)
| UART0                   | USART0_TX       | PA1   | Arduino UNO R3 pin D1 (TX)
| UART1                   | USART1_RX       | PA16  | DAPLink Virtual COM port (UART1_RX_HW)
| UART1                   | USART1_TX       | PA17  | DAPLink Virtual COM port (UART1_TX_HW)

**Note:** configured in `RTE_Device.h`

### NVIC Configuration

| NVIC Interrupt      | Priority
|:--------------------|:--------
| UART0               | 4

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| USART0       | UART0

**STDOUT** is routed to Virtual COM port (DAPLink, baudrate = 115200)
