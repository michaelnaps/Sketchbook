// Project: Hbridge_test()
// Created by: Michael Napoli
// Created on: 3/26/2020

const int EN = 4;
const int MC1 = 3;
const int MC2 = 2;

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
  forward(255);
  delay(6000);

  brake();
  delay(3000);
}
