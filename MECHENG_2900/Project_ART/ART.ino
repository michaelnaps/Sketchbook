// Project: A.R.T. (Autonomous Robotic Toy)
// Created by: Michael Napoli
// Created on: 3/7/2020
// Last modified on: 

/*
 * Purpose:
*/

const int trigPin(5);
const int echoPin(7);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(distance(trigPin, echoPin));
}
