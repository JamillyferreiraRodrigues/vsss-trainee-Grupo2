#ifndef MOTOR_HPP
#define MOTOR_HPP
//Include guard para evitar múltiplas inclusões do cabeçalho

//Pinagem para controle dos motores
#include "pino.hpp"

void motorSetup(); // Função para inicializar o controle dos motores
void controlMotors(int left, int right); // Função para controlar os motores
void stop(); // Função para parar os motores

#endif