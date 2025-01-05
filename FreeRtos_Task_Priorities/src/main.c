#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_PIN GPIO_NUM_2

void high_priority_task(void *pvParameters){
    gpio_set_direction(LED_PIN,GPIO_MODE_OUTPUT);
    while(1){
        gpio_set_level(LED_PIN,1);
        ESP_LOGI("High","Running high priority task");
        vTaskDelay(1000/portTICK_PERIOD_MS);
        
    }
}

void low_priority_task(void *pvParameters){
    gpio_set_direction(LED_PIN,GPIO_MODE_OUTPUT);
    while(1){
        gpio_set_level(LED_PIN,0);
        ESP_LOGI("Low","Running low priority task");
        vTaskDelay(2000/portTICK_PERIOD_MS);
        
    }
}

void app_main() {
    xTaskCreate(high_priority_task, "HIGH_PRIORITY_TAASK", 2048, NULL, 1, NULL);
    xTaskCreate(low_priority_task, "LOW_PRIORITY TASK", 2048, NULL, 2, NULL);
}