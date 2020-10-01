/*
 * Copyright (c) 2020 ARM Limited. All rights reserved.
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

#ifndef KEY_PROVISIONING_H_
#define KEY_PROVISIONING_H_

#include <stdint.h>

/**
 * @brief Provision Private Key.
 *
 * Uses mbed TLS to parse and PSA to store the private key in Internal Trusted Storage.
 * @param[in] pucPrivateKey Private Key (PEM).
 * @param[in] xPrivateKeyLength Private key length.
 *
 * @return `0` on success; negative value indicating error otherwise.
 */

int32_t xProvisionPrivateKey(const uint8_t *pucPrivateKey, size_t xPrivateKeyLength);

#endif /* KEY_PROVISIONING_H_ */
