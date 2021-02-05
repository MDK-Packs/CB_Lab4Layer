Board: NXP LPCXpresso55S69
--------------------------

The tables below list the device configuration for this board. The board layer for the NXP LPCXpresso55S69 is using the software component `::Board Support: SDK Project Template: project_template (Variant: lpcxpresso55s69)` from `NXP.LPCXpresso55S69_BSP.12.4.0` pack.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.

The example project can be re-configured to work on custom hardware. Refer to ["Configuring Example Projects with MCUXpresso Config Tools"](https://github.com/MDK-Packs/Documentation/tree/master/Using_MCUXpresso) for information.

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | LPC55S69JBD100
| Board                   | LPCXpresso55S69
| SDK Version             | ksdk2_0
| Heap                    | 64 kB (configured in linker script LPC55S69_cm33_core0_*.scf file)
| Stack (MSP)             |  1 kB (configured in linker script LPC55S69_cm33_core0_*.scf file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| System                  | 150 MHz
| FXCOM0                  |  12 MHz
| FXCOM2                  |  12 MHz
| HSLSPI                  |  96 MHz

**Note:** configured with Functional Group: `BOARD_BootClockPLL150M`

### GPIO Configuration and usage

| Functional Group              | Pin | Peripheral | Signal / Identifier       | Pin Settings                                           | Usage
|:------------------------------|:----|:-----------|:--------------------------|:-------------------------------------------------------|:-----
| BOARD_InitDEBUG_UARTPins      | 92  | FLEXCOMM0  | RXD_SDA_MOSI_DATA         | default                                                | UART for debug console (FC0_USART_RXD)
| BOARD_InitDEBUG_UARTPins      | 94  | FLEXCOMM0  | TXD_SCL_MISO_WS           | default                                                | UART for debug console (FC0_USART_TXD)
| BOARD_InitLEDsPins            | 1   | GPIO       | PIO1, 4                   | Direction Output, GPIO initial state 1, mode PullUp    | LED BLUE
| BOARD_InitLEDsPins            | 5   | GPIO       | PIO1, 6                   | Direction Output, GPIO initial state 1, mode PullUp    | LED RED
| BOARD_InitLEDsPins            | 9   | GPIO       | PIO1, 7                   | Direction Output, GPIO initial state 1, mode PullUp    | LED GREEN
| BOARD_InitBUTTONsPins         | 88  | GPIO       | PIO0, 5                   | Direction Input, mode PullUp                           | Button ISP    (S1: PIO0_5_ISP1)
| BOARD_InitBUTTONsPins         | 64  | GPIO       | PIO1, 18                  | Direction Input, mode PullUp                           | Button WAKEUP (S2: WAKE/GPIO)
| BOARD_InitBUTTONsPins         | 10  | GPIO       | PIO1, 9                   | Direction Input, mode PullUp                           | Button USER   (S3: PIO1_9_GPI_ARD)
| BOARD_InitBUTTONsPins         | 32  | SYSCON     | RESET                     | Direction Input                                        | Button RESET  (S4: nRESET_ULP)
| BOARD_InitPins_Arduino_USART2 | 27  | FLEXCOMM2  | TXD_SCL_MISO_WS           | default                                                | Arduino UNO R3 pin D1  (P18-13: FC2_USART_TXD_ARD)
| BOARD_InitPins_Arduino_USART2 | 3   | FLEXCOMM2  | RXD_SDA_MOSI_DATA         | default                                                | Arduino UNO R3 pin D0  (P18-15: FC2_USART_RXD_ARD)
| BOARD_InitPins_Arduino_SPI8   | 61  | FLEXCOMM8  | HS_SPI_SCK                | Slew rate Fast                                         | Arduino UNO R3 pin D13 (P17-9:  LSPI_HS_SCK)
| BOARD_InitPins_Arduino_SPI8   | 62  | FLEXCOMM8  | HS_SPI_MISO               | Slew rate Fast                                         | Arduino UNO R3 pin D12 (P17-11: LSPI_HS_MISO)
| BOARD_InitPins_Arduino_SPI8   | 60  | FLEXCOMM8  | HS_SPI_MOSI               | Slew rate Fast                                         | Arduino UNO R3 pin D11 (P17-13: LSPI_HS_MOSI)
| BOARD_InitPins_Arduino_SPI8   | 59  | GPIO       | PIO1, 1 / ARDUINO_SPI_SSN | Direction Output, GPIO initial state 1, Slew rate Fast | Arduino UNO R3 pin D10 (P17-15: LSPI_HS_SSEL1)
| BOARD_InitPins_Arduino_PIO1_5 | 31  | GPIO       | PIO1, 5 / ARDUINO_PIO1_5  | Direction Input                                        | Arduino UNO R3 pin D9  (P17-17: PIO1_5_GPIO_ARD)

### NVIC Configuration

| NVIC Interrupt      | Priority
|:--------------------|:--------
| FLEXCOMM2           | 4
| FLEXCOMM8           | 4

**STDIO** is routed to debug console through LPC-Link Virtual COM port (USART0)

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| USART2       | FLEXCOMM2
| SPI8         | FLEXCOMM8

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER   (PIO1_9)
| vioBUTTON1        | Button ISP    (PIO0_5)
| vioBUTTON2        | Button WAKEUP (PIO1_18)
| vioLED0           | LED RED       (PIO1_6)
| vioLED1           | LED GREEN     (PIO1_7)
| vioLED2           | LED BLUE      (PIO1_4)
