#include "Driver.hpp"
#include <Arduino.h>

void Driver::drive(int speed, Direction direction) {
  if (speed > 255) {
    speed = 255;
  }

  if (direction == Direction::FORWARD)
  {
    analogWrite(motor_a.backward_pin, 0);
    analogWrite(motor_b.backward_pin, 0);
    analogWrite(motor_a.forward_pin, speed);
    analogWrite(motor_b.forward_pin, speed);
  }else{
    analogWrite(motor_a.forward_pin, 0);
    analogWrite(motor_b.forward_pin, 0);
    analogWrite(motor_a.backward_pin, speed);
    analogWrite(motor_b.backward_pin, speed);
  }
}

void Driver::forward(int speed) { drive(speed, Direction::FORWARD); }

void Driver::backward(int speed) { drive(speed, Direction::BACKWARD); }
