Board: STMicroelectronics STM32H735G-DK
---------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32H735IGKx
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HSE                     |  25 MHz
| HCLK                    | 275 MHz
| FCLK                    | 550 MHz
| APB1                    | 275 MHz
| APB2                    | 275 MHz
| APB3                    | 137.5 MHz
| APB4                    | 275 MHz
| To USART1               | 137.5 MHz
| To USART3               | 137.5 MHz
| To SPI5                 | 100 MHz
| To SDMMC1               | 200 MHz

### GPIO Configuration and usage

| GPIO        | Signal / Label | GPIO Settings                                 | Usage
|:------------|:---------------|:----------------------------------------------|:-----
| PA1         | ETH_REF_CLK    | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin REFCLK
| PA2         | ETH_MDIO       | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin MDIO
| PA7         | ETH_CRS_DV     | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin CRS_DV
| PC1         | ETH_MDC        | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin MDC
| PC4         | ETH_RXD0       | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin RXD0
| PC5         | ETH_RXD1       | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin RXD1
| PB11        | ETH_TX_EN      | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin TXEN
| PB12        | ETH_TXD0       | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin TXD0
| PB13        | ETH_TXD1       | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin TXD0
| PC8         | SDMMC1_D0      | Alternate Function, Speed=Very High           | Micro SD Card pin D0
| PC9         | SDMMC1_D1      | Alternate Function, Speed=Very High           | Micro SD Card pin D1
| PC10        | SDMMC1_D2      | Alternate Function, Speed=Very High           | Micro SD Card pin D2
| PC11        | SDMMC1_D3      | Alternate Function, Speed=Very High           | Micro SD Card pin D3
| PC12        | SDMMC1_CK      | Alternate Function, Speed=Very High           | Micro SD Card pin CLK
| PD2         | SDMMC1_CMD     | Alternate Function, Speed=Very High           | Micro SD Card pin CMD
| PF5         | MemoryCard_CD0 | Input mode                                    | Micro SD Card pin Card Detect
| PD9         | USART3_RX      | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_RX)
| PD8         | USART3_TX      | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_TX)
| PB15        | USART1_RX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D0 (RX)
| PB14        | USART1_TX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)
| PF8         | SPI5_MISO      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D12 (MISO)
| PF9         | SPI5_MOSI      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D11 (MOSI)
| PF7         | SPI5_SCK       | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D13 (SCK)
| PB7         | ARDUINO_IO_D9  | Input mode                                    | Arduino UNO R3 pin D9
| PF6         | ARDUINO_IO_D10 | Output Push Pull, Level=High, Speed=Very High | Arduino UNO R3 pin D10
| PH0/OSC_IN  | RCC_OSC_IN     |                                               | External Oscillator (HSE)
| PH1/OSC_OUT | RCC_OSC_OUT    |                                               | External Oscillator (HSE)
| PC13        | vioBUTTON0     | not configured via CubeMX                     | Button USER
| PD3         | vioLED0        | not configured via CubeMX                     | LD2 RED
| PG12        | vioLED1        | not configured via CubeMX                     | LD1 GREEN

### NVIC Configuration

 - Priority Group = 4 bits for preemption priority 0 bits for subpriority

| NVIC Interrupt                          | Preempt Priority | Code Generation
|:----------------------------------------|:-----------------|:---------------
| Non maskable interrupt                  | 0                | Generate IRQ handler
| Hard fault interrupt                    | 0                | Generate IRQ handler
| Memory Management fault                 | 0                | Generate IRQ handler
| Prefetch fault, memory access fault     | 0                | Generate IRQ handler
| Undefined instruction or illegal state  | 0                | Generate IRQ handler
| System service call via SWI instruction | 0                | none
| Debug monitor                           | 0                | Generate IRQ handler
| Pendable request for system service     | 0                | none
| Time base: System tick timer            | 0                | none
| DMA1 stream0 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| DMA1 stream1 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| USART1 global interrupt                 | 8                | Generate IRQ handler, Call HAL handler
| Ethernet global interrupt               | 8                | Generate IRQ handler, Call HAL handler
| SPI5 global                             | 8                | Generate IRQ handler, Call HAL handler
| SDMMC1 global interrupt                 | 8                | Call HAL handler

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA                                              | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:-------------------------------------------------|:----
| SPI5         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | SPI5_RX = DMA1 Stream 0, SPI5_TX = DMA1 Stream 1 | Arduino UNO R3 connector (CN8)
| USART1       | Asynchronous, Hardware Flow Control=off, Do Not Generate Initialization Function Call                              | yes | no                                               | Arduino UNO R3 connector (CN8)
| USART3       | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no                                               | ST-LINK Virtual COM port

**STDIO** is routed to ST-LINK Virtual COM port (USART3)

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| ETH_MAC0     | ETH
| ETH_PHY0     | LAN8742A (external)
| MCI0         | SDMMC1
| SPI5         | SPI5
| USART1       | USART1
| USART3       | USART3

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD2 RED (PD3)
| vioLED1           | LD1 GREEN (PG12)
