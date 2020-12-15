// Project: Retro
// Created by: Michael Napoli
// Created on: 11/11/2020
// Last modified on: 11/11/2020

// Libaray for BLE services and characteristics
#include <ArduinoBLE.h>

// BLE services and characteristics
BLEUnsignedIntCharacteristic hid_cp("0x2A4C", BLENotify);
// BLEUnsignedIntCharacteristic hid_info("0x2A4A", BLENotify);
BLEService hid("00001812-0000-1000-8000-00805f9b34fb");
BLEDevice cDevice;  // variable for central device information

// create buffer variables for gamepad
// byte buf[8] = {0};

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
  // hid.addCharacteristic(hid_info);
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

  // check buttons and send data
  keyCheck_dig(s, 15);
  keyCheck_dig(a, 4);
  keyCheck_dig(b, 5);
  keyCheck_dig(xb, 27);
  keyCheck_dig(yb, 28);

  keyCheck_an(xjs, 94, 92);
  keyCheck_an(yjs, 96, 90);
}
