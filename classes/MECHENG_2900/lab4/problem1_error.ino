/*
const int kPinButton1 = 2;  // line 1
const int kPinButton2 = 3;
const int kPinLed = 9;
int ledBrightness = 128;  // global variable moved to top of script

void setup()
{
  pinMode(kPinLed, OUTPUT);  // removed '}' bracket from after this command

  // moved all pinMode() function calls to setup function
  pinMode(kPinButton1, INPUT);
  pinMode(kPinButton2, INPUT);
}

void loop()
{
  if(digitalRead(kPinButton1) == LOW){
    ledBrightness--;
  }
  // added second '=' sign to create boolean statement
  else if (digitalRead(kPinButton2) == LOW){
    ++ledBrightness;  // fixed iteration functionality
  }
  ledBrightness = constrain(ledBrightness, 0, 255);
  digitalWrite(kPinLed, ledBrightness);
  delay(20);
}  // line 27
*/
/*
const int kPinButton1 = 2;
const int kPinButton2 = 3;
const int kPinLed = 9;

void setup()
{
  pinMode(kPinLed, OUTPUT);}
}

pinMode(kPinButton1, INPUT);
pinMode(kPinButton2, INPUT);
int ledBrightness = 128;

void loop()
{
  if(digitalRead(kPinButton1) == LOW){
    ledBrightness--;
  }
  else if (digitalRead(kPinButton2) = LOW){
    ledBrightness + 1;
  }
  
  ledBrightness = constrain(ledBrightness, 0, 255);
  digitalWrite(kPinLed, ledBrightness);
  delay(20);
}
*/
