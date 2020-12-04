// Function: both_step()
// Created by: Michael Napoli
// Created on: 12/10/2019
// Last modified on: 12/14/2019

/*
 * Function that takes in the number of steps and direction of
 * motion for the motors and moves them at the same time using a
 * loop that iterates their step-wise motion by 1.
 * Automatic step type: SINGLE
*/

bool both_step(const int& step_num, const String& dir)
{
  // until the number of steps given by the function call is reached,
  // the motors will be rotated one step at a time so that they can move
  // in synchrony
  for (int i(0); i < step_num; ++i) {
    if (dir == "FORWARD") {
      motor_left->step(1, FORWARD, SINGLE);
      motor_right->step(1, BACKWARD, SINGLE);
    }
    else if (dir == "BACKWARD") {
      motor_left->step(1, BACKWARD, SINGLE);
      motor_right->step(1, FORWARD, SINGLE);
    }
    // if user input is not correct, return false
    else { return false; }
  }

  // if function is completed successfully, return true
  return true;
}
