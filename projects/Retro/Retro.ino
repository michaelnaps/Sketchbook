// Project: Retro
// Created by: Michael Napoli
// Created on: 11/11/2020
// Last modified on: 11/11/2020

#include "Nano33BleHID.h"

// Button pins (digital)
const int s = 12;
const int a = 11;
const int b = 10;
const int xb = 9;
const int yb = 8;

// Joystick pins (analog)
const int xjs = A0;
const int yjs = A1;

// Gamepad HID variable
Nano33BleKeyboard retro("Mr. Retro");

void setup() {  
  // built-in LED initialization
  pinMode(LED_BUILTIN, OUTPUT);

  // Button(s) initialization
  pinMode(s, INPUT);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(xb, INPUT);
  pinMode(yb, INPUT);

  // initialize Gamepad
  retro.initialize();

  // Launch event queue that will mange both BLE events and the loop
  // After this call the main thread will be halted
  MbedBleHID_RunEventThread();  
}

void loop() {
  // Built-in LED will be off until connected
  digitalWrite(LED_BUILTIN, LOW);
  
  // wait for Nano 33 BLE to connect
  while (!retro.connected());

  // when connected, turn on built in LED
  digitalWrite(LED_BUILTIN, HIGH);

  // Read button inputs
}
