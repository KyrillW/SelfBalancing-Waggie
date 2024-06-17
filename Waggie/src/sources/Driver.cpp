#include "../headers/Driver.hpp"

void Driver::drive(int speed, Direction direction) {
  if (speed > 255) {
    std::cerr << "Error in Driver::drive(): Speed must be <= 255!\n";
    return;
  }

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