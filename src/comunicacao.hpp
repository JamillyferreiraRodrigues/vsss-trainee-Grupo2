#ifndef COMUNICACAO_HPP
#define COMUNICACAO_HPP

struct mensagem {
    int v1;
    int v2;
    uint8_t checksum;
};

void comunicacaoSetup();
mensagem getMotorSpeeds();

#endif