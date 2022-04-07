Board: STMicroelectronics NUCLEO-H743ZI
---------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32H743ZITx
| RCC                     | High Speed Clock (HSI): RC oscillator
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HSE                     |   8 MHz
| HCLK                    | 400 MHz
| FCLK                    | 400 MHz
| APB1                    | 200 MHz
| APB2                    | 200 MHz
| To USART1               | 100 MHz
| To USART3               | 100 MHz
| To SPI1                 | 100 MHz

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
| PB13        | ETH_TXD1       | Alternate Function, Speed=Very High           | Ethernet LAN8742A pin TXD0
| PD8         | USART3_TX      | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (VCP_TX)
| PD9         | USART3_RX      | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (VCP_RX)
| PB6         | USART1_TX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)
| PB7         | USART1_RX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D0 (RX)
| PA6         | SPI1_MISO      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D12 (MISO)
| PB5         | SPI1_MOSI      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D11 (MOSI)
| PA5         | SPI1_SCK       | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D13 (SCK)
| PD15        | ARDUINO_IO_D9  | Input mode                                    | Arduino UNO R3 pin D9
| PD14        | ARDUINO_IO_D10 | Output Push Pull, Level=High, Speed=Very High | Arduino UNO R3 pin D10
| PC13        | vioBUTTON0     | not configured via CubeMX                     | Button USER

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
| DMA1 stream2 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| DMA1 stream3 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| USART1 global interrupt                 | 8                | Generate IRQ handler, Call HAL handler
| SPI1 global interrupt                   | 8                | Generate IRQ handler, Call HAL handler
| Ethernet global interrupt               | 8                | Generate IRQ handler, Call HAL handler

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA                                              | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:-------------------------------------------------|:----
| ETH          | RMII, Do Not Generate Initialization Function Call                                                                 | yes | no                                               | Ethernet LAN8742A
| SPI1         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | SPI1_RX = DMA1 Stream 2, SPI1_TX = DMA1 Stream 3 | Arduino UNO R3 connector (CN7)
| USART3       | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no                                               | ST-LINK Virtual COM port
| USART1       | Asynchronous, Hardware Flow Control=off                                                                            | yes | no                                               | Arduino UNO R3 connector (CN10)

**STDIO** is routed to ST-LINK Virtual COM port (USART3)

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| ETH_MAC0     | ETH
| ETH_PHY0     | LAN8742A (external)
| SPI1         | SPI1
| USART1       | USART1

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD3 RED (PB14)
| vioLED1           | LD1 GREEN (PB0)
| vioLED2           | LD2 YELLOW (PE1)
