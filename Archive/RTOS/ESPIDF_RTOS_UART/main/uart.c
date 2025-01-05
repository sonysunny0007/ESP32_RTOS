
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/uart.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_intr_alloc.h"


#define BLINK_GPIO GPIO_NUM_2

static const char *TAG = "uart_events";

#define EX_UART_NUM UART_NUM_0
#define PATTERN_CHR_NUM 3



TaskHandle_t myTask1Handle = NULL;     //creating task1 handle
//TaskHandle_t myTask2Handle = NULL;     //creating task2 handle

int i=0;
void task1(void *arg){
    /*Write task1 code here*/
    while (1){
        printf("from task1!\n");
        vTaskDelay(1000/portTICK_RATE_MS);
    }
    
}
/*
void task2(void *arg){
//    write task2 code here
    while (1){
        printf("from task2!\n");
        vTaskDelay(1000/portTICK_RATE_MS);
    }
    
    
}*/



void app_main(){
    int ret;
    
    xTaskCreate(task1, "task1", 4096, NULL, 10, &myTask1Handle);  //creating task1
//    xTaskCreate(task2, "Task2", 4096, NULL, 10, &myTask2Handle);  //creating task2

}