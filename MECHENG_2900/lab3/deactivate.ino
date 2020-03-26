// Created by: Michael Napoli
// Created on: 3/24/2020

// function: deactivate()
// Function that returns cylinder to its 'off' state
// input: piston number
// output: void
void deactivate(const int& cyl) {
  digitalWrite((2 * cyl), LOW);  // close the exhaust valve
  digitalWrite((2 * cyl + 1), HIGH);  // open the exhaust valve
}
