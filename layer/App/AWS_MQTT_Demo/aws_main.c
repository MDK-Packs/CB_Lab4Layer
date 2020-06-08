/*----------------------------------------------------------------------------
 * AWS IoT Demo
 *---------------------------------------------------------------------------*/

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "cmsis_os2.h"
#include "main.h"

/* ---------------------------------------------------------------------------*/

extern int32_t network_connect (void);
extern int demo (void);

const osThreadAttr_t app_main_attr = {
  .stack_size = 4096U
};

/*----------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/
void app_main (void *argument) {
  int32_t status;

  printf("AWS IoT Demo\r\n");

  status = network_connect();
  if (status != -1) {
    demo();
  }
}
