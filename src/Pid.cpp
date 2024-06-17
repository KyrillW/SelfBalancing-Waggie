#include "Pid.hpp"

float Pid::getStuuractie(Robot &robot)
{
    static float error_sum = 0;
    static float error_prev = 0;

    float error = setpoint - robot.getAngle();
    double dt = robot.pos_sensor.getElapsedSeconds();
    error_sum += error * dt;
    float error_div = error - error_prev;
    float stuuractie = Kp * error + Ki * error_sum + Kd * error_div;
    error_prev = error;
    return stuuractie;
}