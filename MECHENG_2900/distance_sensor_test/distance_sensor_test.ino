// File: distance_sensor_test
// Created by: Michael Napoli
// Created on: 3/7/2020

/*
 * Purpose: Small program test the useage of the ultrasonic distance sensor.
*/

double distance(0);
int dist_t(0);
const int trigPin(5);
const int echoPin(7);

const int speed_sound(343);  // in m/s

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delay(10);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  dist_t = pulseIn(echoPin, HIGH);  // returns pulse in microseconds
  
  distance = (((double)dist_t / 10000) * (double)speed_sound) / 2;

  Serial.println(distance);

  digitalWrite(echoPin, LOW);
  digitalWrite(trigPin, LOW);
  
  delay(100);
}
