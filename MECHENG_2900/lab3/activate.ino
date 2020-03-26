// Created by: Michael Napoli
// Created on: 3/24/2020

// function: activate()
// Function that fires the given piston
// input: piston number
// output: void
void activate(const int& cyl) {
  digitalWrite((cyl * 2), HIGH);  // open inlet valve
  digitalWrite((cyl * 2 + 1), LOW);  // close exhaust valve
}
