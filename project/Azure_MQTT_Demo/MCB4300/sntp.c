/* -----------------------------------------------------------------------------
 * Copyright (c) 2020 Arm Limited (or its affiliates). All rights reserved.
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
#include "iot_socket.h"

/*
  Get current time from SNTP/NTP server
    [in]  server  server name
    [out] seconds pointer to the variable to return time in seconds
                  since January 1st, 1970
    return        0 on success, -1 on error
*/
int32_t sntp_get_time (const char *server, uint32_t *seconds) {
  int32_t  socket;
  uint8_t  buf[48];
  uint8_t  ip[4];
  uint32_t ip_len;
  uint32_t timeout;
  int32_t  status;

  /* Resolve SNTP/NTP server IP address */
  ip_len = 4U;
  status = iotSocketGetHostByName(server, IOT_SOCKET_AF_INET, ip, &ip_len);
  if (status != 0) {
    return (-1);
  }

  /* Compose SNTP request: vers.3, mode=Client */
  memset(buf, 0, sizeof(buf));
  buf[0] = 0x1B;

  /* Create UDP socket */
  socket = iotSocketCreate(IOT_SOCKET_AF_INET, IOT_SOCKET_SOCK_DGRAM, IOT_SOCKET_IPPROTO_UDP);
  if (socket < 0) {
    return (-1);
  }

  /* Set socket receive timeout: 10 seconds */
  timeout = 10000U;
  status = iotSocketSetOpt(socket, IOT_SOCKET_SO_RCVTIMEO, &timeout, sizeof(timeout));
  if (status < 0) {
    iotSocketClose(socket);
    return (-1);
  }

  /* Send SNTP request (port 123) */
  status = iotSocketSendTo(socket, buf, sizeof(buf), ip, sizeof(ip), 123U);
  if (status < 0) {
    iotSocketClose(socket);
    return (-1);
  }

  /* Read SNTP response */
  status = iotSocketRecv(socket, buf, sizeof(buf));
  if (status < 0) {
    iotSocketClose(socket);
    return (-1);
  }

  /* Extract time */
  if (seconds != NULL) {
    *seconds = ((buf[40] << 24) | (buf[41] << 16) | (buf[42] << 8) | buf[43]) - 2208988800U;
  }

  iotSocketClose(socket);

  return 0;
}
