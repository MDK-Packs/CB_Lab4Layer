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
#include <stdio.h>
#include <string.h>
#include "cmsis_os2.h"
#include "key_provisioning.h"
#include "iot_config.h"

static const osThreadAttr_t app_main_attr = {
  .stack_size = 4096U
};

/*-----------------------------------------------------------------------------
 * Application main thread
 *----------------------------------------------------------------------------*/
static void app_main (void *argument) {
  int32_t status;

  /* Startup delay */
  osDelay(1000U);

  printf("AWS IoT Key Provisioning \r\n");

  status = xProvisionPrivateKey((const uint8_t *)IOT_DEMO_PRIVATE_KEY,
                                 strlen(IOT_DEMO_PRIVATE_KEY) + 1U);
  if (status == 0) {
    printf("Done. \r\n");
  } else {
    printf("Failed!\r\n");
  }
}

/*-----------------------------------------------------------------------------
 * Application initialization
 *----------------------------------------------------------------------------*/
void app_initialize (void) {
  osThreadNew(app_main, NULL, &app_main_attr);
}
