#!/bin/bash

BOARD=STM32L562-DK_NoTZ
MODULE=ISM43362

echo "Generate project AWS_MQTT_Demo"
echo "  Board:  "$BOARD
echo "  Module: "$MODULE
echo

mkdir -p "${BOARD}_${MODULE}"
pushd "${BOARD}_${MODULE}"
cbuildgen compose aws_mqtt_demo.cprj \
 ../../../layer/App/AWS_MQTT_Demo/App.clayer \
 ../../../layer/Socket/WiFi_${MODULE}/Socket.clayer \
 ../../../layer/Board/${BOARD}/Board.clayer
popd

echo
echo "Manually update project"
echo " - RTE/IoT_Client/iot_config.h"
echo "     AWS connection settings (see Abstract.txt)"
echo " - socket_startup.c"
echo "     WiFi connection settings (see Abstract.txt)"
echo " - RTE/CMSIS_Driver/WiFi_ISM43362_Config.h"
echo "     Connect to Driver_SPI3"
echo
echo "Build project (optional)"
echo "  cbuild.sh aws_mqtt_demo.cprj"
echo
echo "Run project"
echo " - open aws_mqtt_demo.cprj (uVision)"
echo " - if already built with cbuild"
echo "   - change folder for Objects: Objects"
echo "   - change folder for Listings: Listings"
echo " - if building with uVision"
echo "   - Software Model: TrustZone disabled"
echo " - select ST-Link Debugger"
echo "     Core Clock: 110 MHz"
echo "     Trace Enable"
echo " - Flash Erase"
echo " - Flash Download"
echo " - Start Debug Session"
echo " - Open Debug (printf) Viewer"
echo " - Run Target"
