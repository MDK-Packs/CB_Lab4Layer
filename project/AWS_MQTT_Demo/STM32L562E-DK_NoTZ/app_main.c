/*----------------------------------------------------------------------------
 * AWS IoT Demo
 *---------------------------------------------------------------------------*/

#include <stdint.h>
#include <stdio.h>
#include "cmsis_os2.h"
#include "main.h"

extern int32_t socket_startup (void);
extern int32_t demo (void);

static const osThreadAttr_t app_main_attr = {
  .stack_size = 4096U
};

/*----------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/
static void app_main (void *argument) {
  int32_t status;

  printf("AWS IoT Demo\r\n");

  status = socket_startup();
  if (status != -1) {
    demo();
  }
}

/*----------------------------------------------------------------------------
 * Application initialization
 *---------------------------------------------------------------------------*/
void app_initialize (void) {
  osThreadNew(app_main, NULL, &app_main_attr);
}
