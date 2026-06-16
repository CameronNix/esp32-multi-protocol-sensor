# esp32-multi-protocol-sensor
Multi-protocol embedded system using UART and SPI on ESP32. Arduino reads DHT22 temperature/humidity data and transmits over UART. ESP32 processes data and drives a 74HC595 shift register over SPI, controlling 8 LEDs as a visual thermometer.
