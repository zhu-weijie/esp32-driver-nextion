// When building using VSCode tooling, the necessary
// variables are not injected in build time.
//#include "../../../build/config/sdkconfig.h"
#include "../build/config/sdkconfig.h"

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "nextion.h"

const static char *TAG = "example";
static QueueHandle_t p_event_queue;

void app_main(void)
{
    if (nextion_driver_install(UART_NUM_2, 9600, GPIO_NUM_17, GPIO_NUM_16, 5, &p_event_queue) != NEX_OK)
    {
        ESP_LOGE(TAG, "could not install nextion driver");
        return;
    }

    if (nextion_driver_init() != NEX_OK)
    {
        ESP_LOGE(TAG, "could not init nextion driver");
        return;
    }

    nex_err_t code = nextion_send_command("page 7\0");

    if (NEX_DVC_CODE_IS_SUCCESS(code))
    {
        nextion_event_t event;

        while (1)
        {
            xQueueReceive(p_event_queue, &event, pdMS_TO_TICKS(100));

            // Was my button (with id 4) released?
            if (event.type == NEXTION_TOUCH_STATE && event.touch.state == NEXTION_TOUCH_RELEASED && event.touch.component_id == 4)
            {
                char city[50];
                int temperature;

                // Get the city name.
                nextion_get_text("get t0.txt\0", city);

                // Get the temperature.
                nextion_get_number("get n0.val\0", &temperature);

                ESP_LOGI(TAG, "City: %s", city);
                ESP_LOGI(TAG, "Temperature: %d", temperature);

                break;
            }

            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }

    if (nextion_driver_delete() != NEX_OK)
    {
        ESP_LOGE(TAG, "could not delete nextion driver");
    }
}
