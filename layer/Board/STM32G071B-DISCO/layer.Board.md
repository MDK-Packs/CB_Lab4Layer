Board: STMicroelectronics STM32G071B-DISCO
------------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**,
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information.

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32G071RBTx
| Heap                    | 1 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HCLK                    | 64 MHz
| FCLK                    | 64 MHz
| APB pripherals          | 64 MHz
| APB timers              | 64 MHz
| To USART3               | 64 MHz

### GPIO Configuration and usage

| GPIO | Signal / Label   | GPIO Settings                                 | Usage
|:-----|:-----------------|:----------------------------------------------|:-----
| PC10 | USART3_TX        | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (VCP_TX)
| PC11 | USART3_RX        | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (VCP_RX)
} PC8  | vioBUTTON0       | Joystick SELECT, with define VIO_BUTTON_REMAP | User button
| PC4  | vioJOYup         | not configured via CubeMX                     | Joystic UP
| PC2  | vioJOYdown       | not configured via CubeMX                     | Joystic DOWN
| PC1  | vioJOYleft       | not configured via CubeMX                     | Joystic LEFT
| PC3  | vioJOYright      | not configured via CubeMX                     | Joystic RIGHT
| PC0  | vioJOYselect     | not configured via CubeMX                     | Joystic SELECT
| PD9  | vioLED0          | not configured via CubeMX                     | LD4 ORANGE
| PD8  | vioLED1          | not configured via CubeMX                     | LD5 ORANGE
| PD5  | vioLED2          | not configured via CubeMX                     | LD6 GREEN
| PC12 | vioLED3          | not configured via CubeMX                     | LD7 GREEN

### NVIC Configuration

 - Priority Group = 3 bits for preemption priority 0 bits for subpriority

| NVIC Interrupt                          | Preempt Priority | Code Generation
|:----------------------------------------|:-----------------|:---------------
| Non maskable interrupt                  | 0                | Generate IRQ handler
| Hard fault interrupt                    | 0                | Generate IRQ handler
| System service call via SWI instruction | 0                | none
| Pendable request for system service     | 0                | none
| Time base: System tick timer            | 0                | none

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:----|:----
| USART3       | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no  | ST-LINK Virtual COM port

**STDIO** is routed to ST-LINK Virtual COM port (USART3)

### CMSIS-Driver mapping

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Joystick SELECT, with define VIO_BUTTON_REMAP
| vioJOYup          | Joystic UP (PC4) 
| vioJOYdown        | Joystic DOWN (PC2) 
| vioJOYleft        | Joystic LEFT (PC1) 
| vioJOYright       | Joystic RIGHT (PC3) 
| vioJOYselect      | Joystic SELECT (PC0) 
| vioLED0           | LD4 ORANGE (PD9) 
| vioLED1           | LD5 ORANGE (PD8) 
| vioLED2           | LD6 GREEN (PD5) 
| vioLED3           | LD7 GREEN (PC12)
