#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

void task_function1(void *pvParameter) {
    while (1) {
        ESP_LOGI("FreeRTOS", "Running FreeRTOS task1!");
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay for 1 second
    }
}

void task_function2(void *pvParameter) {
    while (1) {
        ESP_LOGI("FreeRTOS", "Running FreeRTOS task2!");
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay for 1 second
    }
}

void app_main() {
    xTaskCreate(task_function1, "Task1", 2048, NULL, 1, NULL);
    xTaskCreate(task_function2, "Task2", 2048, NULL, 1, NULL);
}