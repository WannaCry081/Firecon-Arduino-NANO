#include "gas.hpp"

namespace
{
  const uint8_t GAS_SENSOR_DIGITAL_PIN = 4;
  const uint8_t GAS_SENSOR_ANALOG_PIN = A0;
}

void initGasSensor()
{
  // TODO: Test if pullup is needed for the gas sensor. If not, change to INPUT.
  pinMode(GAS_SENSOR_DIGITAL_PIN, INPUT_PULLUP);
}

uint8_t readGasSensorDigital()
{
  return digitalRead(GAS_SENSOR_DIGITAL_PIN);
}

uint16_t readGasSensorAnalog()
{
  return analogRead(GAS_SENSOR_ANALOG_PIN);
}
