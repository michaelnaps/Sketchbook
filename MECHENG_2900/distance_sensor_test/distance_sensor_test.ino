// File: distance_sensor_test
// Created by: Michael Napoli
// Created on: 3/7/2020

/*
 * Purpose: To test the useage of the ultrasonic distance sensor.
*/

int distance(0);
int dist_t(0);
const int dist_out(1);
const int dist_in(3);

const int speed_sound(340);  // in m/s

void setup() {
  pinMode(dist_out, OUTPUT);
  pinMode(dist_in, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(dist_out, HIGH);
  dist_t = micros();
  
  while (digitalRead(dist_in) == LOW) { }
  dist_t = micros() - dist_t;
  
  distance = (dist_t * speed_sound) / 2;

  Serial.println(distance);

  digitalWrite(dist_in, LOW);
  digitalWrite(dist_out, LOW);
}
