
/*
 * Auto generated Run-Time-Environment Configuration File
 *      *** Do not modify ! ***
 *
 * Project: 'aws_mqtt_demo' 
 * Target:  'MCB4300' 
 */

#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H


/*
 * Define the Device Header File: 
 */
#define CMSIS_device_header "LPC43xx.h"

/*  ARM::CMSIS:RTOS2:Keil RTX5:Library:5.5.2 */
#define RTE_CMSIS_RTOS2                 /* CMSIS-RTOS2 */
        #define RTE_CMSIS_RTOS2_RTX5            /* CMSIS-RTOS2 Keil RTX5 */
/*  ARM::Security:mbed TLS:2.17.0 */
#define RTE_Security_mbedTLS            /* Security mbed TLS */
/*  Keil.ARM Compiler::Compiler:I/O:STDOUT:ITM:1.2.0 */
#define RTE_Compiler_IO_STDOUT          /* Compiler I/O: STDOUT */
          #define RTE_Compiler_IO_STDOUT_ITM      /* Compiler I/O: STDOUT ITM */
/*  Keil::CMSIS Driver:Ethernet MAC:2.12 */
#define RTE_Drivers_ETH_MAC0            /* Driver ETH_MAC0 */
/*  Keil::CMSIS Driver:Ethernet PHY:DP83848C:6.2.0 */
#define RTE_Drivers_PHY_DP83848C        /* Driver PHY DP83848C */
/*  Keil::Device:Startup:1.0.0 */
#define RTE_DEVICE_STARTUP_LPC43XX      /* Device Startup for NXP43XX */
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
/*  MDK-Packs::IoT Utility:Socket:lwIP:1.0.0 */
#define RTE_IoT_Socket                  /* IoT Socket */
        #define RTE_IoT_Socket_lwIP             /* IoT Socket: lwIP */
/*  lwIP.lwIP::Network:API:2.1.2 */
#define RTE_Network_API                 /* Network API */
/*  lwIP.lwIP::Network:CORE:IPv4:2.1.2 */
#define RTE_Network_Core                /* Network Core */
          #define RTE_Network_IPv4                /* Network IPv4 Stack */
/*  lwIP.lwIP::Network:Driver:Ethernet:CMSIS Driver:2.1.2 */
#define RTE_Network_Driver_Ethernet     /* Network Driver Ethernet */
/*  lwIP.lwIP::Network:Interface:Ethernet:2.1.2 */
#define RTE_Network_Interface_Ethernet  /* Network Interface Ethernet */
/*  lwIP.lwIP::Network:RTOS:CMSIS-RTOS2:2.1.2 */
#define RTE_Network_RTOS                /* Network RTOS */
          #define RTE_Network_CMSIS_RTOS2         /* Network CMSIS-RTOS2 */


#endif /* RTE_COMPONENTS_H */
