// Function: keyRelease()

// Purpose: Reset buffer values after a key is pressed
//  and sent to the appropriate client.
// input: 'buf' - buffer array which was changed before
//                being sent to client.
//        'n' - length of buffer array
void keyRelease()
{
  hid_report.writeValue(0);
  return;  // return nothing
}
