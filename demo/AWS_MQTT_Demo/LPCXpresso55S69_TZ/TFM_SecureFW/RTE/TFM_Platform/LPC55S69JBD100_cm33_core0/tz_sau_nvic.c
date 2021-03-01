/*
 * Copyright 2019 Arm Limited
 *
 * SPDX-License-Identifier: Apache 2.0
 */

#include "tz_config.h" 
#include "fsl_device_registers.h"

void TZ_Config_SAU(void)
{

  /* Initialize SAU Region 0 */
  SAU->RNR  =  (0U                      & SAU_RNR_REGION_Msk);
  SAU->RBAR =  (0x00030000U             & SAU_RBAR_BADDR_Msk);
  SAU->RLAR =  (0x00087FE0U             & SAU_RLAR_LADDR_Msk) |
              ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk)   | 1U;

  /* Initialize SAU Region 1 */
  SAU->RNR  =  (1U                      & SAU_RNR_REGION_Msk);
  SAU->RBAR =  (0x0009DE00U             & SAU_RBAR_BADDR_Msk);
  SAU->RLAR =  (0x0009FDE0U             & SAU_RLAR_LADDR_Msk) |
              ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk)   | 1U;

  /* Initialize SAU Region 2 */
  SAU->RNR  =  (2U                      & SAU_RNR_REGION_Msk);
  SAU->RBAR =  (0x03000000U             & SAU_RBAR_BADDR_Msk);
  SAU->RLAR =  (0x0301FFE0U             & SAU_RLAR_LADDR_Msk) |
              ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk)   | 1U;

  /* Initialize SAU Region 3 */
  SAU->RNR  =  (3U                      & SAU_RNR_REGION_Msk);
  SAU->RBAR =  (0x04000000U             & SAU_RBAR_BADDR_Msk);
  SAU->RLAR =  (0x04007FE0U             & SAU_RLAR_LADDR_Msk) |
              ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk)   | 1U;

  /* Initialize SAU Region 4 */
  SAU->RNR  =  (4U                      & SAU_RNR_REGION_Msk);
  SAU->RBAR =  (0x1002F800U             & SAU_RBAR_BADDR_Msk);
  SAU->RLAR =  (0x1002FB20U             & SAU_RLAR_LADDR_Msk) |
              ((1U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk)   | 1U;

  /* Initialize SAU Region 5 */
  SAU->RNR  =  (5U                      & SAU_RNR_REGION_Msk);
  SAU->RBAR =  (0x20020000U             & SAU_RBAR_BADDR_Msk);
  SAU->RLAR =  (0x20043FE0U             & SAU_RLAR_LADDR_Msk) |
              ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk)   | 1U;

  /* Initialize SAU Region 6 */
  SAU->RNR  =  (6U                      & SAU_RNR_REGION_Msk);
  SAU->RBAR =  (0x40000000U             & SAU_RBAR_BADDR_Msk);
  SAU->RLAR =  (0x4FFFFFE0U             & SAU_RLAR_LADDR_Msk) |
              ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk)   | 1U;

  /* Initialize SAU Region 7 */
  SAU->RNR  =  (7U                      & SAU_RNR_REGION_Msk);
  SAU->RBAR =  (0x00000000U             & SAU_RBAR_BADDR_Msk);
  SAU->RLAR =  (0x00000000U             & SAU_RLAR_LADDR_Msk) |
              ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk)   | 0U;

  /* Configure SAU Control */
  SAU->CTRL = ((1U << SAU_CTRL_ENABLE_Pos) & SAU_CTRL_ENABLE_Msk) |         /* enable SAU */
              ((0U << SAU_CTRL_ALLNS_Pos)  & SAU_CTRL_ALLNS_Msk)   ;
}

void TZ_Config_NVIC(void)
{
  /* Initialize ITNS 0 (Interrupts 0..31) */
  NVIC->ITNS[0] =
      0x00000001 |      /* Interrupt   0: WDT                   is non-secure */
      0x00000002 |      /* Interrupt   1: SDMA0                 is non-secure */
      0x00000004 |      /* Interrupt   2: GINT0                 is non-secure */
      0x00000008 |      /* Interrupt   3: GINT1                 is non-secure */
      0x00000010 |      /* Interrupt   4: PIN_INT0              is non-secure */
      0x00000020 |      /* Interrupt   5: PIN_INT1              is non-secure */
      0x00000040 |      /* Interrupt   6: PIN_INT2              is non-secure */
      0x00000080 |      /* Interrupt   7: PIN_INT3              is non-secure */
      0x00000100 |      /* Interrupt   8: UTICK                 is non-secure */
      0x00000200 |      /* Interrupt   9: MRT                   is non-secure */
      0x00000400 |      /* Interrupt  10: CTIMER0               is non-secure */
      0x00000800 |      /* Interrupt  11: CTIMER1               is non-secure */
      0x00001000 |      /* Interrupt  12: SCT                   is non-secure */
      0x00002000 |      /* Interrupt  13: CTIMER3               is non-secure */
      0x00004000 |      /* Interrupt  14: FLEXCOMM0             is non-secure */
      0x00008000 |      /* Interrupt  15: FLEXCOMM1             is non-secure */
      0x00010000 |      /* Interrupt  16: FLEXCOMM2             is non-secure */
      0x00020000 |      /* Interrupt  17: FLEXCOMM3             is non-secure */
      0x00040000 |      /* Interrupt  18: FLEXCOMM4             is non-secure */
      0x00080000 |      /* Interrupt  19: FLEXCOMM5             is non-secure */
      0x00100000 |      /* Interrupt  20: FLEXCOMM6             is non-secure */
      0x00200000 |      /* Interrupt  21: FLEXCOMM7             is non-secure */
      0x00400000 |      /* Interrupt  22: ADC                   is non-secure */
      0x00000000 |      /* Interrupt  23: ---                   is secure */
      0x01000000 |      /* Interrupt  24: ACMP                  is non-secure */
      0x00000000 |      /* Interrupt  25: ---                   is secure */
      0x00000000 |      /* Interrupt  26: ---                   is secure */
      0x08000000 |      /* Interrupt  27: USB0_NEEDCLK          is non-secure */
      0x10000000 |      /* Interrupt  28: USB0                  is non-secure */
      0x20000000 |      /* Interrupt  29: RTC                   is non-secure */
      0x00000000 |      /* Interrupt  30: ---                   is secure */
      0x80000000;       /* Interrupt  31: MAILBOX               is non-secure */

  /* Initialize ITNS 1 (Interrupts 32..63) */
  NVIC->ITNS[1] =
      0x00000001 |      /* Interrupt  32: PIN_INT4              is non-secure */
      0x00000002 |      /* Interrupt  33: PIN_INT5              is non-secure */
      0x00000004 |      /* Interrupt  34: PIN_INT6              is non-secure */
      0x00000008 |      /* Interrupt  35: PIN_INT7              is non-secure */
      0x00000010 |      /* Interrupt  36: CTIMER2               is non-secure */
      0x00000020 |      /* Interrupt  37: CTIMER4               is non-secure */
      0x00000040 |      /* Interrupt  38: OSEVTIMER             is non-secure */
      0x00000000 |      /* Interrupt  39: ---                   is secure */
      0x00000000 |      /* Interrupt  40: ---                   is secure */
      0x00000000 |      /* Interrupt  41: ---                   is secure */
      0x00000400 |      /* Interrupt  42: SDIO                  is non-secure */
      0x00000000 |      /* Interrupt  43: ---                   is secure */
      0x00000000 |      /* Interrupt  44: ---                   is secure */
      0x00000000 |      /* Interrupt  45: ---                   is secure */
      0x00000000 |      /* Interrupt  46: ---                   is secure */
      0x00008000 |      /* Interrupt  47: USB1                  is non-secure */
      0x00010000 |      /* Interrupt  48: USB1_NEEDCLK          is non-secure */
      0x00000000 |      /* Interrupt  49: HYPERVISOR            is secure */
      0x00000000 |      /* Interrupt  50: SGPIO_INT0_IRQ0       is secure */
      0x00000000 |      /* Interrupt  51: SGPIO_INT0_IRQ1       is secure */
      0x00100000 |      /* Interrupt  52: PLU                   is non-secure */
      0x00000000 |      /* Interrupt  53: SEC_VIO               is secure */
      0x00000000 |      /* Interrupt  54: HASH                  is secure */
      0x00000000 |      /* Interrupt  55: CASPER                is secure */
      0x00000000 |      /* Interrupt  56: PUF                   is secure */
      0x02000000 |      /* Interrupt  57: POWERQUAD             is non-secure */
      0x04000000 |      /* Interrupt  58: SDMA1                 is non-secure */
      0x08000000 |      /* Interrupt  59: HS_SPI                is non-secure */
      0x00000000 |      /* Interrupt  60: ---                   is secure */
      0x00000000 |      /* Interrupt  61: ---                   is secure */
      0x00000000 |      /* Interrupt  62: ---                   is secure */
      0x00000000;       /* Interrupt  63: ---                   is secure */

#if defined (SCB_CSR_AIRCR_INIT) && (SCB_CSR_AIRCR_INIT == 1U)
  SCB->SCR   = (SCB->SCR   & ~(SCB_SCR_SLEEPDEEPS_Msk    )) |
                 ((SCB_CSR_DEEPSLEEPS_VAL     << SCB_SCR_SLEEPDEEPS_Pos)     & SCB_SCR_SLEEPDEEPS_Msk);

  SCB->AIRCR = (SCB->AIRCR & ~(SCB_AIRCR_VECTKEY_Msk   | SCB_AIRCR_SYSRESETREQS_Msk |
                               SCB_AIRCR_BFHFNMINS_Msk | SCB_AIRCR_PRIS_Msk          ))                    |
                 ((0x05FAU                    << SCB_AIRCR_VECTKEY_Pos)      & SCB_AIRCR_VECTKEY_Msk)      |
                 ((SCB_AIRCR_SYSRESETREQS_VAL << SCB_AIRCR_SYSRESETREQS_Pos) & SCB_AIRCR_SYSRESETREQS_Msk) |
                 ((SCB_AIRCR_PRIS_VAL         << SCB_AIRCR_PRIS_Pos)         & SCB_AIRCR_PRIS_Msk)         |
                 ((SCB_AIRCR_BFHFNMINS_VAL    << SCB_AIRCR_BFHFNMINS_Pos)    & SCB_AIRCR_BFHFNMINS_Msk);
#endif /* defined (SCB_CSR_AIRCR_INIT) && (SCB_CSR_AIRCR_INIT == 1U) */

}
