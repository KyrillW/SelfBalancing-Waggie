#include "Driver.hpp"
#include "Gyro.hpp"
#include "Motor.hpp"
#include "Robot.hpp"
#include "utils/Vector.hpp"
#include <Arduino.h>

Robot *robot;
void setup() {
  Serial.begin(9600);

  // Create motors
  Driver driver1(Motor(10, 5), Motor(6, 9));


  PosSensor gyro();
  robot = new Robot("BB-8", driver1, gyro);

  // Robot initialization messages
  robot->say("BRRT BRRT! I am online! BRRT BRRT!");
  robot->say("I currently have " + String(1) + " motor drivers!");
}

void loop() {

  robot->say("My gyro tells me the position is ( pitch: " +
             String(gyroPos.getPitch()) +
             ", roll: " + String(gyroPos.getRoll()) +
             ", yaw: " + String(gyroPos.getYaw()) + ")");
  robot->forward(30);
  delay(2000);
  robot->backward(255);
  delay(2000);
}
