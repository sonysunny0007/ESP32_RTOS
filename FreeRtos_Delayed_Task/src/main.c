#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

void delayed_task(void *pvParameters) {
    vTaskDelay(5000 / portTICK_PERIOD_MS);  // Delay for 5 seconds
    ESP_LOGI("Task", "Task started after delay");
    while (1) {
        ESP_LOGI("Task", "Running task");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main() {
    xTaskCreate(delayed_task, "Delayed_Task", 2048, NULL, 1, NULL);
}
