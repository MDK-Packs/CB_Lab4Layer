Watson MQTT Demo
================

This demo application connects to 
[Watson IoT](https://quickstart.internetofthings.ibmcloud.com/#/) 
through MQTT and publishes messages.

It requires a registered [device](https://www2.keil.com/iot/ibm) in the Watson IoT Platform.

The following describes the various components and the configuration settings.

Once the application is configured you can:
 - Build the application
 - Connect the debugger
 - Run the application and view messages in a debug printf or terminal window


Watson IoT Client
-----------------
The file `helloWorld.c` configures the connection to Watson IoT with these settings:
 - ORG_ID:      Organization ID
 - DEVICE_TYPE: Device Type
 - DEVICE_ID:   Device ID
 - TOKEN:       Authentication Token

Note: These settings need to be configured by the user!

The file `IoTFoundation.pem` provides the server certificate.

Note: The server certificate needs to be provided by the user
and needs to exist on the file system drive M0!


RTX5 Real-Time Operating System
-------------------------------
The [RTX5 RTOS](https://arm-software.github.io/CMSIS_5/RTOS2/html/rtx5_impl.html) 
implements the resource management. It is configured with the following settings:

- Global Dynamic Memory size: 24000 bytes
- Default Thread Stack size: 3072 bytes


Ethernet IoT Socket (MDK-Middleware Network)
--------------------------------------------
This implementation uses an IoT socket layer that connects to a 
[CMSIS-Driver Ethernet](https://arm-software.github.io/CMSIS_5/Driver/html/index.html).

The IoT Socket is implemented using 
[MDK-Middleware Network](https://www.keil.com/pack/doc/mw/Network/html/index.html).


Keil MCB4300 Target Board
-------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver ETH_MAC0** controlling the DP83848 Ethernet PHY (IC6):
 - ENET_TXD0:    P1_18
 - ENET_TXD1:    P1_20
 - ENET_TX_EN:   P0_1
 - ENET_REF_CLK: P1_19
 - ENET_RXD0:    P1_15
 - ENET_RXD1:    P0_0
 - ENET_RX_DV:   P1_16
 - ENET_MDIO:    P1_17
 - ENET_MDC:     PC_1

**CMSIS-Driver ETH_PHY0** routed to RJ45 connector (P6)

**CMSIS-Driver MCI0** routed to memory card socket (J39):
 - SD_CLK:   PC_0
 - SD_CMD:   PC_10
 - SD_DATA0: PC_4
 - SD_DATA1: PC_5
 - SD_DATA2: PC_6
 - SD_DATA3: PC_7
 - SD_CD:    PC_8

**STDOUT** routed to ITM
