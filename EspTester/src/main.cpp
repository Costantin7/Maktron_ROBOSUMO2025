#include <Arduino.h>

void setup() {
Serial.begin(9600);
Serial.println("iniciando ESP");
pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
digitalWrite(LED_BUILTIN,HIGH);
Serial.println("LED toggled");
delay(1000);  
digitalWrite(LED_BUILTIN,LOW);
delay(1000);
}

