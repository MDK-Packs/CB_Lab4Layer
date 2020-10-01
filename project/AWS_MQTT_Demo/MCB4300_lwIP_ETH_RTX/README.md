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

Socket: Ethernet IoT Socket (lwIP)
----------------------------------
This implementation uses an [IoT socket](https://mdk-packs.github.io/IoT_Socket/html/index.html) layer that connects to a 
[CMSIS-Driver Ethernet](https://arm-software.github.io/CMSIS_5/Driver/html/index.html).

The IoT Socket is implemented using 
[lwIP](https://www.nongnu.org/lwip/2_1_x/index.html).

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

**Note:** configured in `RTE_Device.h`

### NVIC Configuration

| NVIC Interrupt      | Priority
|:--------------------|:--------
| Ethernet            | 4

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| ETH_MAC0     | Ethernet (ENET)
| ETH_PHY0     | DP83848 (external)

**STDOUT** is routed to ITM
