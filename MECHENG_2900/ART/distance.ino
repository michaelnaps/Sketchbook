// Function: distance()
// Created by: Michael Napoli
// Created on: 3/7/2020

/*
 * Purpose: Program that returns the measurement distance
 *  from the distance sensor in centimeters.
*/

double distance(const int trig, const int echo)
{
  int dist_time(0);  // for the time of the ping of the sensor

  // set pins to LOW
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delay(1);  // delay for 1 millisecond

  // set 'trig' to HIGH for 10 microseconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // measure time that 'echo' is set to HIGH
  dist_time = pulseIn(echo, HIGH);
  
  // return the distance using the following eqution:
  // distance = time * speed of sound
  return (dist_time * 0.0343) / 2;
}
