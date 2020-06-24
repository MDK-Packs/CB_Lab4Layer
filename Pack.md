# Software Packs

The various projects in __CB_Lab4Layer__ are based on software packs that public available.

There are different types of software packs required for working with the Layer examples.

Pack Type    | Description
:------------|:----------------
CMSIS        | Standard CMSIS software pack
RTOS         | CMSIS-RTOS2 implementation for FreeRTOS or RTX
DFP (Device) | Device Family Pack with CMSIS-Driver for UART, SPI, and Ethernet
BSP (Board)  | Board support, optional with CMSIS-Driver VIO for board interface I/O
Network      | Various WiFi chipsets, MDK middleware, or LwIP is supported
Security     | Mbed TLS or Mbed Crypto
Cloud SDK    | SDK for AWS, Azure, Google, MQTT, Watson, (Pelion is in the works)
TFM          | Trusted Firmware for Cortex-M (TF-M) (currently v8-M implementation only)
TFM Platform | Device specific configuration for TF-M

## BSP Board Packs

There are several BSPs published for various boards

Pack                                                                                         | Description
:--------------------------------------------------------------------------------------------|:----------------
[github.com/ARM-software/CMSIS-Musca-S1](https://github.com/ARM-software/CMSIS-Musca-S1)     | for Arm Musca-S1
[github.com/MDK-Packs/LPCXpresso55S69_BSP](https://github.com/MDK-Packs/LPCXpresso55S69_BSP) | for NXP LPCXpresso55S69 (LPC55S69)
[github.com/MDK-Packs/MIMXRT1064-EVK_BSP](https://github.com/MDK-Packs/MIMXRT1064-EVK_BSP)   | for NXP MIMXRT1064-EVK
[github.com/MDK-Packs/B-L475E-IOT01A_BSP](https://github.com/MDK-Packs/B-L475E-IOT01A_BSP)   | for STM32L475 IoT Kit
[github.com/MDK-Packs/STM32L562E-DK_BSP](https://github.com/MDK-Packs/STM32L562E-DK_BSP)     | for STM32L5 Discovery Kit
[github.com/MDK-Packs/NUCLEO-L552ZE-Q_BSP](https://github.com/MDK-Packs/NUCLEO-L552ZE-Q_BSP) | for STM32L5 Nucleo

These packs contain the related CMSIS-Driver VIO for the board implementation, in the directory Drivers/Platform, 
for example github.com/MDK-Packs/B-L475E-IOT01A_BSP/tree/develop/Drivers/Platform 
