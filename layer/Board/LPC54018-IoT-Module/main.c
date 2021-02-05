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

#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#ifdef RTE_Compiler_EventRecorder
#include "EventRecorder.h"
#endif

#include "clock_config.h"
#include "board.h"
#include "pin_mux.h"
#include "fsl_pint.h"
#include "fsl_inputmux.h"
#include "fsl_inputmux_connections.h"
#include "main.h"

#include "Driver_WiFi.h"

#ifdef RTE_QCA400X_Host_Driver_SDK_SPI
       void PINT_callback(pint_pin_int_t pintr, uint32_t pmatch_status);
extern void WiFi_QCA400x_Pin_INTR (void);

void PINT_callback(pint_pin_int_t pintr, uint32_t pmatch_status) {
  (void)pintr;
  (void)pmatch_status;

  WiFi_QCA400x_Pin_INTR();
}
#endif

// Callbacks for SPI8 Driver
uint32_t SPI8_GetFreq    (void) { return CLOCK_GetFreq(CLOCK_GetFlexCommClkFreq(8)); }
void     SPI8_InitPins   (void) {}
void     SPI8_DeinitPins (void) {}

int main (void) {

  BOARD_InitBootPins();
  BOARD_InitBootClocks();
  BOARD_InitDebugConsole();

#ifdef RTE_QCA400X_Host_Driver_SDK_SPI
  // Setup WiFi module interrupt pin
  INPUTMUX_Init(INPUTMUX);
  INPUTMUX_AttachSignal(INPUTMUX, kPINT_PinInt1, kINPUTMUX_GpioPort1Pin0ToPintsel);
  INPUTMUX_Deinit(INPUTMUX);

  PINT_Init(PINT);
  PINT_PinInterruptConfig(PINT, kPINT_PinInt1, kPINT_PinIntEnableFallEdge, PINT_callback);
  PINT_EnableCallback(PINT);

  NVIC_SetPriority(PIN_INT1_IRQn, 4);
  NVIC_EnableIRQ(PIN_INT1_IRQn);
#endif

  NVIC_SetPriority(FLEXCOMM8_IRQn, 4);

  SystemCoreClockUpdate();

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
