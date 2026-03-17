#ifndef COMUNICACAO_HPP
#define COMUNICACAO_HPP
//Include guard para evitar múltiplas inclusões do cabeçalho

struct mensagem {
    int v1; //Velocidade do motor 1
    int v2; //Velocidade do motor 2
    uint8_t checksum;
};

//Funções para inicializar a comunicação e obter as velocidades dos motores
void comunicacaoSetup();
mensagem getMotorSpeeds();

#endif