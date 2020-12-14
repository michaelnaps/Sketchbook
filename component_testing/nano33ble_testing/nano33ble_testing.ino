// testing for Arduino Nano 33 BLE microcontroller

#include <ArduinoBLE.h>

// uuid found at https://bluetooth.com
BLEService hid("00001812-0000-1000-8000-00805f9b34fb");

// intialize central BLE device variable
BLEDevice cDevice;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Serial Open.");

  if (!BLE.begin()) {
    Serial.println("Nano 33 BLE was not initialized.");
    while(1);
  }
  else { Serial.println("Nano 33 BLE was initialized successfully."); }

  // set name of device
  BLE.setLocalName("NapoliBLE");
  BLE.setDeviceName("NapoliBLE");

  // set appearance using general ID code (gamepad)
  BLE.setAppearance(964);

  // set service and advertise
  BLE.addService(hid);
  BLE.setAdvertisedService(hid);

  // start advertising to other devices
  BLE.advertise();

  while(!BLE.connected());
  Serial.print("Nano 33 BLE is connected.");
}

void loop() {
  // if BLE is disconnected, advertise and loop
  while (!BLE.connected()) 
    { BLE.advertise(); }

}
