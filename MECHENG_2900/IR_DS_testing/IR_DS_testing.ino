// Project: IR_controller_test
// Created by: Michael Napoli
// Created on: 4/8/2020

#include <IRremote.h>

// IR SENSOR PINS:
const int IR_PIN(6);
IRrecv ir_rec(IR_PIN);
decode_results results;

// DISTANCE SENSOR VARIABLES:
const int TRIG(4);
const int ECHO(5);
float dist(0);

// PROGRAM EXECUTION VARIABLES:
int cmd_input(0);
int current(0);
const int IR_STATIC_VAL(-1);

// MODE OPERATION:
bool MODE = true;  // initialize to remote control mode

void setup() {
  Serial.begin(9600);
  ir_rec.enableIRIn();  // start reciever

  // Initialize distance variables
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIG, LOW);
  digitalWrite(ECHO, LOW);
}

void loop() {
  if (MODE && ir_rec.decode(&results)) {
    current = results.value;  // cannot use raw value call in boolean statements

    // filter out the static IR value (equal to -1)
    if (current != IR_STATIC_VAL) {
      cmd_input = current;
    }

    Serial.print(current);
    Serial.print(": ");
    
    if (cmd_input == 6375) {
      Serial.println("Forward");
    }
    else if (cmd_input == 23205) {
      Serial.println("Right");
    }
    else if (cmd_input == 4335) {
      Serial.println("Left");
    }
    else if (cmd_input == 19125) {
      Serial.println("Backward");
    }
    else if (cmd_input == 14535) {
      Serial.println("Brake");
    }
    else if (cmd_input == 26775) {
      Serial.println("Switching Mode");
      MODE = !MODE;  // switch value of mode to opposite 
    }
    
    ir_rec.resume();
  }
  else if (!MODE) {    
    Serial.print("Distance: ");
    dist = distance(TRIG, ECHO);
    Serial.println(dist);
    delay(500);
    
    // check for the mode switch command from IR sensor
    if (ir_rec.decode(&results)) {
      current = results.value;
      Serial.print(current);
      Serial.print(": ");
      if (current == 26775) {
        Serial.println("Switching Mode");
        MODE = !MODE;
      }
      ir_rec.resume();
    }
  }
}
