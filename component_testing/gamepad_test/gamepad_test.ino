// gamepad testing

// Joystick pins
// const int x_js = A0;
// const int y_js = A1;

// initialize buttons
const int L = 12;
const int a = 11;
const int b = 10;
const int x_b = 9;
const int y_b = 8;

void setup() {
  pinMode(L, INPUT);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(x_b, INPUT);
  pinMode(y_b, INPUT); 

  Serial.begin(9600);
}

void loop() {
  // int x_dir = analogRead(x_js) - 500;
  // int y_dir = analogRead(y_js) - 500;
  
  if (digitalRead(L) == HIGH)
    { Serial.println('L'); }
    
  if (digitalRead(a) == HIGH)
    { Serial.println('a'); }
    
  if (digitalRead(b) == HIGH)
    { Serial.println('b'); }
    
  if (digitalRead(x_b) == HIGH)
    { Serial.println('x'); }
    
  if (digitalRead(y_b) == HIGH)
    { Serial.println('y'); }

/*
  if (x_dir > 50)
    { Serial.println("+X"); }

  if (x_dir < -50)
    { Serial.println("-X"); }

  if (y_dir > 50)
    { Serial.println("+Y"); }

  if (y_dir < -50)
    { Serial.println("-Y"); }
*/
}
