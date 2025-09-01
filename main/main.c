#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

//define constants
#define led 9
#define buzzer 46
#define roof 16
#define door 17
#define parking 18


void app_main(void)
{
    //inputs
    gpio_set_direction(led, GPIO_MODE_OUTPUT);
    gpio_set_direction(buzzer, GPIO_MODE_OUTPUT);

    //outputs
    gpio_set_direction(roof, GPIO_MODE_INPUT);
    gpio_set_direction(door, GPIO_MODE_INPUT);
    gpio_set_direction(parking, GPIO_MODE_INPUT);

    while (1) {

        //store button state in variables
        int btn_roof = gpio_get_level(16);
        int btn_door = gpio_get_level(17);
        int btn_parking = gpio_get_level(18);

        // Inicializar alarmas apagadas
        int led_state = 0;
        int buzzer_state = 0;

        // Verificar cada sensor y activar alarmas correspondientes
        if(btn_door == 1){
            led_state = 1;      // Activa alarma lumínica
            buzzer_state = 1;   // Activa alarma sonora
        }
        
        if(btn_roof == 1){
            led_state = 1;      // Activa solo alarma lumínica
        }
        
        if(btn_parking == 1) {
            buzzer_state = 1;   // Activa solo alarma sonora
        }

        // Aplicar estados a las salidas
        gpio_set_level(led, led_state);
        gpio_set_level(buzzer, buzzer_state);

        // Print status to terminal
        printf("Buttons - Roof: %d, Door: %d, Parking: %d | Outputs - LED: %d, Buzzer: %d\n", 
               btn_roof, btn_door, btn_parking, led_state, buzzer_state);

        vTaskDelay(pdMS_TO_TICKS(100)); // Pequeño retardo para evitar rebotes
    }
}