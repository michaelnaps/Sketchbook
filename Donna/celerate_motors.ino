// Function: celerate()
// Created by: Michael Napoli
// Created on: 12/10/2019
// Last modified on: 12/14/2019

/*
 * Function that takes an initial and final motor speed and iterates
 * a loop function until the motors are at the given speed. The function call
 * also takes in a direction so that the motors can be accelerated in 
 * both directions through the same function.
*/

void celerate_motors(const int& init_speed, const int& fin_speed, const String& dir)
{
  // if the motor is to accelerate
  if (fin_speed > init_speed) {
    for (int i(init_speed); i < fin_speed; ++i) {
      // the loop will increase the speed of the motor by one until
      // it reaches the final speed
      motor_left->setSpeed(i + 1);
      motor_right->setSpeed(i + 1);
  
      // move both forward by one step dependent on direction given
      if (dir == "FORWARD") {
        motor_left->step(1, FORWARD, SINGLE);
        motor_right->step(1, BACKWARD, SINGLE);
      }
      else if (dir == "BACKWARD") {
        motor_left->step(1, BACKWARD, SINGLE);
        motor_right->step(1, FORWARD, SINGLE);
      }
    }
  }

  // if the motor is to decelerate
  else if (fin_speed < init_speed) {
    for (int i(init_speed); i > fin_speed; --i) {
      // the loop will increase the speed of the motor by one until
      // it reaches the final speed
      motor_left->setSpeed(i - 1);
      motor_right->setSpeed(i - 1);
  
      // move both forward by one step
      if (dir == "FORWARD") {
        motor_left->step(1, FORWARD, SINGLE);
        motor_right->step(1, BACKWARD, SINGLE);
      }
      else if (dir == "BACKWARD") {
        motor_left->step(1, BACKWARD, SINGLE);
        motor_right->step(1, FORWARD, SINGLE);
      }
    }
  }

  // if the final speed is 0, release motors for stabilization
  if (fin_speed == 0) {
    motor_left->release();
    motor_right->release();
  }
}
