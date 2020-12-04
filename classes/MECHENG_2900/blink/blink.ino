// File: blink()
// Created by: Michael Napoli
// Created on: 2/25/2020

/*
 * Lecture 1
 * Purpose: Blink an LED light in differing time intervals.
*/

int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(150);
  digitalWrite(ledPin, LOW);
  delay(150);
}
