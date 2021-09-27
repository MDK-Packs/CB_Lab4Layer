#!/bin/bash

# header
echo "Extract layers from master projects"

# master project directory
project_path="../project"

# layer output directory
layer_path="../layer"

# intermediate directory
temp_path="temp"

# silent pushd
pushd () {
  command pushd "$@" > /dev/null
}

# silent popd
popd () {
  command popd "$@" > /dev/null
}

# remove intermediate directory if it exists
if [ -d "${temp_path}" ]
then
  rm -r "${temp_path}"
fi

# remove layer output directory if it exists
if [ -d "${layer_path}" ]
then
  rm -r "${layer_path}"
fi

# create layer output directory structure
mkdir "${layer_path}"

pushd "${layer_path}"

mkdir "App"
pushd "App"
mkdir "Blinky"
mkdir "AWS_MQTT_Demo"
mkdir "Azure_MQTT_Demo"
mkdir "Google_MQTT_Demo"
mkdir "Paho_MQTT_Demo"
mkdir "Watson_MQTT_Demo"
popd

mkdir "RTOS"
pushd "RTOS"
mkdir "RTX"
mkdir "FreeRTOS"
popd

mkdir "Socket"
pushd "Socket"
mkdir "WiFi"
mkdir "MW-Network_ETH"
mkdir "MW-Network_WiFi"
mkdir "lwIP_ETH"
popd

mkdir "Module"
pushd "Module"
mkdir "ESP8266"
mkdir "WizFi360"
mkdir "ISM43362"
popd

mkdir "Board"
pushd "Board"
mkdir "32L4R9IDISCOVERY"
mkdir "32F746GDISCOVERY"
mkdir "B-L475E-IOT01A"
mkdir "FRDM-K32L3A6"
mkdir "IMXRT1050-EVKB"
mkdir "MCB4300"
mkdir "MIMXRT1064-EVK"
mkdir "Musca-S1"
mkdir "LPC54018-IoT-Module"
mkdir "LPCXpresso55S69"
mkdir "NUCLEO-L552ZE-Q"
mkdir "NUCLEO-H743ZI"
mkdir "STM32L562E-DK"
mkdir "STM32H735G-DK"
mkdir "STM32H745I-DISCO"
popd

popd

# extract layers from projects

cbuildgen "${project_path}/Blinky/B-L475E-IOT01A/Blinky.B-L475E-IOT01A.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/App/."    "${layer_path}/App/Blinky"
rm -r "${temp_path}"

cbuildgen "${project_path}/Blinky/STM32H745I-DISCO/Blinky.STM32H745I-DISCO.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/STM32H745I-DISCO"
rm -r "${temp_path}"

cbuildgen "${project_path}/AWS_MQTT_Demo/B-L475E-IOT01A_WiFi_FreeRTOS/aws_mqtt_demo.B-L475E-IOT0A_FreeRTOS.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/App/."    "${layer_path}/App/AWS_MQTT_Demo"
cp -r "${temp_path}/RTOS/."   "${layer_path}/RTOS/FreeRTOS"
cp -r "${temp_path}/Socket/." "${layer_path}/Socket/WiFi"
rm -r "${temp_path}"

cbuildgen "${project_path}/AWS_MQTT_Demo/MCB4300_lwIP_ETH_RTX/aws_mqtt_demo.MCB4300.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/RTOS/."   "${layer_path}/RTOS/RTX"
cp -r "${temp_path}/Socket/." "${layer_path}/Socket/lwIP_ETH"
rm -r "${temp_path}"

cbuildgen "${project_path}/Azure_MQTT_Demo/NUCLEO-L552ZE-Q_ISM43362_WiFi_RTX/azure_mqtt_demo.NUCLEO-L552ZE-Q_ISM43362.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/App/."    "${layer_path}/App/Azure_MQTT_Demo"
cp -r "${temp_path}/Module/." "${layer_path}/Module/ISM43362"
rm -r "${temp_path}"

cbuildgen "${project_path}/Google_MQTT_Demo/Musca-S1_ESP8266_WiFi_RTX/google_mqtt_demo.Musca-S1_ESP8266.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/App/."    "${layer_path}/App/Google_MQTT_Demo"
cp -r "${temp_path}/Module/." "${layer_path}/Module/ESP8266"
cp -r "${temp_path}/Board/."  "${layer_path}/Board/Musca-S1"
rm -r "${temp_path}"

cbuildgen "${project_path}/Paho_MQTT_Demo/32F746GDISCOVERY_WizFi360_WiFi_RTX/paho_mqtt_demo.STM32F746G-D_WizFi360.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/App/."    "${layer_path}/App/Paho_MQTT_Demo"
cp -r "${temp_path}/Module/." "${layer_path}/Module/WizFi360"
rm -r "${temp_path}"

cbuildgen "${project_path}/Paho_MQTT_Demo/LPC54018-IoT-Module_MW-Network_WiFi_RTX/paho_mqtt_demo.LPC54018-IoT-Module.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Socket/." "${layer_path}/Socket/MW-Network_WiFi"
cp -r "${temp_path}/Board/."  "${layer_path}/Board/LPC54018-IoT-Module"
rm -r "${temp_path}"

cbuildgen "${project_path}/Watson_MQTT_Demo/MCB4300_MW-Network_ETH_RTX/watson_mqtt_demo.MCB4300.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/App/."    "${layer_path}/App/Watson_MQTT_Demo"
cp -r "${temp_path}/Socket/." "${layer_path}/Socket/MW-Network_ETH"
cp -r "${temp_path}/Board/."  "${layer_path}/Board/MCB4300"
rm -r "${temp_path}"

cbuildgen "${project_path}/Platform/32L4R9IDISCOVERY/Platform.32L4R9IDISCOVERY.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/32L4R9IDISCOVERY"
rm -r "${temp_path}"

cbuildgen "${project_path}/Platform/32F746GDISCOVERY/Platform.STM32F746G-Discovery.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/32F746GDISCOVERY"
rm -r "${temp_path}"

cbuildgen "${project_path}/Platform/B-L475E-IOT01A/Platform.B-L475E-IOT01A.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/B-L475E-IOT01A"
rm -r "${temp_path}"

cbuildgen "${project_path}/Platform/FRDM-K32L3A6/Platform.FRDM-K32L3A6.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/FRDM-K32L3A6"
rm -r "${temp_path}"

cbuildgen "${project_path}/Platform/IMXRT1050-EVKB/Platform.IMXRT1050-EVKB.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/IMXRT1050-EVKB"
rm -r "${temp_path}"

cbuildgen "${project_path}/Platform/LPCXpresso55S69/Platform.LPCXpresso55S69.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/LPCXpresso55S69"
rm -r "${temp_path}"

cbuildgen "${project_path}/Platform/MIMXRT1064-EVK/Platform.MIMXRT1064-EVK.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/MIMXRT1064-EVK"
rm -r "${temp_path}"

cbuildgen "${project_path}/Platform/NUCLEO-L552ZE-Q/Platform.NUCLEO-L552ZE-Q.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/NUCLEO-L552ZE-Q"
rm -r "${temp_path}"

cbuildgen "${project_path}/Platform/NUCLEO-H743ZI/Platform.NUCLEO-H743ZI.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/NUCLEO-H743ZI"
rm -r "${temp_path}"

cbuildgen "${project_path}/Platform/STM32H735G-DK/Platform.STM32H735G-DK.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/STM32H735G-DK"
rm -r "${temp_path}"

cbuildgen "${project_path}/Platform/STM32L562E-DK/Platform.STM32L562E-DK.cprj" extract --outdir="${temp_path}"
cp -r "${temp_path}/Board/." "${layer_path}/Board/STM32L562E-DK"
rm -r "${temp_path}"

# remove README.md from project (auto generated when projects are composed)
rm "${layer_path}/App/Blinky/README.md"
rm "${layer_path}/App/AWS_MQTT_Demo/README.md"
rm "${layer_path}/App/Azure_MQTT_Demo/README.md"
rm "${layer_path}/App/Google_MQTT_Demo/README.md"
rm "${layer_path}/App/Paho_MQTT_Demo/README.md"
rm "${layer_path}/App/Watson_MQTT_Demo/README.md"
