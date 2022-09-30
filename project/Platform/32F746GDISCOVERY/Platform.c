/*---------------------------------------------------------------------------
 * Copyright (c) 2010-2021 Arm Limited (or its affiliates). 
 * All rights reserved.
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
 *---------------------------------------------------------------------------*/

#include "main.h"

#include "cmsis_os2.h"

static const osThreadAttr_t app_main_attr = {
  .stack_size = 4096U
};

/*---------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/
static void app_main (void *argument) {
  (void)argument;

  // Add user code here:
  for (;;) {}
}

/*---------------------------------------------------------------------------
 * Application initialization
 *---------------------------------------------------------------------------*/
void app_initialize (void) {
  osThreadNew(app_main, NULL, &app_main_attr);
}
