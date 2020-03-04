// Project: Lab 2
// Created by: Michael Napoli
// Created on: 3/3/2020

// analog pin - INPUT
const int pin_a1 = 1;

// pulse width modulating pin - OUTPUT
const int pin_pwm = 6;
int val = 0;

void setup() {
  pinMode(pin_a1, INPUT);
  pinMode(pin_pwm, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // read value from potentiometer
  val = analogRead(pin_a1);
  val = map(val, 0, 1023, 0, 255);
  
  // write corresponding value to LED brightness
  analogWrite(pin_pwm, val);

  delay(100);
  Serial.println(val);
}
