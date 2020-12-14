// gamepad testing

// buffer for keyboard memory
uint8_t buf[8] = {0};

// Joystick pins
const int x_js = A0;
const int y_js = A1;

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
  // int x_dir = analogRead(x_js);
  // int y_dir = analogRead(y_js);

  keyCheck_dig(L, 15);
  keyCheck_dig(a, 4);
  keyCheck_dig(b, 5);
  keyCheck_dig(x_b, 27);
  keyCheck_dig(y_b, 28);

  keyCheck_an(x_js, 94, 92);
  keyCheck_an(y_js, 96, 90);
}
