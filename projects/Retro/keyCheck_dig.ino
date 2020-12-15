// Function: keyCheck_dig()

// Purpose: check for button press and send to BLE device service
// input: 'pin' - button pin
//        'id' - key id to send to BLE
void keyCheck_dig(const int& pin, const int& id)
{
  if (digitalRead(pin)) {
    // buf[2] = (byte)id;
    hid_cp.writeValue((byte)id);  // write to BLE characteristic port
  }
  
  return;  // return nothing
}
