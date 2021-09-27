/*---------------------------------------------------------------------------
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
 *---------------------------------------------------------------------------*/

#include "stm32l4r9i_discovery_io.h"

#if defined MemoryCard_CD0_Pin_Extern
/**
  Function used to read Card Detect (CD) pin state when
  Memory Card is used in MCI mode.
  \param[in]  instance  MCI driver instance number (0:SDMMC1, 1:SDMMC2)
  \return     1:card detected, 0:card not detected, or error
*/
int32_t MCI_ReadCD (uint32_t instance) {
  (void)instance;
  int32_t tmp = 0;

  if (BSP_IO_ReadPin(SD_DETECT_PIN) == IO_PIN_RESET) {
    /* Card present */
    tmp = 1;
  }
  else {
    /* Card not present */
    tmp = 0;
  }

  return (tmp);
}
#endif
