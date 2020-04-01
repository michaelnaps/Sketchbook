// left motor
const int EN_LEFT = 3;
const int MC_LEFT_1 = 2;
const int MC_LEFT_2 = 1;

// right motor
const int EN_RIGHT = 6;
const int MC_RIGHT_1 = 5;
const int MC_RIGHT_2 = 4;

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

void brake() {
  // disable drivers 
  digitalWrite(EN_LEFT, LOW);
  digitalWrite(EN_RIGHT, LOW);
  
  // toggle switches to brake
  digitalWrite(MC_LEFT_1, LOW);
  digitalWrite(MC_LEFT_2, LOW);
  digitalWrite(MC_RIGHT_1, LOW);
  digitalWrite(MC_RIGHT_2, LOW);
  
  // enable drivers
  digitalWrite(EN_LEFT, HIGH);
  digitalWrite(EN_RIGHT, HIGH);
}

void setup()
{
  for (int i(1); i < 7; ++i) {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  forward(150);
  delay(3000);
  
  brake();
  delay(2000);
  
  reverse(150);
  delay(3000);
}
