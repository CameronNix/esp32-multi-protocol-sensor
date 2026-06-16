#include<SPI.h>

#define RXD2 16
#define TXD2 17
#define DATA_PIN 23
#define CLOCK_PIN 18
#define LATCH_PIN 5

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  SPI.begin();
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
}

void loop() {
  if(Serial2.available()) {
    String data = Serial2.readStringUntil('\n');
    if(data.indexOf("Temp") != -1) {
      float temp = data.substring(6).toFloat();
      Serial.println(temp);
        if(temp <= 60) {
          digitalWrite(LATCH_PIN, LOW);
          shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0b00000001);
          digitalWrite(LATCH_PIN, HIGH);
        } else if(temp <= 65) {
          digitalWrite(LATCH_PIN, LOW);
          shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0b00000011);
          digitalWrite(LATCH_PIN, HIGH);
        } else if(temp <= 70) {
          digitalWrite(LATCH_PIN, LOW);
          shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0b00000111);
          digitalWrite(LATCH_PIN, HIGH);
        } else if(temp <= 75) {
          digitalWrite(LATCH_PIN, LOW);
          shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0b00001111);
          digitalWrite(LATCH_PIN, HIGH);
        } else if(temp <= 80) {
          digitalWrite(LATCH_PIN, LOW);
          shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0b00011111);
          digitalWrite(LATCH_PIN, HIGH);
        } else if(temp <= 85) {
          digitalWrite(LATCH_PIN, LOW);
          shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0b00111111);
          digitalWrite(LATCH_PIN, HIGH);
        } else if(temp <= 90) {
          digitalWrite(LATCH_PIN, LOW);
          shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0b01111111);
          digitalWrite(LATCH_PIN, HIGH);
        } else {
          digitalWrite(LATCH_PIN, LOW);
          shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0b11111111);
          digitalWrite(LATCH_PIN, HIGH);
        }

        
    }
  }
  delay(1000);

}
