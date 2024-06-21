#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <Arduino.h>

/**
 * @class Motor
 * @brief Represents a motor with forward and backward control pins.
 *
 * The Motor class provides methods to control a motor using specified pins
 * for forward and backward movement.
 */
class Motor {
private:
public:
  int forward_pin;
  int backward_pin;
  /**
   * @brief Constructs a new Motor object.
   *
   * Initializes the specified pins as output pins for motor control.
   *
   * @param forward_pin The pwm pin used to control forward movement.
   * @param backward_pin The pwm pin used to control backward movement.
   */
  Motor(const int forward_pin, const int backward_pin)
      : forward_pin(forward_pin), backward_pin(backward_pin) {
    pinMode(forward_pin, OUTPUT);
    pinMode(backward_pin, OUTPUT);
  }

  /**
   * @brief Gets the forward control pin.
   *
   * @return The pin used to control forward movement.
   */
  const int getForwardPin() { return forward_pin; }

  /**
   * @brief Gets the backward control pin.
   *
   * @return The pin used to control backward movement.
   */
  const int getBackwardPin() { return backward_pin; }
};

#endif // MOTOR_HPP
