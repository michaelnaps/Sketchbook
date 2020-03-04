// * Project Name: Neith
// * Created by: Michael Napoli
// * Created on: 11/16/2019
// * Last modifed on: 

/* 
 *  Main program file for Neith robot command execution.
*/

#include<Adafruit_MotorShield.h>

Adafruit_MotorShield bottom_shield = Adafruit_MotorShield();
Adafruit_StepperMotor *motor1 = bottom_shield.getStepper(200, 2);


void setup() 
{
  bottom_shield.begin();
}

void loop() 
{
  
}
