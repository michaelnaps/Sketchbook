

void forward(int rate) {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, HIGH);
  digitalWrite(MC2, LOW);
  analogWrite(EN, rate);
}
