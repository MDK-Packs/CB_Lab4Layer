Watson MQTT Demo
================

This demo application connects to **Watson IoT** through MQTT and publishes messages.

It requires a [*registered device*](https://github.com/MDK-Packs/Documentation/blob/master/IBM_Watson_IoT/README.md).

The following describes the various components and the configuration settings.

Once the application is configured you can:
- Build the application.
- Connect the debugger.
- Run the application and view messages in a debug printf or terminal window.

Watson IoT Client
-----------------

The file `helloWorld.c` configures the connection to Watson IoT with these settings:
- `ORG_ID`: Organization ID
- `DEVICE_TYPE`: Device Type
- `DEVICE_ID`:  Device ID
- `TOKEN`: Authentication Token

*Note*: These settings need to be configured by the user!

The file `IoTFoundation.pem` provides the server certificate.

*Note*: The server certificate needs to be provided by the user and needs to exist on the file system drive M0!
