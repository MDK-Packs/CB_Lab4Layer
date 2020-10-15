Board: Keil MCB4300
-------------------

The tables below list the device configuration for this board. This board layer is composed of components selected using the RTE (Run Time Environment) and configured by adapting:
- `startup_LPC43xx.s` (Device:Startup)
- `system_LPC43xx.c` (Device:Startup)
- `RTE_Device.h` (Device:Startup)

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.

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
| SD/MMC                  | SD_CLK          | PC_0  | SD Card socket pin CLK
| SD/MMC                  | SD_CMD          | PC_10 | SD Card socket pin CMD
| SD/MMC                  | SD_DATA0        | PC_4  | SD Card socket pin D0
| SD/MMC                  | SD_DATA1        | PC_5  | SD Card socket pin D1
| SD/MMC                  | SD_DATA2        | PC_6  | SD Card socket pin D2
| SD/MMC                  | SD_DATA3        | PC_7  | SD Card socket pin D3
| SD/MMC                  | SD_CD           | PC_8  | SD Card socket pin CD

**Note:** configured in `RTE_Device.h`

### NVIC Configuration

| NVIC Interrupt      | Priority
|:--------------------|:--------
| Ethernet            | 4
| SDIO                | 4

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| ETH_MAC0     | Ethernet (ENET)
| ETH_PHY0     | DP83848 (external)
| MCI0         | SD/MMC

**STDOUT** is routed to ITM
