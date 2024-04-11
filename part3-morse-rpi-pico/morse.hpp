#ifndef MORSE_HPP
#define MORSE_HPP

#include <string>

class MorseCode {
private:
    const uint LED_PIN;
    const char* morseAlphabet[26] = {
        ".-",    // A
        "-...",  // B
        "-.-.",  // C
        "-..",   // D
        ".",     // E
        "..-.",  // F
        "--.",   // G
        "....",  // H
        "..",    // I
        ".---",  // J
        "-.-",   // K
        ".-..",  // L
        "--",    // M
        "-.",    // N
        "---",   // O
        ".--.",  // P
        "--.-",  // Q
        ".-.",   // R
        "...",   // S
        "-",     // T
        "..-",   // U
        "...-",  // V
        ".--",   // W
        "-..-",  // X
        "-.--",  // Y
        "--.."   // Z
    };

public:
    MorseCode(uint pin);

    void convertCharToMorse(char letter);
    void convertStringToMorse(const std::string& message);
};

#endif // MORSE_HPP