// Function: _successful()

// Purpose: indicates success at certain points
//   in program using the builtin LED
void _successful() 
{
  // fade in and out to indicate success
  for (int i(0); i < 1023; i += 100) {
    analogWrite(LED_BUILTIN, i);
    delay(100);
  }
  for (int i(0); i > 1023; i -= 100) {
    analogWrite(LED_BUILTIN, i);
    delay(100);
  }
  analogWrite(LED_BUILTIN, 0);  // turn off
  
  return;  // return nothing
}
