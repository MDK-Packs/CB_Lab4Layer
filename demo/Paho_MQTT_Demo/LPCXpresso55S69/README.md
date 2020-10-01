Paho MQTT Demo
==============

This demo application connects to [Eclipse Paho](https://www.eclipse.org/paho/) 
through MQTT, subscribes to topics and publishes messages.

The following describes the various components and the configuration settings.

Once the application is configured you can:
 - Build the application
 - Connect the debugger
 - Run the application and view messages in a debug printf or terminal window


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
 - LPCXpresso55S69 ESP8266:  [ESP8266 WiFi Module](https://www2.keil.com/iot/shields/wrl13287)
 - LPCXpresso55S69 WizFi360: [WizFi360 WiFi Module](https://www2.keil.com/iot/shields/wizfi360)

The module is connected via an Arduino connector using a USART or SPI interface.
It exposes a **CMSIS-Driver WiFi**.


NXP LPCXpresso55S69 Target Board
--------------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART2** routed to Arduino UNO R3 connector (P18):
 - RX: D0 PLU_OUT6/GPIO/FC2_USART_RXD_ARD
 - TX: D1 FC2_USART_TXD_ARD

**STDOUT** routed to Virtual COM port (DAP-Link, baudrate = 115200)

The board configuration can be modified using [MCUxpresso](https://www.keil.com/nxp)
and is stored in the file `LPCXpresso55S69.mex`.
