// Project: Mercury
// Created by: Michael Napoli
// Created on: 6/2/2020
// Last modified by:

/*
 * Purpose: Execution files for coin seperation and counting system.
*/

#include "coin.h"
using namespace mercury;

const Coin D("Dime", 0.10, 0, 8);
const Coin P("Penny", 0.01, 0, 9);
const Coin N("Nickel", 0.05, 0, 10);
const Coin Q("Quarter", 0.25, 0, 11);

void setup() {
  pinMode(D.getPin(), INPUT);
  pinMode(P.getPin(), INPUT);
  pinMode(N.getPin(), INPUT);
  pinMode(Q.getPin(), INPUT);
}

void loop() {
  
}
