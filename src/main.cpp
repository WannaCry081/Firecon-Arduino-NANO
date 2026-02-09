#include <Arduino.h>

const uint8_t FLAME_SENSOR_PINS[] = {9, 10, 11, 12, 13};

const uint8_t GAS_SENSOR_DIGITAL_PIN = 8;
const uint8_t GAS_SENSOR_ANALOG_PIN = A0;

uint8_t getFlameSensorData()
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

void setup()
{
  Serial.begin(9600);

  for (uint8_t flameSensorPin : FLAME_SENSOR_PINS)
  {
    pinMode(flameSensorPin, INPUT_PULLUP);
  }

  pinMode(GAS_SENSOR_DIGITAL_PIN, INPUT_PULLUP);
}

void loop()
{
  uint8_t flameDetected = getFlameSensorData();

  uint8_t gasSensorDigitalValue = digitalRead(GAS_SENSOR_DIGITAL_PIN);

  uint16_t gasSensorAnalogValue = analogRead(GAS_SENSOR_ANALOG_PIN);

  Serial.println("flameDetected=" + String(flameDetected));
  Serial.println("gasDetected=" + String(gasSensorDigitalValue));
  Serial.println("gasSensorValue=" + String(gasSensorAnalogValue));
}
