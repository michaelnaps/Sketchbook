void keyRelease(const uint8_t& buf[], const int& n) {
  for (int i(0); i < n; ++i) {
    buf[i] = 0;
  }
  
  return;  // return nothing
}
