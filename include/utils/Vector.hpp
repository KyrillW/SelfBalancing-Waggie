#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <Arduino.h>
#include <Wire.h>
class Vector {
private:
  float x;
  float y;
  float z;

public:
  Vector(float x, float y, float z) : x(x), y(y), z(z){};

  float getX() const { return x; }
  float getY() const { return y; }
  float getZ() const { return z; }
};

#endif // !VECTOR_HPP
