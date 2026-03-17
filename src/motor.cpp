
#include <Arduino.h>
#include "motor.hpp"

//Definição dos pinos para controle dos motores
void motorSetup() {
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(STBY, OUTPUT);
}

//Função para controlar os motores com base nas velocidades recebidas
void controlMotors(int left, int right) {

    //Definir limites para as velocidades dos motores para evitar valores fora do intervalo permitido
    if (left > 255) left = 255;
    if (left < -255) left = -255;
    if (right > 255) right = 255;
    if (right < -255) right = -255;

    //Ativar o modo de controle dos motores ligando o pino de standby
    digitalWrite(STBY, HIGH);

    //Configurar a direção dos motores com base no sinal de velocidade
    if (left > 0) {
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);
    } else if (left < 0) {
        left = -left;
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
    } else {
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, LOW);
    }

    if (right > 0) {
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
    } else if (right < 0) {
        right = -right;
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
    } else {
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, LOW);
    }

    //Controlar a velocidade dos motores usando PWM
    analogWrite(PWMB, left);
    analogWrite(PWMA, right);
}

//Função para parar os motores desligando o pino de standby
void stop() {
    digitalWrite(STBY, LOW);
}