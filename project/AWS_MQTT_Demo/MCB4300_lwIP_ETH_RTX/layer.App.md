AWS MQTT Demo
=============

This demo application connects to **AWS IoT** through MQTT, subscribes to topics and publishes messages.

It requires an active and [*properly configured thing*](https://github.com/MDK-Packs/Documentation/blob/master/AWS_Thing/README.md).

You can use the MQTT client in the **AWS IoT console** to watch the MQTT message exchange.

The following describes the various components and the configuration settings.

Once the application is configured you can:
- Build the application.
- Connect the debugger.
- Run the application and view messages in a debug printf or terminal window.

AWS IoT Client
--------------

The file `iot_config.h` configures the connection to AWS IoT with these settings:
- `IOT_DEMO_SERVER`: Remote Host
- `IOT_DEMO_ROOT_CA`: Trusted Server Root Certificate
- `IOT_DEMO_CLIENT_CERT`: Client Certificate
- `IOT_DEMO_PRIVATE_KEY`: Client Private Key
- `IOT_DEMO_IDENTIFIER`: Thing Identifier

*Note*: These settings require user configuration!
