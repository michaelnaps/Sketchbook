// function: dist_lights()
// Created by: Michael Napoli
// Created on: 3/21/2020

/*
 * Purpose: Take distance input and change the attached LEDs
 *  accordingly. Each range applies to a different light configuration.
 *  
 *  Ranges: (all in meters)
 *    0m - 1m - green and yellow ON, red blinking
 *    1m - 5m - green and yellow ON, red at 50% brightness
 *    5m - 10m - green ON, yellow at 50% brightness
 *    10m - 20m - green at 50% brightness
 *    
 *  intput: 'val' - distance value
 *    'period' - length of time of red LED blink if needed
 *  output: void
*/

void dist_lights(const int val, const int period) {
  if (val > 10 && val <= 20) {
    analogWrite(greenLED, 255/2);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }
  else if (val > 5 && val <= 10) {
    digitalWrite(greenLED, HIGH);
    analogWrite(yellowLED, 255/2);
    digitalWrite(redLED, LOW);
  }
  else if (val > 1 && val <= 5) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    analogWrite(redLED, 255/2);
  }
  else if (val <= 1) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    blink_LED(redLED, period);
  }

  // return nothing
  return;
}
