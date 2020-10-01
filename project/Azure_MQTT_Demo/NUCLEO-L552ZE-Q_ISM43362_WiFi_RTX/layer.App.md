Azure MQTT Demo
===============

This demo application connects to the **Azure IoT Hub** through MQTT, sends messages and checks for receive confirmation.

It requires a [*registered device*](https://github.com/MDK-Packs/Documentation/blob/master/Microsoft_Azure_IoT_Hub/README.md).

The following describes the various components and the configuration settings.

Once the application is configured you can:
- Build the application.
- Connect the debugger.
- Run the application and view messages in a debug printf or terminal window.

Azure IoT Client
----------------
The file `iothub_ll_telemetry_sample_mdk.c` configures the connection to the Azure IoT Hub with these settings:
- `connectionString`: Connection string - primary key

*Note*: This setting requires user configuration!
