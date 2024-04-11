#include "blink.hpp"

BlinkLED::BlinkLED(uint pin) : LED_PIN(pin) {
    //initializing the pin
    gpio_init(LED_PIN);
    //setting directory
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

//innitialization
void BlinkLED::startBlinking() {
    //while loop to blink
    while (1) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);

        //turning off
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }
}