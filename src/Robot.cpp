#include "Robot.hpp"

String Robot::getName() const { return this->name; }

void Robot::forward(int speed) {
  driver_a.forward(speed);
}

void Robot::backward(int speed) {
  driver_a.backward(speed);
}

double Robot::getAngle() {
  static double prevAngle = 0;
  Vector accel = pos_sensor.burstRead(0x3b, 6, accel_sample_rate);
  Vector gyro = pos_sensor.burstRead(0x43, 6, gyro_sensitivity);
  double elapsedTimeInSeconds = pos_sensor.getElapsedSeconds();
  pos_sensor.markTime();

  auto accAngle = atan2(accel.getX(), accel.getY()) * RAD_TO_DEG; // tilt angle
  auto gyroAngle = gyro.getZ() * elapsedTimeInSeconds; // angle change
  auto currentAngle =
      0.95 * (prevAngle + gyroAngle) + 0.05 * accAngle; // complementary filter
  prevAngle = currentAngle;
  return currentAngle;
}
