#include "pico/stdlib.h"
#include <iostream>

int main() {
  stdio_init_all();
  while (true) {
    std::cout << "Hello, World!" << std::endl;
    sleep_ms(250);
  }
}
