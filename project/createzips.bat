@echo off

REM Creating AWS Project ZIP Files

pushd AWS_MQTT_Demo\32F746GDISCOVERY
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_32F746GDISCOVERY.zip * -x!*.cprj
move AWS_MQTT_Demo_32F746GDISCOVERY.zip C:\Temp
popd

pushd AWS_MQTT_Demo\B-L475E-IOT01A
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_B-L475E-IOT01A.zip * -x!*.cprj
move AWS_MQTT_Demo_B-L475E-IOT01A.zip C:\Temp
popd

pushd AWS_MQTT_Demo\LPCXpresso55S69
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_LPCXpresso55S69.zip * -x!*.cprj
move AWS_MQTT_Demo_LPCXpresso55S69.zip C:\Temp
popd

pushd AWS_MQTT_Demo\LPCXpresso55S69_TZ
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_LPCXpresso55S69_TZ.zip * -x!*.cprj
move AWS_MQTT_Demo_LPCXpresso55S69_TZ.zip C:\Temp
popd

pushd AWS_MQTT_Demo\MCB4300
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_MCB4300.zip * -x!*.cprj
move AWS_MQTT_Demo_MCB4300.zip C:\Temp
popd

pushd AWS_MQTT_Demo\MCB4300_lwIP
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_MCB4300_lwIP.zip * -x!*.cprj
move AWS_MQTT_Demo_MCB4300_lwIP.zip C:\Temp
popd

pushd AWS_MQTT_Demo\MIMXRT1064-EVK
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_MIMXRT1064-EVK.zip * -x!*.cprj
move AWS_MQTT_Demo_MIMXRT1064-EVK.zip C:\Temp
popd

pushd AWS_MQTT_Demo\Musca-S1
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_Musca-S1.zip * -x!*.cprj
move AWS_MQTT_Demo_Musca-S1.zip C:\Temp
popd

pushd AWS_MQTT_Demo\Musca-S1_TZ
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_Musca-S1_TZ.zip * -x!*.cprj
move AWS_MQTT_Demo_Musca-S1_TZ.zip C:\Temp
popd

pushd AWS_MQTT_Demo\NUCLEO-L552ZE-Q
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_NUCLEO-L552ZE-Q.zip * -x!*.cprj
move AWS_MQTT_Demo_NUCLEO-L552ZE-Q.zip C:\Temp
popd

pushd AWS_MQTT_Demo\NUCLEO-L552ZE-Q_TZ
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip * -x!*.cprj
move AWS_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip C:\Temp
popd

pushd AWS_MQTT_Demo\STM32L562E-DK
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_STM32L562E-DK.zip * -x!*.cprj
move AWS_MQTT_Demo_STM32L562E-DK.zip C:\Temp
popd

pushd AWS_MQTT_Demo\STM32L562E-DK_TZ
"C:\Program Files\7-ZIP\7z" a -tzip AWS_MQTT_Demo_STM32L562E-DK_TZ.zip * -x!*.cprj
move AWS_MQTT_Demo_STM32L562E-DK_TZ.zip C:\Temp
popd


REM Creating Azure Project ZIP Files

pushd Azure_MQTT_Demo\32F746GDISCOVERY
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_32F746GDISCOVERY.zip * -x!*.cprj
move Azure_MQTT_Demo_32F746GDISCOVERY.zip C:\Temp
popd

pushd Azure_MQTT_Demo\B-L475E-IOT01A
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_B-L475E-IOT01A.zip * -x!*.cprj
move Azure_MQTT_Demo_B-L475E-IOT01A.zip C:\Temp
popd

pushd Azure_MQTT_Demo\LPCXpresso55S69
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_LPCXpresso55S69.zip * -x!*.cprj
move Azure_MQTT_Demo_LPCXpresso55S69.zip C:\Temp
popd

REM pushd Azure_MQTT_Demo\LPCXpresso55S69_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_LPCXpresso55S69_TZ.zip * -x!*.cprj
REM move Azure_MQTT_Demo_LPCXpresso55S69_TZ.zip C:\Temp
REM popd

pushd Azure_MQTT_Demo\MCB4300
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_MCB4300.zip * -x!*.cprj
move Azure_MQTT_Demo_MCB4300.zip C:\Temp
popd

REM pushd Azure_MQTT_Demo\MCB4300_lwIP
REM "C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_MCB4300_lwIP.zip * -x!*.cprj
REM move Azure_MQTT_Demo_MCB4300_lwIP.zip C:\Temp
REM popd

pushd Azure_MQTT_Demo\MIMXRT1064-EVK
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_MIMXRT1064-EVK.zip * -x!*.cprj
move Azure_MQTT_Demo_MIMXRT1064-EVK.zip C:\Temp
popd

pushd Azure_MQTT_Demo\Musca-S1
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_Musca-S1.zip * -x!*.cprj
move Azure_MQTT_Demo_Musca-S1.zip C:\Temp
popd

REM pushd Azure_MQTT_Demo\Musca-S1_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_Musca-S1_TZ.zip * -x!*.cprj
REM move Azure_MQTT_Demo_Musca-S1_TZ.zip C:\Temp
REM popd

pushd Azure_MQTT_Demo\NUCLEO-L552ZE-Q
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_NUCLEO-L552ZE-Q.zip * -x!*.cprj
move Azure_MQTT_Demo_NUCLEO-L552ZE-Q.zip C:\Temp
popd

REM pushd Azure_MQTT_Demo\NUCLEO-L552ZE-Q_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip * -x!*.cprj
REM move Azure_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip C:\Temp
REM popd

pushd Azure_MQTT_Demo\STM32L562E-DK
"C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_STM32L562E-DK.zip * -x!*.cprj
move Azure_MQTT_Demo_STM32L562E-DK.zip C:\Temp
popd

REM pushd Azure_MQTT_Demo\STM32L562E-DK_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Azure_MQTT_Demo_STM32L562E-DK_TZ.zip * -x!*.cprj
REM move Azure_MQTT_Demo_STM32L562E-DK_TZ.zip C:\Temp
REM popd


REM Creating Google Project ZIP Files

pushd Google_MQTT_Demo\32F746GDISCOVERY
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_32F746GDISCOVERY.zip * -x!*.cprj
move Google_MQTT_Demo_32F746GDISCOVERY.zip C:\Temp
popd

pushd Google_MQTT_Demo\B-L475E-IOT01A
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_B-L475E-IOT01A.zip * -x!*.cprj
move Google_MQTT_Demo_B-L475E-IOT01A.zip C:\Temp
popd

pushd Google_MQTT_Demo\LPCXpresso55S69
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_LPCXpresso55S69.zip * -x!*.cprj
move Google_MQTT_Demo_LPCXpresso55S69.zip C:\Temp
popd

REM pushd Google_MQTT_Demo\LPCXpresso55S69_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_LPCXpresso55S69_TZ.zip * -x!*.cprj
REM move Google_MQTT_Demo_LPCXpresso55S69_TZ.zip C:\Temp
REM popd

pushd Google_MQTT_Demo\MCB4300
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_MCB4300.zip * -x!*.cprj
move Google_MQTT_Demo_MCB4300.zip C:\Temp
popd

REM pushd Google_MQTT_Demo\MCB4300_lwIP
REM "C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_MCB4300_lwIP.zip * -x!*.cprj
REM move Google_MQTT_Demo_MCB4300_lwIP.zip C:\Temp
REM popd

pushd Google_MQTT_Demo\MIMXRT1064-EVK
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_MIMXRT1064-EVK.zip * -x!*.cprj
move Google_MQTT_Demo_MIMXRT1064-EVK.zip C:\Temp
popd

pushd Google_MQTT_Demo\Musca-S1
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_Musca-S1.zip * -x!*.cprj
move Google_MQTT_Demo_Musca-S1.zip C:\Temp
popd

REM pushd Google_MQTT_Demo\Musca-S1_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_Musca-S1_TZ.zip * -x!*.cprj
REM move Google_MQTT_Demo_Musca-S1_TZ.zip C:\Temp
REM popd

pushd Google_MQTT_Demo\NUCLEO-L552ZE-Q
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_NUCLEO-L552ZE-Q.zip * -x!*.cprj
move Google_MQTT_Demo_NUCLEO-L552ZE-Q.zip C:\Temp
popd

REM pushd Google_MQTT_Demo\NUCLEO-L552ZE-Q_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip * -x!*.cprj
REM move Google_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip C:\Temp
REM popd

pushd Google_MQTT_Demo\STM32L562E-DK
"C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_STM32L562E-DK.zip * -x!*.cprj
move Google_MQTT_Demo_STM32L562E-DK.zip C:\Temp
popd

REM pushd Google_MQTT_Demo\STM32L562E-DK_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Google_MQTT_Demo_STM32L562E-DK_TZ.zip * -x!*.cprj
REM move Google_MQTT_Demo_STM32L562E-DK_TZ.zip C:\Temp
REM popd


REM Creating Paho Project ZIP Files

pushd Paho_MQTT_Demo\32F746GDISCOVERY
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_32F746GDISCOVERY.zip * -x!*.cprj
move Paho_MQTT_Demo_32F746GDISCOVERY.zip C:\Temp
popd

pushd Paho_MQTT_Demo\B-L475E-IOT01A
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_B-L475E-IOT01A.zip * -x!*.cprj
move Paho_MQTT_Demo_B-L475E-IOT01A.zip C:\Temp
popd

pushd Paho_MQTT_Demo\LPCXpresso55S69
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_LPCXpresso55S69.zip * -x!*.cprj
move Paho_MQTT_Demo_LPCXpresso55S69.zip C:\Temp
popd

REM pushd Paho_MQTT_Demo\LPCXpresso55S69_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_LPCXpresso55S69_TZ.zip * -x!*.cprj
REM move Paho_MQTT_Demo_LPCXpresso55S69_TZ.zip C:\Temp
REM popd

pushd Paho_MQTT_Demo\MCB4300
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_MCB4300.zip * -x!*.cprj
move Paho_MQTT_Demo_MCB4300.zip C:\Temp
popd

REM pushd Paho_MQTT_Demo\MCB4300_lwIP
REM "C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_MCB4300_lwIP.zip * -x!*.cprj
REM move Paho_MQTT_Demo_MCB4300_lwIP.zip C:\Temp
REM popd

pushd Paho_MQTT_Demo\MIMXRT1064-EVK
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_MIMXRT1064-EVK.zip * -x!*.cprj
move Paho_MQTT_Demo_MIMXRT1064-EVK.zip C:\Temp
popd

pushd Paho_MQTT_Demo\Musca-S1
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_Musca-S1.zip * -x!*.cprj
move Paho_MQTT_Demo_Musca-S1.zip C:\Temp
popd

REM pushd Paho_MQTT_Demo\Musca-S1_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_Musca-S1_TZ.zip * -x!*.cprj
REM move Paho_MQTT_Demo_Musca-S1_TZ.zip C:\Temp
REM popd

pushd Paho_MQTT_Demo\NUCLEO-L552ZE-Q
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_NUCLEO-L552ZE-Q.zip * -x!*.cprj
move Paho_MQTT_Demo_NUCLEO-L552ZE-Q.zip C:\Temp
popd

REM pushd Paho_MQTT_Demo\NUCLEO-L552ZE-Q_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip * -x!*.cprj
REM move Paho_MQTT_Demo_NUCLEO-L552ZE-Q_TZ.zip C:\Temp
REM popd

pushd Paho_MQTT_Demo\STM32L562E-DK
"C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_STM32L562E-DK.zip * -x!*.cprj
move Paho_MQTT_Demo_STM32L562E-DK.zip C:\Temp
popd

REM pushd Paho_MQTT_Demo\STM32L562E-DK_TZ
REM "C:\Program Files\7-ZIP\7z" a -tzip Paho_MQTT_Demo_STM32L562E-DK_TZ.zip * -x!*.cprj
REM move Paho_MQTT_Demo_STM32L562E-DK_TZ.zip C:\Temp
REM popd


REM Creating Watson Project ZIP Files

pushd Watson_MQTT_Demo\32F746GDISCOVERY
"C:\Program Files\7-ZIP\7z" a -tzip Watson_MQTT_Demo_32F746GDISCOVERY.zip * -x!*.cprj
move Watson_MQTT_Demo_32F746GDISCOVERY.zip C:\Temp
popd

pushd Watson_MQTT_Demo\MCB4300
"C:\Program Files\7-ZIP\7z" a -tzip Watson_MQTT_Demo_MCB4300.zip * -x!*.cprj
move Watson_MQTT_Demo_MCB4300.zip C:\Temp
popd

pushd Watson_MQTT_Demo\MIMXRT1064-EVK
"C:\Program Files\7-ZIP\7z" a -tzip Watson_MQTT_Demo_MIMXRT1064-EVK.zip * -x!*.cprj
move Watson_MQTT_Demo_MIMXRT1064-EVK.zip C:\Temp
popd
