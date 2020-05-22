#!/bin/bash

BOARD=NUCLEO-L552ZE-Q_NoTZ
MODULE=WizFi360

echo "Generate project AWS_MQTT_Demo"
echo "  Board:  "$BOARD
echo "  Module: "$MODULE
echo

mkdir -p "${BOARD}_${MODULE}"
pushd "${BOARD}_${MODULE}"
cbuildgen compose aws_mqtt_demo.cprj \
 ../../../layer/Application/AWS_MQTT_Demo/Application.clayer \
 ../../../layer/Cloud/AWS/Cloud.clayer \
 ../../../layer/Socket/WiFi/Socket.clayer \
 ../../../layer/Board/${BOARD}/Board.clayer \
 ../../../layer/Module/${MODULE}/Module.clayer
popd

echo
echo "Manually update project"
echo " - RTE/IoT_Client/iot_config.h"
echo "     AWS connection settings (see Abstract.txt)"
echo " - network.c"
echo "     WiFi connection settings (see Abstract.txt)"
echo " - RTE/CMSIS_Driver/WiFi_WizFi360_Config.h"
echo "     Connect to Driver_USART3"
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
