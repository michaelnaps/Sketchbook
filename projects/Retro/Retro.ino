// Project: Retro
// Created by: Michael Napoli
// Created on: 11/11/2020
// Last modified on: 11/11/2020

#include <ArduinoBLE.h>
#include "HID_Buttons.h"

// Button pins (digital)
const int s = 12;
const int a = 11;
const int b = 10;
const int xb = 9;
const int yb = 8;

// Joystick pins (analog)
const int sw = 7;
const int xjs = A0;
const int yjs = A1;

// input buttons and joystick into HID variable
JoystickButton JS;

void setup() {  
  // built-in LED initialization
  pinMode(LED_BUILTIN, OUTPUT);

  // Button(s) initialization
  pinMode(s, INPUT);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(xb, INPUT);
  pinMode(yb, INPUT);

  // initialize Nano 33 BLE - quick blink if successful
  if (BLE.begin()) {
    for (int i(0); i < 1023; i += 100) {
      analogWrite(LED_BUILTIN, i);  // phase on
      delay(50);
    }
    for (int i(1023); i >= 0; i -= 100) {
      analogWrite(LED_BUILTIN, i);  // phase off
      delay(50);
    }
    analogWrite(LED_BUILTIN, 0);  // turn off
  }
  else { analogWrite(LED_BUILTIN, 500); }

  while(1);  // pause until other tests
}

void loop() {  
  // wait for Nano 33 BLE to connect
  while (!BLE.connected());

  // when connected, turn on built in LED
  digitalWrite(LED_BUILTIN, HIGH);

  // Read button inputs  
}
