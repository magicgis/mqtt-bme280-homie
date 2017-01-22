/*
 * BME280Node.h
 * Homie Node for BME280 sensors using Adafruit BME280 library.
 *
 * Version: 1.0
 * Author: Markus Haack (http://github.com/mhaack)
 */

#ifndef SRC_BME280NODE_H_
#define SRC_BME280NODE_H_

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include <HomieNode.hpp>

class BME280Node: public HomieNode {
private:
    unsigned long lastMeasurement;

    Adafruit_BME280 bme;

public:
    BME280Node();
    virtual void setup() override;
    virtual void loop() override;

    float getHumidity() const {
        return humidity;
    }

    float getTemperature() const {
        return temperature;
    }

    float getPressure() const {
        return pressure;
    }

private:
    float temperature = NAN;
    float humidity = NAN;
    float pressure = NAN;
};

#endif