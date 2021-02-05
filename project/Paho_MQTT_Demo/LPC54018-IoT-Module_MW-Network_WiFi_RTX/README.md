Paho MQTT Demo
==============

This demo application connects to **Eclipse Paho** through MQTT, subscribes to topics and publishes messages.

The following describes the various components and the configuration settings.

Once the application is configured you can:
- Build the application.
- Connect the debugger.
- Run the application and view messages in a debug printf or terminal window.

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

Socket: WiFi IoT Socket (MDK-Middleware Network)
------------------------------------------------
This implementation uses an [IoT socket](https://mdk-packs.github.io/IoT_Socket/html/index.html) layer that connects to a 
[CMSIS-Driver WiFi](https://arm-software.github.io/CMSIS_5/Driver/html/index.html).

The IoT Socket is implemented using 
[MDK-Middleware Network](https://www.keil.com/pack/doc/mw/Network/html/index.html).

The file `socket_startup.c` configures the WiFi connection with these settings:
 - SSID:          network identifier
 - PASSWORD:      network password
 - SECURITY_TYPE: network security

Note: These settings need to be configured by the user!

Board: NXP LPC54018-IoT-Module
------------------------------

The tables below list the device configuration for this board. The board layer for the NXP LPC54018-IoT-Module is using the software component `::Board Support: SDK Project Template: project_template (Variant: lpc54018iotmodule)` from `NXP.LPC54018-IoT-Module_BSP.12.2.0` pack.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.

The example project can be re-configured to work on custom hardware. Refer to ["Configuring Example Projects with MCUXpresso Config Tools"](https://github.com/MDK-Packs/Documentation/tree/master/Using_MCUXpresso) for information.

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | LPC54018JET180
| Board                   | LPC54018-IoT-Module
| SDK Version             | ksdk2_0
| Heap                    | 64 kB (configured in linker script LPC54018_xxxx_*.scf file)
| Stack (MSP)             |  1 kB (configured in linker script LPC54018_xxxx_*.scf file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| System                  | 180 MHz
| SYSPLL                  | 180 MHz
| FRO12M                  |  12 MHz
| FXCOM8                  |  12 MHz

**Note:** configured with Functional Group: `BOARD_BootClockRUN`

### GPIO Configuration and usage

| Functional Group       | Pin | Peripheral    | Signal        | Identifier  | Pin Settings                                          | Usage
|:-----------------------|:----|:--------------|:--------------|:------------|:----------------------------------------------------  |:-----
| BOARD_InitGT1216Shield | E1  | FLEXCOMM8 SPI | RXD_SDA_MOSI  | SPI8_MOSI   | Default                                               | SPI8 MOSI for WiFi Module
| BOARD_InitGT1216Shield | K1  | FLEXCOMM8 SPI | TXD_SCL_MISO  | SPI8_MISO   | Default                                               | SPI8 MISO for WiFi Module
| BOARD_InitGT1216Shield | D2  | FLEXCOMM8 SPI | SCK           | SPI8_SCK    | Default                                               | SPI8 SCK for WiFi Module
| BOARD_InitGT1216Shield | P11 | FLEXCOMM8 SPI | RTS_SCL_SSEL1 | SPI8_SSEL1  | Default                                               | SPI8 SSEL1 for WiFi Module
| BOARD_InitGT1216Shield | N3  | PINT1         | PIO1,0        | IRQ         | Direction Input,  mode PullUp                         | Interrupt pin for WiFi module
| BOARD_InitGT1216Shield | A13 | GPIO          | PIO3,3        | PWRON       | Direction Output, GPIO initial state 0, mode PullDown | PowerOn pin for WiFi module

**Note:** configured with Functional Group: `BOARD_InitGT1216Shield`

### NVIC Configuration

| NVIC Interrupt      | Priority
|:--------------------|:--------
| PINT1               | 4
| SPI8                | 4

**STDOUT** is routed to Event Recorder

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:-------------
| SPI8         | FLEXCOMM SPI8
