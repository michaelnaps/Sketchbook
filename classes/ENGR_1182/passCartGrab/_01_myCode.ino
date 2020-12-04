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
  
  //grand canyon via 45% power for 135 marks
  motorSpeed(4,45);
  goToAbsolutePosition(120);
  //airbrake with 30% power for 1.7 seconds
  reverse(4);
  motorSpeed(4,35);
  goFor(1.1);
  //adjust to 140 marks at slow speed
  reverse(4);
  motorSpeed(4,10);
  goToAbsolutePosition(176);
  //airbrake
  reverse(4);
  motorSpeed(4,20);
  goFor(.8);
  //grab cart using hook displacement of 110 degrees
  brake(4);
  goFor(.5);
  rotateServo(110);
  //pause at stop for 3 seconds
  brake(4);
  goFor(3);
  

  // And here--------------------------------------------------------------------------------

} // DO NOT REMOVE. end of void myCode()
