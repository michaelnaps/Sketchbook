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
  if (digitalRead(L) == HIGH)
    { Serial.println('L'); }
    
  if (digitalRead(a) == HIGH)
    { Serial.println('a'); }
    
  if (digitalRead(b) == HIGH)
    { Serial.println('b'); }
    
  if (digitalRead(x) == HIGH)
    { Serial.println('x'); }
    
  if (digitalRead(y) == HIGH)
    { Serial.println('y'); }
    
  if (digitalRead(sw) == HIGH)
    { Serial.println("sw"); }
}
