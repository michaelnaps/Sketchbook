// Function: keyCheck_dig()

// Purpose: check for button press and send to BLE device service
// input: 'pin' - button pin
//        'id' - key id to send to BLE
void keyCheck_dig(const int& pin, const uint8_t& id)
{
  if (digitalRead(pin)) {
    buf[2] = id;
    Serial.write(buf, 8);  // write to serial port
    keyRelease(buf, 8);
  }
  
  return;  // return nothing
}
