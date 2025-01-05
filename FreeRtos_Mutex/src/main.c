#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_PIN GPIO_NUM_2

SemaphoreHandle_t mutex;

void task1(void *pvPrameters){
    while(1){
        if(xSemaphoreTake(mutex, portMAX_DELAY)){
            ESP_LOGI("Task1", "Task1 accessing shared resources");
            vTaskDelay(1000/portTICK_PERIOD_MS);
            xSemaphoreGive(mutex);
        }
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void task2(void *pvParameters){
    while(1){
        if(xSemaphoreTake(mutex, portMAX_DELAY)){
            ESP_LOGI("Task2", "Task2 accessing shared resources");
            vTaskDelay(1000/portTICK_PERIOD_MS);
            xSemaphoreGive(mutex);
        }
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}



void app_main() {
    mutex = xSemaphoreCreateMutex();
    if(mutex!=NULL){
        xTaskCreate(task1, "Task1", 2048, NULL, 1, NULL);
        xTaskCreate(task2, "Task2", 2048, NULL, 2, NULL);
    }
}