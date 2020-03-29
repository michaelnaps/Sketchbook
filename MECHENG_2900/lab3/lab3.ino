// Project: ME 2900 - Lab 3
// Created by: Michael Napoli
// Created on: 3/24/2020
// Last modified on: 3/24/2020

/*
 *  Purpose: ME 2900 - Lab 3 - Air Motor
 *    Program written to control and evaluate an air motor.
 *  
 *  NOTE: Program only works when cylinder pins are in sequence.
 *    i.e. cylinder 1 = pins 2 and 3, cylinder 2 = pins 4 and 5, etc.
*/

const int OPT_SENSOR = A2;  // pin for optical sensor
const int num_cylinders = 6;  // number of cylinders in the system

// for keeping track of the motor rotation
int previous = 6;
int current = 1;

// for the RPM calculation
float init_t = 0;  // initialize to 0
float fin_t = 0; 

void setup() {
  pinMode(OPT_SENSOR, INPUT);
  
  for (int i(0); i <= num_cylinders; ++i) {
    pinMode((2 * i), OUTPUT);
    pinMode((2 * i + 1), OUTPUT);
    
    deactivate(i);  // initialize all motors to deactivated position
  }
  
  // kick start motor by activating both 1 and 6
  activate(1);
  activate(6);
  
  // for RPM display of air motor
  Serial.begin(9600);
}

void loop() {
  // if a rotation is completed (current cylinder is back to 1)
  // calculate the RPM of the rotation
  if (current == 1) {
    fin_t = millis();  // take current time
    float RPM = calcRPM(fin_t - init_t);  // calculate RPM
    
    Serial.println(RPM);  // for testing

    init_t = millis();  // reset initial time value
    fin_t = 0;  // reset time when rotation is complete
  }
  
  // wait for the optical sensor to reach the next cylinder - arbitrary count
  while (digitalRead(OPT_SENSOR) == HIGH);
  while (digitalRead(OPT_SENSOR) == LOW);
  
  deactivate(previous);  // deactivate the previous cylinder
  activate(current);  // activate the current cylinder

  // iterate the 'current' and 'previous' cylinders
  previous = current;
  ++current;
  
  // if the current index exceeds the total number of cylinders (end of rotation)
  if (current > num_cylinders) {    
    current = 1;  // set cylinder back to 1
  }
}
