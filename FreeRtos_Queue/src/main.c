#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_PIN GPIO_NUM_2

QueueHandle_t queue;

void producer_task(void *pvParameters){
    int counter =0;
    while(1){
        counter++;
        ESP_LOGI("Producer", "Sending: %d", counter);
        xQueueSend(queue, &counter, portMAX_DELAY);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void consumer_task(void *pvParamters){
    int received_value;
    while(1){
        xQueueReceive(queue, &received_value, portMAX_DELAY);
        ESP_LOGI("Consumer", "Recived: %d", received_value);
    }
}



void app_main() {
    queue=xQueueCreate(10, sizeof(int));
    if(queue!=NULL){
        xTaskCreate(producer_task,"Producer Task",2048, NULL, 1,NULL);
        xTaskCreate(consumer_task,"Consumer Task",2048, NULL, 1,NULL);
    }
}