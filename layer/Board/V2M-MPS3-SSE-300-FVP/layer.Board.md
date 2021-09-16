Board: ARM V2M-MPS3-SSE-300-FVP
----------------------------------------------

MPS3 platform for Corstone-300 simulated by Fixed Virtual Platform (FVP).

Running the FVP in uVision requires the following settings:
 - open "Options for Target"
 - select "Debug" tab
 - under "Use" select "Models ARMv8-M Debugger" and click "Settings" end enter the following:
   - Command: C:\Program Files\ARM\FVP_Corstone_SSE-300\models\Win64_VC2017\FVP_Corstone_SSE-300_Ethos-U55.exe (when FVP is installed in default directory)
   - Target: cpu0
   - Configuration File: fvp_config.txt

Running the FVP via command line (from project root directory and FVP executable in path):
 - `FVP_Corstone_SSE-300_Ethos-U55.exe -a Objects\image.axf` when using telnet as UART0 output or
 - `FVP_Corstone_SSE-300_Ethos-U55.exe -C mps3_board.telnetterminal0.start_telnet=0 -C mps3_board.uart0.out_file=- -a Objects\image.axf` when using stdout as UART0 output

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | SSE-3000-MPS3
| Clock                   | 32 MHz
| Heap                    | 64 kB (configured in region_limit.h file)
| Stack (MSP)             | 1 kB (configured in region_limit.h file)

**STDIO** is routed to USART0

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| ETH_MAC0     | Ethernet LAN91C111
| ETH_PHY0     | Ethernet LAN91C111
| USART0       | USART0

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | User Button PB1
| vioBUTTON1        | User Button PB2
| vioLED0           | User LED UL0
| vioLED1           | User LED UL1
| vioLED2           | User LED UL2
| vioLED3           | User LED UL3
| vioLED4           | User LED UL4
| vioLED5           | User LED UL5
| vioLED6           | User LED UL6
| vioLED7           | User LED UL7
