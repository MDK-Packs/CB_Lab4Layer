AWS MQTT Demo
=============

This demo application connects to [AWS IoT](https://aws.amazon.com/iot/) 
through MQTT, subscribes to topics and publishes messages.

It requires an active and properly configured [thing](https://www2.keil.com/iot/aws)
with Client Private Key stored in persistent storage in the secure enclave
(see project aws_key_provisioning).

You can use the AWS IoT MQTT client in the AWS IoT console to watch the 
MQTT messages sent and received by AWS IoT.

The following describes the various components and the configuration settings.

Once the application is configured you can:
 - Build the application
 - Connect the debugger
 - Run the application and view messages in a debug printf or terminal window


AWS IoT Client
--------------
The file `iot_config.h` configures the connection to AWS IoT with these settings:
 - IOT_DEMO_SERVER:      Remote Host
 - IOT_DEMO_ROOT_CA:     Trusted Server Root Certificate
 - IOT_DEMO_CLIENT_CERT: Client Certificate
 - IOT_DEMO_PRIVATE_KEY: Leave empty (Client Private Key is in the secure enclave)
 - IOT_DEMO_IDENTIFIER:  Thing Identifier

Note: These settings need to be configured by the user!


RTX5 Real-Time Operating System
-------------------------------
The [RTX5 RTOS](https://arm-software.github.io/CMSIS_5/RTOS2/html/rtx5_impl.html) 
implements the resource management. It is configured with the following settings:

- Global Dynamic Memory size: 24000 bytes
- Default Thread Stack size: 3072 bytes


WiFi IoT Socket
---------------
This implementation uses an IoT socket layer that connects to a 
[CMSIS-Driver WiFi](https://arm-software.github.io/CMSIS_5/Driver/html/index.html).

The file `socket_startup.c` configures the WiFi connection with these settings:
 - SSID:          network identifier
 - PASSWORD:      network password
 - SECURITY_TYPE: network security

Note: These settings need to be configured by the user!


WiFi Module
-----------
This project contains targets for different WiFi shields. Select the right target for your hardware:
 - STM32L562E-DK ESP8266:  [ESP8266 WiFi Module](https://www2.keil.com/iot/shields/wrl13287)
 - STM32L562E-DK WizFi360: [WizFi360 WiFi Module](https://www2.keil.com/iot/shields/wizfi360)
 - STM32L562E-DK ISM43362: [ISM43362 WiFi Module](https://www2.keil.com/iot/shields/ismart43362)

The module is connected via an Arduino connector using a USART or SPI interface.
It exposes a **CMSIS-Driver WiFi**.


STMicroelectronics STM32L562E-DK Target Board
---------------------------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART6** routed to Arduino UNO R3 connector (CN12):
 - RX: D0 LPUART1_RX (PB10)
 - TX: D1 LPUART1_TX (PB11)

**CMSIS-Driver SPI3** routed to Arduino UNO R3 connector (CN11):
 - SCK:  D13 SPI3_SCK (PG9)
 - MISO: D12 SPI3_MISO (PB4)
 - MOSI: D11 SPI3_MOSI (PB5)

**GPIO** pins routed to Arduino UNO R3 connector (CN11):
 - output: D10 SPI_CSn (PE0)
 - input:  D9 TIM4_CH4 (PB9)

**STDOUT** routed to ITM

The board configuration can be modified using 
[STM32CubeMX](https://www.keil.com/pack/doc/STM32Cube/html/index.html) 
and is stored in the file `STCubeGenerated.ioc`.
