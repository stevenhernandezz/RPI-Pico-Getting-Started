#ifndef DEBOUNCE_HPP
#define DEBOUNCE_HPP

#include "pico/stdlib.h"
#include "pico/time.h"

class DebounceExample {
public:
    DebounceExample();
    void initialize();
    static void irqCallback(uint gpio, uint32_t events);
    void run();

private:
    static bool state;
    static unsigned long lastPressTime;
    static const unsigned long delayTime;
};

#endif // DEBOUNCEEXAMPLE_H