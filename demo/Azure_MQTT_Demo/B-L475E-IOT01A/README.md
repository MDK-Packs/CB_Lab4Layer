Azure MQTT Demo
===============

This demo application connects to 
[Azure IoT Hub](https://docs.microsoft.com/en-us/azure/iot-hub/) 
through MQTT, sends messages and checks for receive confirmation.

It requires a registered [device](https://www2.keil.com/iot/microsoft) in the Azure IoT hub.

The following describes the various components and the configuration settings.

Once the application is configured you can:
 - Build the application
 - Connect the debugger
 - Run the application and view messages in a debug printf or terminal window


Azure IoT Client
----------------
The file `iothub_ll_telemetry_sample_mdk.c` configures the connection to 
Azure IoT Hub with these settings:
 - connectionString: Connection string - primary key

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
