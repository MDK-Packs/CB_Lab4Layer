Board: NXP FRDM-K32L3A6
-----------------------

The tables below list the device configuration for this board. The board layer for the NXP FRDM-K32L3A6 is using the software component `::Board Support: SDK Project Template: project_template (Variant: frdmk32l3a6)` from `NXP.FRDM-K32L3A6_BSP.13.0.0` pack.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.

The example project can be re-configured to work on custom hardware. Refer to ["Configuring Example Projects with MCUXpresso Config Tools"](https://github.com/MDK-Packs/Documentation/tree/master/Using_MCUXpresso) for information.

### System Configuration

| System Component        | Setting
|:------------------------|:-------------------------------------------------------------
| Device                  | K32L3A60VPJ1A:cm4
| Board                   | FRDM-K32L3A6
| SDK Version             | ksdk2_0
| Heap                    | 64 kB (configured in linker script K32L3A60xxx_cm4*.scf file)
| Stack (MSP)             |  1 kB (configured in linker script K32L3A60xxx_cm4*.scf file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:-------
| FIRC                    |  48 MHz
| FIRC DIV1 clock         |  48 MHz
| FIRC DIV2 clock         |  48 MHz
| FIRC DIV3 clock         |  48 MHz
| LPUART0 clock           |  48 MHz
| LPUART1 clock           |  48 MHz
| LPSPI0 clock            |  48 MHz
| LPI2C3 clock            |  48 MHz

**Note:** configured with Functional Group: `BOARD_BootClockRUN`

### GPIO Configuration and usage

| Functional Group            | Pin | Peripheral | Signal   | Identifier         | Pin Settings                           | Usage
|:----------------------------|:----|:-----------|:---------|:-------------------|:---------------------------------------|:-----------------------------------
| BOARD_InitDEBUG_UART        | N2  | LPUART0    | TX       | DEBUG_UART0_TX     | default                                | LPUART0 TX for debug console (PTC8)
| BOARD_InitDEBUG_UART        | P3  | LPUART0    | RX       | DEBUG_UART0_RX     | default                                | LPUART0 RX for debug console (PTC7)
| BOARD_InitLEDs              | D6  | GPIOA      | GPIO, 24 | RGB_RED            | default                                | User LED1 (PTA24)
| BOARD_InitLEDs              | E6  | GPIOA      | GPIO, 23 | RGB_GREEN          | default                                | User LED2 (PTA23)
| BOARD_InitLEDs              | B6  | GPIOA      | GPIO, 22 | RGB_BLUE           | default                                | User LED3 (PTA22)
| BOARD_InitButtons           | B10 | GPIOA      | GPIO,  0 | SW2                | default                                | User Button SW2 (PTA2)
| BOARD_InitButtons           | P16 | GPIOE      | GPIO,  8 | SW3                | default                                | User Button SW3 (PTE8)
| BOARD_InitButtons           | N16 | GPIOE      | GPIO,  9 | SW4                | default                                | User Button SW4 (PTE9)
| BOARD_InitButtons           | L12 | GPIOE      | GPIO, 12 | SW5                | default                                | User Button SW5 (PTE12)
| BOARD_InitARDUINO_UART      | A5  | LPUART1    | TX       | ARDUINO_LPUART1_TX | default                                | Arduino UNO R3 pin D1 (PTA26)
| BOARD_InitARDUINO_UART      | B5  | LPUART1    | RX       | ARDUINO_LPUART1_RX | default                                | Arduino UNO R3 pin D0 (PTA27)
| BOARD_InitARDUINO_SPI       | C2  | LPSPI0     | SCK      | ARDUINO_SPI_SCK    | default                                | Arduino UNO R3 pin D13 (PTB4)
| BOARD_InitARDUINO_SPI       | D2  | LPSPI0     | SOUT     | ARDUINO_SPI_MOSI   | default                                | Arduino UNO R3 pin D11 (PTB5)
| BOARD_InitARDUINO_SPI       | E2  | LPSPI0     | SIN      | ARDUINO_SPI_MISO   | default                                | Arduino UNO R3 pin D12 (PTB7)
| BOARD_InitARDUINO_SPI       | E1  | GPIOB      | GPIO,  6 | ARDUINO_SPI_SSN    | Direction Output, GPIO initial state 1 | Arduino UNO R3 pin D10 (PTB6)
| BOARD_InitPins_Arduino_PTB3 | C1  | GPIOB      | GPIO,  3 | ARDUINO_PTB3       | Direction Input                        | Arduino UNO R3 pin D9  (PTB3)

### NVIC Configuration

| NVIC Interrupt      | Priority
|:--------------------|:--------
| LPUART1             | 4
| LPSPI0              | 4

**STDIO** is routed to debug console through Virtual COM port (DAP-Link, peripheral = LPUART0, baudrate = 115200)

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| USART1       | LPUART1
| SPI0         | LPSPI0

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:------------------------------
| vioBUTTON0        | User Button SW2
| vioBUTTON1        | User Button SW3
| vioBUTTON2        | User Button SW4
| vioBUTTON3        | User Button SW5
| vioLED0           | User LED RED
| vioLED1           | User LED GREEN
| vioLED2           | User LED BLUE
| vioMotionAccelero | MEMS accelerometer(FXOS8700CQ)
| vioMotionMagneto  | MEMS magnetometer (FXOS8700CQ)
