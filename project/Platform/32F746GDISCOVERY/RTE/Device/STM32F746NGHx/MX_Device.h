/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 02/10/2020 08:19:26
 * Description : STM32Cube MX parameter definitions
 * Note        : This file is generated by STM32CubeMX (DO NOT EDIT!)
 ******************************************************************************/

#ifndef __MX_DEVICE_H
#define __MX_DEVICE_H

/*---------------------------- Clock Configuration ---------------------------*/

#define MX_LSI_VALUE                            32000
#define MX_LSE_VALUE                            32768
#define MX_HSI_VALUE                            16000000
#define MX_HSE_VALUE                            25000000
#define MX_EXTERNAL_CLOCK_VALUE                 12288000
#define MX_SYSCLKFreq_VALUE                     216000000
#define MX_HCLKFreq_Value                       216000000
#define MX_FCLKCortexFreq_Value                 216000000
#define MX_CortexFreq_Value                     216000000
#define MX_AHBFreq_Value                        216000000
#define MX_APB1Freq_Value                       54000000
#define MX_APB2Freq_Value                       108000000
#define MX_APB1TimFreq_Value                    108000000
#define MX_APB2TimFreq_Value                    216000000
#define MX_EthernetFreq_Value                   216000000
#define MX_CECFreq_Value                        32786
#define MX_LCDTFToutputFreq_Value               48000000
#define MX_I2C1Freq_Value                       54000000
#define MX_I2C2Freq_Value                       54000000
#define MX_I2C3Freq_Value                       54000000
#define MX_I2C4Freq_Value                       54000000
#define MX_I2SFreq_Value                        96000000
#define MX_SAI1Freq_Value                       96000000
#define MX_SAI2Freq_Value                       96000000
#define MX_SDMMCFreq_Value                      48000000
#define MX_RTCFreq_Value                        32000
#define MX_USART1Freq_Value                     108000000
#define MX_USART2Freq_Value                     54000000
#define MX_USART3Freq_Value                     54000000
#define MX_UART4Freq_Value                      54000000
#define MX_UART5Freq_Value                      54000000
#define MX_UART8Freq_Value                      54000000
#define MX_UART7Freq_Value                      54000000
#define MX_USART6Freq_Value                     108000000
#define MX_USBFreq_Value                        48000000
#define MX_WatchDogFreq_Value                   32000
#define MX_LPTIM1Freq_Value                     54000000
#define MX_SPDIFRXFreq_Value                    96000000
#define MX_MCO1PinFreq_Value                    16000000
#define MX_MCO2PinFreq_Value                    216000000

/*-------------------------------- CORTEX_M7  --------------------------------*/

#define MX_CORTEX_M7                            1

/* GPIO Configuration */

/*-------------------------------- DMA        --------------------------------*/

#define MX_DMA                                  1

/* NVIC Configuration */

/* NVIC DMA1_Stream4_IRQn */
#define MX_DMA1_Stream4_IRQn_interruptPremptionPriority 8
#define MX_DMA1_Stream4_IRQn_PriorityGroup      NVIC_PRIORITYGROUP_4
#define MX_DMA1_Stream4_IRQn_Subriority         0

/* NVIC DMA2_Stream3_IRQn */
#define MX_DMA2_Stream3_IRQn_interruptPremptionPriority 8
#define MX_DMA2_Stream3_IRQn_PriorityGroup      NVIC_PRIORITYGROUP_4
#define MX_DMA2_Stream3_IRQn_Subriority         0

/* NVIC DMA1_Stream3_IRQn */
#define MX_DMA1_Stream3_IRQn_interruptPremptionPriority 8
#define MX_DMA1_Stream3_IRQn_PriorityGroup      NVIC_PRIORITYGROUP_4
#define MX_DMA1_Stream3_IRQn_Subriority         0

/* NVIC DMA2_Stream6_IRQn */
#define MX_DMA2_Stream6_IRQn_interruptPremptionPriority 8
#define MX_DMA2_Stream6_IRQn_PriorityGroup      NVIC_PRIORITYGROUP_4
#define MX_DMA2_Stream6_IRQn_Subriority         0

/*-------------------------------- ETH        --------------------------------*/

#define MX_ETH                                  1

/* GPIO Configuration */

/* Pin PA1 */
#define MX_ETH_REF_CLK_GPIO_Speed               GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH_REF_CLK_Pin                      PA1
#define MX_ETH_REF_CLK_GPIOx                    GPIOA
#define MX_ETH_REF_CLK_GPIO_PuPd                GPIO_NOPULL
#define MX_ETH_REF_CLK_GPIO_Pin                 GPIO_PIN_1
#define MX_ETH_REF_CLK_GPIO_AF                  GPIO_AF11_ETH
#define MX_ETH_REF_CLK_GPIO_Mode                GPIO_MODE_AF_PP

/* Pin PA7 */
#define MX_ETH_CRS_DV_GPIO_Speed                GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH_CRS_DV_Pin                       PA7
#define MX_ETH_CRS_DV_GPIOx                     GPIOA
#define MX_ETH_CRS_DV_GPIO_PuPd                 GPIO_NOPULL
#define MX_ETH_CRS_DV_GPIO_Pin                  GPIO_PIN_7
#define MX_ETH_CRS_DV_GPIO_AF                   GPIO_AF11_ETH
#define MX_ETH_CRS_DV_GPIO_Mode                 GPIO_MODE_AF_PP

/* Pin PC4 */
#define MX_ETH_RXD0_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH_RXD0_Pin                         PC4
#define MX_ETH_RXD0_GPIOx                       GPIOC
#define MX_ETH_RXD0_GPIO_PuPd                   GPIO_NOPULL
#define MX_ETH_RXD0_GPIO_Pin                    GPIO_PIN_4
#define MX_ETH_RXD0_GPIO_AF                     GPIO_AF11_ETH
#define MX_ETH_RXD0_GPIO_Mode                   GPIO_MODE_AF_PP

/* Pin PC5 */
#define MX_ETH_RXD1_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH_RXD1_Pin                         PC5
#define MX_ETH_RXD1_GPIOx                       GPIOC
#define MX_ETH_RXD1_GPIO_PuPd                   GPIO_NOPULL
#define MX_ETH_RXD1_GPIO_Pin                    GPIO_PIN_5
#define MX_ETH_RXD1_GPIO_AF                     GPIO_AF11_ETH
#define MX_ETH_RXD1_GPIO_Mode                   GPIO_MODE_AF_PP

/* Pin PG11 */
#define MX_ETH_TX_EN_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH_TX_EN_Pin                        PG11
#define MX_ETH_TX_EN_GPIOx                      GPIOG
#define MX_ETH_TX_EN_GPIO_PuPd                  GPIO_NOPULL
#define MX_ETH_TX_EN_GPIO_Pin                   GPIO_PIN_11
#define MX_ETH_TX_EN_GPIO_AF                    GPIO_AF11_ETH
#define MX_ETH_TX_EN_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PA2 */
#define MX_ETH_MDIO_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH_MDIO_Pin                         PA2
#define MX_ETH_MDIO_GPIOx                       GPIOA
#define MX_ETH_MDIO_GPIO_PuPd                   GPIO_NOPULL
#define MX_ETH_MDIO_GPIO_Pin                    GPIO_PIN_2
#define MX_ETH_MDIO_GPIO_AF                     GPIO_AF11_ETH
#define MX_ETH_MDIO_GPIO_Mode                   GPIO_MODE_AF_PP

/* Pin PG14 */
#define MX_ETH_TXD1_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH_TXD1_Pin                         PG14
#define MX_ETH_TXD1_GPIOx                       GPIOG
#define MX_ETH_TXD1_GPIO_PuPd                   GPIO_NOPULL
#define MX_ETH_TXD1_GPIO_Pin                    GPIO_PIN_14
#define MX_ETH_TXD1_GPIO_AF                     GPIO_AF11_ETH
#define MX_ETH_TXD1_GPIO_Mode                   GPIO_MODE_AF_PP

/* Pin PG13 */
#define MX_ETH_TXD0_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH_TXD0_Pin                         PG13
#define MX_ETH_TXD0_GPIOx                       GPIOG
#define MX_ETH_TXD0_GPIO_PuPd                   GPIO_NOPULL
#define MX_ETH_TXD0_GPIO_Pin                    GPIO_PIN_13
#define MX_ETH_TXD0_GPIO_AF                     GPIO_AF11_ETH
#define MX_ETH_TXD0_GPIO_Mode                   GPIO_MODE_AF_PP

/* Pin PC1 */
#define MX_ETH_MDC_GPIO_Speed                   GPIO_SPEED_FREQ_VERY_HIGH
#define MX_ETH_MDC_Pin                          PC1
#define MX_ETH_MDC_GPIOx                        GPIOC
#define MX_ETH_MDC_GPIO_PuPd                    GPIO_NOPULL
#define MX_ETH_MDC_GPIO_Pin                     GPIO_PIN_1
#define MX_ETH_MDC_GPIO_AF                      GPIO_AF11_ETH
#define MX_ETH_MDC_GPIO_Mode                    GPIO_MODE_AF_PP

/* NVIC Configuration */

/* NVIC ETH_IRQn */
#define MX_ETH_IRQn_interruptPremptionPriority  8
#define MX_ETH_IRQn_PriorityGroup               NVIC_PRIORITYGROUP_4
#define MX_ETH_IRQn_Subriority                  0

/*-------------------------------- RNG        --------------------------------*/

#define MX_RNG                                  1

/* GPIO Configuration */

/*-------------------------------- SDMMC1     --------------------------------*/

#define MX_SDMMC1                               1

/* GPIO Configuration */

/* Pin PD2 */
#define MX_SDMMC1_CMD_Pin                       PD2
#define MX_SDMMC1_CMD_GPIOx                     GPIOD
#define MX_SDMMC1_CMD_GPIO_PuPd                 GPIO_NOPULL
#define MX_SDMMC1_CMD_GPIO_Speed_High_Default   GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_CMD_GPIO_Pin                  GPIO_PIN_2
#define MX_SDMMC1_CMD_GPIO_AF                   GPIO_AF12_SDMMC1
#define MX_SDMMC1_CMD_GPIO_Mode                 GPIO_MODE_AF_PP

/* Pin PC8 */
#define MX_SDMMC1_D0_Pin                        PC8
#define MX_SDMMC1_D0_GPIOx                      GPIOC
#define MX_SDMMC1_D0_GPIO_PuPd                  GPIO_NOPULL
#define MX_SDMMC1_D0_GPIO_Speed_High_Default    GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_D0_GPIO_Pin                   GPIO_PIN_8
#define MX_SDMMC1_D0_GPIO_AF                    GPIO_AF12_SDMMC1
#define MX_SDMMC1_D0_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PC9 */
#define MX_SDMMC1_D1_Pin                        PC9
#define MX_SDMMC1_D1_GPIOx                      GPIOC
#define MX_SDMMC1_D1_GPIO_PuPd                  GPIO_NOPULL
#define MX_SDMMC1_D1_GPIO_Speed_High_Default    GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_D1_GPIO_Pin                   GPIO_PIN_9
#define MX_SDMMC1_D1_GPIO_AF                    GPIO_AF12_SDMMC1
#define MX_SDMMC1_D1_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PC10 */
#define MX_SDMMC1_D2_Pin                        PC10
#define MX_SDMMC1_D2_GPIOx                      GPIOC
#define MX_SDMMC1_D2_GPIO_PuPd                  GPIO_NOPULL
#define MX_SDMMC1_D2_GPIO_Speed_High_Default    GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_D2_GPIO_Pin                   GPIO_PIN_10
#define MX_SDMMC1_D2_GPIO_AF                    GPIO_AF12_SDMMC1
#define MX_SDMMC1_D2_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PC11 */
#define MX_SDMMC1_D3_Pin                        PC11
#define MX_SDMMC1_D3_GPIOx                      GPIOC
#define MX_SDMMC1_D3_GPIO_PuPd                  GPIO_NOPULL
#define MX_SDMMC1_D3_GPIO_Speed_High_Default    GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_D3_GPIO_Pin                   GPIO_PIN_11
#define MX_SDMMC1_D3_GPIO_AF                    GPIO_AF12_SDMMC1
#define MX_SDMMC1_D3_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PC12 */
#define MX_SDMMC1_CK_Pin                        PC12
#define MX_SDMMC1_CK_GPIOx                      GPIOC
#define MX_SDMMC1_CK_GPIO_PuPd                  GPIO_NOPULL
#define MX_SDMMC1_CK_GPIO_Speed_High_Default    GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_CK_GPIO_Pin                   GPIO_PIN_12
#define MX_SDMMC1_CK_GPIO_AF                    GPIO_AF12_SDMMC1
#define MX_SDMMC1_CK_GPIO_Mode                  GPIO_MODE_AF_PP

/* DMA Configuration */

/* DMA SDMMC1_TX */
#define MX_SDMMC1_TX_DMA_MemBurst               DMA_MBURST_INC4
#define MX_SDMMC1_TX_DMA_Instance               DMA2_Stream6
#define MX_SDMMC1_TX_DMA_FIFOMode               DMA_FIFOMODE_ENABLE
#define MX_SDMMC1_TX_DMA_Priority               DMA_PRIORITY_LOW
#define MX_SDMMC1_TX_DMA_Channel                DMA_CHANNEL_4
#define MX_SDMMC1_TX_DMA_MemDataAlignment       DMA_MDATAALIGN_WORD
#define MX_SDMMC1_TX_DMA_Mode                   DMA_PFCTRL
#define MX_SDMMC1_TX_DMA_Direction              DMA_MEMORY_TO_PERIPH
#define MX_SDMMC1_TX_DMA_PeriphBurst            DMA_PBURST_INC4
#define MX_SDMMC1_TX_DMA_MemInc                 DMA_MINC_ENABLE
#define MX_SDMMC1_TX_DMA_IpInstance
#define MX_SDMMC1_TX_DMA_DMA_Handle
#define MX_SDMMC1_TX_DMA_PeriphDataAlignment    DMA_PDATAALIGN_WORD
#define MX_SDMMC1_TX_DMA_PeriphInc              DMA_PINC_DISABLE
#define MX_SDMMC1_TX_DMA_FIFOThreshold          DMA_FIFO_THRESHOLD_FULL

/* DMA SDMMC1_RX */
#define MX_SDMMC1_RX_DMA_MemBurst               DMA_MBURST_INC4
#define MX_SDMMC1_RX_DMA_Instance               DMA2_Stream3
#define MX_SDMMC1_RX_DMA_FIFOMode               DMA_FIFOMODE_ENABLE
#define MX_SDMMC1_RX_DMA_Priority               DMA_PRIORITY_LOW
#define MX_SDMMC1_RX_DMA_Channel                DMA_CHANNEL_4
#define MX_SDMMC1_RX_DMA_MemDataAlignment       DMA_MDATAALIGN_WORD
#define MX_SDMMC1_RX_DMA_Mode                   DMA_PFCTRL
#define MX_SDMMC1_RX_DMA_Direction              DMA_PERIPH_TO_MEMORY
#define MX_SDMMC1_RX_DMA_PeriphBurst            DMA_PBURST_INC4
#define MX_SDMMC1_RX_DMA_MemInc                 DMA_MINC_ENABLE
#define MX_SDMMC1_RX_DMA_IpInstance
#define MX_SDMMC1_RX_DMA_DMA_Handle
#define MX_SDMMC1_RX_DMA_PeriphDataAlignment    DMA_PDATAALIGN_WORD
#define MX_SDMMC1_RX_DMA_PeriphInc              DMA_PINC_DISABLE
#define MX_SDMMC1_RX_DMA_FIFOThreshold          DMA_FIFO_THRESHOLD_FULL

/* NVIC Configuration */

/* NVIC SDMMC1_IRQn */
#define MX_SDMMC1_IRQn_interruptPremptionPriority 8
#define MX_SDMMC1_IRQn_PriorityGroup            NVIC_PRIORITYGROUP_4
#define MX_SDMMC1_IRQn_Subriority               0

/*-------------------------------- SPI2       --------------------------------*/

#define MX_SPI2                                 1

/* GPIO Configuration */

/* Pin PI1 */
#define MX_SPI2_SCK_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI2_SCK_Pin                         PI1
#define MX_SPI2_SCK_GPIOx                       GPIOI
#define MX_SPI2_SCK_GPIO_PuPd                   GPIO_NOPULL
#define MX_SPI2_SCK_GPIO_Pin                    GPIO_PIN_1
#define MX_SPI2_SCK_GPIO_AF                     GPIO_AF5_SPI2
#define MX_SPI2_SCK_GPIO_Mode                   GPIO_MODE_AF_PP

/* Pin PB14 */
#define MX_SPI2_MISO_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI2_MISO_Pin                        PB14
#define MX_SPI2_MISO_GPIOx                      GPIOB
#define MX_SPI2_MISO_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI2_MISO_GPIO_Pin                   GPIO_PIN_14
#define MX_SPI2_MISO_GPIO_AF                    GPIO_AF5_SPI2
#define MX_SPI2_MISO_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PB15 */
#define MX_SPI2_MOSI_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI2_MOSI_Pin                        PB15
#define MX_SPI2_MOSI_GPIOx                      GPIOB
#define MX_SPI2_MOSI_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI2_MOSI_GPIO_Pin                   GPIO_PIN_15
#define MX_SPI2_MOSI_GPIO_AF                    GPIO_AF5_SPI2
#define MX_SPI2_MOSI_GPIO_Mode                  GPIO_MODE_AF_PP

/* DMA Configuration */

/* DMA SPI2_TX */
#define MX_SPI2_TX_DMA_DMA_Handle
#define MX_SPI2_TX_DMA_Instance                 DMA1_Stream4
#define MX_SPI2_TX_DMA_FIFOMode                 DMA_FIFOMODE_DISABLE
#define MX_SPI2_TX_DMA_Priority                 DMA_PRIORITY_LOW
#define MX_SPI2_TX_DMA_Channel                  DMA_CHANNEL_0
#define MX_SPI2_TX_DMA_PeriphDataAlignment      DMA_PDATAALIGN_BYTE
#define MX_SPI2_TX_DMA_MemDataAlignment         DMA_MDATAALIGN_BYTE
#define MX_SPI2_TX_DMA_Mode                     DMA_NORMAL
#define MX_SPI2_TX_DMA_Direction                DMA_MEMORY_TO_PERIPH
#define MX_SPI2_TX_DMA_PeriphInc                DMA_PINC_DISABLE
#define MX_SPI2_TX_DMA_MemInc                   DMA_MINC_ENABLE
#define MX_SPI2_TX_DMA_IpInstance

/* DMA SPI2_RX */
#define MX_SPI2_RX_DMA_DMA_Handle
#define MX_SPI2_RX_DMA_Instance                 DMA1_Stream3
#define MX_SPI2_RX_DMA_FIFOMode                 DMA_FIFOMODE_DISABLE
#define MX_SPI2_RX_DMA_Priority                 DMA_PRIORITY_LOW
#define MX_SPI2_RX_DMA_Channel                  DMA_CHANNEL_0
#define MX_SPI2_RX_DMA_PeriphDataAlignment      DMA_PDATAALIGN_BYTE
#define MX_SPI2_RX_DMA_MemDataAlignment         DMA_MDATAALIGN_BYTE
#define MX_SPI2_RX_DMA_Mode                     DMA_NORMAL
#define MX_SPI2_RX_DMA_Direction                DMA_PERIPH_TO_MEMORY
#define MX_SPI2_RX_DMA_PeriphInc                DMA_PINC_DISABLE
#define MX_SPI2_RX_DMA_MemInc                   DMA_MINC_ENABLE
#define MX_SPI2_RX_DMA_IpInstance

/* NVIC Configuration */

/* NVIC SPI2_IRQn */
#define MX_SPI2_IRQn_interruptPremptionPriority 8
#define MX_SPI2_IRQn_PriorityGroup              NVIC_PRIORITYGROUP_4
#define MX_SPI2_IRQn_Subriority                 0

/*-------------------------------- SYS        --------------------------------*/

#define MX_SYS                                  1

/* GPIO Configuration */

/*-------------------------------- USART1     --------------------------------*/

#define MX_USART1                               1

#define MX_USART1_VM                            VM_ASYNC

/* GPIO Configuration */

/* Pin PA9 */
#define MX_USART1_TX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART1_TX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART1_TX_Pin                        PA9
#define MX_USART1_TX_GPIOx                      GPIOA
#define MX_USART1_TX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART1_TX_GPIO_Pin                   GPIO_PIN_9
#define MX_USART1_TX_GPIO_AF                    GPIO_AF7_USART1

/* Pin PB7 */
#define MX_USART1_RX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART1_RX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART1_RX_Pin                        PB7
#define MX_USART1_RX_GPIOx                      GPIOB
#define MX_USART1_RX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART1_RX_GPIO_Pin                   GPIO_PIN_7
#define MX_USART1_RX_GPIO_AF                    GPIO_AF7_USART1

/*-------------------------------- USART6     --------------------------------*/

#define MX_USART6                               1

#define MX_USART6_VM                            VM_ASYNC

/* GPIO Configuration */

/* Pin PC7 */
#define MX_USART6_RX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART6_RX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART6_RX_Pin                        PC7
#define MX_USART6_RX_GPIOx                      GPIOC
#define MX_USART6_RX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART6_RX_GPIO_Pin                   GPIO_PIN_7
#define MX_USART6_RX_GPIO_AF                    GPIO_AF8_USART6

/* Pin PC6 */
#define MX_USART6_TX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART6_TX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART6_TX_Pin                        PC6
#define MX_USART6_TX_GPIOx                      GPIOC
#define MX_USART6_TX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART6_TX_GPIO_Pin                   GPIO_PIN_6
#define MX_USART6_TX_GPIO_AF                    GPIO_AF8_USART6

/* NVIC Configuration */

/* NVIC USART6_IRQn */
#define MX_USART6_IRQn_interruptPremptionPriority 8
#define MX_USART6_IRQn_PriorityGroup            NVIC_PRIORITYGROUP_4
#define MX_USART6_IRQn_Subriority               0

/*-------------------------------- NVIC       --------------------------------*/

#define MX_NVIC                                 1

/*-------------------------------- GPIO       --------------------------------*/

#define MX_GPIO                                 1

/* GPIO Configuration */

/* Pin PA15 */
#define MX_PA15_Pin                             PA15
#define MX_PA15_GPIOx                           GPIOA
#define MX_PA15_GPIO_PuPd                       GPIO_NOPULL
#define MX_ARDUINO_IO_D9                        PA15
#define MX_PA15_GPIO_Pin                        GPIO_PIN_15
#define MX_PA15_GPIO_Mode                       GPIO_MODE_INPUT

/* Pin PC13 */
#define MX_PC13_Pin                             PC13
#define MX_PC13_GPIOx                           GPIOC
#define MX_PC13_GPIO_PuPd                       GPIO_NOPULL
#define MX_MemoryCard_CD0                       PC13
#define MX_PC13_GPIO_Pin                        GPIO_PIN_13
#define MX_PC13_GPIO_Mode                       GPIO_MODE_INPUT

/* Pin PI0 */
#define MX_PI0_GPIO_Speed                       GPIO_SPEED_FREQ_VERY_HIGH
#define MX_PI0_Pin                              PI0
#define MX_PI0_GPIOx                            GPIOI
#define MX_PI0_PinState                         GPIO_PIN_SET
#define MX_PI0_GPIO_PuPd                        GPIO_NOPULL
#define MX_ARDUINO_IO_D10                       PI0
#define MX_PI0_GPIO_Pin                         GPIO_PIN_0
#define MX_PI0_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

#endif  /* __MX_DEVICE_H */

