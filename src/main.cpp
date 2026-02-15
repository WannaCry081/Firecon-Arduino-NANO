#include <Arduino.h>
#include <SoftwareSerial.h>

#include "dht.hpp"
#include "flame.hpp"
#include "gas.hpp"

unsigned long startTime = 0;

uint8_t RX_PIN = 10,
        TX_PIN = 11;

SoftwareSerial esp(RX_PIN, TX_PIN); // RX, TX (Nano D10 = RX, D11 = TX)

void setup()
{
  // Initialize serial communication for debugging
  Serial.begin(115200);
  esp.begin(9600);

  Serial.println("Initializing flame sensors...");
  initFlameSensors();

  Serial.println("Initializing Gas sensor...");
  initGasSensor();

  Serial.println("Arduino NANO is ready.");
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

    esp.print("flameDetected=");
    esp.println(flameDetected);
    esp.print("gasDetected=");
    esp.println(gasSensorDigitalValue);
    esp.print("gasSensorValue=");
    esp.println(gasSensorAnalogValue);

    if (hasDHTReading)
    {
      esp.print("temperature=");
      esp.println(temperature);
      esp.print("humidity=");
      esp.println(humidity);
    }
    else
    {
      esp.print("temperature=");
      esp.println("error");
      esp.print("humidity=");
      esp.println("error");
    }

    esp.println("---");
  }
}
