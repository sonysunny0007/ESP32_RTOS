#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_pm.h"
#include "esp_sleep.h"

#define TAG "PowerSavingIdleHook"

void vApplicationIdleHook() {
    // Log when entering idle state
    ESP_LOGI(TAG, "Entering light sleep mode...");
    
    // Configure light sleep
    esp_light_sleep_start();

    // Log when waking up
    ESP_LOGI(TAG, "Woke up from light sleep mode.");
}

void task1(void *pvParameters) {
    while (1) {
        ESP_LOGI("Task1", "Task1 is running.");
        vTaskDelay(2000 / portTICK_PERIOD_MS); // Simulate periodic work
    }
}

void app_main() {
    ESP_LOGI(TAG, "App Main Started");

    // // Optional: Configure power management
    // esp_pm_config_t pm_config = {
    //     .max_freq_mhz = 80,   // Maximum CPU frequency
    //     .min_freq_mhz = 10,   // Minimum CPU frequency
    //     .light_sleep_enable = true  // Enable light sleep
    // };
    // ESP_ERROR_CHECK(esp_pm_configure(&pm_config));

    // Create a task
    xTaskCreate(task1, "Task1", 2048, NULL, 1, NULL);
}
