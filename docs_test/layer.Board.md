Board: STMicroelectronics STM32L562E-DK
---------------------------------------

This board layer is configured using *STM32CubeMX*
  - [Setup with classic Keil MDK](https://www.keil.com/st/CubeMX)

### System Setting

| System Component | Setting
|:-----------------|:----------
| Device           | STM32L562QEIxQ
| SYSCLK           | 110 MHz (all peripherals use same clock)
| Clock Source     | MCI RC = 4000KHz with PLL: M=/1 N=X 55 R= /2
| ICACHE           | Mode: 2-ways set associative cache

### GPIO Configuration and usage

| GPIO | Signal           | GPIO Settings                                 | Note
|:-----|:-----------------|:----------------------------------------------|:------
| PB10 | LPUART1_RX       | Alternate Function, Speed=Very High           |
| PB11 | LPUART1_TX       | Alternate Function, Speed=Very High           |
| PB4  | SPI3_MISO        | Alternate Function, Speed=Very High           |
| PB5  | SPI3_MOSI        | Alternate Function, Speed=Very High           |
| PG9  | SPI3_SCK         | Alternate Function, Speed=Very High           |
| PA10 | USART1_RX        | Alternate Function, Speed=Very High           |
| PA9  | USART1_TX        | Alternate Function, Speed=Very High           |
| PB9  | ARDUINO_IO_D9    | Input mode                                    | typical usage: SPI3_DATARDY
| PE0  | ARDUINO_IO_D10   | Output Push Pull, Level=High, Speed=Very High | typical usage: SPI3_NSS
| PC13 | vioBUTTON0       | not configured via CubeMX                     | Button USER
| PD3  | vioLED0          | not configured via CubeMX                     | LD9 RED
| PG12 | vioLED1          | not configured via CubeMX                     | LD10 GREEN

### NVIC Interrupt Settings

 - Priority Group = 3 bits for preemption priority

| NVIC Interrupt                          | Priority     | Code Generation
|:----------------------------------------|:-------------|:--------------------
| Non maskable interrupt                  | Preempt=0    | Generate IRQ handler
| Hard fault interrupt                    | Preempt=0    | Generate IRQ handler
| Memory Management fault                 | Preempt=0    | Generate IRQ handler
| Prefetch fault, memory access fault     | Preempt=0    | Generate IRQ handler
| Undefined instruction or illegal state  | Preempt=0    | Generate IRQ handler
| System service call via SWI instruction | Preempt=6    | none
| Debug monitor                           | Preempt=0    | Generate IRQ handler
| Pendable request for system service     | Preempt=7    | none
| Time base: System tick timer            | Preempt=7    | none
| LPUART1 global / wake-up                | Preempt=0    | Generate IRQ handler, Call HAL handler
| SPI3 global                             | Preempt=0    | Generate IRQ handler, Call HAL handler

### CMSIS-Driver mapping

| Peripheral   | CMSIS-Driver | IRQ | DMA | Note 
|:-------------|:-------------|:----|:----|:----
| SPI3         | SPI3         | yes | no  | Arduino UNO R3 connector (CN11)
| USART1       | USART1       | no  | no  | STDIO: ST-LINK COM port, 115200 baudrate, init via HAL
| LPUART1      | USART6       | yes | no  | Arduino UNO R3 connector (CN12)

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD9 RED (PD3)
| vioLED1           | LD10 GREEN (PG12)
| vioMotionGyro     | iNEMO 3D gyroscope (LSM6DSO)
| vioMotionAccelero | iNEMO 3D accelerometer (LSM6DSO)


