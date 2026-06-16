# ESP32 Multi-Protocol Sensor System

A multi-protocol embedded communication system that demonstrates simultaneous UART and SPI communication on an ESP32. Temperature data flows from a DHT22 sensor through an Arduino via UART, gets processed by the ESP32, and drives a visual LED thermometer through a 74HC595 shift register over SPI.

# How it works

The Arduino reads temperature and humidity from a DHT22 sensor and transmits the data over UART to the ESP32 at 9600 baud. The ESP32 parses incoming strings, extracts the temperature value, and maps it to an 8-bit LED pattern. That pattern is sent to a 74HC595 shift register over SPI using shiftOut — more LEDs illuminate as temperature rises, creating a live visual thermometer.

# Parts list

ESP32 development board
Arduino Uno
DHT22 temperature and humidity sensor
74HC595 shift register
8x LEDs
8x 330Ω resistors
1kΩ and 2kΩ resistors (voltage divider for 5V to 3.3V level shifting)
Breadboard and jumper wires

# Wiring
**UART (Arduino → ESP32):**

Arduino TX → 1kΩ → midpoint → 2kΩ → GND (voltage divider)
Midpoint → ESP32 GPIO16 (RX2)
ESP32 GPIO17 (TX2) → Arduino RX
Shared GND between both boards
Arduino powered from ESP32 5V pin

**SPI (ESP32 → 74HC595):**

GPIO23 (MOSI) → SER (pin 23)
GPIO18 (SCK) → SRCLK (pin 18)
GPIO5 (Latch) → RCLK (pin 5)
OE (pin 13) → GND
SRCLR (pin 10) → 3.3V
VCC (pin 16) → 3.3V
GND (pin 8) → GND
Output pins QA-QH → 330Ω resistor → LED → GND

# Temperature to LED mapping

Below 60°F → 1 LED
60–65°F → 2 LEDs
65–70°F → 3 LEDs
70–75°F → 4 LEDs
75–80°F → 5 LEDs
80–85°F → 6 LEDs
85–90°F → 7 LEDs
Above 90°F → 8 LEDs

# Setup

Install DHT sensor library by Adafruit in Arduino IDE Library Manager
Upload Arduino sketch to Arduino Uno
Upload ESP32 sketch to ESP32
Power Arduino from ESP32 5V pin and disconnect Arduino USB
Open Serial Monitor at 115200 baud to see live temperature readings

# Future improvements

Add I2C sensor (BME280) for a third protocol
Add WiFi web dashboard to display readings remotely
Add humidity-based secondary LED indicator
