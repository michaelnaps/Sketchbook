// Project: Hbridge_test()
// Created by: Michael Napoli
// Created on: 3/26/2020

const int EN = 9;
const int MC1 = 3;
const int MC2 = 2;
const int POT = A0;

int val = 0;
int velocity = 0;

void forward(int rate) {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, HIGH);
  digitalWrite(MC2, LOW);
  analogWrite(EN, rate);
}

void reverse(int rate) {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, HIGH);
  analogWrite(EN, rate);
}

void brake() {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, LOW);
  analogWrite(EN, HIGH);
}

void setup()
{
  pinMode(EN, OUTPUT);
  pinMode(MC1, OUTPUT);
  pinMode(MC2, OUTPUT);
}

void loop()
{
  val = analogRead(POT);
  
  if (val > 562) {
    velocity = map(val, 563, 1023, 0, 255);
    forward(velocity);
  }
  else if ( val < 462) {
    velocity = map(val, 461, 0, 0, 255);
    reverse(velocity);
  }
  else {
    brake();
  }
}
