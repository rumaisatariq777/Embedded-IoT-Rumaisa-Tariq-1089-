#include <Arduino.h>

#define LED_BUILTIN 21

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN,HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(3000);
}
