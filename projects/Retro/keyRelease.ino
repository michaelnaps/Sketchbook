// Function: keyRelease()

// Purpose: Release given button to be used again
// input: 'buf' - buffer variable (operates on 8 bits)
//        'n' - length of buffer variable
void keyRelease(const uint8_t& buf[], const int& n) 
{
  for (int i(0); i < n; ++i) {
    buf[i] = 0;
  }
  
  return;  // return nothing
}
