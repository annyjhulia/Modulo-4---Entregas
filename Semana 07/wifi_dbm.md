# Relatório de ponderada em sala: dBm de sinal WiFi

Este projeto teve como objetivo desenvolver um sistema de Internet das Coisas (IoT) para monitorar a potência do sinal WiFi (RSSI, em dBm) utilizando um microcontrolador ESP32 e publicar os dados em tempo real em uma plataforma online via protocolo MQTT. O projeto culminou na configuração de um dashboard para visualização contínua dos dados e na realização de um teste prático para simular o efeito da **Gaiola de Faraday** em um ambiente real.

## Materiais e tecnologias

| Componente | Descrição |
| :--- | :--- |
| Microcontrolador | ESP32 (qualquer modelo com WiFi) |
| Ambiente de Desenvolvimento | Arduino IDE |
| Linguagem de Programação | C++ |
| Protocolo de Comunicação | MQTT |
| Plataforma IoT/Broker | Adafruit IO |
| Biblioteca MQTT | PubSubClient |

## Montagem

## Código
O código realiza as seguintes etapas:

1.  Conexão à rede WiFi.
2.  Conexão ao broker MQTT do Adafruit IO, utilizando as credenciais de usuário e chave.
3.  Medição contínua do RSSI (Received Signal Strength Indicator) em dBm através da função `WiFi.RSSI()`.
4.  Publicação do valor de RSSI no *Feed* \`rssi-dbm\` do Adafruit IO a cada 3 segundos.

O código utilizado pode ser encontrado aqui: [wifi_dmb.ino](../Semana%2007/src/wifi_dbm.ino)

## Análise dos resultados

No Adafruit IO, foi configurado um **Dashboard** contendo um **Gráfico de Linha (Line Chart)**, que se subscreve ao *Feed* \`rssi-dbm\`. Este gráfico permite a visualização da potência do sinal WiFi em função do tempo (Tempo x dBm).

### 1. Sala de aula

### 2. Recepção

### 3. IT Bar

### 4. Elevador

**Análise Teórica da Gaiola de Faraday:**
Um elevador, por ser uma estrutura metálica fechada, atua como uma Gaiola de Faraday. Esta gaiola é um invólucro condutor que bloqueia campos eletromagnéticos externos. As ondas de rádio (como o WiFi) são formas de radiação eletromagnética. Ao entrar no elevador, o campo eletromagnético do sinal WiFi é drasticamente atenuado pela blindagem metálica.

### 5. Laboratório

### 6. Mezanino 2

### 7. Fora do elevador

### 8. Antigo lago - Quadra de areia

## <b>Link para vídeo da experiência e seu funcionamento:</b> <a href="https://drive.google.com/file/d/1FZeIaP0kcxcx5eXeaSzJgK7f558d-fsS/view?usp=drive_link">Acesse o vídeo demonstrativo</a>
