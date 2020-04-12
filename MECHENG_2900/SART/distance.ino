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
    - distance from UDS
*/

float distance(const int& trigPin, const int& echoPin) {
  float change_t(0);
  const int SOUND(343);  // in m/s
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  change_t = pulseIn(echoPin, HIGH);  // returns pulse in microseconds
  digitalWrite(echoPin, LOW);

  return (((change_t / 10000) * SOUND) / 2);
}
