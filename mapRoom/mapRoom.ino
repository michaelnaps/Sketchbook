
#include <Stepper.h>

const int stepsPerRev(2048);
Stepper EYES(stepsPerRev, 2, 3, 4, 5);

const int TRIG(7);
const int ECHO(8);

bool dir(true);
int ang(0);  // initialize to 0
float dist(0);  // initialize to 0

void setup() {
  EYES.setSpeed(10);
  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {
  if (dir) {
    ang += 64;
    EYES.step(64);
  }
  else {
    ang -= 64;
    EYES.step(-64);
  }
  
  dist = distance(TRIG, ECHO);
  Serial.print(dist);
  Serial.print(", ");
  Serial.println(ang);

  if (ang >= 2048) {
    dir = false;  // switch directions
  }
  else if (ang <= 0) {
    dir = true;  // switch directions
  }
}
