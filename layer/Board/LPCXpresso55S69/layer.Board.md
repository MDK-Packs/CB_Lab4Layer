NXP LPCXpresso55S69 Target Board
--------------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART2** routed to Arduino UNO R3 connector (P18):
 - RX:         D0  (PLU_OUT6/GPIO/FC2_USART_RXD_ARD)
 - TX:         D1  (FC2_USART_TXD_ARD)

**CMSIS-Driver SPI8** routed to Arduino UNO R3 connector (P17):
 - SCK:        D13 (LSPI_HS_SCK)
 - MISO:       D12 (LSPI_HS_MISO)
 - MOSI:       D11 (LSPI_HS_MOSI)

**GPIO** pins routed to Arduino UNO R3 connector (P17):
 - output:     D10 (LSPI_HS_SSEL1)
 - input:      D9  (PIO1_5_GPIO_ARD)

**CMSIS-Driver VIO** with the following board hardware mapping:
 - vioBUTTON0: Button USER (PIO1_9)
 - vioLED0:    LED RED     (PIO1_6)
 - vioLED1:    LED GREEN   (PIO1_7)
 - vioLED2:    LED BLUE    (PIO1_4)

**STDIO** routed to Virtual COM port (DAP-Link, baudrate = 115200)

The board configuration can be modified using 
[MCUxpresso](https://www.keil.com/nxp) 
and is stored in the file `LPCXpresso55S69.mex`.
