# Firecon (Arduino NANO)

Arduino Nano firmware that reads flame, gas, and temperature/humidity sensors and publishes the readings over UART (Serial) for an ESP32 to consume. The ESP32 side handles GPS and alerting to external services. This repository contains **only** the Arduino Nano sensor reader.

## Features

- Reads multiple flame sensors (digital)
- Reads gas sensor (digital + analog)
- Reads DHT11 temperature/humidity (SimpleDHT)
- Outputs readings once per second over Serial at 9600 baud

## Hardware (Nano side)

- Arduino Nano (ATmega328)
- Flame sensors (digital)
- Gas sensor with digital + analog outputs
- DHT11 temperature/humidity sensor

## Pin mapping

From the current code:

- Flame sensors: D9, D10, D11, D12, D13 (INPUT_PULLUP)
- Gas sensor digital: D8 (INPUT_PULLUP)
- Gas sensor analog: A0
- DHT11: D7

Update these in the library sources if your wiring differs:

- [lib/FireconSensors/src/flame.cpp](lib/FireconSensors/src/flame.cpp)
- [lib/FireconSensors/src/gas.cpp](lib/FireconSensors/src/gas.cpp)
- [lib/FireconSensors/src/dht.cpp](lib/FireconSensors/src/dht.cpp)

## Serial output format

The Nano prints key-value lines once per second:

    flameDetected=0|1
    gasDetected=0|1
    gasSensorValue=0-1023
    temperature=<float>|error
    humidity=<float>|error

Baud rate: **9600**.

## Build & upload (PlatformIO)

This project is configured for PlatformIO:

- Environment: nanoatmega328
- Dependency: SimpleDHT

Example commands:

    pio run
    pio run -t upload

## Project structure

- [src/main.cpp](src/main.cpp): main loop that reads sensors and prints data
- [lib/FireconSensors](lib/FireconSensors): sensor drivers
- [platformio.ini](platformio.ini): PlatformIO config

## Notes

- This repository is **only** for the Arduino Nano sensor reader.
- ESP32 logic (UART parsing, GPS, alerting) is not included here.

## Reference

- Arduino NANO Pins

  ![image](/public/arduino-nano-pins.png)
