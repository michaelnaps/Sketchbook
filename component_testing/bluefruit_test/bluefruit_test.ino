// testing of the Adafruit BluefruitLE component

// Include Library for Bluefruit
#include <SoftwareSerial.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"

// Initialize BluefruitLE object
SoftwareSerial mySerial(5, 6);
Adafruit_BluefruitLE_UART btle(mySerial, -1, 3, -1);

void setup()
{
  Serial.begin(9600);

  // establish BluefruitLE connection
  if(!btle.begin(false, false)) {
    Serial.println("Could not initialize BluefruitLE."); 
    while(1);
  }
  else { Serial.println("Initialization successful."); }

  // Factory reset BluefruitLE board
  if(!btle.factoryReset()) {
    Serial.println("Could not perform factory reset.");
    while(1);
  }
  else { Serial.println("Factory reset successful."); }
}

void loop()
{
  
}
