STMicroelectronics STM32L562E-DK Target Board
---------------------------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART6** routed to Arduino UNO R3 connector (CN12):
 - RX: D0 LPUART1_RX (PB10)
 - TX: D1 LPUART1_TX (PB11)

**CMSIS-Driver SPI3** routed to Arduino UNO R3 connector (CN11):
 - SCK:  D13 SPI3_SCK (PG9)
 - MISO: D12 SPI3_MISO (PB4)
 - MOSI: D11 SPI3_MOSI (PB5)

**GPIO** pins routed to Arduino UNO R3 connector (CN11):
 - output: D10 SPI_CSn (PE0)
 - input:  D9 TIM4_CH4 (PB9)

**STDOUT** routed to ITM

The board configuration can be modified using 
[STM32CubeMX](https://www.keil.com/stmicroelectronics-stm32) 
and is stored in the file `STCubeGenerated.ioc`.
