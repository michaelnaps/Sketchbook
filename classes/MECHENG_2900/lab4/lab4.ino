// Project: ME 2900 - Lab 4
// Created by: Michael Napoli
// Created on: 3/31/2020

/*
 *  Purpose: For the execution of appropriate processes in Lab 4.
 *  Activity 2 was chosen for the first part of the following lab project.
*/

/*
// potentiometer and button pins
const int POT = A1;  // analog
const int BUTTON = 8;  // digital

// LED and motor pins
const int LED = 5;  // pwm

// DC motor pins
const int EN = 6;
const int MC1 = 3;
const int MC2 = 2;

// value to write to the LED/motor
int val = 0;  // intialize to 0 - arbitrary

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  
  // H-bridge
  pinMode(EN, OUTPUT);
  pinMode(MC1, OUTPUT);
  pinMode(MC2, OUTPUT);
  
  // begin serial monitor
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(BUTTON) == HIGH) {
    digitalWrite(LED, LOW);  // in case the led was just HIGH
    val = map(analogRead(POT), 0, 1023, 0, 255);
    forward(val);
    Serial.println(val);
  }  
  else {
    brake();  // in case the motor was just running
    val = map(analogRead(POT), 0, 1023, 0, 255);
    analogWrite(LED, val);
    Serial.println(val);
  }
}
*/

/*
// CHANGING SPEEDS PROGRAM
const int buttonGas = 5;
const int buttonBrake = 2;
const int ledPin = 9;

int delayTime = 500;
long lastTime = 0;
int ledState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonGas, INPUT);
  pinMode(buttonBrake, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonGas) == HIGH){
    delayTime -= 5;
  }
  else if(digitalRead(buttonBrake) == HIGH){
    // was initially written as:
    // delayTime = delayTime -5;
    // this is wrong because the "-5" would be read as a negative 5
    delayTime += 5;
  }
  delayTime = constrain(delayTime, 10, 5000);
  if((lastTime + delayTime) < millis()){
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    lastTime = millis();
  }
  delay(10);
}
*/

// RGB PROGRAM
const int redPot = A0;
const int greenPot = A1;
const int bluePot = A2;
const int ledR = 7;
const int ledG = 10;
const int ledB = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue;
  int ledValue;
  
  potValue = analogRead(redPot);
  ledValue = map(potValue, 0, 1023, 0, 255);  // wrong range - was initially (val, 0, 255, 0, 1023)
  analogWrite(ledR, ledValue);
  
  potValue = analogRead(greenPot);
  ledValue = map(potValue, 0, 1023, 0, 255);  // wrong range - was initially (val, 0, 255, 0, 1023)
  analogWrite(ledG, ledValue);
  
  potValue = analogRead(bluePot);
  ledValue = map(potValue, 0, 1023, 0, 255);  // wrong range - was initially (val, 0, 255, 0, 1023)
  analogWrite(ledB, ledValue);
}
