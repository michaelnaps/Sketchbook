// Project: A.R.T. (Autonomous Robotic Toy)
// Created by: Michael Napoli
// Created on: 3/7/2020
// Last modified on:

/*
 * Purpose: Main execution file for the A.R.T. decision making.
*/

const int trigPin(2);
const int echoPin(4);

const int motor_left(3);  // pwm pin
const int motor_right(6);  // pwm pin

void setup()
{
  pinMode(motor_left, OUTPUT);
  pinMode(motor_right, OUTPUT);
}

void loop()
{
  for (int i(50); i < 255; ++i) {
    analogWrite(motor_left, i);
    analogWrite(motor_right, i);
    delay(100);
  }
  
  digitalWrite(motor_left, LOW);
  digitalWrite(motor_right, LOW);
  
  delay(5000);
}
