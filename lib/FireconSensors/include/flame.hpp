#pragma once

#include <Arduino.h>

/**
 * @brief Initializes flame sensor pins.
 */
void initFlameSensors();

/**
 * @brief Checks all flame sensors and returns whether flame is detected.
 *
 * Reads each pin configured for flame sensors. If any sensor reads LOW,
 * flame is considered detected.
 *
 * @return 1 if flame detected, 0 otherwise.
 */
uint8_t getFlameSensorReading();
