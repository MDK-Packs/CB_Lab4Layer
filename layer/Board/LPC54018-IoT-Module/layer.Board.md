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
