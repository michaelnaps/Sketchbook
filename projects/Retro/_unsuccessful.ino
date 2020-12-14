// Function: _unsuccessful()

// Purpose: if called, stops program
// blinks the built in LED to tell user
void _unsuccessful() 
{
  // infinite loop
  while(1) {
    analogWrite(LED_BUILTIN, 800);
    delay(500);
    analogWrite(LED_BUILTIN, 0);
    delay(500);
  }
  
  return;  // return nothing
}
