// Project: BLE_testing
// Created by: Michael Napoli
// Created on: 4/8/2020

// Bluefruit Libraries:
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"

// BLE RELEVANT PINS AND EXPLANATIONS:
const int MODE = -1;  // this pin controls the mode of the Bluefruit
                      // CMD - command mode - HIGH - recieves command from microcontroller
                      // UART - data mode - LOW - collects data and sends to reciever
                      // can also toggle directly on Bluefruit when info is only moving in one direction
                      
const int CTS = -1;   // flow control pin - clear to send
                      // used to tell Bluefruit to send data from the reciever to the microcontroller
                      // HIGH by default                      
                      // if HW flow control not neede, set directly to GND
                      
const int TX = 10;    // UART transmission pin, Bluefruit sends to MCU

const int RX = 9;     // UART recieve pin, MCU sends to Bluefruit

const int RTS = -1;   // flow control pin - read to send
                      // will be LOW when it is fine to send data to the Bluefruit
                      // not necessary - sometimes used for complete flow control

const int DFU = -1;   // setting this to LOW will start Bluefruit in a firmware update mode
                      // can also be used to do a manual factory reset - use a button

// Create Bluefruit Object:
SoftwareSerial ble_serial(TX, RX);
Adafruit_BluefruitLE_UART my_bluefruit(ble_serial, MODE, CTS, RTS);

void setup() {
  Serial.begin(115200);
  Serial.println("Bluefruit testing:");

  if (!my_bluefruit.begin(false)) {
    Serial.println("Could not find Bluefruit.");
    return;
  }
  else {
    Serial.println("Connected to Computer.");
  }

  my_bluefruit.echo(false);  // disable command echo

  Serial.println("Info:");
  my_bluefruit.info();

  // my_bluefruit.verbose(false);  // turn off debug info

  // wait for Bluefruit to Connect
  while (!my_bluefruit.isConnected()) {
    delay(100);
  }
  Serial.println("Bluefruit is Connected.");
}

void loop() {
  // put your main code here, to run repeatedly:

}
