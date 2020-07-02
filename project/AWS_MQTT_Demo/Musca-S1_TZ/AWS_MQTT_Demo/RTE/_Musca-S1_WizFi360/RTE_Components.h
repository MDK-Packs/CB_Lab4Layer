
/*
 * Auto generated Run-Time-Environment Configuration File
 *      *** Do not modify ! ***
 *
 * Project: 'aws_mqtt_demo' 
 * Target:  'Musca-S1 WizFi360' 
 */

#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H


/*
 * Define the Device Header File: 
 */
#define CMSIS_device_header "Musca-S1.h"

/*  ARM::CMSIS Driver:USART:1.1.0 */
#define RTE_Drivers_USART
/*  ARM::CMSIS:RTOS2:Keil RTX5:Library_NS:5.5.2 */
#define RTE_CMSIS_RTOS2                 /* CMSIS-RTOS2 */
        #define RTE_CMSIS_RTOS2_RTX5            /* CMSIS-RTOS2 Keil RTX5 */
        #define RTE_CMSIS_RTOS2_RTX5_ARMV8M_NS  /* CMSIS-RTOS2 Keil RTX5 Armv8-M Non-secure domain */
/*  ARM::Security:mbed TLS:2.17.0 */
#define RTE_Security_mbedTLS            /* Security mbed TLS */
/*  ARM::TFM:API:SFN:1.0.0 */
#define RTE_TFM_API_SFN                 /* TF-M API SFN */
/*  Keil.ARM Compiler::Compiler:I/O:STDOUT:User:1.2.0 */
#define RTE_Compiler_IO_STDOUT          /* Compiler I/O: STDOUT */
          #define RTE_Compiler_IO_STDOUT_User     /* Compiler I/O: STDOUT User */
/*  Keil::CMSIS Driver:WiFi:WizFi360:UART:1.4.0 */
#define RTE_Drivers_WiFi_WIZFI360_UART   /* Driver WiFi WIZFI360 (UART) */
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
