// Testing joystick inputs to microcontroller

// SW pin
const int sw_pin = 7;
// X Direction pin (analog)
const int x_pin = A0;
// Y direction pin (analog)
const int y_pin = A1;


void setup() {
  pinMode(sw_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int x_pos = analogRead(x_pin);
  int y_pos = analogRead(y_pin);
  bool sw = digitalRead(sw_pin);

  if (x_pos > 600)
    { Serial.println("Up"); }
  else if (x_pos < 400)
    { Serial.println("Down"); }
    
  if (y_pos > 600)
    { Serial.println("Right"); }
  else if (y_pos < 400)
    { Serial.println("Left"); }

  if (sw == HIGH)
    { Serial.println("Switch"); }

  delay(100);
}
