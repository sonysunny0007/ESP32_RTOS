#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "driver/gpio.h"

#define LED_BUILTIN 2
#define LED_EXTERNAL 13

#define QUEUE_LENGTH 10
#define ITEM_SIZE sizeof(int)

//Create FreeRTOS Queue
QueueHandle_t messageQueue;



void task1(void *pvParameters) {
    int blink_count=0;
    esp_rom_gpio_pad_select_gpio(LED_BUILTIN);
    gpio_set_direction(LED_BUILTIN, GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(LED_BUILTIN,1);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        gpio_set_level(LED_BUILTIN,0);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    

    //send a message to task2 every 10 sec
    blink_count++;
    printf("Task1: Blink count: %d\r\n", blink_count);
    if(blink_count%10==0){
        int message = blink_count;
        xQueueSend(messageQueue, &message, portMAX_DELAY);
    }
    }
}

void task2(void *pvParameters){
    int received_message;
    esp_rom_gpio_pad_select_gpio(LED_EXTERNAL);
    gpio_set_direction(LED_EXTERNAL, GPIO_MODE_OUTPUT);
    while(1){
        gpio_set_level(LED_EXTERNAL,1);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        gpio_set_level(LED_EXTERNAL,0);
        vTaskDelay(1000/portTICK_PERIOD_MS);

    if(xQueueReceive(messageQueue, &received_message, portMAX_DELAY)==pdTRUE){
        printf("Task2: Task1 send a message: %d\n", received_message);
    }
    }
}

void app_main() {

    printf("App main started \r\n");
     // Initialize the queue
    messageQueue = xQueueCreate(QUEUE_LENGTH,ITEM_SIZE);
    if (messageQueue == NULL) {
        printf("Failed to create queue!\n");
        return;
    }

    // Create Task 1 - Blink onboard LED
    xTaskCreate(task1, "Task Blink Onboard LED", 2048, NULL, 2, NULL);

    // Create Task 2 - Blink external LED and receive message
    xTaskCreate(task2, "Task Blink External LED", 2048, NULL, 1, NULL);
}
