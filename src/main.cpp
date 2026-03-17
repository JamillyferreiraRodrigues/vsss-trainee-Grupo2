
#include <Arduino.h>
#include <motor.hpp>
#include <comunicacao.hpp>

//Bibliotecas para controle dos motores e comunicação via ESP-NOW
void setup() {
    Serial.begin(115200);
    motorSetup();
    comunicacaoSetup();
}

//Loop principal para ler as velocidades dos motores e controlá-los
void loop() {
    mensagem speeds = getMotorSpeeds();
    controlMotors(speeds.v1, speeds.v2);
}

