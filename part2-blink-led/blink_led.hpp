#ifndef BLINK_HPP
#define BLINK_HPP

#include "pico/stdlib.h"

class BlinkLED {
private:
    //define the pin
    const uint LED_PIN;

public:
    BlinkLED(uint pin);

    //innitialization
    void startBlinking();
};

#endif
