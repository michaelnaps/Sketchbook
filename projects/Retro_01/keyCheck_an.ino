// Function: keyCheck_an()

// Purpose: check for button press and send to BLE device service
// input: 'pin' - button pin
//        'high' - key ID for high button for BLE
//        'low' - key ID for low button for BLE
void keyCheck_an(const int& pin, const int& high, const int& low)
{
  if (analogRead(pin) > 600) {
    buf = (byte)high;
    hid_cp.writeValue(buf);  // write to BLE characteristic port
    buf = 0;
  }
  else if (analogRead(pin) < 400) {
    buf = (byte)low;
    hid_cp.writeValue(buf);
    buf = 0;
  }
  
  return;  // return nothing
}
