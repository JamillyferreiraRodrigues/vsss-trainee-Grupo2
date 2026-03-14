# ESP32 Robot Motor Control (ESP-NOW)

Firmware para controle de motores usando **ESP32** e comunicação **ESP-NOW**.

O dispositivo recebe comandos de velocidade para dois motores (esquerdo e direito) e controla a movimentação de um robô diferencial.

## Funcionamento

O ESP32 recebe uma mensagem contendo duas velocidades:

* `v1` → velocidade do motor esquerdo
* `v2` → velocidade do motor direito

Esses valores são enviados via **ESP-NOW** e utilizados para controlar os motores em tempo real.

Fluxo do sistema:

Controle remoto → ESP-NOW → ESP32 → controle dos motores

## Lógica de Movimento

O robô utiliza dois motores independentes.

| v1                 | v2                 | Movimento            |
| ------------------ | ------------------ | -------------------- |
| positivo           | positivo           | frente               |
| negativo           | negativo           | trás                 |
| valores diferentes | valores diferentes | curva                |
| sinais opostos     | sinais opostos     | gira no próprio eixo |

### Exemplos

```
v1 = 100, v2 = 100   → frente
v1 = -100, v2 = -100 → trás
v1 = 50, v2 = 100    → curva
v1 = 100, v2 = -100  → giro
```

## Estrutura do Projeto

```
src/
 ├─ main.cpp            → loop principal
 ├─ motor.cpp           → implementação do controle de motores
 ├─ motor.hpp
 ├─ comunicacao.cpp     → comunicação ESP-NOW
 ├─ comunicacao.hpp
 └─ pino.hpp            → definição dos pinos
```

## Hardware alvo

* ESP32-S2
* Driver de motor (ex: TB6612FNG ou L298N)
* Dois motores DC

## Build

O projeto utiliza **PlatformIO**.

Para compilar:

```
pio run
```

## Observação

Projeto desenvolvido para estudo de **sistemas embarcados**, **controle de motores** e **comunicação ESP-NOW**.

