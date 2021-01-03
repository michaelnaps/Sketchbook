// Function: keyCheck_dig()

// Purpose: check for button press and send to BLE device service
// input: 'pin' - button pin
//        'id' - key id to send to BLE
void keyCheck_dig(const int& pin, const int& id)
{
  if (digitalRead(pin)) {
    buf = (byte)id;
    hid_report.writeValue(buf);  // write to BLE characteristic value
    buf = 0;
  }

  // update board for key release
  keyRelease();
  
  return;  // return nothing
}
