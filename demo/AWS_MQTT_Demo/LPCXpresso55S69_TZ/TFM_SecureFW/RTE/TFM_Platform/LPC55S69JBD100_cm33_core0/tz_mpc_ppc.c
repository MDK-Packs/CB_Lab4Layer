/*
 * Copyright 2019 Arm Limited
 *
 * SPDX-License-Identifier: Apache 2.0
 */

#include "tz_config.h" 
#include "fsl_device_registers.h"


/* Setup Memory Protection Controller (MPC) */
void TZ_Config_MPC(void)
{
  /* Flash */
  AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[0]=
      0x00000002U |      /* memory:CODE_S */
      0x00000020U |      /* memory:CODE_S */
      0x00000200U |      /* memory:CODE_S */
      0x00002000U |      /* memory:CODE_S */
      0x00020000U |      /* memory:CODE_S */
      0x00200000U |      /* memory:CODE_S, memory:VENEERS */
      0x00000000U |      /* memory:CODE_NS */
      0x00000000U;       /* memory:CODE_NS */
  AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[1]=
      0x00000000U |      /* memory:CODE_NS */
      0x00000000U |      /* memory:CODE_NS */
      0x00000000U |      /* memory:CODE_NS */
      0x00000000U |      /* memory:CODE_NS */
      0x00000000U |      /* memory:CODE_NS */
      0x00000000U |      /* memory:CODE_NS */
      0x00000000U |      /* memory:CODE_NS */
      0x00000000U;       /* memory:CODE_NS */
  AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[2]=
      0x00000000U |      /* memory:CODE_NS */
      0x00000000U |      
      0x00000200U |      /* memory:PS, memory:ITS, memory:NV_COUNTERS */
      0x00000000U |      /* memory:FLASH_FFR */
      0x00000000U |      
      0x00000000U |      
      0x00000000U |      
      0x00000000U;       

  /* Boot ROM */
  AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_ROM_MEM_RULE[0]=
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U;       /* memory:ROM */
  AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_ROM_MEM_RULE[1]=
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U;       /* memory:ROM */
  AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_ROM_MEM_RULE[2]=
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U;       /* memory:ROM */
  AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_ROM_MEM_RULE[3]=
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U |      /* memory:ROM */
      0x00000000U;       /* memory:ROM */

  /* SRAMX */
  AHB_SECURE_CTRL->SEC_CTRL_RAMX[0].MEM_RULE[0]=
      0x00000000U |      /* memory:SRAMX */
      0x00000000U |      /* memory:SRAMX */
      0x00000000U |      /* memory:SRAMX */
      0x00000000U |      /* memory:SRAMX */
      0x00000000U |      /* memory:SRAMX */
      0x00000000U |      /* memory:SRAMX */
      0x00000000U |      /* memory:SRAMX */
      0x00000000U;       /* memory:SRAMX */

  /* SRAM Bank 0 */
  AHB_SECURE_CTRL->SEC_CTRL_RAM0[0].MEM_RULE[0]=
      0x00000002U |      /* memory:DATA_S */
      0x00000020U |      /* memory:DATA_S */
      0x00000200U |      /* memory:DATA_S */
      0x00002000U |      /* memory:DATA_S */
      0x00020000U |      /* memory:DATA_S */
      0x00200000U |      /* memory:DATA_S */
      0x02000000U |      /* memory:DATA_S */
      0x20000000U;       /* memory:DATA_S */
  AHB_SECURE_CTRL->SEC_CTRL_RAM0[0].MEM_RULE[1]=
      0x00000002U |      /* memory:DATA_S */
      0x00000020U |      /* memory:DATA_S */
      0x00000200U |      /* memory:DATA_S */
      0x00002000U |      /* memory:DATA_S */
      0x00020000U |      /* memory:DATA_S */
      0x00200000U |      /* memory:DATA_S */
      0x02000000U |      /* memory:DATA_S */
      0x20000000U;       /* memory:DATA_S */

  /* SRAM Bank 1 */
  AHB_SECURE_CTRL->SEC_CTRL_RAM1[0].MEM_RULE[0]=
      0x00000002U |      /* memory:DATA_S */
      0x00000020U |      /* memory:DATA_S */
      0x00000200U |      /* memory:DATA_S */
      0x00002000U |      /* memory:DATA_S */
      0x00020000U |      /* memory:DATA_S */
      0x00200000U |      /* memory:DATA_S */
      0x02000000U |      /* memory:DATA_S */
      0x20000000U;       /* memory:DATA_S */
  AHB_SECURE_CTRL->SEC_CTRL_RAM1[0].MEM_RULE[1]=
      0x00000002U |      /* memory:DATA_S */
      0x00000020U |      /* memory:DATA_S */
      0x00000200U |      /* memory:DATA_S */
      0x00002000U |      /* memory:DATA_S */
      0x00020000U |      /* memory:DATA_S */
      0x00200000U |      /* memory:DATA_S */
      0x02000000U |      /* memory:DATA_S */
      0x20000000U;       /* memory:DATA_S */

  /* SRAM Bank 2 */
  AHB_SECURE_CTRL->SEC_CTRL_RAM2[0].MEM_RULE[0]=
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U;       /* memory:DATA_NS */
  AHB_SECURE_CTRL->SEC_CTRL_RAM2[0].MEM_RULE[1]=
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U;       /* memory:DATA_NS */

  /* SRAM Bank 3 */
  AHB_SECURE_CTRL->SEC_CTRL_RAM3[0].MEM_RULE[0]=
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U;       /* memory:DATA_NS */
  AHB_SECURE_CTRL->SEC_CTRL_RAM3[0].MEM_RULE[1]=
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U;       /* memory:DATA_NS */

  /* SRAM Bank 4 */
  AHB_SECURE_CTRL->SEC_CTRL_RAM4[0].MEM_RULE[0]=
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      /* memory:DATA_NS */
      0x00000000U |      
      0x00000000U |      
      0x00000000U |      
      0x00000000U;       

  /* USB SRAM */
  AHB_SECURE_CTRL->SEC_CTRL_USB_HS[0].MEM_RULE[0]=
      0x00000000U |      
      0x00000000U |      
      0x00000000U |      
      0x00000000U |      
      0x00000000U |      
      0x00000000U |      
      0x00000000U |      
      0x00000000U;       

}


/* Setup Peripheral Protection Controller (PPC) */
void TZ_Config_PPC(void)
{
  AHB_SECURE_CTRL->SEC_CTRL_AHB_PORT10[0].SLAVE0_RULE =
      0x00020000U |      /* HASH-AES */
      0x00200000U;       /* CASPER */

  AHB_SECURE_CTRL->SEC_CTRL_AHB_PORT10[0].SLAVE1_RULE =
      0x00000002U |      /* SGPIO */
      0x00000020U;       /* AHB_SECURE_CTRL */

  AHB_SECURE_CTRL->SEC_CTRL_APB_BRIDGE[0].SEC_CTRL_APB_BRIDGE0_MEM_CTRL0 =
      0x00200000U;       /* SPINT */

  AHB_SECURE_CTRL->SEC_CTRL_APB_BRIDGE[0].SEC_CTRL_APB_BRIDGE1_MEM_CTRL3 =
      0x00000200U |      /* RNG */
      0x00002000U;       /* PUF */

}
