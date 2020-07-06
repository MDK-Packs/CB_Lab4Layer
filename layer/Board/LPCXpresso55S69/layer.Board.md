NXP LPCXpresso55S69 Target Board
--------------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART2** routed to Arduino UNO R3 connector (P18):
 - RX: D0 PLU_OUT6/GPIO/FC2_USART_RXD_ARD
 - TX: D1 FC2_USART_TXD_ARD

**STDOUT** routed to Virtual COM port (DAP-Link, baudrate = 115200)

The board configuration can be modified using [MCUxpresso](https://www.keil.com/nxp)
and is stored in the file `LPCXpresso55S69.mex`.
