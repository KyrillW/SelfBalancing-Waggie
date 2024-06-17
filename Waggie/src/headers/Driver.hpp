#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "Motor.hpp"
#include "utils/Direction.hpp"
#include <Arduino.h>
#include <iostream>
#include <vector>

using std::vector;

class Driver {
private:
  const vector<Motor> motors;
  void drive(const int speed, Direction direction);

public:
  Driver(const vector<Motor> &motors;) : motors(motors){};

  void forward(const int speed);

  void backward(const int speed);
};

#endif // DRIVER_HPP