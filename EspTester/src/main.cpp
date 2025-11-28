#include <Arduino.h>


// DIGITAL PINS 
#define COR_ESQUERDA 34
#define COR_DIREITA 35
#define COR_ATRAS 12

#define OBS_FRENTE_ESQUERDA 25
#define OBS_FRENTE_DIREITA 22
#define OBS_LADO_ESQUERDA 26
#define OBS_LADO_DIREITA 14

#define LOGICAL_ENTRY 13
#define BUZZER 27

#define MOTOR_A1 21
#define MOTOR_A2 19

#define MOTOR_B1 18
#define MOTOR_B2 5 
// não usar pwm no pino 5


// Functions to control motors

void MotorActivate(char motor, int direction, int speed, int time){
  // motor: 'A' or 'B'
  // direction: 0 = stop, 1 = forward, 2 = backward;
  // speed: 0-255 PWM value

  if(motor == 'A'){
    if(direction == 1){
      Serial.println("Motor A Frente");
      analogWrite(MOTOR_A1, speed);
      digitalWrite(MOTOR_A2, LOW);
      delay(time);
      digitalWrite(MOTOR_A1, LOW);
      digitalWrite(MOTOR_A2, LOW);
    }
    if(direction == 2){
      Serial.println("Motor A Tras");
      analogWrite(MOTOR_A2, speed);
      digitalWrite(MOTOR_A1, LOW);
      delay(time);
      digitalWrite(MOTOR_A1, LOW);
      digitalWrite(MOTOR_A2, LOW);
    }
    if(direction == 0){
      digitalWrite(MOTOR_A1, LOW);
      digitalWrite(MOTOR_A2, LOW);
    }
  }
  if(motor == 'B'){
    if(direction == 1){
      Serial.println("Motor B Frente");
      analogWrite(MOTOR_B1, speed);
      digitalWrite(MOTOR_B2, LOW);
      delay(time);
      digitalWrite(MOTOR_B1, LOW);
      digitalWrite(MOTOR_B2, LOW);
    }
    if(direction == 2){
      Serial.println("Motor B Tras");
      digitalWrite(MOTOR_B2, HIGH);
      digitalWrite(MOTOR_B1, LOW);
      delay(time);
      digitalWrite(MOTOR_B1, LOW);
      digitalWrite(MOTOR_B2, LOW);
    }
    if(direction == 0){
      digitalWrite(MOTOR_B1, LOW);
      digitalWrite(MOTOR_B2, LOW);
    }
  }


}


void setup() {
Serial.begin(9600);
Serial.println("iniciando ESP");
pinMode(LED_BUILTIN,OUTPUT);
pinMode(BUZZER,OUTPUT);
pinMode(COR_ESQUERDA,INPUT);
pinMode(COR_DIREITA,INPUT);
pinMode(COR_ATRAS,INPUT);
pinMode(OBS_FRENTE_ESQUERDA,INPUT);
pinMode(OBS_FRENTE_DIREITA,INPUT);
pinMode(OBS_LADO_ESQUERDA,INPUT);
pinMode(OBS_LADO_DIREITA,INPUT);
pinMode(LOGICAL_ENTRY,INPUT);
pinMode(MOTOR_A1,OUTPUT);
pinMode(MOTOR_A2,OUTPUT);
pinMode(MOTOR_B1,OUTPUT);
pinMode(MOTOR_B2,OUTPUT);
digitalWrite(BUZZER, HIGH);

}

void loop() {

}