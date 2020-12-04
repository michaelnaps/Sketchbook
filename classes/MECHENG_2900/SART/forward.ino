// Function: forward()
// Created by: Michael Napoli
// Created on: 3/30/2020

/*
  Purpose: Move the SART vehicle forward at a given speed.
   input: 'rate' - speed of the left motor
*/

void forward(const int& rate) {
  // check speed is in allowable range
  constrain(rate, 0, 255);
  
  // straighten SART legs
  control_servo.write(100);
  
  // disable drivers
  digitalWrite(EN_LEFT, LOW);
  digitalWrite(EN_RIGHT, LOW);
  
  // toggle switches to move forward
  digitalWrite(MC_LEFT_1, HIGH);
  digitalWrite(MC_LEFT_2, LOW);
  digitalWrite(MC_RIGHT_1, HIGH);
  digitalWrite(MC_RIGHT_2, LOW);
  
  // start motors at given speed
  analogWrite(EN_LEFT, rate);
  analogWrite(EN_RIGHT, rate);
}
