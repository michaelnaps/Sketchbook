
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
    ++ang;
    EYES.step(1);
  }
  else {
    --ang;
    EYES.step(-1);
  }
  
  dist = distance(TRIG, ECHO);
  Serial.print(dist);
  Serial.print(", ");
  Serial.println(ang);

  if (ang == 360) {
    dir = true;  // switch directions
  }
  else if (ang == 0) {
    dir = false;  // switch directions
  }
}
