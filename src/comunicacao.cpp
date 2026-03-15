#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include "comunicacao.hpp"

static volatile mensagem receivedSpeeds =  {0, 0, 0};

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {

    if (len != sizeof(mensagem)) {
        Serial.println("Erro: tamanho de mensagem incorreto");
        return;
    }

    mensagem temp;
    memcpy(&temp, incomingData, sizeof(temp));

    uint8_t checksumCalculado = temp.v1 + temp.v2;

    if (temp.checksum != checksumCalculado) {
        Serial.println("Erro: checksum inválido");
        return;
    }

   
    memcpy((void*)&receivedSpeeds, &temp, sizeof(temp));
}

void comunicacaoSetup() {

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK) {
        Serial.println("Erro ao iniciar ESP-NOW");
        return;
    }

    esp_now_register_recv_cb(OnDataRecv);
}

mensagem getMotorSpeeds() {
    mensagem temp;

    temp.v1 = receivedSpeeds.v1;
    temp.v2 = receivedSpeeds.v2;
    temp.checksum = receivedSpeeds.checksum;
    return temp;
}