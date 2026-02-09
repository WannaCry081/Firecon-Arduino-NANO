#pragma once

#include <Arduino.h>

/**
 * @brief Initializes gas sensor pins.
 */
void initGasSensor();

/**s
 * @brief Reads the digital gas sensor value.
 *
 * @return Digital reading (HIGH/LOW).
 */
uint8_t readGasSensorDigital();

/**
 * @brief Reads the analog gas sensor value.
 *
 * @return Analog reading (0-1023).
 */
uint16_t readGasSensorAnalog();
