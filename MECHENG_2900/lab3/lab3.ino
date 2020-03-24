// Project: ME 2900 - Lab 3
// Created by: Michael Napoli
// Created on: 3/24/2020
// Last modified on:

/*
 *  Purpose:
*/

const int opt_sensor = A2;  // pin for optical sensor
const int button = A1;  // for extra-credit portion
const int num_cylinders = 6;  // number of cylinders in the system

// for keeping track of the motor rotation
int previous = 6;
int current = 1;

// for the RPM calculation
float time(0);

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
  return ((2 * M_PI) / ((float)millisec / (60000)));  // return RPM
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
  // wait for the optical sensor to reach the next cylinder - arbitrary count
  while (digitalRead(opt_sensor) == HIGH);
  while (digitalRead(opt_sensor) == LOW);
  
  deactivate(previous);  // deactivate the previous cylinder
  activate(current);  // activate the current cylinder

  // iterate the 'current' and 'previous' cylinders
  previous = current;
  ++current;
  
  // if the current index exceeds the total number of cylinders, set back to 1
  if (current > num_cylinders) {
    float RPM = calcRPM(time);
    Serial.println(RPM);  // for testing
    
    time = 0;  // reset time when rotation is complete
    current = 1;  // set cylinder back to 1
  }
  // otherwise, add time since the previous cylinder to total
  else {
    time += millis();
  }
}
