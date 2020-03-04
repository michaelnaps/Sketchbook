// Function: rotate_cw()
// Created by: Michael Napoli
// Created on: 3/2/2020

/*
 * Purpose: To create a sketch that rotates a clock's hands
 *  in the clockwise direction a given number of hours.
*/

void rotate_cw(const int num_hr) {
  for (int i(0); i < num_hr; ++i) {
    // rotate the clockwise motor
    digitalWrite(cw_motor, HIGH);

    // half of a second = 1 hour on the clock face
    delay(500);
    
    // brake motor
    digitalWrite(cw_motor, LOW);
  }

  // stop the motor for at-least half a second at the final location
  delay(500);
}
