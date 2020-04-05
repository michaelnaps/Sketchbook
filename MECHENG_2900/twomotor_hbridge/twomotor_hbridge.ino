// left motor
const int EN_LEFT = 4;
const int MC_LEFT_1 = 3;
const int MC_LEFT_2 = 2;

// right motor
const int EN_RIGHT = 7;
const int MC_RIGHT_1 = 6;
const int MC_RIGHT_2 = 5;

void setup()
{
  for (int i(2); i < 8; ++i) {
    pinMode(i, OUTPUT);
  }
}

void loop()

{
  forward(130);
  delay(6000);

  brake();
  delay(5000);
}
