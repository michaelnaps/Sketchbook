 // Project: A.R.T. (Autonomous Robotic Toy)
// Created by: Michael Napoli
// Created on: 3/7/2020
// Last modified on:

/*
  Purpose: Main execution file for S.A.R.T. program.
    S.A.R.T. (Semi Automatic Remote Toy)

  This project will have the following capabilities
    
*/

#include <IRremote.h>  // infra-red sensor control/decode library

// PROGRAM EXECUTION PINS:
int cmd_input(0);
int current(0);
bool MODE(true);

// H-BRIDGE MOTOR PINS:
// Left Motor
const int EN_LEFT(4);
const int MC_LEFT_1(3);
const int MC_LEFT_2(2);
// Right Motor
const int EN_RIGHT(7);
const int MC_RIGHT_1(6);
const int MC_RIGHT_2(5);

// IR SENSOR:
const int IR_PIN(10);
const int IR_STATIC_VAL(-1);
IRrecv ir_rec(IR_PIN);
decode_results results;

// DISTANCE SENSOR PINS:
const int TRIG(8);
const int ECHO(9);
float dist(0);

void setup()
{
  ir_rec.enableIRIn();
  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIG, LOW);
  digitalWrite(ECHO, LOW);

  Serial.begin(9600);
}

void loop() 
{
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
      forward(255);
    }
    else if (cmd_input == 23205) {
      Serial.println("Right");
    }
    else if (cmd_input == 4335) {
      Serial.println("Left");
    }
    else if (cmd_input == 19125) {
      Serial.println("Reverse");
      reverse(255);
    }
    else if (cmd_input == 14535) {
      Serial.println("Brake");
      brake();
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
    delay(250);
    
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
