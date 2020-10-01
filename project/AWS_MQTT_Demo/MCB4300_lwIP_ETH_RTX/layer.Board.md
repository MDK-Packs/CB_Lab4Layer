Board: Keil MCB4300
-------------------

This board layer is composed of components selected using the RTE (Run Time Environment) 
and configured by adapting:
- `startup_LPC43xx.s` (Device:Startup)
- `system_LPC43xx.c` (Device:Startup)
- `RTE_Device.h` (Device:Startup)

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | LPC4357:Cortex-M4
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| PLL0USB                 | 480 MHz
| PLL1                    | 180 MHz
| CPU                     | 180 MHz
| IDIV A                  |  60 MHz
| IDIV B                  |  25 MHz
| IDIV C                  |  12 MHz
| IDIV D                  |  12 MHz
| IDIV E                  | 5.3 MHz

**Note:** configured in system file

### GPIO Configuration and usage

| Peripheral              | Signal          | Pin   | Usage
|:------------------------|:----------------|:------|:-----
| ENET RMII               | ENET_TXD0       | P1_18 | DP83848 pin TXD_0
| ENET RMII               | ENET_TXD1       | P1_20 | DP83848 pin TXD_1
| ENET RMII               | ENET_TX_EN      | P0_1  | DP83848 pin TX_EN
| ENET RMII               | ENET_REF_CLK    | P1_19 | DP83848 pin X1
| ENET RMII               | ENET_RXD0       | P1_15 | DP83848 pin RXD_0
| ENET RMII               | ENET_RXD1       | P0_0  | DP83848 pin RXD_1
| ENET RMII               | ENET_RX_DV      | P1_16 | DP83848 pin RX_DV
| ENET MIIM               | ENET_MDIO       | P1_17 | DP83848 pin MDIO
| ENET MIIM               | ENET_MDC        | PC_1  | DP83848 pin MDC

**Note:** configured in `RTE_Device.h`

### NVIC Configuration

| NVIC Interrupt      | Priority
|:--------------------|:--------
| Ethernet            | 4

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| ETH_MAC0     | Ethernet (ENET)
| ETH_PHY0     | DP83848 (external)

**STDOUT** is routed to ITM
