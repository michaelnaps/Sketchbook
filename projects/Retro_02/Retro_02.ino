// Project: Retro
// Created by: Michael Napoli
// Created on: 12/25/2020
// Last modified on: 12/25/2020

/*
 * Purpose: Programming controls for Bluetooth Low Energy
 *  game controller. Program written for Arduino Nano 33 BLE
 *  but should be adjustable to any Arduino BLE module that
 *  can utlize the ArduinoBLE.h library.
*/

#include "Nano33BleHID.h"

// create HID variable
Nano33BleGamepad retro("Retro");

void setup() {
  // initialize gamepad functionality and start event thread
  retro.initialize();
  MbedBleHID_RunEventThread();
}

void loop() {
  auto hid = retro.hid();

}
