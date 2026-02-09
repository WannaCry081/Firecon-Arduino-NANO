#include <Arduino.h>
#include <SimpleDHT.h>

const uint8_t FLAME_SENSOR_PINS[] = {9, 10, 11, 12, 13};

const uint8_t GAS_SENSOR_DIGITAL_PIN = 8;
const uint8_t GAS_SENSOR_ANALOG_PIN = A0;

const uint8_t DHT_SENSOR_PIN = 7;
SimpleDHT11 dht11(DHT_SENSOR_PIN);

/**
 * @brief Checks all flame sensors and returns whether flame is detected.
 *
 * Reads each pin in FLAME_SENSOR_PINS. If any sensor reads LOW,
 * flame is considered detected.
 *
 * @return 1 if flame detected, 0 otherwise.
 */
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

/**
 * @brief Reads temperature and humidity from DHT11 sensor.
 *
 * Uses the SimpleDHT library to read from the DHT11 sensor. If reading is
 * successful, temperature and humidity values are stored in the provided
 * pointers.
 *
 * @param temperature Pointer to store the read temperature value (in Celsius).
 * @param humidity Pointer to store the read humidity value (in %RH).
 * @return 1 if reading is successful, 0 otherwise.
 */
uint8_t getDHTSensorReading(float *temperature, float *humidity)
{
  byte data[40] = {0};
  int result = dht11.read2(temperature, humidity, data);

  if (result != SimpleDHTErrSuccess)
  {
    return 0;
  }
  return 1;
}

void setup()
{
  // Initialize serial communication for debugging
  Serial.begin(9600);

  for (uint8_t flameSensorPin : FLAME_SENSOR_PINS)
  {
    pinMode(flameSensorPin, INPUT_PULLUP);
  }

  pinMode(GAS_SENSOR_DIGITAL_PIN, INPUT_PULLUP);
}

void loop()
{
  float temperature = 0.0f;
  float humidity = 0.0f;

  uint8_t gasSensorDigitalValue = digitalRead(GAS_SENSOR_DIGITAL_PIN);
  uint16_t gasSensorAnalogValue = analogRead(GAS_SENSOR_ANALOG_PIN);

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
}
