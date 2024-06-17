#include "Driver.hpp"
#include <Arduino.h>

void Driver::drive(int speed, Direction direction) {
  if (speed > 255) {
    Serial.println("Error: Speed must be <= 255");
    return;
  }

  Motor motors[] = {motor_a, motor_b};
  for (Motor currentMotor : motors) {
    int pin = (direction == Direction::FORWARD) ? currentMotor.getForwardPin()
                                                : currentMotor.getBackwardPin();

    analogWrite(pin, speed);
  }

  // https://components101.com/sites/default/files/component_datasheet/MX1508-DC-Motor-Driver-Datasheet.pdf
  // -- example (acttime 3000)
  delay(3000);
  for (Motor currentMotor : motors) {
    int pin = (direction == Direction::FORWARD) ? currentMotor.getForwardPin()
                                                : currentMotor.getBackwardPin();

    analogWrite(pin, 0);
  }
  delay(20);
}

void Driver::forward(int speed) { drive(speed, Direction::FORWARD); }

void Driver::backward(int speed) { drive(speed, Direction::BACKWARD); }
