// Function: blink_all()
// Created by: Michael Napoli
// Created on: 3/2/2020

/*
 * Purpose: Given the initial and final pins in a row of LED lights
 *  blink all lights consequentially for a given length of time, 
 *  then turn off.
*/

void blink_all(const int first, const int last, const int t) {
  // if the user would like to go in the forward direction
  if (first <= last) {
    for (int i(first); i <= last; ++i) {
      // turn on for give time 't'
      digitalWrite(i, HIGH);
      delay(t);
  
      // turn off
      digitalWrite(i, LOW);
    }
  }
  // otherwise they will be reversing down the line of pins
  else {
    for (int i(first); i >= last; --i) {
      // turn on for give time 't'
      digitalWrite(i, HIGH);
      delay(t);
  
      // turn off
      digitalWrite(i, LOW);
    }
  }
}
