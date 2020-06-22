// Google Cloud IoT Demo

#include <string.h>
#include "MQTTClient.h"
#include "google_iot.h"
#include "certificates.h"
#include "pkey.h"

#define PROJECT_ID      ""
#define CLOUD_REGION    ""
#define REGISTRY_ID     ""
#define DEVICE_ID       ""

#define JWT_EXPIRATION  3600

#define SERVER_NAME "mqtt.googleapis.com"
#define SERVER_PORT 8883

#define NTP_SERVER  "time.google.com"

extern int32_t sntp_get_time (const char *server, uint32_t *seconds);

void messageArrived(MessageData* data)
{
  printf("Configuration Message arrived: %.*s\n",
         data->message->payloadlen, (char *)data->message->payload);
}

void MQTT_Demo (void)
{
  MQTTClient client;
  MQTTMessage message;
  Network network;
  TLScert tlscert = {(char *)CA_Cert, NULL, NULL};
  char payload[30];
  char *jwt;
  unsigned int timestamp;
  unsigned char sendbuf[768], readbuf[80];

  int rc = 0, count = 0;
  MQTTPacket_connectData connectData = MQTTPacket_connectData_initializer;

  NetworkInit(&network);

  MQTTClientInit(&client, &network, 30000, sendbuf, sizeof(sendbuf), readbuf, sizeof(readbuf));

  if ((rc = NetworkConnectTLS(&network, SERVER_NAME, SERVER_PORT, &tlscert)) != 0)
    printf("Return code from network connect is %d\n", rc);

#if defined(MQTT_TASK)
  if ((rc = MQTTStartTask(&client)) == 0)
    printf("Return code from start tasks is %d\n", rc);
#endif

  sntp_get_time(NTP_SERVER, &timestamp);

  jwt = google_iot_jwt(PrivateKey, PROJECT_ID, timestamp, timestamp + JWT_EXPIRATION);
  if (jwt == NULL)
    printf("JWT not created\n");

  connectData.clientID.cstring = GOOGLE_IOT_CLIENT_ID(PROJECT_ID, CLOUD_REGION, REGISTRY_ID, DEVICE_ID);
  connectData.password.cstring = jwt;

  if ((rc = MQTTConnect(&client, &connectData)) != 0)
    printf("Return code from MQTT connect is %d\n", rc);
  else
    printf("MQTT Connected\n");

  free(jwt);

  message.qos = QOS1;
  message.retained = 0;
  message.payload = payload;

  sprintf(payload, "Device is active");
  message.payloadlen = strlen(payload);

  if ((rc = MQTTPublish(&client, "/devices/"DEVICE_ID"/state", &message)) != 0)
    printf("Return code from MQTT publish is %d\n", rc);
  else
    printf("MQTT Publish Device State (active)\n");

  if ((rc = MQTTSubscribe(&client, "/devices/"DEVICE_ID"/config", QOS1, messageArrived)) != 0)
    printf("Return code from MQTT subscribe is %d\n", rc);

  while (++count <= 10)
  {
    sprintf(payload, "message number %d", count);
    message.payloadlen = strlen(payload);

    if ((rc = MQTTPublish(&client, "/devices/"DEVICE_ID"/events", &message)) != 0)
      printf("Return code from MQTT publish is %d\n", rc);
  else
    printf("MQTT Publish Event (%d)\n", count);

#if !defined(MQTT_TASK)
  if ((rc = MQTTYield(&client, 1000)) != 0)
    printf("Return code from yield is %d\n", rc);
#endif
  }

  sprintf(payload, "Device is idle");
  message.payloadlen = strlen(payload);

  if ((rc = MQTTPublish(&client, "/devices/"DEVICE_ID"/state", &message)) != 0)
    printf("Return code from MQTT publish is %d\n", rc);
  else
    printf("MQTT Publish Device State (idle)\n");

  NetworkDisconnect(&network);
  printf("MQTT Disconnected\n");
}
