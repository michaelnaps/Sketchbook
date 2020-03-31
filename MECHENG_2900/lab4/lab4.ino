// Project: ME 2900 - Lab 4
// Created by: Michael Napoli
// Created on: 3/31/2020

/*
 *  Purpose: For the execution of appropriate processes in Lab 4.
 *  Activity 2 was chosen for the first part of the following lab.
*/

// potentiometer and button pins
const int POT = A1;  // analog
const int BUTTON = 8;  // digital

// LED and motor pins
const int led = 5;  // pwm

// DC motor pins
const int EN = 6;
const int MC1 = 3;
const int MC2 = 2;

// value to write to the LED/motor
int val = 0;  // intialize to 0 - arbitrary

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(led, OUTPUT);
  
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
    digitalWrite(led, LOW);  // in case the led was just on
    val = map(analogRead(POT), 0, 1023, 0, 255);
    forward(val);
    Serial.println(val);
  }  
  else {
    brake();  // in case the motor was just running
    val = map(analogRead(POT), 0, 1023, 0, 255);
    analogWrite(led, val);
    Serial.println(val);
  }
}
