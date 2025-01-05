#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_PIN GPIO_NUM_2

SemaphoreHandle_t semaphore;

void producer_task(void *pvPrameters){
    while(1){
        ESP_LOGI("Task1", "Semephore given");
        xSemaphoreGive(semaphore);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void consumer_task(void *pvParameters){
    while(1){
        if(xSemaphoreTake(semaphore, portMAX_DELAY)){
            ESP_LOGI("Task2", "Semaphore taken");
        }
    }
}



void app_main() {
    semaphore = xSemaphoreCreateBinary();
    if(semaphore!=NULL){
        xTaskCreate(producer_task, "Producer", 2048, NULL, 1, NULL);
        xTaskCreate(consumer_task, "Consumer", 2048, NULL, 2, NULL);
    }
}