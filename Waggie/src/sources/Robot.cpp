#include "../headers/Robot.hpp"

string Robot::getName() const { return name; }

vector<Driver> Robot::getDrivers() const { return drivers; }

void Robot::forward(int speed) {
  this->say("Let's goooo!");
  for (Driver driver : drivers) {
    driver.forward(speed);
  }
}

void Robot::backward(int speed) {
  this->say("Initiating moonwalk! <beep> <boop>");
  for (Driver driver : drivers) {
    driver.backward(speed);
  }
}

void Robot::say(string message) {
  std::cout << "" << this->getName() << ": " << message << std::endl;
}