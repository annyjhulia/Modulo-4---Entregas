#include <WiFi.h>
#include <PubSubClient.h>

// Configurações de WiFi
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

// Configurações do Adafruit IO
#define AIO_SERVER "io.adafruit.com"
#define AIO_SERVERPORT 1883
#define AIO_USERNAME ""
#define AIO_KEY ""
#define AIO_FEED_RSSI "" // Nome do Feed no Adafruit IO

// Variáveis de controle
long lastMsg = 0;
int value = 0;
const int PUBLISH_INTERVAL_MS = 3000; // Intervalo de publicação (5 segundos)

// Objetos de WiFi e MQTT
WiFiClient espClient;
PubSubClient client(espClient);

// Protótipos de funções
void setup_wifi();
void reconnect();
void callback(char* topic, byte* payload, unsigned int length);
void publish_rssi();

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(AIO_SERVER, AIO_SERVERPORT);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > PUBLISH_INTERVAL_MS) {
    lastMsg = now;
    publish_rssi();
  }
}

// Função para conectar ao WiFi
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

// Função de callback (necessária, mas não usada para este projeto de apenas publicação)
void callback(char* topic, byte* payload, unsigned int length) {
}

// Função para reconectar ao broker MQTT
void reconnect() {
  // Loop até que a conexão seja estabelecida
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    // Tenta conectar
    // O client ID deve ser único para cada dispositivo
    if (client.connect("ESP32Client", AIO_USERNAME, AIO_KEY)) {
      Serial.println("conectado");
      // Se necessário, subscreva a algum tópico aqui
      // client.subscribe("inTopic");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      Serial.println(" Tenta novamente em 5 segundos");
      // Espera 5 segundos antes de tentar novamente
      delay(5000);
    }
  }
}

// Função para ler o RSSI e publicar via MQTT
void publish_rssi() {
  // A função WiFi.RSSI() retorna a potência do sinal em dBm
  long rssi = WiFi.RSSI();
  
  // Converte o valor de RSSI para String
  String rssiString = String(rssi);
  
  Serial.print("RSSI (dBm): ");
  Serial.println(rssiString);

  // Converte a String para char array (necessário para a função publish)
  char message_buff[rssiString.length() + 1];
  rssiString.toCharArray(message_buff, rssiString.length() + 1);

  // Publica o valor no feed do Adafruit IO
  Serial.print("Publicando no feed ");
  Serial.print(AIO_FEED_RSSI);
  Serial.print("...");
  
  if (client.publish(AIO_USERNAME "/feeds/" AIO_FEED_RSSI, message_buff)) {
    Serial.println("Sucesso!");
  } else {
    Serial.println("Falha na publicação.");
  }
}