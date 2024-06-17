#include "Gyro.hpp"

int16_t Gyro::read_hl_register(int high_address, int low_address) {
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

// Pitch
int16_t Gyro::readX() {
  const int high_address = 0x43;
  const int low_address = 0x44;
  return read_hl_register(high_address, low_address);
}

// Roll
int16_t Gyro::readY() {
  const int high_address = 0x45;
  const int low_address = 0x46;
  return read_hl_register(high_address, low_address);
}

// Yaw
int16_t Gyro::readZ() {
  const int high_address = 0x47;
  const int low_address = 0x48;
  return read_hl_register(high_address, low_address);
}

Vector Gyro::read() { return Vector(readX(), readY(), readZ()); }
