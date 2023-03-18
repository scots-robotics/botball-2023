#include <iostream>

using namespace std;

float louie_pid();
float albert_pid();

int main()
{
    float controller_output;

    controller_output = louie_pid();
    controller_output = albert_pid();

    return 0;
}

float louie_pid(float kp, float kd, float error, float last_error)
{
    float P, D, Co;
    P = kp * error;
    D = kd * (error - last_error);
    error = last_error;
    Co = P + D;
    return Co;
}

float albert_pid(float kp, float kd, float error, float last_error)
{
    float Co;
    double lastError = 0.0;
    double derivative = error - lastError;
    lastError = error;
    Co = kp * error + kd * derivative;
    return Co;
}