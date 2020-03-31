

void brake() {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, LOW);
  analogWrite(EN, HIGH);
}
