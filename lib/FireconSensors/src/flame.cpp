#include "flame.hpp"

namespace
{
  const uint8_t FLAME_SENSOR_PINS[] = {6, 7, 8, 9};
}

void initFlameSensors()
{
  for (uint8_t flameSensorPin : FLAME_SENSOR_PINS)
  {
    pinMode(flameSensorPin, INPUT_PULLUP);
  }
}

uint8_t getFlameSensorReading()
{
  for (uint8_t flameSensorPin : FLAME_SENSOR_PINS)
  {
    uint8_t sensorValue = digitalRead(flameSensorPin);
    if (sensorValue == LOW)
    {
      return 1; // Flame detected
    }
  }
  return 0; // No flame detected
}
