Board: STMicroelectronics STM32L562E-DK
---------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32L562QEIxQ
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
| To USART1               | 110 MHz
| To LPUART1              |  16 MHz

### GPIO Configuration and usage

| GPIO | Signal / Label   | GPIO Settings                                 | Usage
|:-----|:-----------------|:----------------------------------------------|:-----
| PA10 | USART1_RX        | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_RX)
| PA9  | USART1_TX        | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_TX)
| PB10 | LPUART1_RX       | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D0 (RX)
| PB11 | LPUART1_TX       | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)
| PB4  | SPI3_MISO        | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D12 (MISO)
| PB5  | SPI3_MOSI        | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D11 (MOSI)
| PG9  | SPI3_SCK         | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D13 (SCK)
| PB9  | ARDUINO_IO_D9    | Input mode                                    | Arduino UNO R3 pin D9
| PE0  | ARDUINO_IO_D10   | Output Push Pull, Level=High, Speed=Very High | Arduino UNO R3 pin D10
| PC13 | vioBUTTON0       | not configured via CubeMX                     | Button USER
| PD3  | vioLED0          | not configured via CubeMX                     | LD9 RED
| PG12 | vioLED1          | not configured via CubeMX                     | LD10 GREEN

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
| LPUART1 global / wake-up                | 4                | Generate IRQ handler, Call HAL handler
| SPI3 global                             | 4                | Generate IRQ handler, Call HAL handler

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:----|:----
| SPI3         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | no  | Arduino UNO R3 connector (CN11)
| LPUART1      | Asynchronous, Hardware Flow Control=off, Do Not Generate Initialization Function Call                              | yes | no  | Arduino UNO R3 connector (CN12)
| USART1       | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no  | ST-LINK Virtual COM port

**STDIO** is routed to ST-LINK Virtual COM port (USART1)

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| SPI3         | SPI3
| USART6       | LPUART1

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD9 RED (PD3)
| vioLED1           | LD10 GREEN (PG12)
| vioMotionGyro     | iNEMO 3D gyroscope (LSM6DSO)
| vioMotionAccelero | iNEMO 3D accelerometer (LSM6DSO)
