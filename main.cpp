#include <Arduino.h>
#include <LiquidCrystal.h>

// LCD
#define rs 22
#define en 21
#define d4 19
#define d5 18
#define d6 5
#define d7 23
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Entradas
#define PTCM1 34
#define PTCM2 35
#define BTN1  9
#define BTN2  10

uint8_t cont = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pot1: Pot2: pot3:");

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
}

void loop() {
  int adcValor1 = analogRead(PTCM1);
  int adcValor2 = analogRead(PTCM2);

  float volt = (adcValor2 * 3.3f / 4095.0f);

  // Parte 1
  lcd.setCursor(0, 1);
  lcd.print("    ");               
  lcd.setCursor(0, 1);
  lcd.print(adcValor1);

  // Parte 2
  lcd.setCursor(6, 1);
  lcd.print("    ");               
  lcd.setCursor(6, 1);
  lcd.print(volt, 2);              

  
  if (digitalRead(BTN1) == LOW) {
    cont = cont + 1;   // Incrementar
    delay(200);        
  }

  if (digitalRead(BTN2) == LOW) {
    cont = cont - 1;   // Decrementar
    delay(200);
  }

  // Parte 3: Contador
  lcd.setCursor(12, 1);
  lcd.print("    ");               
  lcd.setCursor(12, 1);
  lcd.print((int)cont);            
}
