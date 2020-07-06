Arm Musca-S1 Target Board
-------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver USART1** routed to Virtual COM port (DAPLink):
 - RX: UART1_RX
 - TX: UART1_TX

**CMSIS-Driver USART0** routed to Arduino UNO R3 connector (J15):
 - RX: D0 GPIO0 (PA0)
 - TX: D1 GPIO1 (PA7)

**STDOUT** routed to Virtual COM port (DAPLink, baudrate = 115200)
