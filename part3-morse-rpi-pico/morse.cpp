#include "morse.hpp"
#include "pico/stdlib.h"

MorseCode::MorseCode(uint pin) : LED_PIN(pin) {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void MorseCode::convertCharToMorse(char letter) {
    int ascii = static_cast<int>('A');

    if (letter >= 'A' && letter <= 'Z') {
        int index = static_cast<int>(letter) - ascii;

        for (int i = 0; morseAlphabet[index][i] != '\0'; i++) {
            if (morseAlphabet[index][i] == '.') {
                gpio_put(LED_PIN, 1);
                sleep_ms(250);
            } else if (morseAlphabet[index][i] == '-') {
                gpio_put(LED_PIN, 1);
                sleep_ms(500);
            }

            gpio_put(LED_PIN, 0);
            sleep_ms(250);
        }
    }
}

void MorseCode::convertStringToMorse(const std::string& message) {
    for (char letter : message) {
        convertCharToMorse(letter);
        sleep_ms(500);
    }
}