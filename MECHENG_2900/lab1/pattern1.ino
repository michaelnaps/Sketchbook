// Function: pattern1()
// Created by: Michael Napoli
// Created on: 2/25/2020

/*
 * Purpose: Simulate Pattern 1 which follows:
 *  All lights connected will turn on consequentially.
 *  All lights will then turn off in the same manner.
*/

void pattern1()
{
  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led4, HIGH);
  delay(500);

  digitalWrite(led1, LOW);
  delay(500);
  digitalWrite(led2, LOW);
  delay(500);
  digitalWrite(led3, LOW);
  delay(500);
  digitalWrite(led4, LOW);
  delay(500);
}
