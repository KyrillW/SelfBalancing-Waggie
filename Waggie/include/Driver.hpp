#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "Motor.hpp"
#include "utils/Direction.hpp"
#include <Arduino.h>

/**
 * @class Driver
 * @brief Represents a driver that controls multiple motors.
 *
 * The Driver class provides methods to control a set of motors, allowing for
 * forward and backward movement at specified speeds.
 */
class Driver {
private:
  Motor motor_a;
  Motor motor_b;

  /**
   * @brief Drives the motors at a specified speed and direction.
   *
   * @param speed The speed at which to drive the motors.
   * @param direction The direction to drive the motors (forward or backward).
   */
  void drive(const int speed, Direction direction);

public:
  /**
   * @brief Constructs a new Driver object.
   *
   * @param motors The array of motors controlled by the driver.
   * @param count The number of motors in the array.
   */
  Driver(const Motor &motor_a, const Motor &motor_b)
      : motor_a(motor_a), motor_b(motor_b) {}

  /**
   * @brief Drives the motors forward at a specified speed.
   *
   * @param speed The speed at which to drive the motors forward.
   */
  void forward(const int speed);

  /**
   * @brief Drives the motors backward at a specified speed.
   *
   * @param speed The speed at which to drive the motors backward.
   */
  void backward(const int speed);
};

#endif // DRIVER_HPP
