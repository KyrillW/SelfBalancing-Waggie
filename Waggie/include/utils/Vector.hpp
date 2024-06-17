#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <Arduino.h>
#include <Wire.h>
class Vector {
private:
  int16_t x;
  int16_t y;
  int16_t z;

public:
  Vector(int16_t x, int16_t y, int16_t z) : x(x), y(y), z(z){};

  int16_t getX() const { return x; }
  int16_t getY() const { return y; }
  int16_t getZ() const { return z; }
};

#endif // !VECTOR_HPP
