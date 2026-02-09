#include "dht.hpp"

#include <SimpleDHT.h>

namespace
{
  const uint8_t DHT_SENSOR_PIN = 7;
  SimpleDHT11 dht11(DHT_SENSOR_PIN);
}

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
