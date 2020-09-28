Board: STMicroelectronics NUCLEO-L552ZE-Q
-----------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32L552ZETxQ
| ICACHE                  | Mode: 2-ways set associative cache
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HCLK                    | 110 MHz
| FCLK                    | 110 MHz
| APB1                    | 110 MHz
| APB2                    | 110 MHz
| To USART3               | 110 MHz
| To LPUART1              | 110 MHz

### GPIO Configuration and usage

| GPIO | Signal / Label   | GPIO Settings                                 | Usage
|:-----|:-----------------|:----------------------------------------------|:-----
| PG7  | LPUART1_TX       | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_TX)
| PG8  | LPUART1_RX       | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_RX)
| PD8  | USART3_TX        | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)
| PD9  | USART3_RX        | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D0 (RX)
| PA5  | SPI1_SCK         | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D13 (SCK)
| PA6  | SPI1_MISO        | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D12 (MISO)
| PA7  | SPI1_MOSI        | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D11 (MOSI)
| PD14 | ARDUINO_IO_D10   | Output Push Pull, Level=High, Speed=Very High | Arduino UNO R3 pin D10
| PD15 | ARDUINO_IO_D9    | Input mode                                    | Arduino UNO R3 pin D9
| PC13 | vioBUTTON0       | not configured via CubeMX                     | Button USER
| PA9  | vioLED0          | not configured via CubeMX                     | LD3 RED
| PC7  | vioLED1          | not configured via CubeMX                     | LD1 GREEN
| PB7  | vioLED2          | not configured via CubeMX                     | LD2 BLUE 

### NVIC Configuration

 - Priority Group = 3 bits for preemption priority 0 bits for subpriority

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
| USART3 global / wake-up                 | 4                | Generate IRQ handler, Call HAL handler
| SPI1 global                             | 4                | Generate IRQ handler, Call HAL handler

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:----|:----
| SPI1         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | no  | Arduino UNO R3 connector (CN7)
| USART3       | Asynchronous, Hardware Flow Control=off, Do Not Generate Initialization Function Call                              | yes | no  | Arduino UNO R3 connector (CN10)
| LPUART1      | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no  | ST-LINK Virtual COM port

**STDIO** is routed to ST-LINK Virtual COM port (LPUART1)

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| SPI1         | SPI1
| USART3       | USART3

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD9 RED (PD3)
| vioLED1           | LD10 GREEN (PG12)
