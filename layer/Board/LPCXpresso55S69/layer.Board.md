Board: NXP LPCXpresso55S69
--------------------------

- The board layer for NXP LPCXpresso55S69 is using the software component `::Board Support: SDK Project Template:project_template (Variant: LPC55S69)`
- It is adapted using [*MCUXPresso Config Tools*](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-config-tools-pins-clocks-peripherals:MCUXpresso-Config-Tools)

### Clock Settings for device LPC55S69JBD100

| Clock Output            | Setting
|:------------------------|:----------------------------------------
| FXCOM0                  | 48 MHz
| FXCOM2                  | 48 MHz
| HLSPI                   | 96 MHz

### GPIO Configuration and Usage

|Pin     |Peripheral |Signal               |CMSIS-Driver|Arduino Pin| Note
|:------:|:--------- |:--------------------|:-----------|:----------|------
|60      |FLEXCOMM8  |HS_SPI_MOSI          |SPI8        | D11       | Arduino UNO R3 connector (P17)
|61      |FLEXCOMM8  |HS_SPI_SCK           |SPI8        | D13       | Arduino UNO R3 connector (P17)
|62      |FLEXCOMM8  |HS_SPI_MISO          |SPI8        | D12       | Arduino UNO R3 connector (P17)
|31      |GPIO       |PIO1_5               |            | D9        | Data ready signal for SPI
|59      |FLEXCOMM8  |HS_SPI_SSEL1         |            | D10       | NSS signal for SPI
|92      |FLEXCOMM0  |FC0_RXD_SDA_MOSI_DATA|USART0      |           | UART for debug console
|94      |FLEXCOMM0  |FC0_TXD_SDA_MOSI_DATA|USART0      |           | UART for debug console
|3       |FLEXCOMM2  |FC2_RXD_SDA_MOSI_DATA|USART2      | D0        | Arduino UNO R3 connector (P18)
|27      |FLEXCOMM2  |FC2_TXD_SDA_MOSI_DATA|USART2      | D1        | Arduino UNO R3 connector (P18)
|1       |GPIO       |PIO1_4               |            |           | LED_BLUE
|5       |GPIO       |PIO1_6               |            |           | LED_RED
|9       |GPIO       |PIO1_7               |            |           | LED_GREEN
|10      |GPIO       |PIO1_9               |            |           | User button S3

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PIO1_9)
| vioLED0           | LED RED     (PIO1_6)
| vioLED1           | LED GREEN   (PIO1_7)
| vioLED2           | LED BLUE    (PIO1_4)
