// Project: A.R.T. (Autonomous Robotic Toy)
// Created by: Michael Napoli
// Created on: 3/7/2020
// Last modified on:

/*
 * Purpose: Main execution file for the A.R.T. decision making.
*/

const int trigPin(5);
const int echoPin(7);

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  Serial.println(distance(trigPin, echoPin));
  delay(500);
}
