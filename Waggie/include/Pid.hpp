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

public:
    Pid(float Kp, float Ki, float Kd, float setpoint) : robot(robot), Kp(Kp), Ki(Ki), Kd(Kd), setpoint(setpoint) {}
    float getStuuractie(const Robot &robot);
}

#endif // PID_HPP