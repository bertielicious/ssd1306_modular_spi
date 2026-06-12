#include <stdio.h>
#include "constants.h"
#include "esp_log.h"
#include "pin_assign.h"
#include "config_display_gpio.h"
#include "config_dev.h"
#include "driver/gpio.h"
#include "config_spi.h"
#include "init_ssd1322.h"
#include "clear_screen.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"



spi_device_handle_t ssd1322_handle = NULL;   // ✅ the one and only definition
static const char *TAG = "gpio num";
void app_main(void)
{
    //assign gpio pins to each SPI pin
   display_pins_t phil; 
   display_pins_t *totnor;
   totnor = &phil;
   pin_assign(&phil); //assign SPI labels to each gpio pin

   ESP_LOGI(TAG, "MOSI = %d\n", totnor->mosi);
   ESP_LOGI(TAG, "SCK = %d\n", totnor->sck);
   ESP_LOGI(TAG, "RES = %d\n", totnor->res);
   ESP_LOGI(TAG, "DC = %d\n", totnor->dc);
   ESP_LOGI(TAG, "CS = %d\n", totnor->cs);
  
    
    
    //config gpio pins cs, dc, res

    config_display_gpio(&phil);
    gpio_set_level(totnor->cs, 1);

    //configure spi bus
    config_spi(&phil);

    //configuration for a SPI slave device (SSD1322)that is 
    //connected to SPI2_HOST bus
    config_dev(&ssd1322_handle, &phil);

    init_ssd1322();
    vTaskDelay(1000/portTICK_PERIOD_MS );

    clear_screen();

    while(true)
    {
        

    }
}

