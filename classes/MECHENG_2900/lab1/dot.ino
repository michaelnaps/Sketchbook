// Function: dot()
// Created by: Michael Napoli
// Created on: 2/25/2020

/*
 * Purpose: Simulate a dot in Morse Code using LED lights.
 *  dot -> 1 unit ON, 1 unit OFF
*/

void dot(int pin, int n)
{
  for (int i(0); i < n; ++i) {
    digitalWrite(pin, HIGH);
    delay(500);

    digitalWrite(pin, LOW);
    delay(500);
  }
}
