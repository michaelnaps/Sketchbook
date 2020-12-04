// Function: turn()
// Created by: Michael Napoli
// Created on: 12/14/2019
// Last modified on:

/* 
 *  Function that takes user inputted direction and angle and
 *  then calculates the steps required to complete the turn.
*/

void turn(const int& ALPHA_deg, const String& dir)
{
  // declare and calculate the alpha angle in radians
  double ALPHA_rad = (ALPHA_deg * (M_PI / 180));

  // initialize and calculate the number of steps needed
  // because step-type is DOUBLE, twice the amount of steps are needed
  int step_num = (2 * ((ALPHA_rad * BODY_WIDTH * 200) / WHEEL_CIRCUM));
  
  if (dir == "LEFT") {
    for (int i(0); i < step_num; ++i) 
      { motor_right->step(1, FORWARD, DOUBLE); }
  }
  else if (dir == "RIGHT") {
    for (int i(0); i < step_num; ++i) 
      { motor_left->step(1, FORWARD, DOUBLE); }
  }
}
