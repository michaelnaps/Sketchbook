// Function: step()
// Created by: Michael Napoli
// Created on: 8/24/2020

/*
 * Purpose:
*/

void clockwise(const int& dir_step, const int& step_pin)
{
  digitalWrite(DIR, LOW);  // clockwise
        
  digitalWrite(step_pin, HIGH);
  delayMicroseconds(500);
  digitalWrite(step_pin, LOW);
  delayMicroseconds(500);
  return;  // return nothing
}
