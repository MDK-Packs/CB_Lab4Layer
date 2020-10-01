@echo off

REM Creating AWS Project ZIP Files

pushd AWS_MQTT_Demo\32F746GDISCOVERY
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_32F746GDISCOVERY.zip *
move AWS_MQTT_Demo_32F746GDISCOVERY.zip C:\Temp
popd

pushd AWS_MQTT_Demo\B-L475E-IOT01A
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_B-L475E-IOT01A.zip *
move AWS_MQTT_Demo_B-L475E-IOT01A.zip C:\Temp
popd

pushd AWS_MQTT_Demo\LPCXpresso55S69
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_LPCXpresso55S69.zip *
move AWS_MQTT_Demo_LPCXpresso55S69.zip C:\Temp
popd

pushd AWS_MQTT_Demo\LPCXpresso55S69_TZ
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_LPCXpresso55S69_TZ.zip *
move AWS_MQTT_Demo_LPCXpresso55S69_TZ.zip C:\Temp
popd

pushd AWS_MQTT_Demo\MCB4300
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_MCB4300.zip *
move AWS_MQTT_Demo_MCB4300.zip C:\Temp
popd

pushd AWS_MQTT_Demo\MCB4300_lwIP
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_MCB4300_lwIP.zip *
move AWS_MQTT_Demo_MCB4300_lwIP.zip C:\Temp
popd

pushd AWS_MQTT_Demo\MIMXRT1064-EVK
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_MIMXRT1064-EVK.zip *
move AWS_MQTT_Demo_MIMXRT1064-EVK.zip C:\Temp
popd

pushd AWS_MQTT_Demo\Musca-S1
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_Musca-S1.zip *
move AWS_MQTT_Demo_Musca-S1.zip C:\Temp
popd

pushd AWS_MQTT_Demo\Musca-S1_TZ
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_Musca-S1_TZ.zip *
move AWS_MQTT_Demo_Musca-S1_TZ.zip C:\Temp
popd

pushd AWS_MQTT_Demo\NUCLEO-L552ZE-Q
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_NUCLEO-L552ZE-Q.zip *
move AWS_MQTT_Demo_NUCLEO-L552ZE-Q.zip C:\Temp
popd

pushd AWS_MQTT_Demo\NUCLEO-L552ZE-Q_TZ
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip *
move AWS_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip C:\Temp
popd

pushd AWS_MQTT_Demo\STM32L562E-DK
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_STM32L562E-DK.zip *
move AWS_MQTT_Demo_STM32L562E-DK.zip C:\Temp
popd

pushd AWS_MQTT_Demo\STM32L562E-DK_TZ
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_STM32L562E-DK_TZ.zip *
move AWS_MQTT_Demo_STM32L562E-DK_TZ.zip C:\Temp
popd


REM Creating Azure Project ZIP Files

pushd Azure_MQTT_Demo\32F746GDISCOVERY
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_32F746GDISCOVERY.zip *
move Azure_MQTT_Demo_32F746GDISCOVERY.zip C:\Temp
popd

pushd Azure_MQTT_Demo\B-L475E-IOT01A
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_B-L475E-IOT01A.zip *
move Azure_MQTT_Demo_B-L475E-IOT01A.zip C:\Temp
popd

pushd Azure_MQTT_Demo\LPCXpresso55S69
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_LPCXpresso55S69.zip *
move Azure_MQTT_Demo_LPCXpresso55S69.zip C:\Temp
popd

REM pushd Azure_MQTT_Demo\LPCXpresso55S69_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_LPCXpresso55S69_TZ.zip *
REM move Azure_MQTT_Demo_LPCXpresso55S69_TZ.zip C:\Temp
REM popd

pushd Azure_MQTT_Demo\MCB4300
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_MCB4300.zip *
move Azure_MQTT_Demo_MCB4300.zip C:\Temp
popd

REM pushd Azure_MQTT_Demo\MCB4300_lwIP
REM "C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_MCB4300_lwIP.zip *
REM move Azure_MQTT_Demo_MCB4300_lwIP.zip C:\Temp
REM popd

pushd Azure_MQTT_Demo\MIMXRT1064-EVK
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_MIMXRT1064-EVK.zip *
move Azure_MQTT_Demo_MIMXRT1064-EVK.zip C:\Temp
popd

pushd Azure_MQTT_Demo\Musca-S1
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_Musca-S1.zip *
move Azure_MQTT_Demo_Musca-S1.zip C:\Temp
popd

REM pushd Azure_MQTT_Demo\Musca-S1_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_Musca-S1_TZ.zip *
REM move Azure_MQTT_Demo_Musca-S1_TZ.zip C:\Temp
REM popd

pushd Azure_MQTT_Demo\NUCLEO-L552ZE-Q
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_NUCLEO-L552ZE-Q.zip *
move Azure_MQTT_Demo_NUCLEO-L552ZE-Q.zip C:\Temp
popd

REM pushd Azure_MQTT_Demo\NUCLEO-L552ZE-Q_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip *
REM move Azure_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip C:\Temp
REM popd

pushd Azure_MQTT_Demo\STM32L562E-DK
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_STM32L562E-DK.zip *
move Azure_MQTT_Demo_STM32L562E-DK.zip C:\Temp
popd

REM pushd Azure_MQTT_Demo\STM32L562E-DK_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_STM32L562E-DK_TZ.zip *
REM move Azure_MQTT_Demo_STM32L562E-DK_TZ.zip C:\Temp
REM popd


REM Creating Google Project ZIP Files

pushd Google_MQTT_Demo\32F746GDISCOVERY
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_32F746GDISCOVERY.zip *
move Google_MQTT_Demo_32F746GDISCOVERY.zip C:\Temp
popd

pushd Google_MQTT_Demo\B-L475E-IOT01A
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_B-L475E-IOT01A.zip *
move Google_MQTT_Demo_B-L475E-IOT01A.zip C:\Temp
popd

pushd Google_MQTT_Demo\LPCXpresso55S69
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_LPCXpresso55S69.zip *
move Google_MQTT_Demo_LPCXpresso55S69.zip C:\Temp
popd

REM pushd Google_MQTT_Demo\LPCXpresso55S69_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_LPCXpresso55S69_TZ.zip *
REM move Google_MQTT_Demo_LPCXpresso55S69_TZ.zip C:\Temp
REM popd

pushd Google_MQTT_Demo\MCB4300
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_MCB4300.zip *
move Google_MQTT_Demo_MCB4300.zip C:\Temp
popd

REM pushd Google_MQTT_Demo\MCB4300_lwIP
REM "C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_MCB4300_lwIP.zip *
REM move Google_MQTT_Demo_MCB4300_lwIP.zip C:\Temp
REM popd

pushd Google_MQTT_Demo\MIMXRT1064-EVK
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_MIMXRT1064-EVK.zip *
move Google_MQTT_Demo_MIMXRT1064-EVK.zip C:\Temp
popd

pushd Google_MQTT_Demo\Musca-S1
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_Musca-S1.zip *
move Google_MQTT_Demo_Musca-S1.zip C:\Temp
popd

REM pushd Google_MQTT_Demo\Musca-S1_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_Musca-S1_TZ.zip *
REM move Google_MQTT_Demo_Musca-S1_TZ.zip C:\Temp
REM popd

pushd Google_MQTT_Demo\NUCLEO-L552ZE-Q
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_NUCLEO-L552ZE-Q.zip *
move Google_MQTT_Demo_NUCLEO-L552ZE-Q.zip C:\Temp
popd

REM pushd Google_MQTT_Demo\NUCLEO-L552ZE-Q_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip *
REM move Google_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip C:\Temp
REM popd

pushd Google_MQTT_Demo\STM32L562E-DK
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_STM32L562E-DK.zip *
move Google_MQTT_Demo_STM32L562E-DK.zip C:\Temp
popd

REM pushd Google_MQTT_Demo\STM32L562E-DK_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_STM32L562E-DK_TZ.zip *
REM move Google_MQTT_Demo_STM32L562E-DK_TZ.zip C:\Temp
REM popd


REM Creating Paho Project ZIP Files

pushd Paho_MQTT_Demo\32F746GDISCOVERY
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_32F746GDISCOVERY.zip *
move Paho_MQTT_Demo_32F746GDISCOVERY.zip C:\Temp
popd

pushd Paho_MQTT_Demo\B-L475E-IOT01A
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_B-L475E-IOT01A.zip *
move Paho_MQTT_Demo_B-L475E-IOT01A.zip C:\Temp
popd

pushd Paho_MQTT_Demo\LPCXpresso55S69
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_LPCXpresso55S69.zip *
move Paho_MQTT_Demo_LPCXpresso55S69.zip C:\Temp
popd

REM pushd Paho_MQTT_Demo\LPCXpresso55S69_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_LPCXpresso55S69_TZ.zip *
REM move Paho_MQTT_Demo_LPCXpresso55S69_TZ.zip C:\Temp
REM popd

pushd Paho_MQTT_Demo\MCB4300
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_MCB4300.zip *
move Paho_MQTT_Demo_MCB4300.zip C:\Temp
popd

REM pushd Paho_MQTT_Demo\MCB4300_lwIP
REM "C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_MCB4300_lwIP.zip *
REM move Paho_MQTT_Demo_MCB4300_lwIP.zip C:\Temp
REM popd

pushd Paho_MQTT_Demo\MIMXRT1064-EVK
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_MIMXRT1064-EVK.zip *
move Paho_MQTT_Demo_MIMXRT1064-EVK.zip C:\Temp
popd

pushd Paho_MQTT_Demo\Musca-S1
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_Musca-S1.zip *
move Paho_MQTT_Demo_Musca-S1.zip C:\Temp
popd

REM pushd Paho_MQTT_Demo\Musca-S1_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_Musca-S1_TZ.zip *
REM move Paho_MQTT_Demo_Musca-S1_TZ.zip C:\Temp
REM popd

pushd Paho_MQTT_Demo\NUCLEO-L552ZE-Q
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_NUCLEO-L552ZE-Q.zip *
move Paho_MQTT_Demo_NUCLEO-L552ZE-Q.zip C:\Temp
popd

REM pushd Paho_MQTT_Demo\NUCLEO-L552ZE-Q_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip *
REM move Paho_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip C:\Temp
REM popd

pushd Paho_MQTT_Demo\STM32L562E-DK
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_STM32L562E-DK.zip *
move Paho_MQTT_Demo_STM32L562E-DK.zip C:\Temp
popd

REM pushd Paho_MQTT_Demo\STM32L562E-DK_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_STM32L562E-DK_TZ.zip *
REM move Paho_MQTT_Demo_STM32L562E-DK_TZ.zip C:\Temp
REM popd


REM Creating Watson Project ZIP Files

pushd Watson_MQTT_Demo\32F746GDISCOVERY
"C:\Program Files\7-ZIP\7z" a -tzip Watson_MQTT_Demo_32F746GDISCOVERY.zip *
move Watson_MQTT_Demo_32F746GDISCOVERY.zip C:\Temp
popd

pushd Watson_MQTT_Demo\MCB4300
"C:\Program Files\7-ZIP\7z" a -tzip Watson_MQTT_Demo_MCB4300.zip *
move Watson_MQTT_Demo_MCB4300.zip C:\Temp
popd

pushd Watson_MQTT_Demo\MIMXRT1064-EVK
"C:\Program Files\7-ZIP\7z" a -tzip Watson_MQTT_Demo_MIMXRT1064-EVK.zip *
move Watson_MQTT_Demo_MIMXRT1064-EVK.zip C:\Temp
popd
