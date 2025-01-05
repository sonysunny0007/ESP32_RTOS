#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"

static const char *TAG = "SIMULATED_SENSOR_PROJECT";

#define QUEUE_LENGTH 5       // Maximum number of items in the queue
#define QUEUE_ITEM_SIZE sizeof(SensorData) // Size of each queue item

typedef struct {
    float temperature;
    float humidity;
    float pressure;
} SensorData;

QueueHandle_t sensorQueue;

// Task to simulate sensor readings
void simulate_sensor_task(void *pvParameters) {
    SensorData data;

    while (1) {
        // Generate simulated sensor data
        data.temperature = 20.0 + (rand() % 100) / 10.0; // Simulate 20.0°C to 30.0°C
        data.humidity = 50.0 + (rand() % 200) / 10.0;    // Simulate 50.0% to 70.0%
        data.pressure = 1013.25 + (rand() % 200) / 10.0; // Simulate 1013.25 to 1033.25 hPa

        // Send data to the queue
        if (xQueueSend(sensorQueue, &data, pdMS_TO_TICKS(100)) == pdPASS) {
            ESP_LOGI(TAG, "Sensor data sent: Temp: %.2f°C, Humidity: %.2f%%, Pressure: %.2f hPa",
                     data.temperature, data.humidity, data.pressure);
        } else {
            ESP_LOGW(TAG, "Queue is full, unable to send data!");
        }

        vTaskDelay(pdMS_TO_TICKS(2000)); // Simulate reading every 2 seconds
    }
}

// Task to process and log sensor data
void process_sensor_data_task(void *pvParameters) {
    SensorData receivedData;

    while (1) {
        // Receive data from the queue
        if (xQueueReceive(sensorQueue, &receivedData, pdMS_TO_TICKS(500)) == pdPASS) {
            ESP_LOGI(TAG, "Processing Data -> Temp: %.2f°C, Humidity: %.2f%%, Pressure: %.2f hPa",
                     receivedData.temperature, receivedData.humidity, receivedData.pressure);
        } else {
            ESP_LOGW(TAG, "No data received from queue!");
        }

        vTaskDelay(pdMS_TO_TICKS(1000)); // Processing delay
    }
}

void app_main() {
    // Create the queue
    sensorQueue = xQueueCreate(QUEUE_LENGTH, QUEUE_ITEM_SIZE);
    if (sensorQueue == NULL) {
        ESP_LOGE(TAG, "Failed to create the queue!");
        return;
    }

    // Create FreeRTOS tasks
    xTaskCreate(simulate_sensor_task, "simulate_sensor_task", 2048, NULL, 5, NULL);
    xTaskCreate(process_sensor_data_task, "process_sensor_data_task", 2048, NULL, 5, NULL);
}
