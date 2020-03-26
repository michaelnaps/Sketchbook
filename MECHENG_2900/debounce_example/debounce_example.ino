// File: debounce_example()
// Created by: Michael Napoli
// Created on: 2/27/2020

const int LED = 9;  // pin number for LED light
const int BUTTON = 2;  // pin number for button input

// 'LOW' works for the boolean type because
// 'LOW' = 0 and 'HIGH' = 1
// initialized to 'LOW' (off)
boolean lastButton = LOW;  // variable for comparison to the current button status
boolean currentButton = LOW;  // current button status
boolean ledOn = false;  // test for the LED status

void setup() 
{
  pinMode(LED, OUTPUT);
  // button pins are type 'INPUT'
  pinMode(BUTTON, INPUT);
}

// function: debounce()
// function for the comparison between current and last LED status
// input:
// 'last' - the status (LOW or HIGH) of the most recent button press
// output:
// 'current' - the status of the LED at the current time
boolean debounce(boolean last) {
  // 'current' initialized to the 'BUTTON' status (LOW or HIGH)
  boolean current = digitalRead(BUTTON);

  // if the given 'last' status is different then 'current'
  if (last != current) {
    delay(0);  // wait 5 ms
    current = digitalRead(BUTTON);  // read again
  }

  return current;  // return the current value
}

void loop()
{
  currentButton = debounce(lastButton);  // set to the current button status

  // if the last status is opposite the current
  if (lastButton == LOW && currentButton == HIGH)
  {
    ledOn = !ledOn;  // change the value of the LED status
  }

  // set button values equal
  lastButton = currentButton;

  // write the current button status to the LED
  digitalWrite(LED, ledOn);
}
