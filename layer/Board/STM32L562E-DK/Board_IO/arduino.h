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

/**
  \fn          void ARDUINO_SPI_A_CS (uint32_t ss)
  \brief       Drive SPI_A_CS Slave Select line.
  \param[in]   ss
                 - value = 0: not active
                 - value = 1: active state
  \return      none
*/
void ARDUINO_SPI_A_CS (uint32_t ss);

/**
  \fn          uint32_t ARDUINO_IO_D9_Get (void)
  \brief       Get IO_D9 line state.
  \return      IO_D9 line state
                 - 0
                 - 1
*/
uint32_t ARDUINO_IO_D9_Get (void);
