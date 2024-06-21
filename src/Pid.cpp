#include "Pid.hpp"

float Pid::getStuuractie(Robot &robot)
{
    double elapsedTimeInSeconds = ((double)(micros() - timer)/1000000);
    timer = micros();

    double angle = robot.getAngle();

    float error = angle - setpoint;

    error_sum += error * elapsedTimeInSeconds;

    float error_div = (error - error_prev) / elapsedTimeInSeconds;
    float stuuractie = round(Kp * error + Ki * error_sum + Kd * error_div);
    error_prev = error;

    return stuuractie;
}