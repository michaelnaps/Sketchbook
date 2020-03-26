// Created by: Michael Napoli
// Created on: 3/24/2020

// function: calcRPM()
// Function that returns the speed of a given rotating body
// input: time in milliseconds
// output: RPM speed
float calcRPM(const int& millisec) {
  return (1 / ((float)millisec / (60000)));  // return RPM
}
