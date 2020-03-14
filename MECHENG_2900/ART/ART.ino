// Project: A.R.T. (Autonomous Robotic Toy)
// Created by: Michael Napoli
// Created on: 3/7/2020
// Last modified on:

/*
 * Purpose: Main execution file for the A.R.T. decision making.
*/

const int trigPin(2);
const int echoPin(4);

const int motor_left(5);  // pwm pin
const int motor_right(10);  // pwm pin

void setup()
{
  pinMode(motor_left, OUTPUT);
  pinMode(motor_right, OUTPUT);
}

void loop()
{
  for (int i(0); i < 255; ++i) {
    analogWrite(motor_left, i);
    analogWrite(motor_right, i);
    delay(100);
  }

  for (int i(255); i > -1; --i) {
    analogWrite(motor_left, i);
    analogWrite(motor_right, i);
    delay(100);
  }
}
