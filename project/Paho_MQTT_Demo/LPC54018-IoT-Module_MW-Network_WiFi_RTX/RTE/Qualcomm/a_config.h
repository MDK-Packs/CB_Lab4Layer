//------------------------------------------------------------------------------
// Copyright (c) 2017 Qualcomm Technologies, Inc.
// All rights reserved.
// Redistribution and use in source and binary forms, with or without modification, are permitted (subject to the limitations in the disclaimer below) 
// provided that the following conditions are met:
// Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
// Redistributions in binary form must reproduce the above copyright notice, 
// this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
// Neither the name of Qualcomm Technologies, Inc. nor the names of its contributors may be used to endorse or promote products derived 
// from this software without specific prior written permission.
// NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE. 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
// BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, 
// OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//------------------------------------------------------------------------------
// Author(s): ="Atheros"
//
// Modified by Arm
//==============================================================================

#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "QCA400x_Config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ENABLE_FPGA_BUILD 0

#define USE_4BYTE_REGISTER_ACCESS

#define TARGET_AR4100_REV2 0x30000582
#define TARGET_AR400X_REV1 0x31C80997
#define TARGET_AR400X_REV2 0x31C80002
#define TARGET_AR400X_REV3 0x31C8270E
#define TARGET_AR400X_REV4 0x32000052
#define TARGET_AR400X_REV5 0x40000026


#define ATH_FIRMWARE_TARGET TARGET_AR400X_REV1		//TARGET_AR400X_REV2


#define SUPPORT_11N 1



#define A_LITTLE_ENDIAN 1
#define A_BIG_ENDIAN 2

/* PORT_NOTE: Set the following DRIVER_CONFIG_... defines according to
 * 	the requirements/attributes of the OS and MCU. */

/* DRIVER_CONFIG_INCLUDE_BMI - optionally set to 0 if the driver will
 * 	not be used in BMI mode and code space needs to be saved.
 *  If the driver will be used in BMI for flash reprogram or other then
 *	this option must be 1.
 */
#define DRIVER_CONFIG_INCLUDE_BMI				1//1 or 0

/* DRIVER_CONFIG_DISABLE_ASSERT - set to 1 if assert NOP behavior is
 * preferred <not recommended> */
#define DRIVER_CONFIG_DISABLE_ASSERT 			0//1 or 0
/* DRIVER_CONFIG_PROFILE_BOOT - can be used to profile driver boot
 * process with GPIO's + logic analyzer */
#define DRIVER_CONFIG_PROFILE_BOOT 				0//1 or 0
/* DRIVER_CONFIG_ENDIANNESS - set according to host CPU endianness */
#define DRIVER_CONFIG_ENDIANNESS				A_LITTLE_ENDIAN
/* DRIVER_CONFIG_MULTI_TASKING - set according to host OS
 * multi-task support */
#define DRIVER_CONFIG_MULTI_TASKING 		1//1 or 0
/* DRIVER_CONFIG_IMPLEMENT_RX_FREE_QUEUE - set if driver should
 * implement a RX Free Queue */
#define DRIVER_CONFIG_IMPLEMENT_RX_FREE_QUEUE 	1//1 or 0

/*TCPIP stack offload for AR4001*/
#define ENABLE_STACK_OFFLOAD                    WIFI_QCA400x_MODE_INT_STACK //1 or 0

#define T_SELECT_VER1                    	 1//1 or 0
	
/* DRIVER_CONFIG_ENABLE_STORE_RECALL - optionally set to zero to reduce
 * driver memory footprint.
 */
#define DRIVER_CONFIG_ENABLE_STORE_RECALL                       1//1 or 0

#define ENABLE_AP_MODE                      					1 //1 or 0

#define MULTI_SOCKET_SUPPORT									1 //1 or 0

#define MANUFACTURING_SUPPORT                                   1
#define ENABLE_P2P_MODE                                         1 //1 or 0

/* DRIVER_CONFIG_PROGRAM_MAC_ADDR - optionally add code to allow an application
 * to program a new mac address to the wifi device.  this code should only
 * be included when programming a mac address is required such as during
 * production.  otherwise code space can be saved by setting this to 0.
 */
#define DRIVER_CONFIG_PROGRAM_MAC_ADDR							1 //1 or 0

/* DRIVER_CONFIG_ENABLE_HOST_FW_DOWNLOAD is used to enable Firmware download
   from the host. This feature is implemented but kept disable and can be enabled
   on need basis. DO NOT EDIT NEXT LINE INCLUDING THE SPACE. BUILD SCRIPT SEARCHES
   FOR THIS PATTERN AND UPDATES IT IN BUILD TIME. */
#define DRIVER_CONFIG_ENABLE_HOST_FW_DOWNLOAD 0 //1 or 0

#define ENABLE_HTTP_SERVER                      1//1 or 0

#define ENABLE_HTTP_CLIENT                      1//1 or 0

#define ENABLE_DNS_SERVER                       1//1 or 0

#define ENABLE_DNS_CLIENT                       1//1 or 0

#define ENABLE_SNTP_CLIENT                      1//1 or 0

#define ENABLE_RAW_SOCKET_DEMO                  0//1 or 0

#define WLAN_NUM_OF_DEVICES                     1 // Only 1 supported

#define ENABLE_ROUTING_CMDS                        1//1 or 0
#define ENABLE_HTTPS_SERVER                     1//1 or 0

#define ENABLE_HTTPS_CLIENT                     1//1 or 0

#define ENABLE_SSL                              1//1 or 0

#define ENABLE_SCC_MODE                     0//1 or 0
#define ENABLE_KF_PERFORMANCE                   1

#define ENABLE_LARGE_DSET                       1   //1 or 0


/*This macro is used to config the number of rx buffers for multiple socket feature.
*if the rx buffers is low, and multiple sockets are receiving data (especially for multiple TCP RX), 
*the application may be blocked
*/
#define WLAN_CONFIG_RX_BUFFERS 2


#include "wlan_config.h"

#ifdef __cplusplus
}
#endif

#endif
