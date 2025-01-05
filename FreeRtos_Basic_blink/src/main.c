#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_PIN GPIO_NUM_2

void led_task(void *pvParameters){
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    while(1){
        gpio_set_level(LED_PIN,1);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        gpio_set_level(LED_PIN,0);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}



void app_main() {
    xTaskCreate(led_task, "LED_Task", 2048, NULL, 1, NULL);
}