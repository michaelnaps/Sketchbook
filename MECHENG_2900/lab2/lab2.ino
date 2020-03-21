// Project: ME 2900 - Lab 2
// Created by: Michael Napoli
// Created on: 3/3/2020
// Last modified on: 3/22/2020

/*
 * Purpose: Main execution file for the programs needed in lab 2
 *  of MECHENG 2900. Postlab functions will also be written here.
 *  
 *  Problem 1:
 *    // where 'val' is the desired brightness
 *    // and is within the boundaries 0-255
 *    digitalWrite(10, val);  // pin 10
*/

// in-lab variables
const int pin_a1 = A1;  // analog pin - INPUT
const int pin_pwm = 6;  // pulse width modulating pin - OUTPUT
int val = 0;  // also used for Problem 3

// Problem 3 variables
const int DIST_SENSOR = A0;  // analog pin
const int greenLED = 3;
const int yellowLED = 5;
const int redLED = 10;

// Problem 3 functions used: dist_lights() and blink_LED()

void setup() {
  // in-lab
  pinMode(pin_a1, INPUT);
  pinMode(pin_pwm, OUTPUT);

  // Problem 3;
  pinMode(DIST_SENSOR, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  val = analogRead(DIST_SENSOR);
  val = map(val, 0, 255, 0, 20);  // change bounds to that of the distance units (meters)
  
  // for debugging
  Serial.println(val);
  
  dist_lights(val, 100);
}

/* loop used during lab period
void loop() {
  // read value from potentiometer and map to 0-255 range
  val = analogRead(pin_a1);
  val = map(val, 0, 1023, 0, 255);  // convert to proper range
  
  // write potentiometer value to LED brightness
  analogWrite(pin_pwm, val);
}
*/
