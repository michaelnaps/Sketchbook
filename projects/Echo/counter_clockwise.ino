// Function: step()
// Created by: Michael Napoli
// Created on: 8/24/2020

/*
 * Purpose:
*/

void counter_clockwise(const int& dir_pin, const int& step_pin)
{
  digitalWrite(dir_pin, HIGH);  // counter-clockwise
        
  digitalWrite(step_pin, HIGH);
  delayMicroseconds(500);
  digitalWrite(step_pin, LOW);
  delayMicroseconds(500);
  return;  // return nothing
}
