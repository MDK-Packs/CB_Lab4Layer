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
 - Musca-S1 ESP8266:  [ESP8266 WiFi Module](https://www2.keil.com/iot/shields/wrl13287)
 - Musca-S1 WizFi360: [WizFi360 WiFi Module](https://www2.keil.com/iot/shields/wizfi360)

The module is connected via an Arduino connector using a USART or SPI interface.
It exposes a **CMSIS-Driver WiFi**.


Arm Musca-S1 Target Board
-------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART1** routed to Virtual COM port (DAPLink):
 - RX: UART1_RX
 - TX: UART1_TX

**CMSIS-Driver USART0** routed to Arduino UNO R3 connector (J15):
 - RX: D0 GPIO0 (PA0)
 - TX: D1 GPIO1 (PA7)

**STDOUT** routed to Virtual COM port (DAPLink, baudrate = 115200)
