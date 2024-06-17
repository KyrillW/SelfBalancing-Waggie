#include "Robot.hpp"

String Robot::getName() const { return this->name; }

void Robot::forward(int speed)
{
  this->say("Let's goooo!");
  driver_a.forward(speed);
}

void Robot::backward(int speed)
{
  this->say("Initiating moonwalk! <beep> <boop>");
  driver_a.backward(speed);
}

void Robot::say(const String &message)
{
  Serial.print(this->getName() + ": " + message + "\n");
}

double Robot::getAngle()
{
  Vector accel = pos_sensor.readAccel();
  Vector gyro = pos_sensor.readGyro();
  double elapsedTimeInSeconds = pos_sensor.getElapsedSeconds();
  pos_sensor.markTime();

  // might need to find individual gyro offset using a program
  auto accAngle = atan2(accel.getY(), accel.getZ()) * RAD_TO_DEG;      // tilt angle
  auto gyroAngle = gyro.getX() * elapsedTimeInSeconds;                 // angle change
  auto currentAngle = 0.95 * (prevAngle + gyroRotX) + 0.05 * accAngle; // complementary filter
  return currentAngle;
}
