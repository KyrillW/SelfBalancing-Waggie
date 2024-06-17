#ifndef GYRO_HPP
#define GYRO_HPP

#include "utils/Vector.hpp"
#include <Arduino.h>
#include <Wire.h>

class PosSensor
{
private:
  const int ADDRESS = 0x68;
  const int accel_sample_rate = 16384; // for 2g
  const float gyro_sensitivity = 65.5; // for 500dps
  int16_t read_hl_register(int high_address, int low_address);
  double timer;

public:
  PosSensor()
  {
    Wire.begin();

    Wire.beginTransmission(this->ADDRESS);
    Wire.write(0x6B); // Power management register
    Wire.write(0);    // Wake up the sensor
    Wire.endTransmission(true);

    Wire.beginTransmission(this->ADDRESS);
    Wire.write(0x1B);       // Gyroscope configuration register
    Wire.write(0b00000010); // 500dps
    Wire.endTransmission(true);

    Wire.beginTransmission(this->ADDRESS);
    Wire.write(0x1B); // Accelerometer configuration register
    Wire.write(0x0);  // 2G
    Wire.endTransmission(true);
  }

  int16_t readPitch();
  int16_t readRoll();
  int16_t readYaw();
  Vector readGyro();

  int16_t readGX();
  int16_t readGY();
  int16_t readGZ();
  Vector readAccel();

  void markTime();
  double getElapsedSeconds();
};

#endif // GYRO_HPP
