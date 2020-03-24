// Project: ME 2900 - Lab 3
// Created by: Michael Napoli
// Created on: 3/24/2020
// Last modified on:

/*
 *  Purpose:
*/

const int opt_sensor = A2;
const int button = A1;  // for extra-credit portion
const int num_cylinders = 6;

int previous = 1;
int current = 2;

// HELPER FUNCTIONS:

void activate(const int& cyl) {
  digitalWrite((cyl * 2), HIGH);  // open inlet valve
  digitalWrite((cyl * 2 + 1), LOW);  // close exhaust valve
}

void deactivate(const int& cyl) {
  digitalWrite((2 * cyl), LOW);  // close the exhaust valve
  digitalWrite((2 * cyl + 1), HIGH);  // open the exhaust valve
}

// MAIN EXECUTION FUNCTIONS

void setup() {
  pinMode(opt_sensor, INPUT);
  pinMode(button, INPUT);
  
  for (int i(0); i < num_cylinders; ++i) {
    pinMode((2 * i), OUTPUT);
    pinMode((2 * i + 1), OUTPUT);
    
    digitalWrite((2 * i), LOW);
    digitalWrite((2 * i + 1), HIGH);
  }
  
  // kick start motor by activating both 1 and 6
  activate(1);
  activate(2);
}

void loop() {
  while (digitalRead(opt_sensor) == HIGH);
  while (digitalRead(opt_sensor) == LOW);
  
  deactivate(previous);  // deactivate the previous cylinder
  activate(current);  // activate the current cylinder
  
  previous = current;
  ++current;
  
  // if the current index exceeds the total number of cylinders, set back to 1
  if (current > num_cylinders) {
    current = 1;
  }
}
