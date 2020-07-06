Keil MCB4300 Target Board
-------------------------
The Board layer contains the following configured interface drivers:

**CMSIS-Driver ETH_MAC0** controlling the DP83848 Ethernet PHY (IC6):
 - ENET_TXD0:    P1_18
 - ENET_TXD1:    P1_20
 - ENET_TX_EN:   P0_1
 - ENET_REF_CLK: P1_19
 - ENET_RXD0:    P1_15
 - ENET_RXD1:    P0_0
 - ENET_RX_DV:   P1_16
 - ENET_MDIO:    P1_17
 - ENET_MDC:     PC_1

**CMSIS-Driver ETH_PHY0** routed to RJ45 connector (P6)

**CMSIS-Driver MCI0** routed to memory card socket (J39):
 - SD_CLK:   PC_0
 - SD_CMD:   PC_10
 - SD_DATA0: PC_4
 - SD_DATA1: PC_5
 - SD_DATA2: PC_6
 - SD_DATA3: PC_7
 - SD_CD:    PC_8

**STDOUT** routed to ITM
