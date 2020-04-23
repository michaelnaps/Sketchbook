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

  NOTE: For submission all serial related commands were commented out,
    but remain in the program in case they are needed later.
*/

#include <Servo.h>  // servo motor control library
#include <IRremote.h>  // infra-red sensor control/decode library

// PROGRAM EXECUTION VARIABLES:
int cmd_input(0);  // input from IR remote
// for switching between manual and automatic functionality
bool MODE(true);  // initilized to manual (manual == true)

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
  // initialize h-bridge pins - all output
  pinMode(EN_LEFT, OUTPUT);
  pinMode(MC_LEFT_1, OUTPUT);
  pinMode(MC_LEFT_2, OUTPUT);
  pinMode(EN_RIGHT, OUTPUT);
  pinMode(MC_RIGHT_1, OUTPUT);
  pinMode(MC_RIGHT_2, OUTPUT);

  control_servo.attach(SERVO_PIN);  // initialize servo motor
  control_servo.write(100);  // start in forward angle position
  
  ir_rec.enableIRIn();  // initialize IR sensor

  // initialize distance sensor pins
  pinMode(TRIG, OUTPUT);  // trigger is output
  pinMode(ECHO, INPUT);  // echo pin is input

  // start both distance sensor pins LOW
  digitalWrite(TRIG, LOW);
  digitalWrite(ECHO, LOW);

  // Serial.begin(9600);  // begin // Serial monitor for error evaluation
}

void loop() 
{
  // if the mode is in manual and there is a signal to the remote use this branch
  if (MODE && ir_rec.decode(&results)) {
    // convert result to integer value to use in conditional statements
    cmd_input = results.value;  // cannot use raw value call in boolean statements
  
    // Serial.print(cmd_input);
    // Serial.print(": ");

    // forward signal
    if (cmd_input == 1785) {
      // Serial.println("Forward");
      forward(255);
    }
    // right turn signal
    else if (cmd_input == 18105) {
      // Serial.println("Right");
      turn_right();
    }
    // left turn signal
    else if (cmd_input == -22951) {
      // Serial.println("Left");
      turn_left();
    }
    // reverse signal
    else if (cmd_input == -31111) {
      // Serial.println("Reverse");
      reverse(255);
    }
    // signal to brake
    else if (cmd_input == 5865) {
      // Serial.println("Brake");
      brake();
    }
    // signal to switch modes
    else if (cmd_input == -11731) {
      // Serial.println("Switching Mode");
      brake();  // brake when switching between modes
      MODE = !MODE;  // switch value of mode to opposite 
    }

    // clear IR sensor for next input
    ir_rec.resume();
  }
  // if the mode is switched to automatic (MODE = false), use this branch
  else if (!MODE) {    
    dist = distance(TRIG, ECHO);  // get distance from UDS
    
    // Serial.print("Distance: ");
    // Serial.println(distance(TRIG, ECHO));

    // direction of SART conditions
    // NOTE: distance sensor return values automatically help to remove noise
    // and improper distances

    // if the distance from UDS is greater than 40 cm
    if (dist > 40) {
      forward(255);  // move forward
    }
    //  if distance is between 20-40 cm, begin to turn
    else if (dist > 20 && dist <= 40) {
      // begin turning but continue moving forward
      forward(255);
      turn_left();
    }
    // if the distance is less than 20 cm enter turn sequence
    else if (dist <= 20) {
      // reverse and turn right for 2 seconds
      reverse(255);
      turn_right();
      delay(2000);
      // move forward turning left for 2 seconds
      forward(255);
      turn_left();
      delay(2000);
    }
    
    // check for the mode switch command from IR remote
    if (ir_rec.decode(&results)) {
      cmd_input = results.value;
      // Serial.print(cmd_input);
      // Serial.print(": ");
      if (cmd_input == -11731) {
        // Serial.println("Switching Mode");
        brake();  // brake when converting between modes
        MODE = !MODE;
      }
      // clear IR sensor for next value
      ir_rec.resume();
    }
  }
}
