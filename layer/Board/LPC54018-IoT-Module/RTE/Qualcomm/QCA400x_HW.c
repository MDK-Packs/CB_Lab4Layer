/* -----------------------------------------------------------------------------
 * Copyright (c) 2021 Arm Limited
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
 * $Date:        26. Januar 2021
 * $Revision:    V1.0
 *
 * Project:      Hardware specific implementation for 
 *               Qualcomm QCA400x SDK
 * -------------------------------------------------------------------------- */

#include <stdbool.h>

#include "pin_mux.h"
#include "fsl_gpio.h"
#include "QCA400x.h"

extern QCA400x_WiFi wifiDev;
extern void WiFi_QCA400x_Pin_INTR_cb (QCA400x_WiFi *pDev);

/**
  \fn          void WiFi_QCA400x_Pin_PWDN (bool pwdn)
  \brief       Drive PWDN (power down negative) line.
  \param[in]   pwdn
                 - \b false Drive PWDN line to Low state
                 - \b true  Drive PWDN line to High state
  \return      none
*/
void WiFi_QCA400x_Pin_PWDN (bool pwdn) {
  GPIO_PinWrite(BOARD_INITGT1216SHIELD_PWRON_GPIO, BOARD_INITGT1216SHIELD_PWRON_PORT, BOARD_INITGT1216SHIELD_PWRON_PIN, pwdn ? 1 : 0);
}

/**
  \fn          void WiFi_QCA400x_Pin_INTR (void)
  \brief       Interrupt on INTR line state changed to low state.
  \detail      This callback function should be called by external user code
               when INTR line changes to low state. If possible from External
               interrupt handler, otherwise from a thread which is monitoring
               the state of INTR line.
  \return      none
*/
void WiFi_QCA400x_Pin_INTR (void) {
  WiFi_QCA400x_Pin_INTR_cb (&wifiDev);
}
