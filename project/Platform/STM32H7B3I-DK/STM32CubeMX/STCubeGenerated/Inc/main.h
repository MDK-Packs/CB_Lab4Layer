/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
extern void app_initialize (void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define WIFI_GPIO_Pin GPIO_PIN_4
#define WIFI_GPIO_GPIO_Port GPIOI
#define I2S6_SDO_Pin GPIO_PIN_14
#define I2S6_SDO_GPIO_Port GPIOG
#define SDIO1_D2_Pin GPIO_PIN_10
#define SDIO1_D2_GPIO_Port GPIOC
#define WIFI_BOOT_Pin GPIO_PIN_3
#define WIFI_BOOT_GPIO_Port GPIOI
#define WIFI_DATRDY_Pin GPIO_PIN_5
#define WIFI_DATRDY_GPIO_Port GPIOI
#define USER_LED1_Pin GPIO_PIN_11
#define USER_LED1_GPIO_Port GPIOG
#define SDIO1_CMD_Pin GPIO_PIN_2
#define SDIO1_CMD_GPIO_Port GPIOD
#define SDIO1_CK_Pin GPIO_PIN_12
#define SDIO1_CK_GPIO_Port GPIOC
#define JTCK_Pin GPIO_PIN_14
#define JTCK_GPIO_Port GPIOA
#define uSD_Detect_Pin GPIO_PIN_8
#define uSD_Detect_GPIO_Port GPIOI
#define JTDO_TRACESWO_Pin GPIO_PIN_3
#define JTDO_TRACESWO_GPIO_Port GPIOB
#define I2S6_SDI_Pin GPIO_PIN_12
#define I2S6_SDI_GPIO_Port GPIOG
#define JTDI_Pin GPIO_PIN_15
#define JTDI_GPIO_Port GPIOA
#define SPI2_SCK_Pin GPIO_PIN_12
#define SPI2_SCK_GPIO_Port GPIOA
#define SPI2_NSS_Pin GPIO_PIN_11
#define SPI2_NSS_GPIO_Port GPIOA
#define I2S6_CK_Pin GPIO_PIN_13
#define I2S6_CK_GPIO_Port GPIOG
#define SDIO1_D3_Pin GPIO_PIN_11
#define SDIO1_D3_GPIO_Port GPIOC
#define WIFI_WKUP_Pin GPIO_PIN_2
#define WIFI_WKUP_GPIO_Port GPIOI
#define WIFI_RST_Pin GPIO_PIN_1
#define WIFI_RST_GPIO_Port GPIOI
#define JTMS_Pin GPIO_PIN_13
#define JTMS_GPIO_Port GPIOA
#define VCP_RX_Pin GPIO_PIN_10
#define VCP_RX_GPIO_Port GPIOA
#define SDIO1_D1_Pin GPIO_PIN_9
#define SDIO1_D1_GPIO_Port GPIOC
#define WAKEUP_Pin GPIO_PIN_13
#define WAKEUP_GPIO_Port GPIOC
#define VCP_TX_Pin GPIO_PIN_9
#define VCP_TX_GPIO_Port GPIOA
#define SDIO1_D0_Pin GPIO_PIN_8
#define SDIO1_D0_GPIO_Port GPIOC
#define MCO_Pin GPIO_PIN_8
#define MCO_GPIO_Port GPIOA
#define AUDIO_NRST_Pin GPIO_PIN_3
#define AUDIO_NRST_GPIO_Port GPIOG
#define USER_LED2_Pin GPIO_PIN_2
#define USER_LED2_GPIO_Port GPIOG
#define SPI2_MISO_Pin GPIO_PIN_2
#define SPI2_MISO_GPIO_Port GPIOC
#define I2C4_SDA_Pin GPIO_PIN_13
#define I2C4_SDA_GPIO_Port GPIOD
#define I2C4_SCL_Pin GPIO_PIN_12
#define I2C4_SCL_GPIO_Port GPIOD
#define SPI2_MOSI_Pin GPIO_PIN_3
#define SPI2_MOSI_GPIO_Port GPIOC
#define I2S6_WS_Pin GPIO_PIN_0
#define I2S6_WS_GPIO_Port GPIOA
#define I2S6_MCK_Pin GPIO_PIN_3
#define I2S6_MCK_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
