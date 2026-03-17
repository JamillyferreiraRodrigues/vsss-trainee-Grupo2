#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include "comunicacao.hpp"
/* Bibliotecas arduino, ESP-NOW, Wi-fi para realização de operações e
Estrutura de comunicação.*/

//Variável global para armazenar a última mensagem recebida
static volatile mensagem receivedSpeeds =  {0, 0, 0};

//Função de callback para receber dados via ESP-NOW
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {

    //Verificar se o tamanho da mensagem recebida é o esperado
    if (len != sizeof(mensagem)) {
        Serial.println("Erro: tamanho de mensagem incorreto");
        return;
    }

    //Copiar os dados recebidos para uma estrutura temporária para processamento
    mensagem temp;
    memcpy(&temp, incomingData, sizeof(temp));

    uint8_t checksumCalculado = temp.v1 + temp.v2;

    //Verificar se o checksum calculado corresponde ao checksum recebido
    if (temp.checksum != checksumCalculado) {
        Serial.println("Erro: checksum inválido");
        return;
    }

   //Se o checksum for válido, atualizar a variável global com os novos valores de velocidade
    memcpy((void*)&receivedSpeeds, &temp, sizeof(temp));
}

//Função de configuração para inicializar o ESP-NOW e configurar o modo Wi-Fi
void comunicacaoSetup() {

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK) {
        Serial.println("Erro ao iniciar ESP-NOW");
        return;
    }

    //Registrar a função de callback para receber dados via ESP-NOW
    esp_now_register_recv_cb(OnDataRecv);
}

//Função para obter as velocidades dos motores a partir da variável global
mensagem getMotorSpeeds() {
    mensagem temp;

    temp.v1 = receivedSpeeds.v1; 
    temp.v2 = receivedSpeeds.v2;
    temp.checksum = receivedSpeeds.checksum;
    return temp;
}