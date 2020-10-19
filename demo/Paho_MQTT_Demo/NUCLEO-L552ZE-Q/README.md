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
 - NUCLEO-L552ZE-Q ESP8266:  [ESP8266 WiFi Module](https://www2.keil.com/iot/shields/wrl13287)
 - NUCLEO-L552ZE-Q WizFi360: [WizFi360 WiFi Module](https://www2.keil.com/iot/shields/wizfi360)
 - NUCLEO-L552ZE-Q ISM43362: [ISM43362 WiFi Module](https://www2.keil.com/iot/shields/ismart43362)

The module is connected via an Arduino connector using a USART or SPI interface.
It exposes a **CMSIS-Driver WiFi**.


STMicroelectronics NUCLEO-L552ZE-Q Target Board
-----------------------------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART3** routed to Arduino UNO R3 connector (CN10):
 - RX: D0 USART_A_RX (PD9)
 - TX: D1 USART_A_TX (PD8)

**CMSIS-Driver SPI1** routed to Arduino UNO R3 connector (CN7):
 - SCK:  D13 SPI_A_SCK (PA5)
 - MISO: D12 SPI_A_MISO (PA6)
 - MOSI: D11 SPI_A_MOSI (PA7)

**GPIO** pins routed to Arduino UNO R3 connector (CN7):
 - output: D10 SPI_A_CS (PD14)
 - input:  D9 TIM_B_PWM2 (PD15)

**STDOUT** routed to ITM

The board configuration can be modified using 
[STM32CubeMX](https://www.keil.com/pack/doc/STM32Cube/html/index.html) 
and is stored in the file `STCubeGenerated.ioc`.
