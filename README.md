# ESP32 FreeRTOS Projects

This repository contains various **FreeRTOS-based projects** designed for the ESP32 platform. These projects demonstrate essential real-time embedded systems concepts such as task management, synchronization, and sensor integration. Each project is designed to provide hands-on experience with FreeRTOS functionalities, helping developers understand the key features of this operating system.

## Projects Overview

### 1. **Blink**
   - A simple project that demonstrates basic GPIO pin blinking with FreeRTOS task management.

### 2. **FreeRtos_BME_tph**
   - This project integrates a **BME sensor** to read and display **Temperature**, **Pressure**, and **Humidity** data.

### 3. **FreeRtos_Basic_blink**
   - An extension of the **Blink** project, showcasing basic blinking of an LED with the FreeRTOS framework, including task management.

### 4. **FreeRtos_Binary_Semaphore**
   - Demonstrates the use of **binary semaphores** for task synchronization and mutual exclusion in FreeRTOS.

### 5. **FreeRtos_Delayed_Task**
   - This project focuses on **delayed task execution** using FreeRTOS functions.

### 6. **FreeRtos_IdleHook_function**
   - A project showcasing the **Idle Hook** function, allowing for custom behavior when the CPU is idle.

### 7. **FreeRtos_LightSleep_IdleHook**
   - Implements **light sleep** mode and uses the **Idle Hook** to manage power-efficient behavior during idle times.

### 8. **FreeRtos_Mutex**
   - A simple example demonstrating the use of **mutexes** to ensure mutual exclusion and synchronization between tasks.

### 9. **FreeRtos_PressTempHum_Simulation**
   - Simulates **pressure**, **temperature**, and **humidity** data from a sensor and communicates with FreeRTOS tasks for data processing.

### 10. **FreeRtos_Queue**
   - Demonstrates task-to-task communication using **FreeRTOS queues**.

### 11. **FreeRtos_Task_Priorities**
   - Focuses on **task prioritization** and scheduling, showing how FreeRTOS handles tasks with different priority levels.

### 12. **FreeRtos_Taskttwo**
   - A simple example with two FreeRTOS tasks running concurrently, demonstrating basic task management.

## Getting Started

To get started with any of these projects:

1. Clone this repository:
   ```bash
   git clone https://github.com/sonysunny0007/FreeRTOS-ESP32.git
