#!/bin/bash

BOARD=MCB4300
SOCKET=lwIP

echo "Generate project AWS_MQTT_Demo"
echo "  Board:  "$BOARD
echo "  Socket: "$SOCKET
echo

mkdir -p "${BOARD}_${SOCKET}"
pushd "${BOARD}_${SOCKET}"
cbuildgen compose aws_mqtt_demo.cprj \
 ../../../layer/Application/AWS_MQTT_Demo/Application.clayer \
 ../../../layer/Cloud/AWS/Cloud.clayer \
 ../../../layer/Socket/${SOCKET}/Socket.clayer \
 ../../../layer/Board/${BOARD}/Board.clayer
popd

echo
echo "Manually update project"
echo " - RTE/IoT_Client/iot_config.h"
echo "     AWS connection settings (see Abstract.txt)"
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
echo " - select ULINKplus Debugger"
echo "     Core Clock: 180 MHz"
echo "     Trace Enable"
echo " - Start Debug Session"
echo " - Open Debug (printf) Viewer"
echo " - Run Target"
