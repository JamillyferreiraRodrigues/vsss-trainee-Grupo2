#ifndef COMUNICACAO_HPP
#define COMUNICACAO_HPP

struct mensagem {
    int v1;
    int v2;
};

void comunicacaoSetup();
mensagem getMotorSpeeds();

#endif