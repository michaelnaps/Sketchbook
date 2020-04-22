 // Project: A.R.T. (Autonomous Robotic Toy)
// Created by: Michael Napoli
// Created on: 3/7/2020
// Last modified on:

/*
  Purpose: Main execution file for S.A.R.T. program.
    S.A.R.T. (Semi Automatic Remote Toy)

  This project will have the following capabilities:
    1). Control of a small Arduino Uno operated car via IR remote.
    2). Simple automated movement via UltraSonic Distance Sensor.
    3). Easy way to switch between the two different modes.
    
*/

#include <Servo.h>  // servo motor control library
#include <IRremote.h>  // infra-red sensor control/decode library

// PROGRAM EXECUTION VARIABLES:
int cmd_input(0);  // input from IR remote
bool MODE(true);  // for switching between manual and automatic function

// H-BRIDGE MOTOR PINS:
// Left Motor
const int EN_LEFT(4);
const int MC_LEFT_1(3);
const int MC_LEFT_2(2);
// Right Motor
const int EN_RIGHT(7);
const int MC_RIGHT_1(6);
const int MC_RIGHT_2(5);

// SERVO MOTOR VARIABLES:
const int SERVO_PIN(11);  // pin for servo motor
Servo control_servo;

// IR SENSOR VARIABLES:
const int IR_PIN(10);  // pin for IR sensor
IRrecv ir_rec(IR_PIN);
decode_results results;

// DISTANCE SENSOR PINS:
const int TRIG(8);
const int ECHO(9);
float dist(0);

void setup()
{
  // initialize h-bridge pins
  pinMode(EN_LEFT, OUTPUT);
  pinMode(MC_LEFT_1, OUTPUT);
  pinMode(MC_LEFT_2, OUTPUT);
  pinMode(EN_RIGHT, OUTPUT);
  pinMode(MC_RIGHT_1, OUTPUT);
  pinMode(MC_RIGHT_2, OUTPUT);

  control_servo.attach(SERVO_PIN);  // initialize servo motor
  control_servo.write(100);  // start in forward position
  
  ir_rec.enableIRIn();  // initialize IR sensor

  // DISTANCE SENSOR VARIABLES
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIG, LOW);
  digitalWrite(ECHO, LOW);

  Serial.begin(9600);
}

void loop() 
{
  // if the mode is in manual and there is a signal to the remote use this branch
  if (MODE && ir_rec.decode(&results)) {
    cmd_input = results.value;  // cannot use raw value call in boolean statements
  
    Serial.print(cmd_input);
    Serial.print(": ");
    
    if (cmd_input == 1785) {
      Serial.println("Forward");
      forward(255);
    }
    else if (cmd_input == 18105) {
      Serial.println("Right");
      turn_right();
    }
    else if (cmd_input == -22951) {
      Serial.println("Left");
      turn_left();
    }
    else if (cmd_input == -31111) {
      Serial.println("Reverse");
      reverse(255);
    }
    else if (cmd_input == 5865) {
      Serial.println("Brake");
      brake();
    }
    else if (cmd_input == -11731) {
      Serial.println("Switching Mode");
      brake();  // brake when switching between modes
      MODE = !MODE;  // switch value of mode to opposite 
    }
    
    ir_rec.resume();
  }
  // if the mode is switched it automatic use this branch
  else if (!MODE) {    
    Serial.print("Distance: ");
    dist = distance(TRIG, ECHO);
    Serial.println(distance(TRIG, ECHO));

    // direction of SART conditions
    // NOTE: distance sensor return values automatically help to remove noise
    // and improper distances
    if (dist > 40) {
      forward(255);
    }
    else if (dist > 20 && dist <= 40) {
      // begin turning but continue moving forward
      forward(255);
      turn_left();
    }
    else if (dist <= 20) {
      reverse(255);
      turn_right();
      delay(2000);
      forward(255);
      turn_left();
      delay(2000);
    }
    
    // check for the mode switch command from IR remote
    if (ir_rec.decode(&results)) {
      cmd_input = results.value;
      Serial.print(cmd_input);
      Serial.print(": ");
      if (cmd_input == -11731) {
        Serial.println("Switching Mode");
        brake();  // brake when converting between modes
        MODE = !MODE;
      }
      // clear IR sensor for next value
      ir_rec.resume();
    }
  }
}
