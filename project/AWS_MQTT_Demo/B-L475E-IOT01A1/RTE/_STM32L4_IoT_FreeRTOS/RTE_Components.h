
/*
 * Auto generated Run-Time-Environment Configuration File
 *      *** Do not modify ! ***
 *
 * Project: 'aws_mqtt_demo' 
 * Target:  'STM32L4 IoT FreeRTOS' 
 */

#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H


/*
 * Define the Device Header File: 
 */
#define CMSIS_device_header "stm32l4xx.h"

/*  ARM.FreeRTOS::RTOS:Config:CMSIS RTOS2:10.3.1 */
#define RTE_RTOS_FreeRTOS_CONFIG_RTOS2  /* RTOS FreeRTOS Config for CMSIS RTOS2 API */
/*  ARM.FreeRTOS::RTOS:Core:Cortex-M:10.3.1 */
#define RTE_RTOS_FreeRTOS_CORE          /* RTOS FreeRTOS Core */
/*  ARM.FreeRTOS::RTOS:Event Groups:10.3.1 */
#define RTE_RTOS_FreeRTOS_EVENTGROUPS   /* RTOS FreeRTOS Event Groups */
/*  ARM.FreeRTOS::RTOS:Heap:Heap_4:10.3.1 */
#define RTE_RTOS_FreeRTOS_HEAP_4        /* RTOS FreeRTOS Heap 4 */
/*  ARM.FreeRTOS::RTOS:Timers:10.3.1 */
#define RTE_RTOS_FreeRTOS_TIMERS        /* RTOS FreeRTOS Timers */
/*  ARM::CMSIS:RTOS2:FreeRTOS:Cortex-M:10.3.1 */
#define RTE_CMSIS_RTOS2                 /* CMSIS-RTOS2 */
        #define RTE_CMSIS_RTOS2_FreeRTOS        /* CMSIS-RTOS2 FreeRTOS */
/*  ARM::Security:mbed TLS:2.17.0 */
#define RTE_Security_mbedTLS            /* Security mbed TLS */
/*  Keil.ARM Compiler::Compiler:I/O:STDOUT:ITM:1.2.0 */
#define RTE_Compiler_IO_STDOUT          /* Compiler I/O: STDOUT */
          #define RTE_Compiler_IO_STDOUT_ITM      /* Compiler I/O: STDOUT ITM */
/*  Keil::CMSIS Driver:SPI:1.2.0 */
#define RTE_Drivers_SPI1                /* Driver SPI1 */
        #define RTE_Drivers_SPI2                /* Driver SPI2 */
        #define RTE_Drivers_SPI3                /* Driver SPI3 */
/*  Keil::CMSIS Driver:WiFi:ISM43362:SPI:1.8.0 */
#define RTE_Drivers_WiFi_ISM43362_SPI   /* Driver WiFi ISM43362 (SPI) */
/*  Keil::Device:STM32Cube Framework:STM32CubeMX:1.1.0 */
#define RTE_DEVICE_FRAMEWORK_CUBE_MX
/*  Keil::Device:STM32Cube HAL:Common:1.11.0 */
#define RTE_DEVICE_HAL_COMMON
/*  Keil::Device:STM32Cube HAL:Cortex:1.11.0 */
#define RTE_DEVICE_HAL_CORTEX
/*  Keil::Device:STM32Cube HAL:DMA:1.11.0 */
#define RTE_DEVICE_HAL_DMA
/*  Keil::Device:STM32Cube HAL:GPIO:1.11.0 */
#define RTE_DEVICE_HAL_GPIO
/*  Keil::Device:STM32Cube HAL:PWR:1.11.0 */
#define RTE_DEVICE_HAL_PWR
/*  Keil::Device:STM32Cube HAL:RCC:1.11.0 */
#define RTE_DEVICE_HAL_RCC
/*  Keil::Device:STM32Cube HAL:RNG:1.11.0 */
#define RTE_DEVICE_HAL_RNG
/*  Keil::Device:STM32Cube HAL:SPI:1.11.0 */
#define RTE_DEVICE_HAL_SPI
/*  Keil::Device:STM32Cube HAL:UART:1.11.0 */
#define RTE_DEVICE_HAL_UART
/*  Keil::Device:Startup:1.3.1 */
#define RTE_DEVICE_STARTUP_STM32L4XX    /* Device Startup for STM32L4 */
/*  MDK-Packs::IoT Client:AWS:4.0.0 */
#define RTE_IoT_Client_AWS              /* AWS IoT Client */
/*  MDK-Packs::IoT Utility:AWS:Common:1.1.0 */
#define RTE_IoT_AWS_Base                /* AWS Base */
/*  MDK-Packs::IoT Utility:AWS:MQTT:2.1.0 */
#define RTE_IoT_AWS_MQTT                /* AWS MQTT */
/*  MDK-Packs::IoT Utility:AWS:Platform:CMSIS-RTOS2 mbedTLS:1.0.0 */
#define RTE_IoT_AWS_Platform            /* AWS Platform */
        #define RTE_IoT_AWS_Platform_RTOS2      /* AWS Platform CMSIS-RTOS2 */
        #define RTE_IoT_AWS_Platform_mbedTLS    /* AWS Platform mbedTLS */
/*  MDK-Packs::IoT Utility:Socket:WiFi:1.0.0 */
#define RTE_IoT_Socket                  /* IoT Socket */
        #define RTE_IoT_Socket_WiFi             /* IoT Socket: WiFi */


#endif /* RTE_COMPONENTS_H */
