#ifndef PID_HPP
#define PID_HPP

#include "Robot.hpp"

class Pid
{
private:
    float Kp;
    float Ki;
    float Kd;
    float setpoint;

    float error_sum = 0;
    float error_prev = 0;

    double timer = 0;

public:
    Pid(float Kp, float Ki, float Kd, float setpoint) : Kp(Kp), Ki(Ki), Kd(Kd), setpoint(setpoint) {}
    float getStuuractie(Robot &robot);
};

#endif // PID_HPP