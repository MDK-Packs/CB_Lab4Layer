#!/bin/bash

# header
echo "Creating AWS Project ZIP Files"

# usage
usage() {
  echo "Usage:"
  echo "  createzips.sh"
  echo ""
}

pushd AWS_MQTT_Demo/LPCXpresso55S69_ESP8266_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip AWS_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_FreeRTOS.zip *
mv AWS_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_FreeRTOS.zip /c/Temp
popd

pushd AWS_MQTT_Demo/LPCXpresso55S69_ESP8266_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip AWS_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_RTX.zip *
mv AWS_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_RTX.zip /c/Temp
popd

pushd AWS_MQTT_Demo/LPCXpresso55S69_ISM43362_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip AWS_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_FreeRTOS.zip *
mv AWS_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_FreeRTOS.zip /c/Temp
popd

pushd AWS_MQTT_Demo/LPCXpresso55S69_ISM43362_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip AWS_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_RTX.zip *
mv AWS_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_RTX.zip /c/Temp
popd

pushd AWS_MQTT_Demo/LPCXpresso55S69_WizFi360_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip AWS_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_FreeRTOS.zip *
mv AWS_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_FreeRTOS.zip /c/Temp
popd

pushd AWS_MQTT_Demo/LPCXpresso55S69_WizFi360_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip AWS_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_RTX.zip *
mv AWS_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_RTX.zip /c/Temp
popd

pushd AWS_MQTT_Demo/MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip AWS_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS.zip *
mv AWS_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS.zip /c/Temp
popd

pushd AWS_MQTT_Demo/MIMXRT1064-EVK_ESP8266_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip AWS_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_RTX.zip *
mv AWS_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_RTX.zip /c/Temp
popd

pushd AWS_MQTT_Demo/MIMXRT1064-EVK_MW-Network_ETH_RTX
"/c/Program Files/7-ZIP/7z" a -tzip AWS_MQTT_Demo_MIMXRT1064-EVK_ISM43362_MW-Network_ETH_RTX.zip *
mv AWS_MQTT_Demo_MIMXRT1064-EVK_MW-Network_ETH_RTX.zip /c/Temp
popd

pushd AWS_MQTT_Demo/MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip AWS_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS.zip *
mv AWS_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS.zip /c/Temp
popd

pushd AWS_MQTT_Demo/MIMXRT1064-EVK_WizFi360_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip AWS_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_RTX.zip *
mv AWS_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_RTX.zip /c/Temp
popd



# Creating Azure Project ZIP Files

pushd Azure_MQTT_Demo/LPCXpresso55S69_ESP8266_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_FreeRTOS.zip *
mv Azure_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Azure_MQTT_Demo/LPCXpresso55S69_ESP8266_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_RTX.zip *
mv Azure_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_RTX.zip /c/Temp
popd

pushd Azure_MQTT_Demo/LPCXpresso55S69_ISM43362_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_FreeRTOS.zip *
mv Azure_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Azure_MQTT_Demo/LPCXpresso55S69_ISM43362_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_RTX.zip *
mv Azure_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_RTX.zip /c/Temp
popd

pushd Azure_MQTT_Demo/LPCXpresso55S69_WizFi360_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_FreeRTOS.zip *
mv Azure_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Azure_MQTT_Demo/LPCXpresso55S69_WizFi360_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_RTX.zip *
mv Azure_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_RTX.zip /c/Temp
popd

pushd Azure_MQTT_Demo/MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS.zip *
mv Azure_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Azure_MQTT_Demo/MIMXRT1064-EVK_ESP8266_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_RTX.zip *
mv Azure_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_RTX.zip /c/Temp
popd

pushd Azure_MQTT_Demo/MIMXRT1064-EVK_MW-Network_ETH_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_MIMXRT1064-EVK_ISM43362_MW-Network_ETH_FreeRTOS.zip *
mv Azure_MQTT_Demo_MIMXRT1064-EVK_MW-Network_ETH_FreeRTOS.zip /c/Temp
popd

pushd Azure_MQTT_Demo/MIMXRT1064-EVK_MW-Network_ETH_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_MIMXRT1064-EVK_ISM43362_MW-Network_ETH_RTX.zip *
mv Azure_MQTT_Demo_MIMXRT1064-EVK_MW-Network_ETH_RTX.zip /c/Temp
popd

pushd Azure_MQTT_Demo/MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS.zip *
mv Azure_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Azure_MQTT_Demo/MIMXRT1064-EVK_WizFi360_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Azure_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_RTX.zip *
mv Azure_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_RTX.zip /c/Temp
popd


# Creating Google Project ZIP Files

pushd Google_MQTT_Demo/LPCXpresso55S69_ESP8266_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_FreeRTOS.zip *
mv Google_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Google_MQTT_Demo/LPCXpresso55S69_ESP8266_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_RTX.zip *
mv Google_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_RTX.zip /c/Temp
popd

pushd Google_MQTT_Demo/LPCXpresso55S69_ISM43362_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_FreeRTOS.zip *
mv Google_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Google_MQTT_Demo/LPCXpresso55S69_ISM43362_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_RTX.zip *
mv Google_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_RTX.zip /c/Temp
popd

pushd Google_MQTT_Demo/LPCXpresso55S69_WizFi360_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_FreeRTOS.zip *
mv Google_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Google_MQTT_Demo/LPCXpresso55S69_WizFi360_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_RTX.zip *
mv Google_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_RTX.zip /c/Temp
popd

pushd Google_MQTT_Demo/MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS.zip *
mv Google_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Google_MQTT_Demo/MIMXRT1064-EVK_ESP8266_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_RTX.zip *
mv Google_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_RTX.zip /c/Temp
popd

pushd Google_MQTT_Demo/MIMXRT1064-EVK_MW-Network_ETH_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_MIMXRT1064-EVK_ISM43362_MW-Network_ETH_FreeRTOS.zip *
mv Google_MQTT_Demo_MIMXRT1064-EVK_MW-Network_ETH_FreeRTOS.zip /c/Temp
popd

pushd Google_MQTT_Demo/MIMXRT1064-EVK_MW-Network_ETH_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_MIMXRT1064-EVK_ISM43362_MW-Network_ETH_RTX.zip *
mv Google_MQTT_Demo_MIMXRT1064-EVK_MW-Network_ETH_RTX.zip /c/Temp
popd

pushd Google_MQTT_Demo/MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS.zip *
mv Google_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Google_MQTT_Demo/MIMXRT1064-EVK_WizFi360_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Google_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_RTX.zip *
mv Google_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_RTX.zip /c/Temp
popd


# Creating Paho Project ZIP Files

pushd Paho_MQTT_Demo/LPCXpresso55S69_ESP8266_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_FreeRTOS.zip *
mv Paho_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Paho_MQTT_Demo/LPCXpresso55S69_ESP8266_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_RTX.zip *
mv Paho_MQTT_Demo_LPCXpresso55S69_ESP8266_WiFi_RTX.zip /c/Temp
popd

pushd Paho_MQTT_Demo/LPCXpresso55S69_ISM43362_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_FreeRTOS.zip *
mv Paho_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Paho_MQTT_Demo/LPCXpresso55S69_ISM43362_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_RTX.zip *
mv Paho_MQTT_Demo_LPCXpresso55S69_ISM43362_WiFi_RTX.zip /c/Temp
popd

pushd Paho_MQTT_Demo/LPCXpresso55S69_WizFi360_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_FreeRTOS.zip *
mv Paho_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Paho_MQTT_Demo/LPCXpresso55S69_WizFi360_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_RTX.zip *
mv Paho_MQTT_Demo_LPCXpresso55S69_WizFi360_WiFi_RTX.zip /c/Temp
popd

pushd Paho_MQTT_Demo/MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS.zip *
mv Paho_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Paho_MQTT_Demo/MIMXRT1064-EVK_ESP8266_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_RTX.zip *
mv Paho_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_RTX.zip /c/Temp
popd

pushd Paho_MQTT_Demo/MIMXRT1064-EVK_MW-Network_ETH_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_MIMXRT1064-EVK_ISM43362_MW-Network_ETH_FreeRTOS.zip *
mv Paho_MQTT_Demo_MIMXRT1064-EVK_MW-Network_ETH_FreeRTOS.zip /c/Temp
popd

pushd Paho_MQTT_Demo/MIMXRT1064-EVK_MW-Network_ETH_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_MIMXRT1064-EVK_ISM43362_MW-Network_ETH_RTX.zip *
mv Paho_MQTT_Demo_MIMXRT1064-EVK_MW-Network_ETH_RTX.zip /c/Temp
popd

pushd Paho_MQTT_Demo/MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS.zip *
mv Paho_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Paho_MQTT_Demo/MIMXRT1064-EVK_WizFi360_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Paho_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_RTX.zip *
mv Paho_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_RTX.zip /c/Temp
popd


# Creating Watson Project ZIP Files

pushd Watson_MQTT_Demo/MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Watson_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS.zip *
mv Watson_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Watson_MQTT_Demo/MIMXRT1064-EVK_ESP8266_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Watson_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_RTX.zip *
mv Watson_MQTT_Demo_MIMXRT1064-EVK_ESP8266_WiFi_RTX.zip /c/Temp
popd

pushd Watson_MQTT_Demo/MIMXRT1064-EVK_MW-Network_ETH_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Watson_MQTT_Demo_MIMXRT1064-EVK_ISM43362_MW-Network_ETH_FreeRTOS.zip *
mv Watson_MQTT_Demo_MIMXRT1064-EVK_MW-Network_ETH_FreeRTOS.zip /c/Temp
popd

pushd Watson_MQTT_Demo/MIMXRT1064-EVK_MW-Network_ETH_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Watson_MQTT_Demo_MIMXRT1064-EVK_ISM43362_MW-Network_ETH_RTX.zip *
mv Watson_MQTT_Demo_MIMXRT1064-EVK_MW-Network_ETH_RTX.zip /c/Temp
popd

pushd Watson_MQTT_Demo/MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Watson_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS.zip *
mv Watson_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_FreeRTOS.zip /c/Temp
popd

pushd Watson_MQTT_Demo/MIMXRT1064-EVK_WizFi360_WiFi_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Watson_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_RTX.zip *
mv Watson_MQTT_Demo_MIMXRT1064-EVK_WizFi360_WiFi_RTX.zip /c/Temp
popd

# Creating Blinky Project ZIP Files

pushd Blinky/LPCXpresso55S69_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Blinky_LPCXpresso55S69_FreeRTOS.zip *
mv Blinky_LPCXpresso55S69_FreeRTOS.zip /c/Temp
popd

pushd Blinky/LPCXpresso55S69_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Blinky_LPCXpresso55S69_RTX.zip *
mv Blinky_LPCXpresso55S69_RTX.zip /c/Temp
popd

pushd Blinky/MIMXRT1064-EVK_FreeRTOS
"/c/Program Files/7-ZIP/7z" a -tzip Blinky_MIMXRT1064-EVK_FreeRTOS.zip *
mv Blinky_MIMXRT1064-EVK_FreeRTOS.zip /c/Temp
popd

pushd Blinky/MIMXRT1064-EVK_RTX
"/c/Program Files/7-ZIP/7z" a -tzip Blinky_MIMXRT1064-EVK_RTX.zip *
mv Blinky_MIMXRT1064-EVK_RTX.zip /c/Temp
popd

