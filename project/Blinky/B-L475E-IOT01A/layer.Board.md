Board: STMicroelectronics B-L475E-IOT01A
----------------------------------------

The tables below list the device configuration for this board. This setup is configured using **STM32CubeMX**, 
an interactive tool provided by ST for device configuration. Refer to ["Create Projects with STM32Cube HAL and STM32CubeMX"](https://www.keil.com/pack/doc/STM32Cube) for additional information.

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.
**STM32CubeMX** is used for all other settings.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32L475VGtx
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 2 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| HCLK                    | 80 MHz
| FCLK                    | 80 MHz
| APB1                    | 80 MHz
| APB2                    | 80 MHz

### NVIC Configuration

 - Priority Group = 4 bits for preemption priority 0 bits for subpriority

| NVIC Interrupt                          | Preempt Priority | Code Generation
|:----------------------------------------|:-----------------|:---------------
| Non maskable interrupt                  | 0                | Generate IRQ handler
| Hard fault interrupt                    | 0                | Generate IRQ handler
| Memory Management fault                 | 0                | Generate IRQ handler
| Prefetch fault, memory access fault     | 0                | Generate IRQ handler
| Undefined instruction or illegal state  | 0                | Generate IRQ handler
| System service call via SWI instruction | 14               | none
| Debug monitor                           | 0                | Generate IRQ handler
| Pendable request for system service     | 15               | none
| Time base: System tick timer            | 15               | none

### CMSIS-Driver mapping

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD2 GREEN (PB14)
| vioMotionGyro     | ST MEMS gyroscope (LSM6DSL)
| vioMotionAccelero | ST MEMS accelerometer (LSM6DSL)
| vioAIN0           | ST MEMS temperature (HTS221)
| vioAIN1           | ST MEMS barometer (LPS22HB)
| vioAIN2           | ST MEMS humidity (HTS221)
