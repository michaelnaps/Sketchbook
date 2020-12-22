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

// BLE descriptor, characteristics and services
byte buf = 0;  // initialize to 0
BLEDescriptor hid_p("0011", "HIDP");
BLEByteCharacteristic hid_cp("2A4A", BLENotify);
BLEService hid("11240000-0000-1000-8000-00805f9b34fb");
BLEDevice cDevice;  // variable for central device information

// Button pins (digital)
const int s(12), a(11), b(10), xb(9), yb(8);

// Joystick pins (analog)
const int xjs(A0), yjs(A1);

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
  hid_cp.addDescriptor(hid_p);  // descriptor for service
  hid.addCharacteristic(hid_cp);
  BLE.addService(hid);
  BLE.setAdvertisedService(hid);

  // advertise to other devices
  BLE.advertise();

  // wait for connection then stop advertising
  while(!BLE.connected());
  _successful();  // show successful connection
  BLE.stopAdvertise();
}

void loop() {  
  // wait for Nano 33 BLE to connect
  cDevice = BLE.central();
  while (!BLE.connected()) { BLE.advertise(); }

  // check buttons and send data if applicable
  keyCheck_dig(s, 83);
  keyCheck_dig(a, 65);
  keyCheck_dig(b, 66);
  keyCheck_dig(xb, 88);
  keyCheck_dig(yb, 89);

  // check Joystick axis and send data if applicable
  keyCheck_an(xjs, 100, 102);
  keyCheck_an(yjs, 98, 104);
}
