#ifndef GYRO_HPP
#define GYRO_HPP

#include "utils/Vector.hpp"
#include <Arduino.h>
#include <Wire.h>

class PosSensor {
private:
  const int ADDRESS = 0x68;
  const float accel_sample_rate = 16384.0; // for 2g
  const float gyro_sensitivity = 65.5;     // for 500dps
  int16_t read_hl_register(int high_address, int low_address);
  double timer;

public:
  PosSensor() {
    Wire.begin();

    Wire.beginTransmission(this->ADDRESS);
    Wire.write(0x6B);       // Power management register
    Wire.write(0b10000000); // Reset registers
    Wire.endTransmission(true);
    delay(100);
    Wire.beginTransmission(this->ADDRESS);
    Wire.write(0x6B);       // SPR Register
    Wire.write(0b00000111); // Reset sensors
    Wire.endTransmission(true);
    delay(100);

    Wire.beginTransmission(this->ADDRESS);
    Wire.write(0x6B); // Power management register
    Wire.write(0);    // Wake up the sensor
    Wire.endTransmission(true);

    Wire.beginTransmission(this->ADDRESS);
    Wire.write(0x1B);       // Gyroscope configuration register
    Wire.write(0b00000001); // 500dps
    Wire.endTransmission(true);

    Wire.beginTransmission(this->ADDRESS);
    Wire.write(0x1C); // Accelerometer configuration register
    Wire.write(0x0);  // 2G
    Wire.endTransmission(true);
  }

  float readPitch();
  float readRoll();
  float readYaw();
  Vector readGyro();

  Vector burstRead(int start_address, int bytes, float sensitivity);

  float readGX();
  float readGY();
  float readGZ();
  Vector readAccel();

  void markTime();
  double getElapsedSeconds();
};

#endif // GYRO_HPP
