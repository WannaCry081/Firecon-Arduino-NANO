#include <Arduino.h>

const uint8_t FLAME_SENSOR_PINS[] = {9, 10, 11, 12, 13};

boolean getFlameSensorData()
{
  for (uint8_t flameSensorPin : FLAME_SENSOR_PINS)
  {
    uint8_t sensorValue = digitalRead(flameSensorPin);
    if (sensorValue == LOW)
    {
      return true; // Flame detected
    }
  }
  return false; // No flame detected
}

void setup()
{
  for (uint8_t flameSensorPin : FLAME_SENSOR_PINS)
  {
    pinMode(flameSensorPin, INPUT_PULLUP);
  }
}

void loop()
{
  boolean flameDetected = getFlameSensorData();
  Serial.println("Flame detected: " + String(flameDetected));
}
