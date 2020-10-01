/**************************************************************************//**
 * @file     partition_gen.h
 * @brief    CMSIS-CORE Initial Setup for Secure / Non-Secure Zones for STM32L552xx Device
 * @version  V1.0.0
 * @date     20.02.2020
 ******************************************************************************/
/*
 * Copyright (c) 2009-2019 Arm Limited. All rights reserved.
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

#ifndef PARTITION_GEN_H
#define PARTITION_GEN_H

/*
//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------
*/

/*
// <h>Initialize Security Attribution Unit (SAU) Address Regions
// <i>SAU configuration specifies regions to be one of:
// <i> - Secure and Non-Secure Callable
// <i> - Non-Secure
// <i>Note: All memory regions not configured by SAU are Secure
*/
#define SAU_REGIONS_MAX   8                 /* Max. number of SAU regions */

/*
//   <e>Initialize SAU Region 0
//   <i> Setup SAU Region 0 memory attributes
*/
#define SAU_INIT_REGION0    1

/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START0     0x08040000      /* start address of SAU region 0 */

/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END0       0x0806FFE0      /* end address of SAU region 0 */

/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC0       0
/*
//   </e>
*/

/*
//   <e>Initialize SAU Region 1
//   <i> Setup SAU Region 1 memory attributes
*/
#define SAU_INIT_REGION1    1

/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START1     0x0C03FC00      /* start address of SAU region 1 */

/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END1       0x0C03FF20      /* end address of SAU region 1 */

/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC1       1
/*
//   </e>
*/

/*
//   <e>Initialize SAU Region 2
//   <i> Setup SAU Region 2 memory attributes
*/
#define SAU_INIT_REGION2    1

/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START2     0x20020000      /* start address of SAU region 2 */

/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END2       0x2003FFE0      /* end address of SAU region 2 */

/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC2       0
/*
//   </e>
*/

/*
//   <e>Initialize SAU Region 3
//   <i> Setup SAU Region 3 memory attributes
*/
#define SAU_INIT_REGION3    1

/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START3     0x40000000      /* start address of SAU region 3 */

/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END3       0x4FFFFFE0      /* end address of SAU region 3 */

/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC3       0
/*
//   </e>
*/

/*
//   <e>Initialize SAU Region 4
//   <i> Setup SAU Region 4 memory attributes
*/
#define SAU_INIT_REGION4    0

/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START4     0x00000000      /* start address of SAU region 4 */

/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END4       0x00000000      /* end address of SAU region 4 */

/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC4       0
/*
//   </e>
*/

/*
//   <e>Initialize SAU Region 5
//   <i> Setup SAU Region 5 memory attributes
*/
#define SAU_INIT_REGION5    0

/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START5     0x00000000      /* start address of SAU region 5 */

/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END5       0x00000000      /* end address of SAU region 5 */

/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC5       0
/*
//   </e>
*/

/*
//   <e>Initialize SAU Region 6
//   <i> Setup SAU Region 6 memory attributes
*/
#define SAU_INIT_REGION6    0

/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START6     0x00000000      /* start address of SAU region 6 */

/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END6       0x00000000      /* end address of SAU region 6 */

/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC6       0
/*
//   </e>
*/

/*
//   <e>Initialize SAU Region 7
//   <i> Setup SAU Region 7 memory attributes
*/
#define SAU_INIT_REGION7    0

/*
//     <o>Start Address <0-0xFFFFFFE0>
*/
#define SAU_INIT_START7     0x00000000      /* start address of SAU region 7 */

/*
//     <o>End Address <0x1F-0xFFFFFFFF>
*/
#define SAU_INIT_END7       0x00000000      /* end address of SAU region 7 */

/*
//     <o>Region is
//         <0=>Non-Secure
//         <1=>Secure, Non-Secure Callable
*/
#define SAU_INIT_NSC7       0
/*
//   </e>
*/

/*
// </h>
*/


/*
// <h>Setup Interrupt Target
*/

/*
//   <e>Initialize ITNS 0 (Interrupts 0..31)
*/
#define NVIC_INIT_ITNS0    1

/*
// Interrupts 0..31
//   <o.0>  WWDG_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.1>  PVD_PVM_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.2>  RTC_IRQn            <0=> Secure state <1=> Non-Secure state
//   <o.3>  RTC_S_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.4>  TAMP_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.5>  TAMP_S_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.6>  FLASH_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.7>  FLASH_S_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.8>  GTZC_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.9>  RCC_IRQn            <0=> Secure state <1=> Non-Secure state
//   <o.10> RCC_S_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.11> EXTI0_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.12> EXTI1_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.13> EXTI2_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.14> EXTI3_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.15> EXTI4_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.16> EXTI5_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.17> EXTI6_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.18> EXTI7_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.19> EXTI8_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.20> EXTI9_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.21> EXTI10_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.22> EXTI11_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.23> EXTI12_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.24> EXTI13_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.25> EXTI14_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.26> EXTI15_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.27> DMAMUX1_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.28> DMAMUX1_S_IRQn      <0=> Secure state <1=> Non-Secure state
//   <o.29> DMA1_Channel1_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.30> DMA1_Channel2_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.31> DMA1_Channel3_IRQn  <0=> Secure state <1=> Non-Secure state
*/
#define NVIC_INIT_ITNS0_VAL      0xFFFFFFFF

/*
//   </e>
*/

/*
//   <e>Initialize ITNS 1 (Interrupts 32..63)
*/
#define NVIC_INIT_ITNS1    1

/*
// Interrupts 32..63
//   <o.0>  DMA1_Channel4_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.1>  DMA1_Channel5_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.2>  DMA1_Channel6_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.3>  DMA1_Channel7_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.4>  DMA1_Channel8_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.5>  ADC1_2_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.6>  DAC_IRQn            <0=> Secure state <1=> Non-Secure state
//   <o.7>  FDCAN1_IT0_IRQn     <0=> Secure state <1=> Non-Secure state
//   <o.8>  FDCAN1_IT1_IRQn     <0=> Secure state <1=> Non-Secure state
//   <o.9>  TIM1_BRK_IRQn       <0=> Secure state <1=> Non-Secure state
//   <o.10> TIM1_UP_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.11> TIM1_TRG_COM_IRQn   <0=> Secure state <1=> Non-Secure state
//   <o.12> TIM1_CC_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.13> TIM2_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.14> TIM3_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.15> TIM4_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.16> TIM5_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.17> TIM6_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.18> TIM7_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.19> TIM8_BRK_IRQn       <0=> Secure state <1=> Non-Secure state
//   <o.20> TIM8_UP_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.21> TIM8_TRG_COM_IRQn   <0=> Secure state <1=> Non-Secure state
//   <o.22> TIM8_CC_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.23> I2C1_EV_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.24> I2C1_ER_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.25> I2C2_EV_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.26> I2C2_ER_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.27> SPI1_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.28> SPI2_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.29> USART1_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.30> USART2_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.31> USART3_IRQn         <0=> Secure state <1=> Non-Secure state
*/
#define NVIC_INIT_ITNS1_VAL      0xFFFFFFFF

/*
//   </e>
*/

/*
//   <e>Initialize ITNS 2 (Interrupts 64..95)
*/
#define NVIC_INIT_ITNS2    1

/*
// Interrupts 64..95
//   <o.0>  UART4_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.1>  UART5_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.2>  LPUART1_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.3>  LPTIM1_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.4>  LPTIM2_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.5>  TIM15_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.6>  TIM16_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.7>  TIM17_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.8>  COMP_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.9>  USB_FS_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.10> CRS_IRQn            <0=> Secure state <1=> Non-Secure state
//   <o.11> FMC_IRQn            <0=> Secure state <1=> Non-Secure state
//   <o.12> OCTOSPI1_IRQn       <0=> Secure state <1=> Non-Secure state
//   <o.13> Reserved            <0=> Secure state <1=> Non-Secure state
//   <o.14> SDMMC1_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.15> Reserved            <0=> Secure state <1=> Non-Secure state
//   <o.16> DMA2_Channel1_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.17> DMA2_Channel2_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.18> DMA2_Channel3_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.19> DMA2_Channel4_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.20> DMA2_Channel5_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.21> DMA2_Channel6_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.22> DMA2_Channel7_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.23> DMA2_Channel8_IRQn  <0=> Secure state <1=> Non-Secure state
//   <o.24> I2C3_EV_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.25> I2C3_ER_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.26> SAI1_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.27> SAI2_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.28> TSC_IRQn            <0=> Secure state <1=> Non-Secure state
//   <o.30> RNG_IRQn            <0=> Secure state <1=> Non-Secure state
//   <o.31> FPU_IRQn            <0=> Secure state <1=> Non-Secure state
*/
#define NVIC_INIT_ITNS2_VAL      0xFFFFFFFF

/*
//   </e>
*/

/*
//   <e>Initialize ITNS 3 (Interrupts 96..108)
*/
#define NVIC_INIT_ITNS3    1

/*
// Interrupts 96..108
//   <o.0>  HASH_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.2>  LPTIM3_IRQn         <0=> Secure state <1=> Non-Secure state
//   <o.3>  SPI3_IRQn           <0=> Secure state <1=> Non-Secure state
//   <o.4>  I2C4_EV_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.5>  I2C4_ER_IRQn        <0=> Secure state <1=> Non-Secure state
//   <o.6>  DFSDM1_FLT0_IRQn    <0=> Secure state <1=> Non-Secure state
//   <o.7>  DFSDM1_FLT1_IRQn    <0=> Secure state <1=> Non-Secure state
//   <o.8>  DFSDM1_FLT2_IRQn    <0=> Secure state <1=> Non-Secure state
//   <o.9>  DFSDM1_FLT3_IRQn    <0=> Secure state <1=> Non-Secure state
//   <o.10> UCPD1_IRQn          <0=> Secure state <1=> Non-Secure state
//   <o.11> ICACHE_IRQn         <0=> Secure state <1=> Non-Secure state
*/
#define NVIC_INIT_ITNS3_VAL      0x00000FFF

/*
//   </e>
*/

/*
// </h>
*/

#endif  /* PARTITION_GEN_H */
