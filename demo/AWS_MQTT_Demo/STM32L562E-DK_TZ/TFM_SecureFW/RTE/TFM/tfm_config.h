/*
 * Copyright (c) 2019-2020, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TFM_CONFIG_H
#define TFM_CONFIG_H

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

// <c>Bootloader
//#define BL2
// </c>

// <o>TF-M Isolation Level
//   <1=> 1  <2=> 2  <3=> 3
#define TFM_LVL                 1

// <c>Non-Secure Client Identification
//#define TFM_NS_CLIENT_IDENTIFICATION
// </c>

// <o>SPM Log Level
//   <0=> 0 (Silence) <1=> 1 (Error)  <2=> 2 (Info)  <3=> 3 (Debug)
#define TFM_SPM_LOG_LEVEL       2

// <c>Core Debug Messages
//#define TFM_CORE_DEBUG
// </c>

// <o>STDIO USART Driver Number (Driver_USART#) <0-255>
#define STDIO_TFM_USART_DRV_NUM 1

// <o>STDIO USART Baudrate
#define DEFAULT_UART_BAUDRATE   115200U

// <o>Flash Driver Number (Driver_FLASH#) <0-255>
#define FLASH_DRV_NUM           0

// <h>Protected Storage (PS)

//   <o>Flash Driver Number (Driver_FLASH#) <0-255>
#define PS_FLASH_DRV_NUM        0

//   <c>Create Flash Layout
#define PS_CREATE_FLASH_LAYOUT
//   </c>

//   <c>Validate Flash Metadata
//#define PS_VALIDATE_METADATA_FROM_FLASH
//   </c>

//   <c>Rollback Protection
//#define PS_ROLLBACK_PROTECTION
//   </c>

//   <o>Maximum Asset Size
#define PS_MAX_ASSET_SIZE       2048

//   <o>Maximum Number of Assets
#define PS_NUM_ASSETS           8

// </h>

// <h>Internal Trusted Storage (ITS)

//   <o>Flash Driver Number (Driver_FLASH#) <0-255>
#define ITS_FLASH_DRV_NUM       0

//   <c>Create Flash Layout
#define ITS_CREATE_FLASH_LAYOUT
//   </c>

//   <c>Validate Flash Metadata
//#define ITS_VALIDATE_METADATA_FROM_FLASH
//   </c>

//   <o>Maximum Asset Size
#define ITS_MAX_ASSET_SIZE      2048

//   <o>Maximum Number of Assets
#define ITS_NUM_ASSETS          4

// </h>

// <h>Crypto

//   <o>Crypto Engine Buffer Size
#define TFM_CRYPTO_ENGINE_BUF_SIZE      0x4000

//   <o>PSA FF IOVec Buffer Size
#define TFM_CRYPTO_IOVEC_BUFFER_SIZE    5120

//   <c>Disable PSA Cyrpto Key Module
//#define TFM_CRYPTO_KEY_MODULE_DISABLED
//   </c>

//   <c>Disable PSA Cyrpto AEAD Module
//#define TFM_CRYPTO_AEAD_MODULE_DISABLED
//   </c>

//   <c>Disable PSA Cyrpto MAC Module
//#define TFM_CRYPTO_MAC_MODULE_DISABLED
//   </c>

//   <c>Disable PSA Cyrpto Hash Module
//#define TFM_CRYPTO_HASH_MODULE_DISABLED
//   </c>

//   <c>Disable PSA Cyrpto Cipher Module
//#define TFM_CRYPTO_CIPHER_MODULE_DISABLED
//   </c>

//   <c>Disable PSA Cyrpto Key Derivation Module
//#define TFM_CRYPTO_GENERATOR_MODULE_DISABLED
//   </c>

//   <c>Disable PSA Cyrpto Asymmetric Key Module
//#define TFM_CRYPTO_ASYMMETRIC_MODULE_DISABLED
//   </c>

// </h>

// <h>Initial Attestation

//   <c>Include optional Claims
//#define INCLUDE_OPTIONAL_CLAIMS
//   </c>

//   <c>Include COSE Key-id
//#define INCLUDE_COSE_KEY_ID
//   </c>

// </h>

//------------- <<< end of configuration section >>> ---------------------------

#endif /* TFM_CONFIG_H */
