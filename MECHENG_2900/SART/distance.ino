// Function: distance()
// Created by: Michael Napoli
// Created on: 4/9/2020

/*
  Purpose: Function to return the distance from a given ultrasonic
    distance sensor (UDS).
  input:
    'trigPin' - pin number for UDS trigger pin - output
    'echoPin' - pin number for UDS echo pin - input
  output:
    - distance from UDS - type float
*/

float distance(const int trigPin, const int echoPin) {
  float change_t(0);
  const int SOUND(343);  // in cm/s

  // clear trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // set pin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  change_t = pulseIn(echoPin, HIGH);  // returns length of pulse in microseconds
  digitalWrite(echoPin, LOW);  // set echo pin to LOW

  return ((change_t * 0.0343) / 2);
}
