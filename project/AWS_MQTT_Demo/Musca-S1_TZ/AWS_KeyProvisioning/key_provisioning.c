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

#include <stdint.h>

/* PSA includes. */
#include "psa/crypto.h"

/* mbedTLS includes. */
#include "mbedtls/pk.h"
#include "mbedtls/asn1.h"

/* PSA Device Private Key ID. */
#ifndef PSA_DEVICE_PRIVATE_KEY_ID
#define PSA_DEVICE_PRIVATE_KEY_ID   1U
#endif

/*
 * Get the content of the privateKey field of the ECPrivateKey
 * format defined by RFC 5915.
 *
 * RFC 5915, or SEC1 Appendix C.4
 *
 * ECPrivateKey ::= SEQUENCE {
 *   version        INTEGER { ecPrivkeyVer1(1) } (ecPrivkeyVer1),
 *   privateKey     OCTET STRING,
 *   parameters [0] ECParameters {{ NamedCurve }} OPTIONAL,
 *   publicKey  [1] BIT STRING OPTIONAL
 * }
 */
static int get_ECPrivateKey_sequence_privatekey_sec1_der ( const uint8_t * key,
                                                           size_t keylen,
                                                           uint8_t **privatekeystart,
                                                           size_t * privatekeyderlength )
{
    int ret;
    int version;
    size_t len;
    uint8_t *p = (uint8_t *) key;
    uint8_t *end = p + keylen;

    if( ( ret = mbedtls_asn1_get_tag( &p, end, &len,
        MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE ) ) != 0 )
    {
        return( MBEDTLS_ERR_PK_KEY_INVALID_FORMAT + ret );
    }

    end = p + len;

    if( ( ret = mbedtls_asn1_get_int( &p, end, &version ) ) != 0 )
        return( MBEDTLS_ERR_PK_KEY_INVALID_FORMAT + ret );

    if( version != 1 )
        return( MBEDTLS_ERR_PK_KEY_INVALID_VERSION );

    if( ( ret = mbedtls_asn1_get_tag( &p, end, &len, MBEDTLS_ASN1_OCTET_STRING ) ) != 0 )
        return( MBEDTLS_ERR_PK_KEY_INVALID_FORMAT + ret );

    /* Finally get the start address of privatekey and its length. */
    *privatekeystart = p;
    *privatekeyderlength = len;

    return 0;
}

/**
 * @brief Provision Private Key.
 *
 * Uses mbed TLS to parse and PSA to store the private key in Internal Trusted Storage.
 * @param[in] pucPrivateKey Private Key (PEM).
 * @param[in] xPrivateKeyLength Private key length.
 *
 * @return `0` on success; negative value indicating error otherwise.
 */

int32_t xProvisionPrivateKey( const uint8_t * pucPrivateKey,
                              size_t xPrivateKeyLength )
{
    const uint8_t *pucKeyData;
    size_t xKeyDataSize;
    uint8_t *pucPrivateKeyDerStart;
    size_t xPrivateKeyDerSize;
    mbedtls_pk_context pk_ctx;
    mbedtls_pk_type_t pk_type;
    const mbedtls_ecp_keypair *ec;
    int ret;
    psa_key_handle_t key_handle;
    psa_key_attributes_t key_attributes;
    psa_key_type_t key_type;
    psa_algorithm_t algorithm;
    psa_ecc_curve_t curve_id;
    psa_status_t status;
    int32_t result = 0;

    mbedtls_pk_init( &pk_ctx );

    ret = mbedtls_pk_parse_key( &pk_ctx, pucPrivateKey, xPrivateKeyLength, NULL, 0U );
    if( ret != 0 )
    {
        result = -1;
    }

    if( result == 0 )
    {
        status = psa_crypto_init();
        if( status != PSA_SUCCESS )
        {
            result = -1;
        }
    }

    if( result == 0 )
    {
        status = psa_open_key( PSA_DEVICE_PRIVATE_KEY_ID, &key_handle );
        if( status == PSA_SUCCESS )
        {
            psa_destroy_key( key_handle );
        }
    }

    if( result == 0 )
    {

        pk_type = mbedtls_pk_get_type( &pk_ctx );
        switch ( pk_type )
        {
            case MBEDTLS_PK_RSA:
                key_type = PSA_KEY_TYPE_RSA_KEY_PAIR;
                switch( ( ( mbedtls_rsa_context * ) ( &pk_ctx ) )->padding )
                {
                    case MBEDTLS_RSA_PKCS_V15:
                        algorithm = PSA_ALG_RSA_PKCS1V15_SIGN( PSA_ALG_SHA_256 );
                        break;
                    case MBEDTLS_RSA_PKCS_V21:
                        algorithm = PSA_ALG_RSA_PSS( PSA_ALG_SHA_256 );
                        break;
                    default:
                        algorithm = 0U;
                        break;
                }
                pucKeyData = pucPrivateKey;
                xKeyDataSize = xPrivateKeyLength;
                break;
            case MBEDTLS_PK_ECKEY:
            case MBEDTLS_PK_ECDSA:
                ec = ( mbedtls_ecp_keypair * ) ( &pk_ctx );
                curve_id = mbedtls_ecp_curve_info_from_grp_id( ec->grp.id )->tls_id;
                key_type = PSA_KEY_TYPE_ECC_KEY_PAIR( curve_id );
                algorithm = PSA_ALG_ECDSA( PSA_ALG_SHA_256 );
                ret = get_ECPrivateKey_sequence_privatekey_sec1_der( pucPrivateKey,
                                                                     xPrivateKeyLength,
                                                                     &pucPrivateKeyDerStart,
                                                                     &xPrivateKeyDerSize );
                if( ret == 0 )
                {
                    pucKeyData = pucPrivateKeyDerStart;
                    xKeyDataSize = xPrivateKeyDerSize;
                }
                else
                {
                    key_type = PSA_KEY_TYPE_NONE;
                    algorithm = 0U;
                }
                break;
            default:
                key_type = PSA_KEY_TYPE_NONE;
                algorithm = 0U;
        }

        key_attributes = psa_key_attributes_init();
        psa_set_key_id( &key_attributes, PSA_DEVICE_PRIVATE_KEY_ID );
        psa_set_key_lifetime( &key_attributes, PSA_KEY_LIFETIME_PERSISTENT );
        psa_set_key_usage_flags( &key_attributes, PSA_KEY_USAGE_SIGN );
        psa_set_key_type( &key_attributes, key_type );
        psa_set_key_algorithm( &key_attributes, algorithm );

        status = psa_import_key( &key_attributes, pucKeyData, xKeyDataSize, &key_handle );
        if( status == PSA_SUCCESS )
        {
            psa_close_key( key_handle );
        }
        else
        {
            result = -1;
        }
    }

    return result;
}
