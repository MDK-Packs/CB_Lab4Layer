/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 23/01/2020 10:54:30
 * Description : STM32Cube MX parameter definitions
 * Note        : This file is generated by STM32CubeMX (DO NOT EDIT!)
 ******************************************************************************/

#ifndef __MX_DEVICE_H
#define __MX_DEVICE_H

/*---------------------------- Clock Configuration ---------------------------*/

#define MX_LSI_VALUE                            32000
#define MX_LSE_VALUE                            32768
#define MX_HSI_VALUE                            16000000
#define MX_HSE_VALUE                            8000000
#define MX_SYSCLKFreq_VALUE                     80000000
#define MX_HCLKFreq_Value                       80000000
#define MX_FCLKCortexFreq_Value                 80000000
#define MX_CortexFreq_Value                     80000000
#define MX_AHBFreq_Value                        80000000
#define MX_APB1Freq_Value                       80000000
#define MX_APB2Freq_Value                       80000000
#define MX_APB1TimFreq_Value                    80000000
#define MX_APB2TimFreq_Value                    80000000
#define MX_PWRFreq_Value                        80000000
#define MX_RTCFreq_Value                        32000
#define MX_USBFreq_Value                        48000000
#define MX_WatchDogFreq_Value                   32000
#define MX_MCO1PinFreq_Value                    80000000

/*-------------------------------- DMA        --------------------------------*/

#define MX_DMA                                  1

/* NVIC Configuration */

/* NVIC DMA2_Channel2_IRQn */
#define MX_DMA2_Channel2_IRQn_interruptPremptionPriority 7
#define MX_DMA2_Channel2_IRQn_PriorityGroup     NVIC_PRIORITYGROUP_4
#define MX_DMA2_Channel2_IRQn_Subriority        0

/* NVIC DMA2_Channel1_IRQn */
#define MX_DMA2_Channel1_IRQn_interruptPremptionPriority 7
#define MX_DMA2_Channel1_IRQn_PriorityGroup     NVIC_PRIORITYGROUP_4
#define MX_DMA2_Channel1_IRQn_Subriority        0

/*-------------------------------- RNG        --------------------------------*/

#define MX_RNG                                  1

/* GPIO Configuration */

/*-------------------------------- SPI3       --------------------------------*/

#define MX_SPI3                                 1

/* GPIO Configuration */

/* Pin PC10 */
#define MX_SPI3_SCK_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI3_SCK_Pin                         PC10
#define MX_SPI3_SCK_GPIOx                       GPIOC
#define MX_SPI3_SCK_GPIO_PuPd                   GPIO_NOPULL
#define MX_SPI3_SCK_GPIO_Pin                    GPIO_PIN_10
#define MX_SPI3_SCK_GPIO_AF                     GPIO_AF6_SPI3
#define MX_SPI3_SCK_GPIO_Mode                   GPIO_MODE_AF_PP

/* Pin PC11 */
#define MX_SPI3_MISO_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI3_MISO_Pin                        PC11
#define MX_SPI3_MISO_GPIOx                      GPIOC
#define MX_SPI3_MISO_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI3_MISO_GPIO_Pin                   GPIO_PIN_11
#define MX_SPI3_MISO_GPIO_AF                    GPIO_AF6_SPI3
#define MX_SPI3_MISO_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PC12 */
#define MX_SPI3_MOSI_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI3_MOSI_Pin                        PC12
#define MX_SPI3_MOSI_GPIOx                      GPIOC
#define MX_SPI3_MOSI_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI3_MOSI_GPIO_Pin                   GPIO_PIN_12
#define MX_SPI3_MOSI_GPIO_AF                    GPIO_AF6_SPI3
#define MX_SPI3_MOSI_GPIO_Mode                  GPIO_MODE_AF_PP

/* DMA Configuration */

/* DMA SPI3_RX */
#define MX_SPI3_RX_DMA_DMA_Handle               
#define MX_SPI3_RX_DMA_Instance                 DMA2_Channel1
#define MX_SPI3_RX_DMA_NoTestForDmaSupport      false
#define MX_SPI3_RX_DMA_Priority                 DMA_PRIORITY_LOW
#define MX_SPI3_RX_DMA_PeriphDataAlignment      DMA_PDATAALIGN_BYTE
#define MX_SPI3_RX_DMA_MemDataAlignment         DMA_MDATAALIGN_BYTE
#define MX_SPI3_RX_DMA_Mode                     DMA_NORMAL
#define MX_SPI3_RX_DMA_Request                  DMA_REQUEST_3
#define MX_SPI3_RX_DMA_Direction                DMA_PERIPH_TO_MEMORY
#define MX_SPI3_RX_DMA_PeriphInc                DMA_PINC_DISABLE
#define MX_SPI3_RX_DMA_MemInc                   DMA_MINC_ENABLE
#define MX_SPI3_RX_DMA_IpInstance               

/* DMA SPI3_TX */
#define MX_SPI3_TX_DMA_DMA_Handle               
#define MX_SPI3_TX_DMA_Instance                 DMA2_Channel2
#define MX_SPI3_TX_DMA_NoTestForDmaSupport      false
#define MX_SPI3_TX_DMA_Priority                 DMA_PRIORITY_LOW
#define MX_SPI3_TX_DMA_PeriphDataAlignment      DMA_PDATAALIGN_BYTE
#define MX_SPI3_TX_DMA_MemDataAlignment         DMA_MDATAALIGN_BYTE
#define MX_SPI3_TX_DMA_Mode                     DMA_NORMAL
#define MX_SPI3_TX_DMA_Request                  DMA_REQUEST_3
#define MX_SPI3_TX_DMA_Direction                DMA_MEMORY_TO_PERIPH
#define MX_SPI3_TX_DMA_PeriphInc                DMA_PINC_DISABLE
#define MX_SPI3_TX_DMA_MemInc                   DMA_MINC_ENABLE
#define MX_SPI3_TX_DMA_IpInstance               

/* NVIC Configuration */

/* NVIC SPI3_IRQn */
#define MX_SPI3_IRQn_interruptPremptionPriority 8
#define MX_SPI3_IRQn_PriorityGroup              NVIC_PRIORITYGROUP_4
#define MX_SPI3_IRQn_Subriority                 0

/*-------------------------------- SYS        --------------------------------*/

#define MX_SYS                                  1

/* GPIO Configuration */

/*-------------------------------- USART1     --------------------------------*/

#define MX_USART1                               1

#define MX_USART1_VM                            VM_ASYNC

/* GPIO Configuration */

/* Pin PB6 */
#define MX_USART1_TX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART1_TX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART1_TX_GPIO_FM6                   __NULL
#define MX_USART1_TX_Pin                        PB6
#define MX_USART1_TX_GPIOx                      GPIOB
#define MX_USART1_TX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART1_TX_GPIO_Pin                   GPIO_PIN_6
#define MX_USART1_TX_GPIO_AF                    GPIO_AF7_USART1

/* Pin PB7 */
#define MX_USART1_RX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART1_RX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART1_RX_Pin                        PB7
#define MX_USART1_RX_GPIOx                      GPIOB
#define MX_USART1_RX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART1_RX_GPIO_Pin                   GPIO_PIN_7
#define MX_USART1_RX_GPIO_AF                    GPIO_AF7_USART1
#define MX_USART1_RX_GPIO_FM7                   __NULL

/*-------------------------------- USART3     --------------------------------*/

#define MX_USART3                               1

#define MX_USART3_VM                            VM_ASYNC

/* GPIO Configuration */

/* Pin PD8 */
#define MX_USART3_TX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART3_TX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART3_TX_Pin                        PD8
#define MX_USART3_TX_GPIOx                      GPIOD
#define MX_USART3_TX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART3_TX_GPIO_Pin                   GPIO_PIN_8
#define MX_USART3_TX_GPIO_AF                    GPIO_AF7_USART3

/* Pin PD9 */
#define MX_USART3_RX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART3_RX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART3_RX_Pin                        PD9
#define MX_USART3_RX_GPIOx                      GPIOD
#define MX_USART3_RX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART3_RX_GPIO_Pin                   GPIO_PIN_9
#define MX_USART3_RX_GPIO_AF                    GPIO_AF7_USART3

/*-------------------------------- NVIC       --------------------------------*/

#define MX_NVIC                                 1

/*-------------------------------- GPIO       --------------------------------*/

#define MX_GPIO                                 1

/* GPIO Configuration */

/* Pin PB13 */
#define MX_PB13_GPIO_Speed                      GPIO_SPEED_FREQ_LOW
#define MX_PB13_Pin                             PB13
#define MX_PB13_GPIOx                           GPIOB
#define MX_PB13_PinState                        GPIO_PIN_RESET
#define MX_PB13_GPIO_PuPd                       GPIO_NOPULL
#define MX_ISM43362_WAKEUP                      PB13
#define MX_PB13_GPIO_Pin                        GPIO_PIN_13
#define MX_PB13_GPIO_ModeDefaultOutputPP        GPIO_MODE_OUTPUT_PP

/* Pin PE8 */
#define MX_PE8_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PE8_Pin                              PE8
#define MX_PE8_GPIOx                            GPIOE
#define MX_PE8_PinState                         GPIO_PIN_RESET
#define MX_PE8_GPIO_PuPd                        GPIO_NOPULL
#define MX_ISM43362_RESET                       PE8
#define MX_PE8_GPIO_Pin                         GPIO_PIN_8
#define MX_PE8_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PE0 */
#define MX_PE0_GPIO_Speed                       GPIO_SPEED_FREQ_VERY_HIGH
#define MX_PE0_Pin                              PE0
#define MX_PE0_GPIOx                            GPIOE
#define MX_PE0_PinState                         GPIO_PIN_RESET
#define MX_PE0_GPIO_PuPd                        GPIO_NOPULL
#define MX_ISM43362_SPI_NSS                     PE0
#define MX_PE0_GPIO_Pin                         GPIO_PIN_0
#define MX_PE0_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PE1 */
#define MX_PE1_Pin                              PE1
#define MX_PE1_GPIOx                            GPIOE
#define MX_PE1_GPIO_PuPd                        GPIO_NOPULL
#define MX_ISM43362_DATARDY                     PE1
#define MX_PE1_GPIO_Pin                         GPIO_PIN_1
#define MX_PE1_GPIO_ModeDefaultEXTI             GPIO_MODE_IT_RISING

#endif  /* __MX_DEVICE_H */

