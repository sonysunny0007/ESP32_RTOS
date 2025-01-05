#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SDA_PIN 26
#define SCL_PIN 27

Adafruit_BME280 bme; // Create an instance of the BME280 sensor

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  Serial.println("BME280 sensor found!");
}

void loop() {
  // Your code to read and display sensor data
}
