Board: STMicroelectronics 32L4R9IDISCOVERY
------------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32L4R9AIIx
| RCC                     | High Speed Clock (HSI): RC oscillator
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HSE                     |  16 MHz
| HCLK                    | 120 MHz
| FCLK                    | 120 MHz
| APB1                    | 120 MHz
| APB2                    | 120 MHz
| To LTDC                 |  15 MHz
| To USART2               | 120 MHz
| To LPSART1              | 120 MHz
| To SPI2                 | 120 MHz
| To SDMMC1               | 120 MHz

### GPIO Configuration and usage

| GPIO    | Signal / Label | GPIO Settings                                 | Usage
|:--------|:---------------|:----------------------------------------------|:-----
| PC8     | SDMMC1_D0      | Alternate Function, Speed=Very High           | Micro SD Card pin D0
| PC9     | SDMMC1_D1      | Alternate Function, Speed=Very High           | Micro SD Card pin D1
| PC10    | SDMMC1_D2      | Alternate Function, Speed=Very High           | Micro SD Card pin D2
| PC11    | SDMMC1_D3      | Alternate Function, Speed=Very High           | Micro SD Card pin D3
| PC12    | SDMMC1_CK      | Alternate Function, Speed=Very High           | Micro SD Card pin CLK
| PD2     | SDMMC1_CMD     | Alternate Function, Speed=Very High           | Micro SD Card pin CMD
| MFX_IO5 | MemoryCard_CD0 | not configured via CubeMX                     | Micro SD Card pin Card Detect
| PA3     | USART2_RX      | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_RX)
| PA2     | USART2_TX      | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_TX)
| PC0     | LPUART1_RX     | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D0 (RX)
| PC1     | LPUART1_TX     | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)
| PB14    | SPI2_MISO      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D12 (MISO)
| PB15    | SPI2_MOSI      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D11 (MOSI)
| PB13    | SPI2_SCK       | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D13 (SCK)
| PH13    | ARDUINO_IO_D9  | Input mode                                    | Arduino UNO R3 pin D9
| PI0     | ARDUINO_IO_D10 | Output Push Pull, Level=High, Speed=Very High | Arduino UNO R3 pin D10
| PH0     | RCC_OSC_IN     |                                               | External Oscillator (HSE)
| PH1     | RCC_OSC_OUT    |                                               | External Oscillator (HSE)
| PC14    | RCC_OSC32_IN   |                                               | External Oscillator (LSE)
| PC15    | RCC_OSC32_OUT  |                                               | External Oscillator (LSE)
| PC13    | vioBUTTON0     | not configured via CubeMX                     | Joystic SELECT (with define VIO_BUTTON_REMAP)
| PH4     | vioLED0        | not configured via CubeMX                     | LD2 GREEN
| MFX_IO0 | vioLED1        | not configured via CubeMX                     | LD1 ORANGE
| MFX_IO1 | vioSignalIn.4  | not configured via CubeMX                     | Joystic UP
| MFX_IO2 | vioSignalIn.5  | not configured via CubeMX                     | Joystic DOWN
| MFX_IO4 | vioSignalIn.6  | not configured via CubeMX                     | Joystic LEFT
| MFX_IO3 | vioSignalIn.7  | not configured via CubeMX                     | Joystic RIGHT
| PC13    | vioSignalIn.8  | not configured via CubeMX                     | Joystic SELECT

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
| DMA1 channel1 global interrupt          | 8                | Generate IRQ handler, Call HAL handler
| DMA1 channel2 global interrupt          | 8                | Generate IRQ handler, Call HAL handler
| SPI2 global                             | 8                | Generate IRQ handler, Call HAL handler
| SDMMC1 global interrupt                 | 8                | Call HAL handler
| LPUART1 global interrupt                | 8                | Generate IRQ handler, Call HAL handler

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA                                                | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:-------------------------------------------------- |:----
| SPI2         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | SPI2_RX = DMA1 Channel 1, SPI2_TX = DMA1 Channel 2 | Arduino UNO R3 connector (CN10)
| USART2       | Asynchronous, Hardware Flow Control=off, Do Not Generate Initialization Function Call                              | yes | no                                                 | Arduino UNO R3 connector (CN11)
| LPUART1      | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no                                                 | ST-LINK Virtual COM port

**STDIO** is routed to ST-LINK Virtual COM port (USART2)

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| MCI0         | SDMMC1
| SPI2         | SPI2
| USART2       | USART2
| USART6       | LPUART1

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | B2 Joystick (with define VIO_BUTTON_REMAP)
| vioLED0           | LD2 GREEN (PH4)
| vioLED1           | LD1 ORANGE (MFX_IO0)
| vioJOYup          | B2 Joystic UP (MFX_IO1)
| vioJOYdown        | B2 Joystic DOWN (MFX_IO2)
| vioJOYleft        | B2 Joystic LEFT (MFX_IO4)
| vioJOYright       | B2 Joystic RIGHT (MFX_IO3)
| vioJOYselect      | B2 Joystic SELECT (PC13)
