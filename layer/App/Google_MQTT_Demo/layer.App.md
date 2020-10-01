Google MQTT Demo
================

This demo application connects to **Google Cloud IoT** through MQTT and publishes messages.

It requires a [*registered device*](https://github.com/MDK-Packs/Documentation/blob/master/Google_Cloud/README.md).

The following describes the various components and the configuration settings.

Once the application is configured you can:
- Build the application.
- Connect the debugger.
- Run the application and view messages in a debug printf or terminal window.

Google IoT Client
-----------------
The file `demo.c` configures the connection to Google IoT with these settings:
- `PROJECT_ID`: Project ID
- `CLOUD_REGION`: Cloud region
- `REGISTRY_ID`: Registry ID
- `DEVICE_ID`: Device ID

*Note*: These settings need to be configured by the user!

The file `pkey.h` configures the device private key.

*Note*: The device private key needs to be provided by the user!
