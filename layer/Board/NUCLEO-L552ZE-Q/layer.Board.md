Board: STMicroelectronics NUCLEO-L552ZE-Q
-----------------------------------------

- This board layer is configured using [*STM32CubeMX*](https://www.st.com/en/development-tools/stm32cubemx.html)
- [Setup with classic Keil MDK](https://www.keil.com/pack/doc/STM32Cube)

### System  Settings

| System  Component       | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32L552ZETxQ
| System Clock Mux Source | PLLCLK: PLLM=/1, *N=X55, /R=/2
| SYSCLK                  | 110 MHz (all peripherals use same clock)
| ICACHE                  | Mode: 2-ways set associative cache

### GPIO Configuration and Usage

| GPIO | Signal           | GPIO Settings                                 | Note
|:-----|:-----------------|:----------------------------------------------|:------
| PG7  | LPUART1_TX       | Alternate Function, Speed=Very High           |
| PG8  | LPUART1_RX       | Alternate Function, Speed=Very High           |
| PA5  | SPI1_SCK         | Alternate Function, Speed=Very High           |
| PA6  | SPI1_MISO        | Alternate Function, Speed=Very High           |
| PA7  | SPI1_MOSI        | Alternate Function, Speed=Very High           |
| PD8  | USART3_TX        | Alternate Function, Speed=Very High           |
| PD9  | USART3_RX        | Alternate Function, Speed=Very High           |
| PD14 | ARDUINO_IO_D10   | Output Push Pull, Level=High, Speed=Very High | typical usage: SPI3_NSS
| PD15 | ARDUINO_IO_D9    | Input mode                                    | typical usage: SPI3_DATARDY
| PC13 | vioBUTTON0       | not configured via CubeMX                     | Button USER
| PA9  | vioLED0          | not configured via CubeMX                     | LD3 RED
| PC7  | vioLED1          | not configured via CubeMX                     | LD1 GREEN
| PB7  | vioLED2          | not configured via CubeMX                     | LD2 BLUE 

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
| USART3 global / wake-up                 | Preempt=0    | Generate IRQ handler, Call HAL handler, Do Not Generate Function Call
| SPI1 global                             | Preempt=0    | Generate IRQ handler, Call HAL handler, Do Not Generate Function Call

### CMSIS-Driver mapping

| Peripheral   | CMSIS-Driver | Mode / Settings                             | IRQ | DMA | Note 
|:-------------|:-------------|:--------------------------------------------|:----|:----|:----
| SPI1         | SPI1         | Full-Duplex Master, Hardware NSS Signal=off | yes | no  | Arduino UNO R3 connector (CN7)
| USART3       | USART3       | Asynchronous, Hardware Flow Control=off     | no  | no  | Arduino UNO R3 connector (CN10)
| LPUART1      | USART6       | Asynchronous, Hardware Flow Control=off     | yes | no  | STDIO: ST-LINK COM port

**Note:**
- Basic Parameters LPUART1/USART3: Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD9 RED (PD3)
| vioLED1           | LD10 GREEN (PG12)
| vioMotionGyro     | iNEMO 3D gyroscope (LSM6DSO)
| vioMotionAccelero | iNEMO 3D accelerometer (LSM6DSO)
