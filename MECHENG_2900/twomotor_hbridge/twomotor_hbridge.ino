// Project: twomotor_hbridge
// Created by: Michael Napoli
// Created on: 3/30/2020

/*
  Purpose: To test the functionality of running two
    DC motors with a single H-bridge.
*/

// left motor
const int EN_LEFT = 4;
const int MC_LEFT_1 = 3;
const int MC_LEFT_2 = 2;

// right motor
const int EN_RIGHT = 7;
const int MC_RIGHT_1 = 6;
const int MC_RIGHT_2 = 5;

void setup()
{
  for (int i(2); i < 8; ++i) {
    pinMode(i, OUTPUT);
  }
}

void loop()

{
  forward(255);
  delay(6000);

  brake();
  delay(5000);
}
