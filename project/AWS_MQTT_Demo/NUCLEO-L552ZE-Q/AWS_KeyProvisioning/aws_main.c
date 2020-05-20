/*----------------------------------------------------------------------------
 * AWS IoT Private Key Provisioning
 *---------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include "cmsis_os2.h"
#include "key_provisioning.h"
#include "tfm_ns_interface.h"

#include "iot_config.h"

/* ---------------------------------------------------------------------------*/

const osThreadAttr_t app_main_attr = {
  .stack_size = 4096U
};

/*----------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/
void app_main (void *argument) {
  int32_t status;

  /* Startup delay */
  osDelay(1000U);

  /* Initialize the TFM NS interface */
  tfm_ns_interface_init();

  printf("AWS IoT Key Provisioning \r\n");

  status = xProvisionPrivateKey((const uint8_t *)IOT_DEMO_PRIVATE_KEY,
                                 strlen(IOT_DEMO_PRIVATE_KEY) + 1);
  if (status == 0) {
    printf("Done. \r\n");
  } else {
    printf("Failed!\r\n");
  }
}
