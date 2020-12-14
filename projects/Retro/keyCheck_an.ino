// Function: keyCheck_an()

// Purpose: check for button press and send to BLE device service
// input: 'pin' - button pin
//        'high' - key ID for high button for BLE
//        'low' - key ID for low button for BLE
void keyCheck_dig(const int& pin, const uint8_t& high, const uint8_t& low)
{
  if (analogRead(pin) > 600) {
    buf[2] = high;
    Serial.write(buf, 8);  // write to serial port
    keyRelease(buf, 8);
  }
  else if (analogRead(pin) < 400) {
    buf[2] = low;
    Serial.write(buf, 8);
    keyRelease(buf, 8);
  }
  
  return;  // return nothing
}
