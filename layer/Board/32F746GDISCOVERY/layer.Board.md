Board: STMicroelectronics 32F746GDISCOVERY
------------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**,
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32F746NGHx
| RCC                     | High Speed Clock (HSE): Crystal/Ceramic Resonator
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HSE                     |  25 MHz
| HCLK                    | 216 MHz
| FCLK                    | 216 MHz
| APB1                    |  54 MHz
| APB2                    | 108 MHz
| To USART1               | 108 MHz
| To USART6               | 108 MHz
| To RNG                  |  48 MHz
| To SDMMC                |  48 MHz

### GPIO Configuration and usage

| GPIO        | Signal / Label | GPIO Settings                                 | Usage
|:------------|:---------------|:----------------------------------------------|:-----
| PA1         | ETH_REF_CLK    | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin REFCLK
| PA2         | ETH_MDIO       | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin MDIO
| PA7         | ETH_CRS_DV     | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin CRS_DV
| PC1         | ETH_MDC        | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin MDC
| PC4         | ETH_RXD0       | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin RXD0
| PC5         | ETH_RXD1       | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin RXD1
| PG11        | ETH_TX_EN      | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin TXEN
| PG13        | ETH_TXD0       | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin TXD0
| PG14        | ETH_TXD1       | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin TXD0
| PC8         | SDMMC1_D0      | Alternate Function, Speed=Very High           | Micro SD Card pin D0
| PC9         | SDMMC1_D1      | Alternate Function, Speed=Very High           | Micro SD Card pin D1
| PC10        | SDMMC1_D2      | Alternate Function, Speed=Very High           | Micro SD Card pin D2
| PC11        | SDMMC1_D3      | Alternate Function, Speed=Very High           | Micro SD Card pin D3
| PC12        | SDMMC1_CK      | Alternate Function, Speed=Very High           | Micro SD Card pin CLK
| PD2         | SDMMC1_CMD     | Alternate Function, Speed=Very High           | Micro SD Card pin CMD
| PC13        | MemoryCard_CD0 | Input mode                                    | Micro SD Card pin Card Detect
| PA9         | USART1_TX      | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (VCP_TX)
| PB7         | USART1_RX      | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (VCP_RX)
| PC6         | USART6_TX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)
| PC7         | USART6_RX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D0 (RX)
| PB14        | SPI2_MISO      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D12 (MISO)
| PB15        | SPI2_MOSI      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D11 (MOSI)
| PI1         | SPI2_SCK       | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D13 (SCK)
| PA15        | ARDUINO_IO_D9  | External interrupt Mode, Rissing edge trigger | Arduino UNO R3 pin D9
| PA8         | ARDUINO_IO_D10 | Output Push Pull, Level=High, Speed=Very High | Arduino UNO R3 pin D10
| PH0/OSC_IN  | RCC_OSC_IN     |                                               | External Oscillator (HSE)
| PH1/OSC_OUT | RCC_OSC_OUT    |                                               | External Oscillator (HSE)
| PI11        | vioBUTTON0     | not configured via CubeMX                     | Button USER

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
| DMA1 stream3 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| DMA1 stream4 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| SPI2 global interrupt                   | 8                | none
| SDMMC1 global interrupt                 | 8                | none
| DMA2 stream3 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| Ethernet global interrupt               | 8                | none
| DMA2 stream6 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| USART6 global interrupt                 | 8                | none

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA                                                  | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:-----------------------------------------------------|:----
| ETH          | RMII, PHY Address=0, PHY=LAN8742A_PHY_ADDRESS, Do Not Generate Initialization Function Call                        | yes |                                                      | Ethernet LAN8742A
| SDMMC1       | SD 4 bits, Do Not Generate Initialization Function Call                                                            | yes | SDMMC1_RX = DMA2 Stream 2, SDMMC1_TX = DMA2 Stream 6 | Micro SD Card connector
| SPI2         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | SPI2_RX = DMA1 Stream 3, SPI2_TX = DMA1 Stream 4     | Arduino UNO R3 connector (CN7)
| USART1       | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no                                                   | ST-LINK Virtual COM port
| USART6       | Asynchronous, Hardware Flow Control=off, Do Not Generate Initialization Function Call                              | yes | no                                                   | Arduino UNO R3 connector (CN4)

### Security Peripherals Configuration

| Peripheral   | Mode / Settings                                                                        | IRQ | DMA                                                  | Note
|:-------------|:---------------------------------------------------------------------------------------|:----|:-----------------------------------------------------|:----
| RNG          | Activated                                                                              | no  |                                                      | Random Number Generator

**STDIO** is routed to ST-LINK Virtual COM port (USART1)

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| ETH_MAC0     | ETH
| ETH_PHY0     | LAN8742A (external)
| MCI0         | SDMMC
| SPI2         | SPI2
| USART6       | USART6

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PI11)
