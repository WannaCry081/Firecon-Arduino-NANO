#include <Arduino.h>

#include "dht.hpp"
#include "flame.hpp"
#include "gas.hpp"

unsigned long startTime = 0;

void setup()
{
  Serial.begin(9600);

  Serial.println("Initializing flame sensors...");
  initFlameSensors();

  Serial.println("Initializing Gas sensor...");
  initGasSensor();

  Serial.println("Arduino NANO is ready.");
}

void logSerial(const String &label, const String &value)
{
  Serial.print(label);
  Serial.println(value);
}

void loop()
{
  unsigned long currentMillis = millis();

  float temperature = 0.0f;
  float humidity = 0.0f;

  if (currentMillis - startTime >= 500)
  {
    startTime = currentMillis;

    uint8_t gasSensorDigitalValue = readGasSensorDigital();
    uint16_t gasSensorAnalogValue = readGasSensorAnalog();

    uint8_t flameDetected = getFlameSensorReading();
    uint8_t hasDHTReading = getDHTSensorReading(&temperature, &humidity);

    logSerial("flameDetected=", String(flameDetected));
    logSerial("gasDetected=", String(gasSensorDigitalValue));
    logSerial("gasSensorValue=", String(gasSensorAnalogValue));

    if (hasDHTReading)
    {
      logSerial("temperature=", String(temperature));
      logSerial("humidity=", String(humidity));
    }
    else
    {
      logSerial("temperature=", "error");
      logSerial("humidity=", "error");
    }
  }
}