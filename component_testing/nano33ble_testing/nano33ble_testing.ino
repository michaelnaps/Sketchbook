// testing for Arduino Nano 33 BLE microcontroller

#include <ArduinoBLE.h>

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

  BLE.setLocalName("napoli_controller");
}

void loop() {
  // put your main code here, to run repeatedly:

}
