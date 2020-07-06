STMicroelectronics 32F746GDISCOVERY Target Board
------------------------------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART6** routed to Arduino UNO R3 connector (CN4):
 - RX: D0 USART6_RX (PC7)
 - TX: D1 USART6_TX (PC6)

**CMSIS-Driver MCI0** routed to memory card socket (CN3):
 - DATA0: SDMMC_D0 (PC8)
 - DATA1: SDMMC_D1 (PC9)
 - DATA2: SDMMC_D2 (PC10)
 - DATA3: SDMMC_D3 (PC11)
 - CMD:   SDMMC_CMD (PD2)
 - CLK:   SDMMC_CK (PC12)
 - CD:    MicroSDcard_detect (PC13)

**STDOUT** routed to ITM

The board configuration can be modified using 
[STM32CubeMX](https://www.keil.com/stmicroelectronics-stm32) 
and is stored in the file `STCubeGenerated.ioc`.
