/* -----------------------------------------------------------------------------
 * Copyright (c) 2013-2019 Arm Limited
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software. Permission is granted to anyone to use this
 * software for any purpose, including commercial applications, and to alter
 * it and redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software in
 *    a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 *
 *
 * $Date:        14. February 2019
 * $Revision:    V1.0
 *
 * Project:      Driver Configuration for 
 *               Qualcomm QCA400x WiFi Module
 * -------------------------------------------------------------------------- */

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

#ifndef __QCA400x_CONFIG_H
#define __QCA400x_CONFIG_H

// <h> WiFi Qualcomm QCA400x Driver Configuration (SPI variant)

//   <o> SPI Driver Number
//   <i> Configuration settings specifying index of SPI driver used (if Module uses SPI interface)
#define WIFI_QCA400x_SPI_DRV_NUM            8

//   <o> Mode <0=>Internal Network Stack <1=>Pass-through
//   <i> Internal Network Stack: Socket functions available.
//   <i> Pass-through: Transmit and Receive Ethernet Frames. Internal Network stack is bypassed.
#define WIFI_QCA400x_MODE                   (1U)
#if (WIFI_QCA400x_MODE == 0U)
#define WIFI_QCA400x_MODE_INT_STACK         (1U)
#define WIFI_QCA400x_MODE_PASSTHROUGH       (0U)
#else
#define WIFI_QCA400x_MODE_INT_STACK         (0U)
#define WIFI_QCA400x_MODE_PASSTHROUGH       (1U)
#endif

// </h>

// SPI mutex acquire timeout (default: 3000 ms)
#define WIFI_QCA400x_SPI_TIMEOUT            (3000)

// SPI transfer timeout - max time to complete SPI transfer (default: 3000 ms)
#define WIFI_QCA400x_SPI_COMPLETED_TIMEOUT  (3000)

#endif // __QCA400x_CONFIG_H
