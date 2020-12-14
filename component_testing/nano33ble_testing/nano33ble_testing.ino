// testing for Arduino Nano 33 BLE microcontroller

#include <ArduinoBLE.h>

// see function definitions below
const int L = LED_BUILTIN;
void successful();
void unsuccessful();

// uuid found at https://bluetooth.com
BLEService hid("00001812-0000-1000-8000-00805f9b34fb");

// intialize central BLE device variable
BLEDevice cDevice;

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);
  // while(!Serial);

  // Serial.println("Serial Open.");

  if (!BLE.begin()) {
    // Serial.println("Nano 33 BLE was not initialized.");
    unsuccessful();  // stop program
  }
  else { 
    // Serial.println("Nano 33 BLE was initialized successfully."); 
    successful();
  }
  
  // set name of device
  BLE.setLocalName("NapoliBLE");
  BLE.setDeviceName("NapoliBLE");

  // set appearance using general ID code (gamepad)
  BLE.setAppearance(964);

  // set service and advertise
  BLE.setAdvertisedService(hid);
  BLE.addService(hid);

  // add characteristic
  BLECharacteristic hid_info("0x2A4A");
  BLECharacteristic hid_controlPoint("0x2A4C");
  BLE.addCharacteristic(hid_info, BLERead | BLEWrite);
  BLE.addCharacteristic(hid_controlPoint, BLEWrite);

  // start advertising to other devices
  BLE.advertise();

  while(!BLE.connected());
  // Serial.print("Nano 33 BLE is connected.");
  successful();
}

void loop() {
  // if BLE is disconnected, advertise and loop
  while (!BLE.connected()) 
    { BLE.advertise(); }

  cDevice = BLE.central();
  // Serial.print("BLE is connected to: ");
  // Serial.println(cDevice.address());

  if (cDevice.connected())
    { successful(); }
}

// indicates success at certain points in program
void successful() {
  // fade in and out to indicate success
  for (int i(0); i < 1023; i += 100) {
    analogWrite(L, i);
    delay(100);
  }
  for (int i(0); i > 1023; i -= 100) {
    analogWrite(L, i);
    delay(100);
  }
  analogWrite(L, 0);  // turn off
  
  return;  // return nothing
}

// if called, stops program
// blinks the built in LED to tell user
void unsuccessful() {
  // infinite loop
  while(1) {
    analogWrite(L, 800);
    delay(500);
    analogWrite(L, 0);
    delay(500);
  }
  
  return;  // return nothing
}
