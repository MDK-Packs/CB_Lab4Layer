Board: STMicroelectronics NUCLEO-L552ZE-Q (Device : STM32L552ZETxQ)
-------------------------------------------------------------------

The board layer for STMicroelectronics NUCLEO-L552ZE-Q is configured as follows:

## System Core Configuration

### GPIO

> Two GPIO pins are used together with the SPI1 interface. They provide the data ready and the slave select signal. They are connected to the Arduino R3 header via the CN7 header on the board.

|Pin Name|Signal on Pin|GPIO Mode  |User Label    |Output Level|Maximum Output Speed|
|:------:|:-----------:|:---------:|:------------:|:----------:|:------------------:|
|PD14    |N/A          |Output     |ARDUINO_IO_D10|High        |Very High           |
|PD15    |N/A          |Input      |ARDUINO_IO_D9 |N/A         |N/A                 |

### ICACHE

> To speed up the overall processing time, the instruction cache is enabled.

The **Mode** is set to *2-ways associative cache*.

### NVIC

> For the correct operation of the RTOS and the serial interfaces, some interrupts have to be enabled and preemption priorities have to be set right.

|NVIC Interrupt                         |Preemption Priority|
|---------------------------------------|:-----------------:|
|System service call via SWI instruction|6                  |
|Pendable request for system service    |7                  |
|Time base: System tick timer           |7                  |

> Handler generation and calls are configured as follows.

|Interrupt                              |Generate IRQ handler|Call HAL handler|
|---------------------------------------|:------------------:|:--------------:|
|System service call via SWI instruction|disabled            |                |
|Pendable request for system service    |disabled            |                |
|Time base: System tick timer           |disabled            |disabled        |

## Connectivity Configuration

### LPUART1

> The low-power UART is connected to the ST-LINK debug adapter for virtual serial communication. It shows printf debug messages via STDIO. The interface is configured as follows.

- The **Mode** is set to *Asynchronous*.
- The **GPIO Settings** are as follows:
  |Pin Name|Signal on Pin|Interface|CMSIS-Driver|Maximum Output Speed|
  |:------:|:-----------:|:-------:|:----------:|:------------------:|
  |PG7     |LPUART1_TX   |LPUART1  |USART6      |Low                 |
  |PG8     |LPUART1_TX   |LPUART1  |USART6      |Low                 |

### SPI1

> For Arduino shields using SPI communication, the SPI1 interface is connected to the Arduino R3 header via the CN7 header on the board. 

- The **Mode** is set to *Full-Duplex Master*.
- Under **Parameter Settings - Clock Parameters**, the **Prescaler (for Baud Rate)** is set to *4*.
- Under **NVIC Settings**, the **SPI1 global interrupt** is *enabled*.
- The **GPIO Settings** are as follows:
  |Pin Name|Signal on Pin|Interface|CMSIS-Driver|Maximum Output Speed|
  |:------:|:-----------:|:-------:|:----------:|:------------------:|
  |PA5     |SPI1_SCK     |SPI1     |SPI1        |Very High           |
  |PA6     |SPI1_MISO    |SPI1     |SPI1        |Very High           |
  |PA7     |SPI1_MOSI    |SPI1     |SPI1        |Very High           |

### USART3

> For Arduino shields using USART communication, the USART3 interface is connected to the Arduino R3 header via the CN10 header on the board. 

- The **Mode** is set to *Asynchronous*.
- Under **Parameter Settings - Basic Parameters**, the **Baud Rate** is set to *115200*.
- Under **NVIC Settings**, the **USART3 global interrupt** is *enabled*.
- The **GPIO Settings** are as follows:
  |Pin Name|Signal on Pin|Interface|CMSIS-Driver|Maximum Output Speed|
  |:------:|:-----------:|:-------:|:----------:|:------------------:|
  |PD8     |USART3_TX    |USART3   |USART3      |Very High           |
  |PD9     |USART3_RX    |USART3   |USART3      |Very High           |

## Clock Configuration

> To achieve the right baud rates for the serial interfaces, the clock setup has been changed.

The **System Clock Mux** uses the *PLLCLK* and the **PLL - N** multiplier is set to *55*.

## Code Generation and Output Configuration

> For the correct code generation, some configuration settings have been made.

- On the **Project Manager** tab, in the **Code Generator** section, *Add necessary library files as reference in the toolchain project configuration file* has been enabled.
- On the **Project Manager** tab, in the **Advanced Settings** section, *Not Generate Function Call* for **SPI1** and **USART3** has been enabled.

![STM32CubeMX Advanced Settings](./images/captures/NUCLEO-STM32L552ZE-Q/stm32cubemx_config_adv_set.png)

## Modify the board configuration

The board configuration can be modified using [STM32CubeMX](https://www.keil.com/stmicroelectronics-stm32) and is stored in the file `.\RTE\Device\STM32L552ZETxQ\STCubeGenerated\STCubeGenerated.ioc`.

## To Do: the following is not reflected in the IOC file

**CMSIS-Driver VIO** with the following board hardware mapping:
 - vioBUTTON0: Button USER (PC13)
 - vioLED0:    LD3 RED (PA9)
 - vioLED1:    LD1 GREEN (PC7)
 - vioLED2:    LD2 BLUE (PB7)

