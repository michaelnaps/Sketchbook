// Function: _unsuccessful()

// Purpose: if called, stops program blinks
//   the built in LED to tell user operation was
//   not completed. Stops program.
void _unsuccessful() 
{
  for (int i(0); i < 3; ++i) {
    analogWrite(LED_BUILTIN, 800);
    delay(500);
    analogWrite(LED_BUILTIN, 0);
    delay(500);
  }
  
  return;  // return nothing
}
