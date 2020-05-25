#include "coin.h"
using namespace mercury;

const Coin Q("Quarter", 0.25);
const Coin D("Dime", 0.10);
const Coin N("Nickel", 0.05);
const Coin P("Penny", 0.01);

const int Q_pin(7);
const int D_pin(6);
const int N_pin(5);
const int P_pin(4);

void setup() {
  pinMode(Q_pin, INPUT);
  pinMode(D_pin, INPUT);
  pinMode(N_pin, INPUT);
  pinMode(P_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  if(digitalRead(Q_pin)) {
    Serial.println(Q.getName());
  }
  if(digitalRead(D_pin)) {
    Serial.println(D.getName());
  }
  if(digitalRead(N_pin)) {
    Serial.println(N.getName());
  }
  if(digitalRead(P_pin)) {
    Serial.println(P.getName());
  }

  delay(1000);
}
