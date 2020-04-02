
void reverse(const int& rate) {
  // disable drivers
  digitalWrite(EN_LEFT, LOW);
  digitalWrite(EN_RIGHT, LOW);
  
  // toggle switches to move backwards
  digitalWrite(MC_LEFT_1, LOW);
  digitalWrite(MC_LEFT_2, HIGH);
  digitalWrite(MC_RIGHT_1, LOW);
  digitalWrite(MC_RIGHT_2, HIGH);
  
  // start motors at given speed
  analogWrite(EN_LEFT, rate);
  analogWrite(EN_RIGHT, rate);
}
