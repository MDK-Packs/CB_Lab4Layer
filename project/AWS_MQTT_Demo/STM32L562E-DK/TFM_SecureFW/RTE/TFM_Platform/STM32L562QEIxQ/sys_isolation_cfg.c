/*----------------------------------------------------------------------------
  System Isolation Configuration
  This function is responsible for Memory and Peripheral isolation
  for secure and non-secure application parts
 *----------------------------------------------------------------------------*/

#include "stm32l5xx_hal.h"

void SystemIsolation_Config(void)
{
  /* Enable GTZC peripheral clock */
  __HAL_RCC_GTZC_CLK_ENABLE();

  /* Setup Memory Protection Controller (MPC) */
  /* SRAM1 */
  WRITE_REG(GTZC_MPCBB1_S->VCTR[0], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[1], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[2], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[3], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[4], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[5], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[6], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[7], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[8], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[9], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[10], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[11], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[12], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[13], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[14], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[15], 0xFFFFFFFFU);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[16], 0x00000000U);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[17], 0x00000000U);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[18], 0x00000000U);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[19], 0x00000000U);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[20], 0x00000000U);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[21], 0x00000000U);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[22], 0x00000000U);
  WRITE_REG(GTZC_MPCBB1_S->VCTR[23], 0x00000000U);
  /* SRAM2 */
  WRITE_REG(GTZC_MPCBB2_S->VCTR[0], 0x00000000U);
  WRITE_REG(GTZC_MPCBB2_S->VCTR[1], 0x00000000U);
  WRITE_REG(GTZC_MPCBB2_S->VCTR[2], 0x00000000U);
  WRITE_REG(GTZC_MPCBB2_S->VCTR[3], 0x00000000U);
  WRITE_REG(GTZC_MPCBB2_S->VCTR[4], 0x00000000U);
  WRITE_REG(GTZC_MPCBB2_S->VCTR[5], 0x00000000U);
  WRITE_REG(GTZC_MPCBB2_S->VCTR[6], 0x00000000U);
  WRITE_REG(GTZC_MPCBB2_S->VCTR[7], 0x00000000U);
  
  /* Setup Peripheral Protection Controller (PPC) */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  WRITE_REG(GPIOB_S->SECCFGR,
    0x00000001 | /* GPIOB */
    0x00000002 | /* GPIOB */
    0x00000004 | /* GPIOB */
    0x00000008 | /* GPIOB */
    0x00000040 | /* GPIOB */
    0x00000080 | /* GPIOB */
    0x00000100 | /* GPIOB */
    0x00001000 | /* GPIOB */
    0x00002000 | /* GPIOB */
    0x00004000 | /* GPIOB */
    0x00008000   /* GPIOB */
  );
  __HAL_RCC_GPIOE_CLK_ENABLE();
  WRITE_REG(GPIOE_S->SECCFGR,
    0x00000002 | /* GPIOE */
    0x00000004 | /* GPIOE */
    0x00000008 | /* GPIOE */
    0x00000010 | /* GPIOE */
    0x00000020 | /* GPIOE */
    0x00000040 | /* GPIOE */
    0x00000080 | /* GPIOE */
    0x00000100 | /* GPIOE */
    0x00000200 | /* GPIOE */
    0x00000400 | /* GPIOE */
    0x00000800 | /* GPIOE */
    0x00001000 | /* GPIOE */
    0x00002000 | /* GPIOE */
    0x00004000 | /* GPIOE */
    0x00008000   /* GPIOE */
  );
  __HAL_RCC_GPIOG_CLK_ENABLE();
  WRITE_REG(GPIOG_S->SECCFGR,
    0x00000001 | /* GPIOG */
    0x00000002 | /* GPIOG */
    0x00000004 | /* GPIOG */
    0x00000008 | /* GPIOG */
    0x00000010 | /* GPIOG */
    0x00000020 | /* GPIOG */
    0x00000040 | /* GPIOG */
    0x00000080 | /* GPIOG */
    0x00000100 | /* GPIOG */
    0x00000400 | /* GPIOG */
    0x00000800 | /* GPIOG */
    0x00001000 | /* GPIOG */
    0x00002000 | /* GPIOG */
    0x00004000 | /* GPIOG */
    0x00008000   /* GPIOG */
  );

  /* Clear all illegal access pending interrupts in TZIC */
  if (HAL_GTZC_TZIC_ClearFlag(GTZC_PERIPH_ALL) != HAL_OK)
  {
    /* Initialization Error */
    while(1);
  }

  /* Enable all illegal access interrupts in TZIC */
  if(HAL_GTZC_TZIC_EnableIT(GTZC_PERIPH_ALL) != HAL_OK)
  {
    /* Initialization Error */
    while(1);
  }

  /* Enable TZIC secure interrupt */
  HAL_NVIC_SetPriority(GTZC_IRQn, 0, 0); /* Highest priority level */
  HAL_NVIC_ClearPendingIRQ(GTZC_IRQn);
  HAL_NVIC_EnableIRQ(GTZC_IRQn);
}
