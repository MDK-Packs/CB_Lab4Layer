RTOS: FreeRTOS Real-Time Operating System
-----------------------------------------
The real-time operating system [FreeRTOS](https://github.com/ARM-software/CMSIS-FreeRTOS) implements the resource management.

It is configured with the following settings:

- Minimal stack size \[words]: 768
- Total heap size \[bytes]: 24000
- Preemption interrupt priority: 128
- Event Recorder configuration
  - Initialize Event Recorder: 1

Refer to [Configure CMSIS-FreeRTOS](https://arm-software.github.io/CMSIS-FreeRTOS/General/html/cre_freertos_proj.html#cmsis_freertos_config) for a detailed description of all configuration options.
