// Testing joystick inputs to microcontroller

// SW pin
int sw_pin = 7;
// X Direction pin (analog)
int x_pin = A0;
// Y direction pin (analog)
int y_pin = A1;


void setup() {
  pinMode(sw_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int x_pos = analogRead(x_pin) - 500;
  int y_pos = analogRead(y_pin) - 500;
  bool sw = digitalRead(sw_pin);

  if (x_pos > 50)
    { Serial.println("Up"); }
  else if (x_pos < -50)
    { Serial.println("Down"); }
    
    
  if (y_pos > 50)
    { Serial.println("Right"); }
  else if (y_pos < -50)
    { Serial.println("Left"); }

  delay(100);
}
