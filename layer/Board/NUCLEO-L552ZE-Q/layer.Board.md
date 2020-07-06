STMicroelectronics NUCLEO-L552ZE-Q Target Board
-----------------------------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART3** routed to Arduino UNO R3 connector (CN10):
 - RX: D0 USART_A_RX (PD9)
 - TX: D1 USART_A_TX (PD8)

**CMSIS-Driver SPI1** routed to Arduino UNO R3 connector (CN7):
 - SCK:  D13 SPI_A_SCK (PA5)
 - MISO: D12 SPI_A_MISO (PA6)
 - MOSI: D11 SPI_A_MOSI (PA7)

**GPIO** pins routed to Arduino UNO R3 connector (CN7):
 - output: D10 SPI_A_CS (PD14)
 - input:  D9 TIM_B_PWM2 (PD15)

**STDOUT** routed to ITM

The board configuration can be modified using 
[STM32CubeMX](https://www.keil.com/stmicroelectronics-stm32) 
and is stored in the file `STCubeGenerated.ioc`.
