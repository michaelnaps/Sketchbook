// Function: dash()
// Created by: Michael Napoli
// Created on: 2/25/2020

/*
 * Purpose: Simulate a dash in Morse Code using LED lights.
 *  dash -> three units ON, 1 unit OFF
*/

void dash(int pin, int n)
{
  for (int i(0); i < n; ++i) {
    digitalWrite(pin, HIGH);
    delay(1500);

    digitalWrite(pin, LOW);
    delay(500);
  }
}
