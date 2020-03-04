// File: morse_name()
// Created by: Michael Napoli
// Created on: 2/25/2020

/* 
 *  Purpose: Spell the name MICHAEL in Morse Code
 *  using user-made functions and LED lights.
*/

void morse_name()
{
  // spell 'MICHAEL' in Morse Code
  dash(ledPin, 2);
  
  dot(ledPin, 2);
  
  dash(ledPin, 1);
  dot(ledPin, 1);
  dash(ledPin, 1);
  dot(ledPin, 1);
  
  dot(ledPin, 4);

  dot(ledPin, 1);
  dash(ledPin, 1);
  
  dot(ledPin, 1);

  dot(ledPin, 1);
  dash(ledPin, 1);
  dot(ledPin, 2);
}
