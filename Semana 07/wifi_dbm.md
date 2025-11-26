# Relatório de ponderada em sala: dBm de sinal WiFi

## Anny Cerazi e Eduardo Casarini - T17

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

A montagem do projeto foi simples, envolvendo apenas conectar o ESP32 ao computador como fonte de energia e conectar a antena ao microcontrolador.

## Código

O código realiza as seguintes etapas:

1.  Conexão à rede WiFi.
2.  Conexão ao broker MQTT do Adafruit IO, utilizando as credenciais de usuário e chave.
3.  Medição contínua do RSSI (Received Signal Strength Indicator) em dBm através da função `WiFi.RSSI()`.
4.  Publicação do valor de RSSI no *Feed* \`rssi-dbm\` do Adafruit IO a cada 3 segundos.

O código utilizado pode ser encontrado aqui: [wifi_dmb.ino](../Semana%2007/src/wifi_dbm.ino)

## Análise dos resultados

No Adafruit IO, foi configurado um Dashboard contendo um **Gráfico de Linha (Line Chart)**, que se subscreve ao Feed "rssi-dbm". Este gráfico permite a visualização da potência do sinal WiFi em função do tempo (Tempo x dBm).

### 1. Sala de aula

Na sala de aula, a potência medida obteve uma variação entre -74 e -53 dBm, indicando uma qualidade de sinal entre aceitável e boa.

### 2. Recepção

Na recepção, a potência medida obteve uma variação entre -70 e -65 dBm, indicando uma qualidade de sinal aceitável.

### 3. IT Bar

No IT Bar, a potência medida obteve uma variação entre -75 e -61 dBm, indicando uma qualidade de sinal aceitável.

### 4. Elevador

Dentro do elevador parado, o sinal de recepção era baixo e de pouca qualidade, porém, enquanto este estava em movimento, se tornou uma Gaiola de Faraday, interrompendo a sua recepção de sinal.

**Análise Teórica da Gaiola de Faraday:**
Um elevador, por ser uma estrutura metálica fechada, atua como uma Gaiola de Faraday. Esta gaiola é um invólucro condutor que bloqueia campos eletromagnéticos externos. As ondas de rádio (como o WiFi) são formas de radiação eletromagnética. Ao entrar no elevador, o campo eletromagnético do sinal WiFi é drasticamente atenuado pela blindagem metálica.

### 5. Laboratório

No laboratório, a potência medida obteve uma variação entre -67 e -56 dBm, indicando uma qualidade de sinal entre aceitável e boa.

### 6. Mezanino 2

No final do mezanino, a potência medida obteve uma variação entre -57 e -52 dBm, indicando uma qualidade de sinal boa.

### 7. Fora do elevador

Fora do elevador, a potência medida obteve uma variação entre -80 e -68 dBm, indicando uma qualidade de sinal fraca.

### 8. Antigo lago - Quadra de areia

Na quadra de areia, a potência medida obteve uma variação entre -84 e -72 dBm, indicando uma qualidade de sinal fraca.

## Gráfico gerado 

<div align="center">
<p align="center">
<img src="assets/grafico_final.png"></a>
</p>
</div>

Os resultados obtidos em formato CSV podem ser ecnontrados aqui: [rssi-dbm.csv](../Semana%2007/src/rssi-dbm.csv)

## <b>Link para vídeo da experiência e seu funcionamento:</b> <a href="https://drive.google.com/file/d/1FZeIaP0kcxcx5eXeaSzJgK7f558d-fsS/view?usp=drive_link">Acesse o vídeo demonstrativo</a>
