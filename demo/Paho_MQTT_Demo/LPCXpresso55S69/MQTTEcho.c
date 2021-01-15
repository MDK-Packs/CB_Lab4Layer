// MQTT Echo

#include <string.h>
#include "MQTTClient.h"

#if (MQTT_MBEDTLS != 0)
#include "certificates.h"
#endif

#define SERVER_NAME "test.mosquitto.org"
#if (MQTT_MBEDTLS != 0)
#define SERVER_PORT 8883
#else
#define SERVER_PORT 1883
#endif

void messageArrived(MessageData* data)
{
  printf("Message arrived on topic %.*s: %.*s\n", data->topicName->lenstring.len, data->topicName->lenstring.data,
  data->message->payloadlen, (char *)data->message->payload);
}

void MQTTEcho_Test (void)
{
  MQTTClient client;
  Network network;
#if (MQTT_MBEDTLS != 0)
  TLScert tlscert = {(char *)CA_Cert, NULL, NULL};
#endif
  unsigned char sendbuf[80], readbuf[80];

  int rc = 0, count = 0;
  MQTTPacket_connectData connectData = MQTTPacket_connectData_initializer;

  NetworkInit(&network);

  MQTTClientInit(&client, &network, 30000, sendbuf, sizeof(sendbuf), readbuf, sizeof(readbuf));

#if (MQTT_MBEDTLS != 0)
  if ((rc = NetworkConnectTLS(&network, SERVER_NAME, SERVER_PORT, &tlscert)) != 0)
#else
  if ((rc = NetworkConnect(&network, SERVER_NAME, SERVER_PORT)) != 0)
#endif
    printf("Return code from network connect is %d\n", rc);

#if defined(MQTT_TASK)
  if ((rc = MQTTStartTask(&client)) == 0)
    printf("Return code from start tasks is %d\n", rc);
#endif

  connectData.MQTTVersion = 3;
  connectData.clientID.cstring = "MDK_sample";

  if ((rc = MQTTConnect(&client, &connectData)) != 0)
    printf("Return code from MQTT connect is %d\n", rc);
  else
    printf("MQTT Connected\n");

  if ((rc = MQTTSubscribe(&client, "MDK/sample/#", QOS2, messageArrived)) != 0)
    printf("Return code from MQTT subscribe is %d\n", rc);

  while (++count <= 10)
  {
    MQTTMessage message;
    char payload[30];

    message.qos = QOS1;
    message.retained = 0;
    message.payload = payload;
    sprintf(payload, "message number %d", count);
    message.payloadlen = strlen(payload);

    if ((rc = MQTTPublish(&client, "MDK/sample/a", &message)) != 0)
      printf("Return code from MQTT publish is %d\n", rc);

#if !defined(MQTT_TASK)
    if ((rc = MQTTYield(&client, 1000)) != 0)
      printf("Return code from yield is %d\n", rc);
#endif
  }

  NetworkDisconnect(&network);
  printf("MQTT Disconnected\n");
}
