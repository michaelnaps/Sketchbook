// Function: turn_right()
// Created by: Michael Napoli
// Created on: 4/14/2020

/*
  Purpose: Turn the SART vehicle at a given maximum radius speed.

   input: 'rate' - speed of the left motor
*/

void turn_right(const int& rate) {
  // turn SART legs right
  sart_servo.write(60);
  
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
