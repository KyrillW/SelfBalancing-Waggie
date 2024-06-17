#include "Robot.hpp"

String Robot::getName() const { return this->name; }

void Robot::forward(int speed) {
  this->say("Let's goooo!");
  driver_a.forward(speed);
}

void Robot::backward(int speed) {
  this->say("Initiating moonwalk! <beep> <boop>");
  driver_a.backward(speed);
}

void Robot::say(const String &message) {
  Serial.print(this->getName() + ": " + message + "\n");
}
