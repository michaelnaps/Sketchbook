// Function: distance()
// Created by: Michael Napoli
// Created on: 3/7/2020
// Last modified on:

/*
 * Purpose: Function for the measurement of horizontal
 *   distance from the point of execution.
*/

double distance(const int trig, const int echo)
{
  int dist_time(0);
  
  // set 'trig' and 'echo' to LOW
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delay(1);
  
  // set 'trig' to HIGH for a cycle of ping
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  // set back to LOW
  digitalWrite(trig, LOW);
  
  // time that it takes for the pulse to return to the sensor
  dist_time = pulseIn(echo, HIGH);
  
  // return distance using eqution:
  // distance = (time * speed of sound) / 2;
  return (dist_time * 0.0343) / 2;
}
