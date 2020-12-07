// testing of the Adafruit BluefruitLE component

// Include Library for Bluefruit
#include <HardwareSerial.h>
// #include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"

// Initialize BluefruitLE object
Adafruit_BluefruitLE_UART btle(Serial1, -1, 3, -1);

void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);

  // establish BluefruitLE connection
  if(!btle.begin(true)) {
    Serial.println("Could not initialize BluefruitLE."); 
    while(1);
  }
  else { 
    Serial.println("Initialization successful."); 
  }

  // Factory reset BluefruitLE board
  if(!btle.factoryReset()) {
    Serial.println("Could not perform factory reset.");
    while(1);
  }
  else { Serial.println("Factory reset successful."); }

  // Set name of module
  btle.print("AT+GAPDEVNAME=");
  btle.println("simple_controller");
  if(!btle.waitForOK()) {
    Serial.println("Name of module could not be changed.");
    while(1);
  }
  else { Serial.println("New BluefruitLE Name: napoli_simple_controller"); }

  btle.verbose(false);
}

void loop()
{
  // check/wait for connection
  while(!btle.isConnected());
  
}
