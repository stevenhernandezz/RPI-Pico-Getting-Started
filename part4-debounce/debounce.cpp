#include "debounce.hpp"
#include <iostream>
#include <ctime>

bool DebounceExample::state;
unsigned long DebounceExample::lastPressTime;
const unsigned long DebounceExample::delayTime = 200;

DebounceExample::DebounceExample() {
}

void DebounceExample::initialize() {
    stdio_init_all();
    // Initialize time
    lastPressTime = to_ms_since_boot(get_absolute_time());

    // LED setting up
    const uint LED_PIN = 2;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    state = true;

    // Button setup
    const uint BTN_PIN = 3; // Use GPIO pin 0 for the button
    gpio_init(BTN_PIN);
    gpio_pull_up(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_set_irq_enabled_with_callback(BTN_PIN, GPIO_IRQ_EDGE_FALL, true, &irqCallback);
}

void DebounceExample::irqCallback(uint gpio, uint32_t events) {
    unsigned long currentTime = to_ms_since_boot(get_absolute_time());
    if ((currentTime - lastPressTime) > delayTime) {
        lastPressTime = currentTime;
        //std::cout << "Good. BTN " << gpio << " Event: " << events << std::endl;

        state = !state;
        // Toggle the LED
        const uint LED_PIN = 2;
        gpio_put(LED_PIN, state);
    } else {
        //std::cout << "Bad.  BTN " << gpio << " Event: " << events << std::endl;
    }
}

void DebounceExample::run() {
    while (1) {}
}