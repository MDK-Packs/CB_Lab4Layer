Board: NXP LPCXpresso55S69 (Device: LPC55S69JBD100)
---------------------------------------------------

The board layer for NXP LPCXpresso55S69 is using the software component ::Board Support: SDK Project Template:project_template (Variant: LPC55S69). It is adapted to the interfaces on the Arduino R3 connector as follows:

### GPIO

> Two GPIO pins are used together with the SPI8 interface. They provide the data ready and the slave select signal. They are connected to the Arduino R3 header via the P17 header on the board.

  |Pin Name|Peripheral |Signal       |Route to     |Arduino Pin|
  |:------:|:---------:|:-----------:|:-----------:|:---------:|
  |31      |GPIO       |PIO1, 5      |PIO1_5       |D9         |
  |59      |FLEXCOMM8  |HS_SPI_SSEL1 |HS_SPI_SSEL1 |D10        |

### SPI8

> For Arduino shields using SPI communication, the SPI8 interface is connected to the Arduino R3 header via the P17 header on the board. 

  |Pin Name|Peripheral |Signal      |Route to    |CMSIS-Driver|Arduino Pin|
  |:------:|:---------:|:----------:|:----------:|:----------:|:---------:|
  |60      |FLEXCOMM8  |HS_SPI_MOSI |HS_SPI_MOSI |SPI8        |D11        |
  |61      |FLEXCOMM8  |HS_SPI_SCK  |HS_SPI_SCK  |SPI8        |D13        |
  |62      |FLEXCOMM8  |HS_SPI_MISO |HS_SPI_MISO |SPI8        |D12        |

### USART0

> For the debug console output, the USART0 interface is connected to the DAP-Link debug adapter. 

  |Pin Name|Peripheral   |Signal           |Route to             |CMSIS-Driver|
  |:------:|:-----------:|:---------------:|:-------------------:|:----------:|
  |92      |FLEXCOMM0    |RXD_SDA_MOSI_DATA|FC0_RXD_SDA_MOSI_DATA|USART0      |
  |94      |FLEXCOMM0    |TXD_SDA_MOSI_DATA|FC0_TXD_SDA_MOSI_DATA|USART0      |

- **STDIO** routed to Virtual COM port on the DAP-Link with a baud rate of 115200.

### USART2

> For Arduino shields using USART communication, the USART2 interface is connected to the Arduino R3 header via the P18 header on the board. 

  |Pin Name|Peripheral   |Signal           |Route to             |CMSIS-Driver|Arduino Pin|
  |:------:|:-----------:|:---------------:|:-------------------:|:----------:|:---------:|
  |3       |FLEXCOMM2    |RXD_SDA_MOSI_DATA|FC2_RXD_SDA_MOSI_DATA|USART2      |D0         |
  |27      |FLEXCOMM2    |TXD_SDA_MOSI_DATA|FC2_TXD_SDA_MOSI_DATA|USART2      |D1         |

## Clock Configuration

> To achieve the correct baud rates for the serial interfaces, the clock setup has been changed.

- The clocks **FXCOM0** and **FXCOM2** are set to *48 MHz*.
- The clock **HSLSPI** is set to *???*.

## Modify the board configuration

The board configuration can be modified using [MCUXpresso Config Tools](https://www2.keil.com/nxp) and is stored in the file `LPCXpresso55S69.mex`.

## To Do: the following is not reflected in the IOC file

**CMSIS-Driver VIO** with the following board hardware mapping:
 - vioBUTTON0: Button USER (PIO1_9)
 - vioLED0:    LED RED     (PIO1_6)
 - vioLED1:    LED GREEN   (PIO1_7)
 - vioLED2:    LED BLUE    (PIO1_4)

