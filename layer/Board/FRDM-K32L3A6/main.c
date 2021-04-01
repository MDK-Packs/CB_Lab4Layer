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

#include "main.h"

#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "cmsis_vio.h"
#ifdef RTE_Compiler_EventRecorder
#include "EventRecorder.h"
#endif

#include "clock_config.h"
#include "board.h"
#include "pin_mux.h"
#include "peripherals.h"

// Callbacks for LPUART0 Driver
uint32_t LPUART0_GetFreq   (void) { return BOARD_DEBUG_UART_CLK_FREQ; }
void     LPUART0_InitPins  (void) { /* Done in BOARD_InitDEBUG_UART function */ }
void     LPUART0_DeinitPins(void) { /* Not implemented */ }

// Callbacks for LPUART1 Driver
uint32_t LPUART1_GetFreq   (void) { return BOARD_DEBUG_UART_CLK_FREQ; }
void     LPUART1_InitPins  (void) { /* Done in BOARD_InitARDUINO_UART function */ }
void     LPUART1_DeinitPins(void) { /* Not implemented */ }

// Callbacks for LPSPI0 Driver
uint32_t LPSPI0_GetFreq      (void) { return CLOCK_GetIpFreq(kCLOCK_Lpspi0); }
void     LPSPI0_InitPins     (void) { /* Done in BOARD_InitBootPins function */ }
void     LPSPI0_DeinitPins   (void) { /* Not implemented */ }

int main (void) {

  CLOCK_EnableClock(kCLOCK_Rgpio1);
  BOARD_InitBootPeripherals();
  BOARD_InitBootPins();
  BOARD_InitBootClocks();
  BOARD_InitDebugConsole();

  NVIC_SetPriority(LPUART1_IRQn, 4U);
  NVIC_SetPriority(LPSPI0_IRQn, 4U);

  SystemCoreClockUpdate();

  vioInit();                            // Initialize Virtual I/O

#if defined(RTE_Compiler_EventRecorder) && \
    (defined(__MICROLIB) || \
    !(defined(RTE_CMSIS_RTOS2_RTX5) || defined(RTE_CMSIS_RTOS2_FreeRTOS)))
  EventRecorderInitialize(EventRecordAll, 1U);
#endif

  osKernelInitialize();                 // Initialize CMSIS-RTOS2
  app_initialize();                     // Initialize application
  osKernelStart();                      // Start thread execution

  for (;;) {}
}
