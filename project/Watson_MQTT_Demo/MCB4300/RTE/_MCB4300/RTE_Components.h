
/*
 * Auto generated Run-Time-Environment Configuration File
 *      *** Do not modify ! ***
 *
 * Project: 'watson_mqtt_demo' 
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
/*  Keil.ARM Compiler::Compiler:I/O:File:File System:1.2.0 */
#define RTE_Compiler_IO_File            /* Compiler I/O: File */
          #define RTE_Compiler_IO_File_FS         /* Compiler I/O: File (File System) */
/*  Keil.ARM Compiler::Compiler:I/O:STDOUT:ITM:1.2.0 */
#define RTE_Compiler_IO_STDOUT          /* Compiler I/O: STDOUT */
          #define RTE_Compiler_IO_STDOUT_ITM      /* Compiler I/O: STDOUT ITM */
/*  Keil.MDK-Pro::File System:CORE:LFN:6.13.6 */
#define RTE_FileSystem_Core             /* File System Core */
          #define RTE_FileSystem_LFN              /* File System with Long Filename support */
          #define RTE_FileSystem_Release          /* File System Release Version */
/*  Keil.MDK-Pro::File System:Drive:Memory Card:6.13.6 */
#define RTE_FileSystem_Drive_MC_0       /* File System Memory Card Drive 0 */

/*  Keil.MDK-Pro::Network:CORE:IPv4 Release:7.13.1 */
#define RTE_Network_Core                /* Network Core */
          #define RTE_Network_IPv4                /* Network IPv4 Stack */
          #define RTE_Network_Release             /* Network Release Version */
/*  Keil.MDK-Pro::Network:Interface:ETH:7.13.1 */
#define RTE_Network_Interface_ETH_0     /* Network Interface ETH 0 */

/*  Keil.MDK-Pro::Network:Service:DNS Client:7.13.1 */
#define RTE_Network_DNS_Client          /* Network DNS Client */
/*  Keil.MDK-Pro::Network:Socket:BSD:7.13.1 */
#define RTE_Network_Socket_BSD          /* Network Socket BSD */
/*  Keil.MDK-Pro::Network:Socket:TCP:7.13.1 */
#define RTE_Network_Socket_TCP          /* Network Socket TCP */
/*  Keil.MDK-Pro::Network:Socket:UDP:7.13.1 */
#define RTE_Network_Socket_UDP          /* Network Socket UDP */
/*  Keil::CMSIS Driver:Ethernet MAC:2.12 */
#define RTE_Drivers_ETH_MAC0            /* Driver ETH_MAC0 */
/*  Keil::CMSIS Driver:Ethernet PHY:DP83848C:6.2.0 */
#define RTE_Drivers_PHY_DP83848C        /* Driver PHY DP83848C */
/*  Keil::CMSIS Driver:MCI:2.7 */
#define RTE_Drivers_MCI0                /* Driver MCI0 */
/*  Keil::Device:Startup:1.0.0 */
#define RTE_DEVICE_STARTUP_LPC43XX      /* Device Startup for NXP43XX */
/*  MDK-Packs::Data Exchange:JSON:cJSON:1.7.7 */
#define RTE_DataExchange_JSON_cJSON     /* cJSON */
/*  MDK-Packs::IoT Client:MQTTClient-C:1.1.0 */
#define RTE_IoT_Client_MQTTClient_C     /* MQTTClient-C IoT Client */
/*  MDK-Packs::IoT Client:Watson:1.0.0 */
#define RTE_IoT_Client_Watson           /* Watson IoT Client */
        #define MQTTCLIENT_PLATFORM_HEADER      iotf_network_tls_wrapper.h
/*  MDK-Packs::IoT Utility:MQTTPacket:1.1.0 */
#define RTE_IoT_MQTTPacket              /* IoT MQTTPacket */
/*  MDK-Packs::IoT Utility:Socket:MDK Network:1.2.0 */
#define RTE_IoT_Socket                  /* IoT Socket */
        #define RTE_IoT_Socket_MDK_Network      /* IoT Socket: MDK::Network */


#endif /* RTE_COMPONENTS_H */
