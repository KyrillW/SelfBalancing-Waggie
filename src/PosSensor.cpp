#include "PosSensor.hpp"

int16_t PosSensor::read_hl_register(int high_address, int low_address) {
  Wire.beginTransmission(this->ADDRESS);
  Wire.write(high_address);
  Wire.endTransmission(false);
  Wire.requestFrom(this->ADDRESS, 1, true);

  int16_t value = Wire.read() << 8;
  Wire.beginTransmission(this->ADDRESS);
  Wire.write(low_address);
  Wire.endTransmission(false);
  Wire.requestFrom(this->ADDRESS, 1, true);

  value |= Wire.read();

  return value;
}

Vector PosSensor::burstRead(int start_address, int bytes, float sensitivity) {
  Wire.beginTransmission(this->ADDRESS);
  Wire.write(start_address);
  Wire.endTransmission(false);
  Wire.requestFrom(this->ADDRESS, 6, true); // 6 registers, 3* hl

  while (Wire.available() < 6) {
    delay(1);
  }

  int16_t x = Wire.read() << 8 | Wire.read();
  int16_t y = Wire.read() << 8 | Wire.read();
  int16_t z = Wire.read() << 8 | Wire.read();

  return Vector(x / sensitivity, y / sensitivity, z / sensitivity);
}

// Pitch (gyro maybe * insteaad of /)
float PosSensor::readPitch() {
  const int high_address = 0x43;
  const int low_address = 0x44;
  return read_hl_register(high_address, low_address) / gyro_sensitivity;
}

// Roll
float PosSensor::readRoll() {
  const int high_address = 0x45;
  const int low_address = 0x46;
  return read_hl_register(high_address, low_address) / gyro_sensitivity;
}

// Yaw
float PosSensor::readYaw() {
  const int high_address = 0x47;
  const int low_address = 0x48;
  return read_hl_register(high_address, low_address) / gyro_sensitivity;
}

Vector PosSensor::readGyro() {
  return Vector(readPitch(), readRoll(), readYaw());
}

float PosSensor::readGX() {
  const int high_address = 0x3B;
  const int low_address = 0x3C;
  return read_hl_register(high_address, low_address) / accel_sample_rate;
}

float PosSensor::readGY() {
  const int high_address = 0x3D;
  const int low_address = 0x3E;
  return read_hl_register(high_address, low_address) / accel_sample_rate;
}

float PosSensor::readGZ() {
  const int high_address = 0x3F;
  const int low_address = 0x40;
  return read_hl_register(high_address, low_address) / accel_sample_rate;
}

Vector PosSensor::readAccel() { return Vector(readGX(), readGY(), readGZ()); }

void PosSensor::markTime() { timer = micros(); }

double PosSensor::getElapsedSeconds() {
  return ((double)(micros() - timer) / 1000000);
}