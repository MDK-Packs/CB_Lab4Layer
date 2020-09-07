Board: STMicroelectronics 32F746GDISCOVERY
------------------------------------------

- This board layer is configured using [*STM32CubeMX*](https://www.st.com/en/development-tools/stm32cubemx.html)
- [Setup with classic Keil MDK](https://www.keil.com/pack/doc/STM32Cube)

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
| To USART6               | 108 MHz
| To RNG                  |  48 MHz
| To SDMMC                |  48 MHz

### GPIO Configuration and usage

| GPIO        | Signal / Label | GPIO Settings                                 | Usage
|:------------|:---------------|:----------------------------------------------|:-----
| PC6         | USART6_TX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)
| PC7         | USART6_RX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D0 (RX)
| PC8         | SDMMC1_D0      | Alternate Function, Speed=Very High           | Micro SD Card pin D0
| PC9         | SDMMC1_D1      | Alternate Function, Speed=Very High           | Micro SD Card pin D1
| PC10        | SDMMC1_D2      | Alternate Function, Speed=Very High           | Micro SD Card pin D2
| PC11        | SDMMC1_D3      | Alternate Function, Speed=Very High           | Micro SD Card pin D3
| PC12        | SDMMC1_CK      | Alternate Function, Speed=Very High           | Micro SD Card pin CLK
| PC13        | MemoryCard_CD0 | Input mode                                    | Micro SD Card pin Card Detect
| PD2         | SDMMC1_CMD     | Alternate Function, Speed=Very High           | Micro SD Card pin CMD
| PH0/OSC_IN  | RCC_OSC_IN     |                                               | External Oscillator (HSE)
| PH1/OSC_OUT | RCC_OSC_OUT    |                                               | External Oscillator (HSE)

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
| SDMMC1 global interrupt                 | 8                | none
| DMA2 stream3 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| DMA2 stream6 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| USART6 global interrupt                 | 8                | none

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                        | IRQ | DMA                                                  | Note
|:-------------|:---------------------------------------------------------------------------------------|:----|:-----------------------------------------------------|:----
| SDMMC1       | SD 4 bits, Do Not Generate Initialization Function Call                                | yes | SDMMC1_RX = DMA2 Stream 2, SDMMC1_TX = DMA2 Stream 6 | Micro SD Card connector
| USART6       | Asynchronous, Hardware Flow Control=off, Do Not Generate Initialization Function Call  | yes | no                                                   | Arduino UNO R3 connector (CN4)

### Security Peripherals Configuration

| Peripheral   | Mode / Settings                                                                        | IRQ | DMA                                                  | Note
|:-------------|:---------------------------------------------------------------------------------------|:----|:-----------------------------------------------------|:----
| RNG          | Activated                                                                              | no  |                                                      | Random Number Generator

**STDOUT** routed to ITM

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| USART6       | USART6
| MCI0         | SD/MMC
