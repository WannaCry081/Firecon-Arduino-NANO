#include <Arduino.h>

#include "dht.hpp"
#include "flame.hpp"
#include "gas.hpp"

void setup()
{
  // Initialize serial communication for debugging
  Serial.begin(9600);

  initFlameSensors();
  initGasSensor();
}

void loop()
{
  float temperature = 0.0f;
  float humidity = 0.0f;

  uint8_t gasSensorDigitalValue = readGasSensorDigital();
  uint16_t gasSensorAnalogValue = readGasSensorAnalog();

  uint8_t flameDetected = getFlameSensorReading();
  uint8_t hasDHTReading = getDHTSensorReading(&temperature, &humidity);

  Serial.println("flameDetected=" + String(flameDetected));
  Serial.println("gasDetected=" + String(gasSensorDigitalValue));
  Serial.println("gasSensorValue=" + String(gasSensorAnalogValue));

  if (hasDHTReading)
  {
    Serial.println("temperature=" + String(temperature));
    Serial.println("humidity=" + String(humidity));
  }
  else
  {
    Serial.println("temperature=error");
    Serial.println("humidity=error");
  }

  delay(1000);
}
