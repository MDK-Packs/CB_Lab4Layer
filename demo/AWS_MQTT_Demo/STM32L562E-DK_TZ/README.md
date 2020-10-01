AWS Demo for TrustZone enabled device
-------------------------------------

Device needs to be configured with TrustZone enabled.
Use STM32CubeProgrammer to program the following Option Bytes:
 - RDP = 0xAA (RDP Level 0)
 - DBANK = 1 (Dual bank mode enabled)
 - TZEN  = 1 (TrustZone security enabled)
 - SECWM1_PSTRT=0, SECWM1_PEND=127, SECWM2_PSTRT=0x60, SECWM2_PEND=0x7F
   secure bank1 / non-secure bank2 (last 64kB secure)

Workspace contains the following projects:
 - tfm_secure_fw: TF-M Firmware running on the secure side
 - aws_key_provisioning: AWS Key provisioning application (non-secure side)
 - aws_mqtt_demo: AWS MQTT Demo (non-secure side)

Project for the secure side (tfm_secure_fw) needs to be built first before
building the non-secure side projects. 

The secure side image also needs to be flashed separately.

TF-M Firmware on the secure side runs first and then transfers execution
to the active non-secure application.

AWS Key provisioning needs to executed before running the AWS Demo.

How to configure, build and run the non-secure applications is described in:
 - ./AWS_KeyProvisioning/README.md
 - ./AWS_MQTT_Demo/README.md
