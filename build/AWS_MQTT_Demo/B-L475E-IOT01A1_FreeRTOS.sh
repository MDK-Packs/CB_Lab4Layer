#!/bin/bash

BOARD=B-L475E-IOT01A1
RTOS=FreeRTOS

echo "Generate project AWS_MQTT_Demo"
echo "  Board:  "$BOARD
echo "  RTOS:   "$RTOS
echo

mkdir -p "${BOARD}_${RTOS}"
pushd "${BOARD}_${RTOS}"
cbuildgen compose aws_mqtt_demo.cprj \
 ../../../layer/App/AWS_MQTT_Demo/App.clayer \
 ../../../layer/Socket/WiFi/Socket.clayer \
 ../../../layer/Board/${BOARD}_${RTOS}/Board.clayer
popd

echo
echo "Manually update project"
echo " - RTE/IoT_Client/iot_config.h"
echo "     AWS connection settings (see Abstract.txt)"
echo " - network.c"
echo "     WiFi connection settings (see Abstract.txt)"
echo
echo "Build project (optional)"
echo "  cbuild.sh aws_mqtt_demo.cprj"
echo
echo "Run project"
echo " - open aws_mqtt_demo.cprj (uVision)"
echo " - if already built with cbuild"
echo "   - change folder for Objects: Objects"
echo "   - change folder for Listings: Listings"
echo " - otherwise build with uVision"
echo " - select ST-Link Debugger"
echo "     Core Clock: 80 MHz"
echo "     Trace Enable"
echo " - Start Debug Session"
echo " - Open Debug (printf) Viewer"
echo " - Run Target"
