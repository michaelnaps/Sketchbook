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
    - distance from UDS - type float - unit centimeters
*/

float distance(const int trigPin, const int echoPin) {
  float change_t(0);  // change in time variable
  const int SOUND(343);  // in cm/s

  // turn trig pin off
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // set trigger pin HIGH for 10 microseconds to send sound pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // returns length of pulse in microseconds
  change_t = pulseIn(echoPin, HIGH);
  
  // turn echo pin off after use
  digitalWrite(echoPin, LOW);

  // return distance in centimeters
  return ((change_t * 0.0343) / 2);
}
