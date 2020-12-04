// Function: brake()
// Created by: Michael Napoli
// Created on: 3/30/2020

void forward(const int& rate) {
  // disable drivers
  digitalWrite(EN_LEFT, LOW);
  digitalWrite(EN_RIGHT, LOW);
  
  // toggle switches to move forward
  digitalWrite(MC_LEFT_1, HIGH);
  digitalWrite(MC_LEFT_2, LOW);
  digitalWrite(MC_RIGHT_1, HIGH);
  digitalWrite(MC_RIGHT_2, LOW);
  
  // start motors at given speed
  analogWrite(EN_LEFT, rate);
  analogWrite(EN_RIGHT, rate);
}
