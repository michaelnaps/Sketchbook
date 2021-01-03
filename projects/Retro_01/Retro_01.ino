// Project: Retro
// Created by: Michael Napoli
// Created on: 12/11/2020
// Last modified on: 12/22/2020

/*
 * Purpose: Programming controls for Bluetooth Low Energy
 *  game controller. Program written for Arduino Nano 33 BLE
 *  but should be adjustable to any Arduino BLE module that
 *  can utlize the ArduinoBLE.h library.
*/

// Libaray for BLE services and characteristics
#include <ArduinoBLE.h>

// connected and disconnected function initializations for event handler
void ble_connected(BLEDevice central);
void ble_disconnected(BLEDevice central);

// buffer variable for sending value to central device
byte buf(0);  // initialize to 0

// BLE characteristic(s)
BLEByteCharacteristic hid_cp("00002A4C-0000-1000-8000-00805F9B34FB", BLEWriteWithoutResponse);
BLEByteCharacteristic hid_report("00002A4D-0000-1000-8000-00805F9B34FB", BLERead | BLENotify);


// BLE service(s)
BLEService hid("00001812-0000-1000-8000-00805F9B34FB");

// Button pins (digital)
const int s(12), a(11), b(10), xb(9), yb(8);

// Joystick pins (analog)
const int xjs(A0), yjs(A1);

void setup() {
  // serial communication for analysis
  Serial.begin(9600);
  while(!Serial);
  
  // Button(s) initialization
  pinMode(s, INPUT);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(xb, INPUT);
  pinMode(yb, INPUT);

  // initialize Nano 33 BLE - constant blink if successful
  if (!BLE.begin()) { 
    Serial.println("ERROR: Retro could not be initialized.");
    _unsuccessful(); 
  }
  else { 
    Serial.println("Retro initialized successfully.");
    _successful(); 
  }

  // set event handlers for connected and disconnected
  BLE.setEventHandler(BLEConnected, ble_connected);
  BLE.setEventHandler(BLEDisconnected, ble_disconnected);

  // set name of BLE device
  BLE.setDeviceName("Napoli-Retro");
  BLE.setLocalName("Napoli-Retro");

  // set service and advertise as such
  hid.addCharacteristic(hid_cp);
  hid.addCharacteristic(hid_report);
  BLE.addService(hid);

  // set appearance to Gamepad
  BLE.setAdvertisedService(hid);
  BLE.setAppearance(964);
  BLE.setConnectable(true);

  // show local address (for testing)
  Serial.print("Local address is: ");
  Serial.println(BLE.address());

  // advertise to other devices
  BLE.advertise();

  // wait for connection then stop advertising
  while(!BLE.connected());
  BLE.stopAdvertise();
}

void loop() {  
  // if Retro is disconnected, stop and wait
  while (!BLE.connected()) { BLE.advertise(); }
  BLE.stopAdvertise();

  // check buttons and send data if applicable
  keyCheck_dig(s, 32);
  keyCheck_dig(a, 31);
  keyCheck_dig(b, 50);
  keyCheck_dig(xb, 46);
  keyCheck_dig(yb, 22);

  // check Joystick axis and send data if applicable
  keyCheck_an(xjs, 92, 102);
  keyCheck_an(yjs, 98, 96);
}

// Event Handler Function definitions
void ble_connected(BLEDevice central) { 
  _successful();
  Serial.print("Retro connected to: ");
  Serial.println(central.address());
}

void ble_disconnected(BLEDevice central) { 
  _unsuccessful();
  Serial.print("Retro disconnected from: ");
  Serial.println(central.address());
}
