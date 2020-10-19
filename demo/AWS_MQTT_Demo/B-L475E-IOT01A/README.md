AWS MQTT Demo
=============

This demo application connects to [AWS IoT](https://aws.amazon.com/iot/) 
through MQTT, subscribes to topics and publishes messages.

It requires an active and properly configured [thing](https://www2.keil.com/iot/aws).

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
 - IOT_DEMO_PRIVATE_KEY: Client Private Key
 - IOT_DEMO_IDENTIFIER:  Thing Identifier

Note: These settings need to be configured by the user!


Real-Time Operating System
--------------------------
This project contains targets for different RTOS. Select the desired target:
 - B-L475E-IOT01A RTX:      uses CMSIS:RTOS2:Keil RTX5
 - B-L475E-IOT01A FreeRTOS: uses CMSIS:RTOS2:FreeRTOS

The [RTOS](https://arm-software.github.io/CMSIS_5/RTOS2/html/index.html) 
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


STMicroelectronics B-L475E-IOT01A Target Board
----------------------------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver WiFi0** routed to Inventek system ISM43362-M3G-L44 module:
 - SCK:  INTERNAL-SPI3_SCK (PC10)
 - MISO: INTERNAL-SPI3_MISO (PC11)
 - MOSI: INTERNAL-SPI3_MOSI (PC12)
 - GPIO: ISM43362-SPI3_CSN (PE0)
 - GPIO: ISM43362-WAKEUP (PB13)
 - GPIO: ISM43362-RST (PE8)
 - GPIO: ISM43362-DRDY_EXTI1 (PE1)

**STDOUT** routed to ITM

The board configuration can be modified using 
[STM32CubeMX](https://www.keil.com/pack/doc/STM32Cube/html/index.html) 
and is stored in the file `STCubeGenerated.ioc`.
