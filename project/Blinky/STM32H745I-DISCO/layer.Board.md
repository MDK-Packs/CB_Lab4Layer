Board: STMicroelectronics STM32H745I-DISCO
------------------------------------------

The tables below list the device configuration for this board.

The heap/stack setup is in configuration files of related software components.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32H745XIHx
| ICACHE                  | enabled
| DCACHE                  | enabled
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| SYSCLK                  | 400 MHz (Cortex-M7 CPU Clock)
| HCLK                    | 200 MHz (Cortex-M4 CPU, Bus matrix Clocks)
| APB1                    | 100 MHz
| APB2                    | 100 MHz
| APB3                    | 100 MHz

### CMSIS-Driver mapping

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD6 RED (PJ2)
| vioLED1           | LD7 RED (PI13)
