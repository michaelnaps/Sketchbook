
// Function: distance()
// Created by: Michael Napoli
// Created on: 4/9/2020
int distance(const int& trigPin, const int& echoPin) {
  int dist(0);
  int change_t(0);
  const int SOUND(343);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  change_t = pulseIn(echoPin, HIGH);  // returns pulse in microseconds
  
  dist = ((change_t / 10000) * SOUND) / 2;

  digitalWrite(echoPin, LOW);
  digitalWrite(trigPin, LOW);

  return dist;
}
