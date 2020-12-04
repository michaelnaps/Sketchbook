// Project: Lab 1
// Created by: Michael Napoli
// Created on: 2/25/2020

/*
 * Lab 1:
 * Task 1: Pseudocode
 *  A unit in the morse code system will be equal to 0.5 seconds
 *  For the number of dashes and dots in a given letter, iterate the user-defined
 *    functions 'dash()' and 'dot()'
 *  The user-defined function 'dash()' will light the for 1.5 seconds (3 units)
 *  The user-defined function 'dot()' will light the LED for 0.5 seconds (1 unit)
 *  'M' - 2 dashes
 *  'I' - 2 dots
 *  'C' - 1 dash, 1 dot, 1 dash, 1 dot
 *  'H' - 4 dots
 *  'A' - 1 dot, 1 dash
 *  'E' - 1 dot
 *  'L' - 1 dot, 1 dash, 2 dots
 *  
 *  Task 4:
 *    Three more LED lights will be added to the system and will have the following 
 *    patterns programmed into them.
 *      Pattern 1: pattern1()
 *      - Each light will be lit subsequently down the line.
 *      - Each light will then be turned off in the same manner.
 *      Pattern 2: pattern2()
 *      - The light will be turned off in sets of two.
 *      - Whenever one pair is lit, the other will turn off immediately.
 *      
 *  Post-lab:
 *  Problem 1:
 *    Using a two-motor system, rotate the hour hand of a clock to the given locations.
 *    Locations: 18-10-23-8-0
 *    Pseudocode:
 *      - build a function that rotates the clockwise direction
 *      - build a function that rotates the counter-clockwise direction
 *      - using the loop in the main script, follow the pattern stated above
 *      - note: the hand will stop for half a second at each location
 *  Problem 2:
 *    Using same function method as in Problem 1 create the following pattern.
 *    Locations: 2-10-7-8-0
*/

// for Task 1
const int ledPin = 13;

// for Task 4
const int led1 = 2;
const int led2 = 4;
const int led3 = 7;
const int led4 = 8;

// for postlab Problem 1
const int cw_motor = 5;  // motor for clockwise rotation of clock
const int ccw_motor = 6;  // motor for counter-clockwise rotation of clock

void setup() {
  for (int i(3); i <= 8; ++i) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  blink_all(3, 8, 50);
  blink_all(7, 4, 50);
}
