// Function: pattern2()
// Created by: Michael Napoli
// Created on: 2/25/2020

/*
 * Purpose: Simulate Pattern 2 which follows:
 *  Lights will turn on and off in pairs.
 *  Once a pair is turned off, the opposite pair is immediately turned on.
*/

void pattern2()
{
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(500);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(500);
}
