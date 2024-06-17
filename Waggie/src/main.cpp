#include "Driver.hpp"
#include "Gyro.hpp"
#include "Motor.hpp"
#include "Robot.hpp"
#include "utils/Vector.hpp"
#include <Arduino.h>

Robot *robot;
Gyro *gyro;
void setup() {
  Serial.begin(9600);

  // Create motors
  Driver driver1(Motor(10, 5), Motor(6, 9));

  robot = new Robot("BB-8", driver1);

  gyro = new Gyro();

  // Robot initialization messages
  robot->say("BRRT BRRT! I am online! BRRT BRRT!");
  robot->say("I currently have " + String(1) + " motor drivers!");
}

void loop() {
  Vector gyroPos = gyro->read();

  robot->say("My gyro tells me the position is (" + String(gyroPos.getX()) +
             ", " + String(gyroPos.getY()) + ", " + String(gyroPos.getZ()) +
             ")");
  robot->forward(30);
  delay(2000);
  robot->backward(255);
  delay(2000);
}
