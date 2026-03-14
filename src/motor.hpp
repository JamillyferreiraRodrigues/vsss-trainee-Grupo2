#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "pino.hpp"

void motorSetup();
void controlMotors(int left, int right);
void stop();

#endif