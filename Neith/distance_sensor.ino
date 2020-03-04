// File: distance_sensor
// Created by: Michael Napoli
// Created on: 11/18/2019
// Last modified on: 

/*
 * Function that returns the calculated distance from the closest object as type double.
 * Range of sensor: 3cm - 400cm
 * If the distance is above 400cm, function returns -1 as error code.
*/

double distance_sensor(const int& pin1, const int& pin2)
{
  // initialization for pin locations
  const int TRIG_PIN = pin1;  // output
  const int ECHO_PIN = pin2;  // input

  // 400cm a.k.a. the maximum distance of the sensor (measured in microseconds)
  const int MAX_DIST = 23200;

  // initial and final time variables
  double t_init(0);
  double t_fin(0);
  double t_total(0);
  double distance(0);

  pinMode(TRIG_PIN, OUTPUT);  // sends the sensor pulse
  pinMode(ECHO_PIN, INPUT);  // reads the sensor pulse

  // begin range find
  digitalWrite(TRIG_PIN, LOW);

  // hold trigger pin HIGH in order to send pulse (at least 10 microseconds)
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  // turn trigger back to LOW
  digitalWrite(TRIG_PIN, LOW);

  // wait for initial pulse and record initial time
  while(digitalRead(ECHO_PIN) == 0);
  t_init = micros();

  // wait for pulse to return and record final time
  while(digitalRead(ECHO_PIN) == 1);
  t_fin = micros();

  // calculate final time
  t_total = t_fin - t_init;

  // if the time value does not exceed the maximum, return the distance in cm
  if (t_total < MAX_DIST) {
    // calculate distance in centimeters
    distance = (t_total / 58);
    
    return distance;
  }
  else { return -1; }  // otherwise return -1 (ERROR code value)
}
