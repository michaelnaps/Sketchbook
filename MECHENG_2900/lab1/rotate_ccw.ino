// Function: rotate_ccw()
// Created by: Michael Napoli
// Created on: 3/2/2020

/*
 * Purpose: To create a sketch that rotates a clock's hands
 *  in the counter-clockwise direction a given number of hours.
*/

void rotate_ccw(const int num_hr) {
  for (int i(0); i < num_hr; ++i) {
    // rotate the counter-clockwise motor
    digitalWrite(ccw_motor, HIGH);

    // half of a second = 1 hour on the clock face
    delay(500);
    
    // brake motor
    digitalWrite(ccw_motor, LOW);
  }

  // stop the motor for at-least half a second at the final location
  delay(500);
}
