// Project: IR_controller_test
// Created by: Michael Napoli
// Created on: 4/8/2020

#include <IRremote.h>

// IR input pins:
const int IR_REMOTE_PIN = 11;
IRrecv ir_rec(IR_REMOTE_PIN);
decode_results result;

void setup() {
  Serial.begin(9600);
  ir_rec.enableIRIn();  // start reciever
}

void loop() {
  // check for input from remote
  if (ir_rec.decode(&result)) {
    Serial.println(result.value);
    ir_rec.resume();  // recieve next value
  }
}
