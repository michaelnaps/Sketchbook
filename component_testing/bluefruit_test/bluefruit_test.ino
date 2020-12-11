// testing of the Adafruit BluefruitLE component

// Include Library for BluefruitLE and SoftwareSerial
#include <HardwareSerial.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"

// Initialize BluefruitLE object
Adafruit_BluefruitLE_UART btle(Serial);

void setup()
{
  // establish BluefruitLE connection
  if(!btle.begin(true, false)) {
    // Serial.println("Could not initialize BluefruitLE."); 
    while(1);
  }
  else { 
    // Serial.println("Initialization successful.");
  }

  // Factory reset BluefruitLE board
  if(!btle.factoryReset()) {
    // Serial.println("Could not perform factory reset.");
    while(1);
  }
  else { 
    // Serial.println("Factory reset successful.");
  }

  // Set name of module
  btle.print("AT+GAPDEVNAME=");
  btle.println("Napoli BluefruitLE Controller");
  if(!btle.waitForOK()) {
    // Serial.println("Name of module could not be changed.");
    while(1);
  }
  else { 
    // Serial.println("New BluefruitLE Name: Napoli BluefruitLE Controller");
  }

  btle.verbose(false);
}

void loop()
{
  // check/wait for connection
  while(!btle.isConnected());
  
}
