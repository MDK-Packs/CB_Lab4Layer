/******************************************************************************
 * @file     vio_STM32H745I-DISCO.c
 * @brief    Virtual I/O implementation for board STM32H745I-DISCO
 * @version  V1.0.0
 * @date     15. March 2021
 ******************************************************************************/
/*
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
 */

/*! \page vio_STM32H745I-DISCO Physical I/O Mapping

The table below lists the physical I/O mapping of this CMSIS-Driver VIO implementation.

Virtual Resource  | Variable       | Physical Resource on STM32H745I-DISCO          |
:-----------------|:---------------|:-----------------------------------------------|
vioBUTTON0        | vioSignalIn.0  | GPIO C.13: Button USER                         |
vioLED0           | vioSignalOut.0 | GPIO J.2 : LD6 RED                             |
vioLED1           | vioSignalOut.1 | GPIO I.13: LD7 GREEN                           |

*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "cmsis_vio.h"

#include "RTE_Components.h"
#include CMSIS_device_header

#if !defined CMSIS_VOUT || !defined CMSIS_VIN
#include "stm32h745i_discovery.h"
#if !defined VIO_LCD_DISABLE
#include "stm32h745i_discovery_lcd.h"
#include "stm32_lcd.h"
#include "stm32h745i_discovery_sdram.h"

#include "cmsis_os2.h"
#endif
#endif

// VIO input, output definitions
#define VIO_PRINT_MAX_SIZE      64U     // maximum size of print memory
#define VIO_PRINTMEM_NUM         4U     // number of print memories
#define VIO_VALUE_NUM            3U     // number of values
#define VIO_VALUEXYZ_NUM         3U     // number of XYZ values
#define VIO_IPV4_ADDRESS_NUM     2U     // number of IPv4 addresses
#define VIO_IPV6_ADDRESS_NUM     2U     // number of IPv6 addresses

// VIO input, output variables
__USED uint32_t      vioSignalIn;                                       // Memory for incoming signal
__USED uint32_t      vioSignalOut;                                      // Memory for outgoing signal
__USED char          vioPrintMem[VIO_PRINTMEM_NUM][VIO_PRINT_MAX_SIZE]; // Memory for the last value for each level
__USED int32_t       vioValue   [VIO_VALUE_NUM];                        // Memory for value used in vioGetValue/vioSetValue
__USED vioValueXYZ_t vioValueXYZ[VIO_VALUEXYZ_NUM];                     // Memory for XYZ value for 3-D vector
__USED vioAddrIPv4_t vioAddrIPv4[VIO_IPV4_ADDRESS_NUM];                 // Memory for IPv4 address value used in vioSetIPv4/vioGetIPv4
__USED vioAddrIPv6_t vioAddrIPv6[VIO_IPV6_ADDRESS_NUM];                 // Memory for IPv6 address value used in vioSetIPv6/vioGetIPv6

#if !defined CMSIS_VOUT
// Global types, variables, functions
#if !defined VIO_LCD_DISABLE
static osMutexId_t  mid_mutLCD;         // Mutex ID of mutex:  LCD
#endif

static char         ip_ascii[40];       // String buffer for IP address conversion

/**
  convert IP4 address to ASCII

  \param[in]   ip4_addr   pointer to IP4 address.
  \param[out]  buf        pointer to ascii buffer.
  \param[in]   buf_len    length of a buffer (16 bytes)
*/
static void ip4_2a (const uint8_t *ip4_addr, char *buf, uint32_t buf_len) {
  if (buf_len < 16U) {
    return;
  }
  sprintf(buf, "%d.%d.%d.%d", ip4_addr[0], ip4_addr[1], ip4_addr[2], ip4_addr[3]);
}

/**
  convert IP6 address to ASCII

  \param[in]   ip6_addr   pointer to IP6 address.
  \param[out]  buf        pointer to ascii buffer.
  \param[in]   buf_len    length of a buffer (40 bytes)
*/
static void ip6_2a (const uint8_t *ip6_addr, char *buf, uint32_t buf_len) {
  uint16_t v16[8];
  int32_t i, j, nmax, idx;

  if (buf_len < 40U) {
    return;
  }

  /* Read IPv6 address in hextets */
  for (i = 0; i < 16; i += 2) {
    v16[i >> 1] = (uint16_t)(ip6_addr[i] << 8) | ip6_addr[i+1];
  }

  /* Find the largest block of consecutive zero hextets */
  idx = 8;
  for (i = nmax = 0; i < 8-1; i++) {
    if (v16[i] != 0U) {
      continue;
    }
    for (j = i; j < 8-1; j++) {
      if (v16[j+1] != 0U) {
        break;
      }
    }
    if (i == j) {
      continue;
    }
    if ((j - i) >= nmax) {
      /* Remember position and count */
      nmax = j - i + 1;
      idx  = i;
    }
    /* Skip already processed zero hextets */
    i = j;
  }
  for (i = j = 0; i < idx;  ) {
    j += sprintf(&buf[j], "%x", v16[i]);
    if (++i == idx) {
      break;
    }
    buf[j++] = ':';
  }
  if (i < 8) {
    /* Right-end not yet complete */
    buf[j++] = ':';
    for (i += nmax; i < 8; i++) {
      j += sprintf(&buf[j], ":%x", v16[i]);
    }
    if (buf[j-1] == ':') {
      buf[j++] = ':';
    }
  }
  /* Make string null-terminated */
  buf[j] = 0;
}

#if !defined VIO_LCD_DISABLE
typedef struct displayArea {
  uint16_t   xOrigin;          // x Origin
  uint16_t   xWidth;           // x width
  uint16_t   xPos;             // current x position
  uint16_t   yOrigin;          // y Origin
  uint16_t   yHeight;          // y height
  uint16_t   yPos;             // current y position
  uint16_t   fontWidth;        // font width
  uint16_t   fontHeight;       // font height
} displayArea_t;

static displayArea_t display[4];

/**
  Scroll content of the selected display for dy pixels vertically

  \param[in]   idx   Display index.
*/
static void displayScrollVertical (uint32_t idx) {
  uint32_t x, y, color;

  for (y = display[idx].yOrigin; y < (display[idx].yHeight - display[idx].fontHeight); y++) {
    for (x = display[idx].xOrigin; x < display[idx].xWidth; x++) {
      UTIL_LCD_GetPixel(x, y + display[idx].fontHeight, &color);
      UTIL_LCD_SetPixel(x, y,                            color);
    }
  }

  for (; y < display[idx].yHeight; y++) {
    for (x = display[idx].xOrigin; x < display[idx].xWidth; x++) {
      UTIL_LCD_SetPixel(x, y,     UTIL_LCD_COLOR_BLACK);
    }
  }
}

/**
  write a string to the selected display

  \param[in]   idx   Display index.
  \param[in]   str   String
*/
static void displayString (uint32_t idx, char *str) {
  char ch;
  uint8_t i = 0;

  while (str[i] != '\0') {
    ch = str[i++];                                                   /* Get character and increase index */

    switch (ch) {
      case 0x0A:                          // Line Feed
        display[idx].yPos += display[idx].fontHeight;                /* Move cursor one row down */
        if (display[idx].yPos >= display[idx].yHeight) {             /* If bottom of display was overstepped */
          displayScrollVertical(idx);
          display[idx].yPos -= display[idx].fontHeight;              /* Stay in last row */
        }
        break;
      case 0x0D:                                                     /* Carriage Return */
        display[idx].xPos = display[idx].xOrigin;                    /* Move cursor to first column */
        break;
      default:
        // Display character at current cursor position
        UTIL_LCD_DisplayChar(display[idx].xPos, display[idx].yPos, ch);
        display[idx].xPos += display[idx].fontWidth;                 /* Move cursor one column to right */
        if (display[idx].xPos >= display[idx].xWidth) {              /* If last column was overstepped */
          display[idx].xPos = display[idx].xOrigin;                  /* First column */
          display[idx].yPos += display[idx].fontHeight;              /* Move cursor one row down and to */
        }
        if (display[idx].yPos >= display[idx].yHeight) {             /* If bottom of display was overstepped */
          displayScrollVertical(idx);
          display[idx].yPos -= display[idx].fontHeight;              /* Stay in last row */
        }
        break;
    }

  }
}
#endif
#endif

#if !defined CMSIS_VIN
// Add global user types, variables, functions here:

#endif

// Initialize test input, output.
void vioInit (void) {
#if !defined CMSIS_VOUT
#if !defined VIO_LCD_DISABLE
  // Display variables:
  LCD_UTILS_Drv_t GuiDrv;
  uint32_t XSize, YSize;
#endif
#endif

#if !defined CMSIS_VIN
// Add user variables here:

#endif

  vioSignalIn  = 0U;
  vioSignalOut = 0U;

  memset(vioPrintMem, 0, sizeof(vioPrintMem));
  memset(vioValue,    0, sizeof(vioValue));
  memset(vioValueXYZ, 0, sizeof(vioValueXYZ));
  memset(vioAddrIPv4, 0, sizeof(vioAddrIPv4));
  memset(vioAddrIPv6, 0, sizeof(vioAddrIPv6));

#if !defined CMSIS_VOUT

  // Initialize LEDs pins
  BSP_LED_Init(LED_RED);
  BSP_LED_Init(LED_GREEN);

#if !defined VIO_LCD_DISABLE
  // Create LCD mutex
  mid_mutLCD = osMutexNew(NULL);
  if (mid_mutLCD == NULL) { /* add error handling */ }

  // Initialize the LCD
  BSP_LCD_Init(0, LCD_ORIENTATION_LANDSCAPE);

  // Set GUI functions
  GuiDrv.DrawBitmap  = BSP_LCD_DrawBitmap;
  GuiDrv.FillRGBRect = BSP_LCD_FillRGBRect;
  GuiDrv.DrawHLine   = BSP_LCD_DrawHLine;
  GuiDrv.DrawVLine   = BSP_LCD_DrawVLine;
  GuiDrv.FillRect    = BSP_LCD_FillRect;
  GuiDrv.GetPixel    = BSP_LCD_ReadPixel;
  GuiDrv.SetPixel    = BSP_LCD_WritePixel;
  GuiDrv.GetXSize    = BSP_LCD_GetXSize;
  GuiDrv.GetYSize    = BSP_LCD_GetYSize;
  GuiDrv.SetLayer    = BSP_LCD_SetActiveLayer;
  GuiDrv.GetFormat   = BSP_LCD_GetPixelFormat;
  UTIL_LCD_SetFuncDriver(&GuiDrv);

  // Clear the LCD
  UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);

  // Set the display on
  BSP_LCD_DisplayOn(0U);

  // Get the LCD X and Y size
  BSP_LCD_GetXSize(0U, &XSize);
  BSP_LCD_GetYSize(0U, &YSize);

  // Initialize display areas
  display[vioLevelHeading].fontWidth  =  11;
  display[vioLevelHeading].fontHeight =  16;
  display[vioLevelHeading].xOrigin    =   3;
  display[vioLevelHeading].xWidth     = XSize - 4;
  display[vioLevelHeading].xPos       = display[vioLevelHeading].xOrigin;
  display[vioLevelHeading].yOrigin    =   4;
  display[vioLevelHeading].yHeight    =  2 * display[vioLevelHeading].fontHeight + display[vioLevelHeading].yOrigin;
  display[vioLevelHeading].yPos       = display[vioLevelHeading].yOrigin;

  display[vioLevelNone].fontWidth     =   7;
  display[vioLevelNone].fontHeight    =  12;
  display[vioLevelNone].xOrigin       =   3;
  display[vioLevelNone].xWidth        = XSize - 4;
  display[vioLevelNone].xPos          = display[vioLevelNone].xOrigin;
  display[vioLevelNone].yOrigin       =  40;
  display[vioLevelNone].yHeight       =  2 * display[vioLevelNone].fontHeight + display[vioLevelNone].yOrigin;
  display[vioLevelNone].yPos          = display[vioLevelNone].yOrigin;

  display[vioLevelError].fontWidth    =   7;
  display[vioLevelError].fontHeight   =  12;
  display[vioLevelError].xOrigin      =   3;
  display[vioLevelError].xWidth       = XSize - 4;
  display[vioLevelError].xPos         = display[vioLevelError].xOrigin;
  display[vioLevelError].yOrigin      =  68;
  display[vioLevelError].yHeight      =  4 * display[vioLevelError].fontHeight + display[vioLevelError].yOrigin;
  display[vioLevelError].yPos         = display[vioLevelError].yOrigin;

  display[vioLevelMessage].fontWidth  =   7;
  display[vioLevelMessage].fontHeight =  12;
  display[vioLevelMessage].xOrigin    =   3;
  display[vioLevelMessage].xWidth     = XSize - 4;
  display[vioLevelMessage].xPos       = display[vioLevelMessage].xOrigin;
  display[vioLevelMessage].yOrigin    = 120;
  display[vioLevelMessage].yHeight    =  9 * display[vioLevelMessage].fontHeight + display[vioLevelMessage].yOrigin;
  display[vioLevelMessage].yPos       = display[vioLevelMessage].yOrigin;

  // Draw LCD layout
  UTIL_LCD_DrawRect(0U, 0U, XSize,    YSize,    UTIL_LCD_COLOR_ORANGE);
  UTIL_LCD_DrawRect(1U, 1U, XSize-2U, YSize-2U, UTIL_LCD_COLOR_ORANGE);
  /*   3        pixel row empty */
  /*   4.. 35   2 lines font16 =  2*16 vioLevelHeading */
  /*  36        pixel row empty  */

  UTIL_LCD_DrawHLine(2U, 37U, XSize-4U, UTIL_LCD_COLOR_ORANGE);
  UTIL_LCD_DrawHLine(2U, 38U, XSize-4U, UTIL_LCD_COLOR_ORANGE);
  /*  39        pixel row empty */
  /*  40.. 63   2 lines font12 =  2*12 vioLevelNone */
  /*  64        pixel row empty */

  UTIL_LCD_DrawHLine(2U, 65U, XSize-4U, UTIL_LCD_COLOR_ORANGE);
  UTIL_LCD_DrawHLine(2U, 66U, XSize-4U, UTIL_LCD_COLOR_ORANGE);
  /*  67        pixel row empty */
  /*  68..115   4 lines font12 =  4*12 vioLevelError */
  /* 116        pixel row empty */

  UTIL_LCD_DrawHLine(2U, 117U, XSize-4U, UTIL_LCD_COLOR_ORANGE);
  UTIL_LCD_DrawHLine(2U, 118U, XSize-4U, UTIL_LCD_COLOR_ORANGE);
  /* 119        pixel row empty */
  /* 120..227   9 lines font12 = 9*12 vioLevelMessage */
  /* 228        pixel row empty */
#endif
#endif

#if !defined CMSIS_VIN
  // Initialize buttons pins (only USER button)
  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);
#endif
}

// Print formated string to test terminal.
int32_t vioPrint (uint32_t level, const char *format, ...) {
  va_list args;
  int32_t ret;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (level > vioLevelError) {
    return (-1);
  }

  if (level > VIO_PRINTMEM_NUM) {
    return (-1);
  }

  va_start(args, format);

  ret = vsnprintf((char *)vioPrintMem[level], sizeof(vioPrintMem[level]), format, args);

  va_end(args);

#if !defined CMSIS_VOUT
#if !defined VIO_LCD_DISABLE
// Draw LCD level
  osMutexAcquire(mid_mutLCD, osWaitForever);
  switch (level) {
    case vioLevelNone:
      UTIL_LCD_SetFont(&Font12);
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
      displayString(level, (char *)vioPrintMem[level]);
      break;
    case vioLevelHeading:
      UTIL_LCD_SetFont(&Font16);
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_GREEN);
      displayString(level, (char *)vioPrintMem[level]);
      break;
    case vioLevelMessage:
      UTIL_LCD_SetFont(&Font12);
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_BLUE);
      displayString(level, (char *)vioPrintMem[level]);
      break;
    case vioLevelError:
      UTIL_LCD_SetFont(&Font12);
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_RED);
      displayString(level, (char *)vioPrintMem[level]);
      break;
  }
  UTIL_LCD_SetFont(&Font12);
  UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKBLUE);
  osMutexRelease(mid_mutLCD);
#endif
#endif

  return (ret);
}

// Set signal output.
void vioSetSignal (uint32_t mask, uint32_t signal) {
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  vioSignalOut &= ~mask;
  vioSignalOut |=  mask & signal;

#if !defined CMSIS_VOUT
  // Output signals to LEDs
  if ((mask & vioLED0) != 0U) {
    if ((signal & vioLED0) != 0U) {
      BSP_LED_On(LED_RED);
    } else {
      BSP_LED_Off(LED_RED);
    }
  }

  if ((mask & vioLED1) != 0U) {
    if ((signal & vioLED1) != 0U) {
      BSP_LED_On(LED_GREEN);
    } else {
      BSP_LED_Off(LED_GREEN);
    }
  }
#endif
}

// Get signal input.
uint32_t vioGetSignal (uint32_t mask) {
  uint32_t signal;
#if !defined CMSIS_VIN
// Add user variables here:

#endif

#if !defined CMSIS_VIN
  // Get input signals from buttons (only USER button)
  if ((mask & vioBUTTON0) != 0U) {
    if (BSP_PB_GetState(BUTTON_USER) == 1U) {
      vioSignalIn |=  vioBUTTON0;
    } else {
      vioSignalIn &= ~vioBUTTON0;
    }
  }
#endif

  signal = vioSignalIn;

  return (signal & mask);
}

// Set value output.
void vioSetValue (uint32_t id, int32_t value) {
  uint32_t index = id;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (index >= VIO_VALUE_NUM) {
    return;                             /* return in case of out-of-range index */
  }

  vioValue[index] = value;

#if !defined CMSIS_VOUT
// Add user code here:

#endif
}

// Get value input.
int32_t vioGetValue (uint32_t id) {
  uint32_t index = id;
  int32_t  value = 0;
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  if (index >= VIO_VALUE_NUM) {
    return value;                       /* return default in case of out-of-range index */
  }

#if !defined CMSIS_VIN
// Add user code here:

//   vioValue[index] = ...;
#endif

  value = vioValue[index];

  return value;
}

// Set XYZ value output.
void vioSetXYZ (uint32_t id, vioValueXYZ_t valueXYZ) {
  uint32_t index = id;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (index >= VIO_VALUEXYZ_NUM) {
    return;                             /* return in case of out-of-range index */
  }

  vioValueXYZ[index] = valueXYZ;

#if !defined CMSIS_VOUT
// Add user code here:

#endif
}

// Get XYZ value input.
vioValueXYZ_t vioGetXYZ (uint32_t id) {
  uint32_t index = id;
  vioValueXYZ_t valueXYZ = {0, 0, 0};
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  if (index >= VIO_VALUEXYZ_NUM) {
    return valueXYZ;                    /* return default in case of out-of-range index */
  }

#if !defined CMSIS_VIN
// Add user code here:

//   vioValueXYZ[index] = ...;
#endif

  valueXYZ = vioValueXYZ[index];

  return valueXYZ;
}

// Set IPv4 address output.
void vioSetIPv4 (uint32_t id, vioAddrIPv4_t addrIPv4) {
  uint32_t index = id;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (index >= VIO_IPV4_ADDRESS_NUM) {
    return;                             /* return in case of out-of-range index */
  }

  vioAddrIPv4[index] = addrIPv4;

#if !defined CMSIS_VOUT
  // Convert IP4 address to ASCII
  ip4_2a((uint8_t *)&vioAddrIPv4[index], ip_ascii, sizeof(ip_ascii));

#if !defined VIO_LCD_DISABLE
  osMutexAcquire(mid_mutLCD, osWaitForever);
  UTIL_LCD_SetFont(&Font12);
  UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
  displayString(vioLevelNone, "\r\n");
  displayString(vioLevelNone, ip_ascii);
  osMutexRelease(mid_mutLCD);
#endif
#endif
}

// Get IPv4 address input.
vioAddrIPv4_t vioGetIPv4 (uint32_t id) {
  uint32_t index = id;
  vioAddrIPv4_t addrIPv4 = {0U, 0U, 0U, 0U};
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  if (index >= VIO_IPV4_ADDRESS_NUM) {
    return addrIPv4;                    /* return default in case of out-of-range index */
  }

#if !defined CMSIS_VIN
// Add user code here:

//   vioAddrIPv4[index] = ...;
#endif

  addrIPv4 = vioAddrIPv4[index];

  return addrIPv4;
}

// Set IPv6 address output.
void vioSetIPv6 (uint32_t id, vioAddrIPv6_t addrIPv6) {
  uint32_t index = id;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (index >= VIO_IPV6_ADDRESS_NUM) {
    return;                             /* return in case of out-of-range index */
  }

  vioAddrIPv6[index] = addrIPv6;

#if !defined CMSIS_VOUT
  // Convert IP6 address to ASCII
  ip6_2a((uint8_t *)&vioAddrIPv6[index], ip_ascii, sizeof(ip_ascii));

#if !defined VIO_LCD_DISABLE
  osMutexAcquire(mid_mutLCD, osWaitForever);
  UTIL_LCD_SetFont(&Font12);
  UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
  displayString(vioLevelNone, "\r\n");
  displayString(vioLevelNone, ip_ascii);
  osMutexRelease(mid_mutLCD);
#endif
#endif
}

// Get IPv6 address input.
vioAddrIPv6_t vioGetIPv6 (uint32_t id) {
  uint32_t index = id;
  vioAddrIPv6_t addrIPv6 = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
                            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  if (index >= VIO_IPV6_ADDRESS_NUM) {
    return addrIPv6;                    /* return default in case of out-of-range index */
  }

#if !defined CMSIS_VIN
// Add user code here:

//   vioAddrIPv6[index] = ...;
#endif

  addrIPv6 = vioAddrIPv6[index];

  return addrIPv6;
}
