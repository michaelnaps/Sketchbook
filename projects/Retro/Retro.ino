// Project: Retro
// Created by: Michael Napoli
// Created on: 11/11/2020
// Last modified on: 11/11/2020

/*
 * Purpose: Programming controls for Bluetooth Low Energy
 *  game controller. Program written for Arduino Nano 33 BLE
 *  but should be adjustable to any Arduino BLE module that
 *  can utlize the ArduinoBLE.h library.
*/

// Libaray for BLE services and characteristics
#include <ArduinoBLE.h>

// BLE services and characteristics
const char id[] = "00002A4A-0000-1000-8000-00805f9b34fb";
BLEByteCharacteristic hid_cp(id, BLENotify);
BLEService hid("00001812-0000-1000-8000-00805f9b34fb");
BLEDevice cDevice;  // variable for central device information

// function initializations (see definitions)
void _successful();
void un_successful();

// Button pins (digital)
const int s = 12;
const int a = 11;
const int b = 10;
const int xb = 9;
const int yb = 8;

// Joystick pins (analog)
const int xjs = A0;
const int yjs = A1;

void setup() {  
  // built-in LED initialization
  pinMode(LED_BUILTIN, OUTPUT);

  // Button(s) initialization
  pinMode(s, INPUT);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(xb, INPUT);
  pinMode(yb, INPUT);

  // initialize Nano 33 BLE - constant blink if successful
  if (!BLE.begin()) { _unsuccessful(); }
  else { _successful(); }

  // set name of BLE device
  BLE.setDeviceName("Retro");
  BLE.setLocalName("Retro");

  // set appearance to HID
  BLE.setAppearance(964);

  // set service and advertise as such
  hid.addCharacteristic(hid_cp);
  BLE.addService(hid);
  BLE.setAdvertisedService(hid);

  // advertise to other devices
  BLE.advertise();

  // wait for connection then stop advertising
  while(!BLE.connected());
  BLE.stopAdvertise();
  _successful();
}

void loop() {  
  // wait for Nano 33 BLE to connect
  cDevice = BLE.central();
  while (!BLE.connected()) { BLE.advertise(); }

  // check buttons and send data if applicable
  keyCheck_dig(s, 's');
  keyCheck_dig(a, 'a');
  keyCheck_dig(b, 'b');
  keyCheck_dig(xb, 'x');
  keyCheck_dig(yb, 'y');

  // check Joystick axis and send data if applicable
  keyCheck_an(xjs, 94, 92);
  keyCheck_an(yjs, 96, 90);
}
