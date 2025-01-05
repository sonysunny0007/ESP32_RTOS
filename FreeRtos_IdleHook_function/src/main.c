#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

void vApplicationIdleHook() {
    ESP_LOGI("IdleHook", "CPU is idle");
}

void task1(void *pvParameters) {
    while (1) {
        ESP_LOGI("Task1", "Task1 is running");
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        
    }
}

void app_main() {
    ESP_LOGI("Main", "Main function started");
    xTaskCreate(task1, "Task1", 2048, NULL, 1, NULL);
}
