/*******************************************************************************
 * Copyright (c) 2015 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Jeffrey Dare - initial implementation and API implementation
 *    Lokesh Haralakatta - Added required changes to use Client Side certificates
 *******************************************************************************/

#include "deviceclient.h"
#include "cmsis_os2.h"

#define ORG_ID                  ""
#define DEVICE_TYPE             ""
#define DEVICE_ID               ""
#define TOKEN                   ""

#define USE_CERT                0
#define CA_CERT_PATH            ""
#define CLIENT_CERT_PATH        ""
#define CLIENT_KEY_PATH         ""

int helloWorld (void)
{
    int rc = -1;
    int count = 0;

    iotfclient client;

    rc = initialize(&client, ORG_ID, "internetofthings.ibmcloud.com",
                    DEVICE_TYPE, DEVICE_ID, "token", TOKEN, NULL,
                    USE_CERT, CA_CERT_PATH, CLIENT_CERT_PATH, CLIENT_KEY_PATH,
                    0);

    if (rc != SUCCESS) {
        printf("Initialize failed and returned rc = %d.\n Quitting..", rc);
        return -1;
    }

    rc = connectiotf(&client);
    if (rc != SUCCESS) {
        printf("Connection failed and returned rc = %d.\n Quitting..", rc);
        return -1;
    }

    printf("Connection Successful.\n");

    char *data = "{\"d\" : {\"x\" : 26 }}";

    while (++count <= 10)
    {
        printf("Publishing the event stat with rc ");
        rc = publishEvent(&client, "status", "json", data , QOS0);
        printf(" %d\n", rc);
        osDelay(2000);
    }

    printf("Quitting!!\n");

    disconnect(&client);

    return 0;
}
