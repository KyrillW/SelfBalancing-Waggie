#ifndef GYRO_HPP
#define GYRO_HPP

#include "utils/Vector.hpp"
#include <Arduino.h>
#include <Wire.h>

class Gyro {
private:
  const int ADDRESS = 0x68;

  int16_t read_hl_register(int high_address, int low_address);

public:
  Gyro() {
    Wire.begin();

    Wire.beginTransmission(this->ADDRESS);
    Wire.write(0x6B); // Power management register
    Wire.write(0);    // Wake up the sensor
    Wire.endTransmission(true);

    Wire.beginTransmission(this->ADDRESS);
    Wire.write(0x1B); // Gyroscope configuration register
    Wire.write(0x10);
    Wire.endTransmission(true);
  }

  int16_t readX();
  int16_t readY();
  int16_t readZ();
  Vector read();
};

#endif // GYRO_HPP
