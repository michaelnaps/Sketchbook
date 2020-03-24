// Project: ME 2900 - Lab 3
// Created by: Michael Napoli
// Created on: 3/24/2020
// Last modified on:

/*
 *  Purpose: ME 2900 - Lab 3 - Air Motor
 *    Program written to control and evaluate an air motor.
*/

const int opt_sensor = A2;  // pin for optical sensor
const int button = A1;  // for extra-credit portion
const int num_cylinders = 6;  // number of cylinders in the system

// for keeping track of the motor rotation
int previous = 6;
int current = 1;

// for the RPM calculation
float init_t = 0;
float fin_t = 0;  // initialize to 0

// HELPER FUNCTIONS:

// function: activate()
// Function that fires the given piston
// input: piston number
// output: void
void activate(const int& cyl) {
  // NOTE: function only works when cylinder pins are in sequential order
  digitalWrite((cyl * 2), HIGH);  // open inlet valve
  digitalWrite((cyl * 2 + 1), LOW);  // close exhaust valve
}

// function: deactivate()
// Function that returns cylinder to its 'off' state
// input: piston number
// output: void
void deactivate(const int& cyl) {
  // NOTE: function only works when cylinder pins are in sequential order
  digitalWrite((2 * cyl), LOW);  // close the exhaust valve
  digitalWrite((2 * cyl + 1), HIGH);  // open the exhaust valve
}

float calcRPM(const int& millisec) {
  return (1 / ((float)millisec / (60000)));  // return RPM
}

// MAIN EXECUTION FUNCTIONS

void setup() {
  pinMode(opt_sensor, INPUT);
  pinMode(button, INPUT);
  
  for (int i(0); i <= num_cylinders; ++i) {
    pinMode((2 * i), OUTPUT);
    pinMode((2 * i + 1), OUTPUT);
    
    deactivate(i);  // initialize all motors to deactivated position
  }
  
  // kick start motor by activating both 1 and 2
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
  while (digitalRead(opt_sensor) == HIGH);
  while (digitalRead(opt_sensor) == LOW);
  
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
