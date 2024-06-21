#include "Driver.hpp"
#include "Motor.hpp"
#include "Pid.hpp"
#include "PosSensor.hpp"
#include "Robot.hpp"
#include "utils/Vector.hpp"
#include <Arduino.h>

Robot *robot;
Pid *pid;
void setup() {
  Serial.begin(9600);

  // Create motors
  Driver driver1(Motor(10, 5), Motor(6, 9));

  PosSensor gyro1 = PosSensor();
  robot = new Robot("BB-8", driver1, gyro1);

  // pid = new Pid(7.5, 30.0, 0.15, -2.6); // zet pid waardes //EZ GAME
  pid = new Pid(7.5, 37.5, 0.15, -2.4); // Beste waardes
  // pid = new Pid(7.5, 40.0, 0.15, -2.4);
}

void loop() {
  float stuuractie = pid->getStuuractie(*robot);

  if (stuuractie > 0) {
    robot->forward(stuuractie);
  } else {
    stuuractie *= -1;
    robot->backward(stuuractie);
  }
  
  delay(15);
}
