/* -----------------------------------------------------------------------------
 * Copyright (c) 2021 Arm Limited (or its affiliates). All rights reserved.
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
 * -------------------------------------------------------------------------- */

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "rl_net.h"

#define SSID            ""
#define PASSWORD        ""
#define SECURITY_TYPE   netWiFi_SecurityWPA2

int32_t socket_startup (void) {
  NET_WIFI_CONFIG config;

  printf("Connecting to WiFi ...\r\n");

  netInitialize();

  memset((void *)&config, 0, sizeof(config));

  config.ssid     = SSID;
  config.password = PASSWORD;
  config.security = SECURITY_TYPE;
  config.channel  = 0U;

  netWiFi_Activate(0U, &config);

  if (netWiFi_IsConnected(0U) == 0U) {
    printf("WiFi network connection failed!\r\n");
    return (-1);
  } else {
    printf("WiFi network connection succeeded!\r\n");
  }
  return 0;
}
