#pragma once

#include <Arduino.h>

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
uint8_t getDHTSensorReading(float *temperature, float *humidity);
