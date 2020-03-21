// function: blink_LED()
// Created by: Michael Napoli
// Created on: 3/21/2020

/*
 * Purpose: Blink given LED pin for the given length of time (ms)
 * 
 * intput: 'LED' - pin number for light
 *  'period' - length of time of blink in milliseconds
 * output: void
*/
void blink_LED(const int LED, const int period){
  // turn on LEDs for 'period' seconds
  digitalWrite(LED, HIGH);
  delay(period);

  // turn off LEDs for 'period' seconds
  digitalWrite(LED, LOW);
  delay(period);

  // return nothing
  return;
}
