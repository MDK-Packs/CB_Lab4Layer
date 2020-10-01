Watson MQTT Demo
================

This demo application connects to **Watson IoT** through MQTT and publishes messages.

It requires a [*registered device*](https://github.com/MDK-Packs/Documentation/blob/master/IBM_Watson_IoT/README.md).

The following describes the various components and the configuration settings.

Once the application is configured you can:
- Build the application.
- Connect the debugger.
- Run the application and view messages in a debug printf or terminal window.

Watson IoT Client
-----------------

The file `helloWorld.c` configures the connection to Watson IoT with these settings:
- `ORG_ID`: Organization ID
- `DEVICE_TYPE`: Device Type
- `DEVICE_ID`:  Device ID
- `TOKEN`: Authentication Token

*Note*: These settings need to be configured by the user!

The file `IoTFoundation.pem` provides the server certificate.

*Note*: The server certificate needs to be provided by the user and needs to exist on the file system drive M0!

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

Socket: Ethernet IoT Socket (MDK-Middleware Network)
----------------------------------------------------
This implementation uses an [IoT socket](https://mdk-packs.github.io/IoT_Socket/html/index.html) layer that connects to a 
[CMSIS-Driver Ethernet](https://arm-software.github.io/CMSIS_5/Driver/html/index.html).

The IoT Socket is implemented using 
[MDK-Middleware Network](https://www.keil.com/pack/doc/mw/Network/html/index.html).

Board: Keil MCB4300
-------------------

This board layer is composed of components selected using the RTE (Run Time Environment) 
and configured by adapting:
- `startup_LPC43xx.s` (Device:Startup)
- `system_LPC43xx.c` (Device:Startup)
- `RTE_Device.h` (Device:Startup)

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | LPC4357:Cortex-M4
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| PLL0USB                 | 480 MHz
| PLL1                    | 180 MHz
| CPU                     | 180 MHz
| IDIV A                  |  60 MHz
| IDIV B                  |  25 MHz
| IDIV C                  |  12 MHz
| IDIV D                  |  12 MHz
| IDIV E                  | 5.3 MHz

**Note:** configured in system file

### GPIO Configuration and usage

| Peripheral              | Signal          | Pin   | Usage
|:------------------------|:----------------|:------|:-----
| ENET RMII               | ENET_TXD0       | P1_18 | DP83848 pin TXD_0
| ENET RMII               | ENET_TXD1       | P1_20 | DP83848 pin TXD_1
| ENET RMII               | ENET_TX_EN      | P0_1  | DP83848 pin TX_EN
| ENET RMII               | ENET_REF_CLK    | P1_19 | DP83848 pin X1
| ENET RMII               | ENET_RXD0       | P1_15 | DP83848 pin RXD_0
| ENET RMII               | ENET_RXD1       | P0_0  | DP83848 pin RXD_1
| ENET RMII               | ENET_RX_DV      | P1_16 | DP83848 pin RX_DV
| ENET MIIM               | ENET_MDIO       | P1_17 | DP83848 pin MDIO
| ENET MIIM               | ENET_MDC        | PC_1  | DP83848 pin MDC
| SD/MMC                  | SD_CLK          | PC_0  | SD Card socket pin CLK
| SD/MMC                  | SD_CMD          | PC_10 | SD Card socket pin CMD
| SD/MMC                  | SD_DATA0        | PC_4  | SD Card socket pin D0
| SD/MMC                  | SD_DATA1        | PC_5  | SD Card socket pin D1
| SD/MMC                  | SD_DATA2        | PC_6  | SD Card socket pin D2
| SD/MMC                  | SD_DATA3        | PC_7  | SD Card socket pin D3
| SD/MMC                  | SD_CD           | PC_8  | SD Card socket pin CD

**Note:** configured in `RTE_Device.h`

### NVIC Configuration

| NVIC Interrupt      | Priority
|:--------------------|:--------
| Ethernet            | 4
| SDIO                | 4

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| ETH_MAC0     | Ethernet (ENET)
| ETH_PHY0     | DP83848 (external)
| MCI0         | SD/MMC

**STDOUT** is routed to ITM
