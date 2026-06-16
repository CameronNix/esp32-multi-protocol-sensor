#include<DHT.h>

#define DHTTYPE DHT22;
#define DHTPIN 4;

DHT dht(4, DHT22);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.println(temp * 9 / 5 + 32);
  delay(1000);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  delay(1000);
}
