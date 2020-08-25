// Project: mapRoom
// Created by: Michael Napoli
// Created on: 8/21/2020

/*
 * Purpose: Program for a room mapping prototype which utilizes an
 *  ultrasonic distance sensor and stepper motor to measure the dimensions
 *  of a given room.
*/

/*
 * NOTE: Nema-17 wire configuration
 *       1A - red
 *       1B - yellow
 *       2A - grey
 *       2B - green
*/

#include "ardu_polarcoordinate.h"
using namespace napoli;

const int DIR(4);
const int STEP(5);

const int TRIG(7);
const int ECHO(8);

PolarCoordinate loc('d', 0, 0);

void setup() {
  // stepper motor pins
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);

  // distance sensor pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
  delay(8000);  // short pause for setup
}

void loop() {
  loc.setTheta('d', 0);
  
  // one rotation
  for (int i(0); i < 101; ++i) {
    if (i % 10 != 0) {
      loc.setTheta('d', (i * 1.8));
      loc.setRadius(distance(TRIG, ECHO));
      Serial.print(loc.getTheta());
      Serial.print(", ");
      Serial.println(loc.getRadius());

      clockwise(DIR, STEP);
    }
  }

  delay(500);  // short pause

  digitalWrite(DIR, HIGH);  // counter-clockwise

  // one rotation (reset location)
  for (int i(0); i <= 101; ++i) {    
    counter_clockwise(DIR, STEP);
  }

  delay(10000);
}
