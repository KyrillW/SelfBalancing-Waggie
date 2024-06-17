#include "headers/Driver.hpp"
#include "headers/Motor.hpp"
#include <Arduino.h>
#include <vector>

using std::vector;
const Robot robot;
void setup() {
  const Motor motor1(3, 5); // selected some random pwm pins
  const Motor motor2(6, 9);
  const driver = Driver({motor1, motor2});
  robot = Robot("BB-8", driver);

  robot.say("BRRT BRRT! I am online! BRRT BRRT!");
  robot.say("I currently have " + robot.getDrivers.size() + " motor drivers!");
}

void loop() {
  robot.forward();
  delay(2000);
  robot.backward();
  delay(2000);
}
