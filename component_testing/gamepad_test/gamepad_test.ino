// gamepad testing

// initialize buttons
const int L = 12;
const int a = 11;
const int b = 10;
const int x = 9;
const int y = 8;

// initialize joystick
const int sw = 7;

void setup() {
  pinMode(L, INPUT);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(sw, INPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(L) == LOW)
    { Serial.println('L'); }
    
  if (digitalRead(a) == LOW)
    { Serial.println('a'); }
    
  if (digitalRead(b) == LOW)
    { Serial.println('b'); }
    
  if (digitalRead(x) == LOW)
    { Serial.println('x'); }
    
  if (digitalRead(y) == LOW)
    { Serial.println('y'); }
    
  if (digitalRead(sw) == HIGH)
    { Serial.println("sw"); }
}
