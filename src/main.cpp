#include "Driver.hpp"
#include "Gyro.hpp"
#include "Motor.hpp"
#include "Robot.hpp"
#include "Pid.hpp"
#include "utils/Vector.hpp"
#include <Arduino.h>

Robot *robot;
Pid *pid;
void setup()
{
  Serial.begin(9600);

  // Create motors
  Driver driver1(Motor(10, 5), Motor(6, 9));

  PosSensor gyro();
  robot = new Robot("BB-8", driver1, gyro);

  // Robot initialization messages
  robot->say("BRRT BRRT! I am online! BRRT BRRT!");
  robot->say("I currently have " + String(1) + " motor drivers!");

  auto rot = robot->getAngle();
  robot->say("I am currently at " + rot + " deg rotation!");

  // pid = new Pid(1, 0, 0); zet pid waardes
}

void loop()
{
  float stuuractie = pid->getStuuractie(*robot);

  if (struuractie > 0)
  {
    robot->forward(100);
  }
  else
  {
    robot->backward(100);
  }
  delay(50);
}
