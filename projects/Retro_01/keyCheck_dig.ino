// Function: keyCheck_dig()

// Purpose: check for button press and send to BLE device service
// input: 'pin' - button pin
//        'id' - key id to send to BLE
void keyCheck_dig(const int& pin, const int& id)
{
  if (digitalRead(pin)) {
    buf = (byte)id;
    hid_cp.writeValue(buf);  // write to BLE characteristic value
    buf = 0;
  }
  
  return;  // return nothing
}
