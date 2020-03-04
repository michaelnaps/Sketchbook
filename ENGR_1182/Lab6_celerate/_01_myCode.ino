void myCode()
{
  //----------------------------------------------------------------------------------------
  // myCode();
  //
  // This is the tab where the programming of your vehicle operation is done.
  // Tab _00_AEV_key_words contains a compiled list of functions/subroutines used for vehicle
  // operation. 
  //
  // Note:
  // (1) After running your AEV do not turn the AEV off, connect the AEV to a computer, or 
  //     push the reset button on the Arduino. There is a 13 second processing period. In 
  //     post processing, data is stored and battery recuperation takes place. 
  // (2) Time, current, voltage, total marks, position traveled are recorded approximately 
  //     every 60 milliseconds. This may vary depending on the vehicles operational tasks. 
  //     It takes approximately 35-40 milliseconds for each recording. Thus when programming,
  //     code complexity may not be beneficial. 
  // (3) Always comment your code. Debugging will be quicker and easier to do and will 
  //     especially aid the instructional team in helping you. 
  //---------------------------------------------------------------------------------------- 

  // Program between here-------------------------------------------------------------------

  //accelerate motors from 0 to 45% in 2 seconds and continue for 1.7 seconds
  reverse(4);
  celerate(4,0,45,2);
  goFor(1.7);

  //reverse all motors and use 35% power for 1.6 seconds to bring the AEV to a stop
  reverse(4);
  motorSpeed(4,35);
  goFor(1.6);
  motorSpeed(4,0);
  goFor(3);

  //accelerate motors from 0 to 30% in 2 seconds and continue for 7.2 seconds
  celerate(4,0,30,2);
  goFor(7.2);

  //reverse motors and airbrake with motors at 25% power for 2 seconds
  reverse(4);
  motorSpeed(4,25);
  goFor(2);

  //reverse motors and accelerate from 0 to 45% in 2 seconds and continue for 4.15 seconds
  reverse(4);
  celerate(4,0,45,2);
  goFor(4.15);

  //reverse all motors and airbrake at 25% power for 1.5 seconds
  reverse(4);
  motorSpeed(4,25);
  goFor(1.5);

  // And here--------------------------------------------------------------------------------

} // DO NOT REMOVE. end of void myCode()
