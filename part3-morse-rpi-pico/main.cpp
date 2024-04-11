#include "morse.hpp"
#include "pico/stdlib.h"

int main() {
    MorseCode morseCode(0);
    morseCode.convertStringToMorse("HELLO WORLD");

    return 0;
}