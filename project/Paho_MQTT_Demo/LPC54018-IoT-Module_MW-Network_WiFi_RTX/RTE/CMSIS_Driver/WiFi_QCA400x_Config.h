/* -----------------------------------------------------------------------------
 * Copyright © 2019 Arm Limited (or its affiliates). All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * $Date:        27. June 2019
 * $Revision:    V1.0
 *
 * Project:      WiFi Driver Configuration for 
 *               Qualcomm QCA400x WiFi Module
 * -------------------------------------------------------------------------- */

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

#ifndef __WIFI_QCA400x_CONFIG_H
#define __WIFI_QCA400x_CONFIG_H

#include "QCA400x_Config.h"

// <h> WiFi Qualcomm QCA400x Driver Configuration
//   <i> QCA400x SDK can be configured in QCA400x_Config.h
//   <i> QCA400x SDK hardware specific implementation can be adapted in QCA400x_HW.c

//   <o> WiFi Driver Number
//   <i> Configuration settings specifying driver number (default: Driver_WiFi0)
#define WIFI_QCA400x_DRV_NUM                 0

// </h>

// WiFi Connect/Disconnect timeout (default: 30000 ms)
#define WIFI_QCA400x_CON_DISCON_TIMEOUT     (60000U)

// Hostname DNS resolve timeout (default: 5000 ms)
#define WIFI_QCA400x_DNS_RESOLVE_TIMEOUT    (5000U)

// Maximum packet length - in bytes (default: 1576)
#define WIFI_QCA400x_MAX_PACKET_LEN         (1576U)

// Scan Buffer size - in bytes (default: 520, 1 entry occupies 52 bytes)
#define WIFI_QCA400x_SCAN_BUF_LEN           (520U)

#endif // __WIFI_QCA400x_CONFIG_H
