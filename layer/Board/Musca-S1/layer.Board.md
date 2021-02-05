Board: Arm Musca-S1
-------------------

The tables below list the device configuration for this board.

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | Musca-S1:CM33-0
| Heap                    | 64 kB (configured in linker scatter file)
| Stack (MSP)             | 1 kB (configured in linker scatter file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| System                  | 50 MHz

### GPIO Configuration and usage

| Peripheral              | Signal          | Pin   | Usage
|:------------------------|:----------------|:------|:-----
| UART0                   | USART0_RX       | PA0   | Arduino UNO R3 pin D0 (RX)
| UART0                   | USART0_TX       | PA1   | Arduino UNO R3 pin D1 (TX)
| UART1                   | USART1_RX       | PA16  | DAPLink Virtual COM port (UART1_RX_HW)
| UART1                   | USART1_TX       | PA17  | DAPLink Virtual COM port (UART1_TX_HW)

**Note:** configured in `RTE_Device.h`

### NVIC Configuration

| NVIC Interrupt      | Priority
|:--------------------|:--------
| UART0               | 4

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| USART0       | UART0

**STDOUT** is routed to Virtual COM port (DAPLink, baudrate = 115200)
