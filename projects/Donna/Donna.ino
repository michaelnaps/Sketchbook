// Project Donna
// Created by: Michael Napoli
// Created on: 11/28/2019
// Last modified on:  

/*  
 *  Purpose: A small two-wheeles robot that will move
 *  as guided. The goal is to do this remotely and/or 
 *  automatically with future hardware updates.
*/

#include<Adafruit_MotorShield.h>

// declare the motor attached shield for use
Adafruit_MotorShield SHIELD_1;

// declare the right and left motors
Adafruit_StepperMotor* motor_left = SHIELD_1.getStepper(200, 1);
Adafruit_StepperMotor* motor_right = SHIELD_1.getStepper(200,2);

// circumference of wheel in centimeters
const double WHEEL_CIRCUM = 51.427871739;

// width of body from middle left wheel to middle right wheel in centimeters
const double BODY_WIDTH = 13.7;

void setup() {
  // activate motor shield3
  SHIELD_1.begin();
}

void loop() {  
  delay(2000);

  celerate_motors(0, 100, "FORWARD");
  
  both_step(200, "FORWARD");

  celerate_motors(100, 0, "FORWARD");

  turn(180, "FORWARD");
}
