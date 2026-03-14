#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include "comunicacao.hpp"

static mensagem receivedSpeeds = {0, 0};

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
    memcpy(&receivedSpeeds, incomingData, sizeof(receivedSpeeds));
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
    return receivedSpeeds;
}