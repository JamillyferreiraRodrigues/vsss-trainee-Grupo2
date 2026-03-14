#include <Arduino.h>
#include <motor.hpp>
#include <comunicacao.hpp>

void setup() {
    Serial.begin(115200);
    motorSetup();
    comunicacaoSetup();
}

void loop() {
    mensagem speeds = getMotorSpeeds();
    controlMotors(speeds.v1, speeds.v2);
}

