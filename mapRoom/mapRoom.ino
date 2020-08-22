// Project: mapRoom
// Created by: Michael Napoli
// Created on: 8/21/2020

/*
 * Purpose:
*/

/*
 * NOTE: Nema-17 wire configuration
 * 1A - red
 * 1B - yellow
 * 2A - grey
 * 2B - green
*/

const int DIR(4);
const int STEP(5);

const int TRIG(7);
const int ECHO(8);

int ang(0);  // initialize to 0
float dist(0);  // initialize to 0

void setup() {
  // stepper motor pins
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);

  // distance sensor pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(DIR, HIGH);
  
  for (int i(0); i < 200; ++i) {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP, LOW);
    delayMicroseconds(500);
  }

  delay(1000);

  digitalWrite(DIR, LOW);
  
  for (int i(0); i < 400; ++i) {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP, LOW);
    delayMicroseconds(500);
  }

  delay(1000);
}
