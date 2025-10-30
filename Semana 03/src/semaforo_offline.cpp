#include <LiquidCrystal_I2C.h> // Biblioteca para display LCD

// Pinos dos LEDs do semáforo
const int ledVermelho = 16;
const int ledAmarelo  = 17;
const int ledVerde    = 5;

// Tempos de cada fase em segundos
const int tempoVermelho = 6;
const int tempoVerde    = 4;
const int tempoAmarelo  = 2;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
  // Inicializa o LCD
  lcd.init();
  lcd.backlight();
  
  // Mensagem inicial
  lcd.clear();
  lcd.print("Semaforo Offline");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  delay(2000);
}

// Gerencia uma fase do semáforo
// - ledPin: ponteiro para o pino do LED ativo
// - nomeCor: ponteiro para o texto exibido no LCD
// - duracaoSegundos: ponteiro para o tempo de duração
void gerenciarFase(const int* ledPin, const char* nomeCor, const int* duracaoSegundos) {

  // Liga apenas o LED correspondente e desliga os outros
  digitalWrite(ledVermelho, (*ledPin == ledVermelho) ? HIGH : LOW);
  digitalWrite(ledAmarelo,  (*ledPin == ledAmarelo)  ? HIGH : LOW);
  digitalWrite(ledVerde,    (*ledPin == ledVerde)    ? HIGH : LOW);
  
  // Atualiza cabeçalho do LCD 
  lcd.clear();
  lcd.print("Fase: ");
  lcd.print(nomeCor);
  
  // Contagem regressiva do LCD
  for (int i = *duracaoSegundos; i > 0; i--) {
    lcd.setCursor(0, 1); 
    lcd.print("Resta: ");
    
    if (i < 10) {
      lcd.print(" ");
    }
    
    lcd.print(i);
    lcd.print("s ");
    
    delay(1000);
  }
}

void loop() {
  const int* pVerde    = &ledVerde;
  const int* pAmarelo  = &ledAmarelo;
  const int* pVermelho = &ledVermelho;
  
  const int* tVerde    = &tempoVerde;
  const int* tAmarelo  = &tempoAmarelo;
  const int* tVermelho = &tempoVermelho;

  // Loop de funcionamento do semáforo
  gerenciarFase(pVerde,    "VERDE",    tVerde);
  gerenciarFase(pAmarelo,  "AMARELO",  tAmarelo);
  gerenciarFase(pVermelho, "VERMELHO", tVermelho);
}
